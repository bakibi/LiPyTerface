
GtkWidget* right_body(All *all)
{
    //  frame
    GtkWidget *right = gtk_frame_new("  Console  ");
    all->rightFrame=right;
    cssDataToWidget(right, "color : #23D18B;background-color: #1E1E1D");

    GtkWidget *titre = gtk_frame_get_label_widget(GTK_FRAME(right));
    all->rightTitre=titre;
    cssDataToWidget(titre, "color : #23D18B;font:Bold 30px");
    
    //  console
    GtkWidget* console_scroll_container = gtk_scrolled_window_new(NULL, NULL);
    gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW(console_scroll_container),
                                    GTK_POLICY_NEVER, GTK_POLICY_ALWAYS );

    GtkWidget *console = gtk_text_view_new();
    all->console=console;
    cssDataToWidget(console, "color : #DDDDDD;background-color: #1E1E1D;");

    GtkTextBuffer *buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(console));
    gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(console), GTK_WRAP_WORD);

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
    //  END TEST

    gtk_container_add(GTK_CONTAINER(console_scroll_container), console);
    gtk_container_add( GTK_CONTAINER(right) ,console_scroll_container );

    //  setting some spacing
    gtk_container_set_border_width ( GTK_CONTAINER(right), 10);
    gtk_container_set_border_width ( GTK_CONTAINER(console_scroll_container), 10);

    //  SIGNALS
    g_signal_connect(buffer, "changed",G_CALLBACK(update_lnCol), all->lnCol->this);
    g_signal_connect(buffer, "mark_set", G_CALLBACK(mark_set_callback), all);

    g_signal_connect(all->f->this, "key-release-event", G_CALLBACK(supprimer_console), all);
    g_signal_connect(all->f->this, "key-press-event", G_CALLBACK(supprimer_console), all);

    return(right);
}