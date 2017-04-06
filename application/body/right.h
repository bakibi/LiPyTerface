
void update_lnCol(GtkTextBuffer *buffer,
                  GtkStatusbar *lnCol) {
  gchar *msg;
  gint row, col;
  GtkTextIter iter;
  
  gtk_statusbar_pop(lnCol, 3); 

  gtk_text_buffer_get_iter_at_mark(buffer,
      &iter, gtk_text_buffer_get_insert(buffer));

  row = gtk_text_iter_get_line(&iter);
  col = gtk_text_iter_get_line_offset(&iter);

  msg = g_strdup_printf("Ln %d | Col %d", row+1, col+1);

  gtk_statusbar_push(lnCol, 3, msg);

  g_free(msg);
}

void mark_set_callback(GtkTextBuffer *buffer, 
    const GtkTextIter *new_location, GtkTextMark *mark, gpointer data) {

    All *all=data;
    GtkTextIter iter;

    gtk_text_buffer_get_iter_at_mark(buffer, &iter, gtk_text_buffer_get_insert(buffer));

    if(! gtk_text_iter_is_end (&iter)) 
        gtk_text_view_set_editable (GTK_TEXT_VIEW(all->console),FALSE);
    else
        gtk_text_view_set_editable (GTK_TEXT_VIEW(all->console),TRUE);
                       
    update_lnCol(buffer, GTK_STATUSBAR(all->lnCol->this));
}

GtkWidget* right_body(All *all)
{
    GtkWidget *right = gtk_frame_new("  Console  ");
    all->rightFrame=right;
    cssDataToWidget(right, "color : #23D18B;background-color: #1E1E1D");

    GtkWidget *titre = gtk_frame_get_label_widget(GTK_FRAME(right));
    all->rightTitre=titre;
    cssDataToWidget(titre, "color : #23D18B;font:Bold 30px");
    
    Container *console_container =  new_Box(HORIZENTAL, 0, FALSE);

    GtkWidget *console = gtk_text_view_new();
    all->console=console;
    cssDataToWidget(console, "color : #DDDDDD;background-color: #1E1E1D;");

    GtkTextBuffer *buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(console));
    gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(console), GTK_WRAP_WORD);

    gtk_widget_grab_focus(console);

    GtkTextIter iter;
    gtk_text_buffer_get_iter_at_offset(buffer, &iter, 0);
    
    //  START TEST

    gtk_text_buffer_create_tag(buffer, "blue_fg","foreground", "blue", NULL);
    gtk_text_buffer_create_tag(buffer, "green_fg","foreground", "green", NULL);
    gtk_text_buffer_create_tag(buffer, "red_fg","foreground", "red", NULL);

    gtk_text_buffer_insert_with_tags_by_name(buffer, &iter, "\n>", -1, "red_fg", NULL);
    gtk_text_buffer_insert_with_tags_by_name(buffer, &iter, " // Ceci est un commentaire", -1, "green_fg", NULL);
    gtk_text_buffer_insert_with_tags_by_name(buffer, &iter, "\n>", -1, "red_fg", NULL);
    gtk_text_buffer_insert_with_tags_by_name(buffer, &iter, " int ", -1, "blue_fg", NULL);
    gtk_text_buffer_insert(buffer, &iter, "x = 0 ;", -1);
    gtk_text_buffer_insert_with_tags_by_name(buffer, &iter, "\n>", -1, "red_fg", NULL);
    
   
    gtk_text_buffer_set_modified (buffer,TRUE);

    //  END TEST

    gtk_text_iter_forward_cursor_positions (&iter,4); 

    console_container = Box_addFirst(console_container,console,TRUE,TRUE,0);
    gtk_container_add( GTK_CONTAINER(right) ,GTK_WIDGET(console_container->this) );

    //  setting some spacing
    gtk_container_set_border_width ( GTK_CONTAINER(right), 10);
    gtk_container_set_border_width ( GTK_CONTAINER(console_container->this), 10);


    //  SIGNALS
    g_signal_connect(buffer, "changed",
        G_CALLBACK(update_lnCol), all->lnCol->this);

  g_signal_connect(buffer, "mark_set", 
        G_CALLBACK(mark_set_callback), all);

    return(right);
}