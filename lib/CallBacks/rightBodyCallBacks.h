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

void supprimer_console(GtkWidget *widget,GdkEventKey *event, gpointer data)
{
    
    All *all=data;
	
	//	recuperation du caractere saisi
	gchar *key_name = gdk_keyval_name(event->keyval);

    GtkTextBuffer *buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(all->console));

    GtkTextIter iter;
    gtk_text_buffer_get_iter_at_mark(buffer, &iter, gtk_text_buffer_get_insert(buffer));
  
    int col = gtk_text_iter_get_line_offset(&iter);


    if(gtk_text_iter_is_end (&iter))
    {
        if ( g_strcmp0(key_name, "BackSpace")==0 && col == 1 ) 
            gtk_text_view_set_editable (GTK_TEXT_VIEW(all->console),FALSE);
        else 
            gtk_text_view_set_editable (GTK_TEXT_VIEW(all->console),TRUE);
    }
}
