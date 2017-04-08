
GtkWidget* bottom_bodyBash(All *all)
{
    //  frame
    GtkWidget *bottom = gtk_frame_new("  Output  ");
    all->bottomFrame=bottom;
    cssDataToWidget(bottom, "color : #23D18B;background-color: #1E1E1D");

    GtkWidget *titre = gtk_frame_get_label_widget(GTK_FRAME(bottom));
    all->bottomTitre=titre;
    cssDataToWidget(titre, "color : #23D18B;font:Bold 20px");
    
    //  output
    GtkWidget* console_scroll_container = gtk_scrolled_window_new(NULL, NULL);
    gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW(console_scroll_container),
                                    GTK_POLICY_NEVER, GTK_POLICY_ALWAYS );

    GtkWidget *output = gtk_text_view_new();
    all->output=output;
    cssDataToWidget(output, "color : #DDDDDD;background-color: #1E1E1D;");
    gtk_text_view_set_editable (GTK_TEXT_VIEW(output), FALSE);

    GtkTextBuffer *buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(output));
    gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(output), GTK_WRAP_WORD);

    GtkTextIter iter;
    gtk_text_buffer_get_iter_at_offset(buffer, &iter, 0);
    
    //  START TEST
    gtk_text_buffer_create_tag(buffer, "red_fg","foreground", "red", NULL);
    gtk_text_buffer_create_tag(buffer, "green_fg","foreground", "green", NULL);
 
    gtk_text_buffer_insert_with_tags_by_name(buffer, &iter, "\n> Erreur ! ", -1, "red_fg", NULL);
    gtk_text_buffer_insert(buffer, &iter, "variable (x) non declare ", -1);
    gtk_text_buffer_insert_with_tags_by_name(buffer, &iter, " ligne 1 col 3", -1, "green_fg", NULL);
    //  END TEST

    gtk_container_add(GTK_CONTAINER(console_scroll_container), output);
    gtk_container_add( GTK_CONTAINER(bottom) ,console_scroll_container );

    //  setting some spacing
    gtk_container_set_border_width ( GTK_CONTAINER(bottom), 10);
    gtk_container_set_border_width ( GTK_CONTAINER(console_scroll_container), 10);

    return(bottom);
}