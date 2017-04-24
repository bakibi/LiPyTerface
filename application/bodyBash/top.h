
GtkWidget* top_bodyBash(All *all)
{
    //  frame
    GtkWidget *top = gtk_frame_new("  Editeur de Texte  ");
    all->topFrame=top;
    cssDataToWidget(top, "color : #23D18B;background-color: #1E1E1D;margin:30px;");

    GtkWidget *titre = gtk_frame_get_label_widget(GTK_FRAME(top));
    all->topTitre=titre;
    cssDataToWidget(titre, "color : #23D18B;font:Bold 20px");
    
    //  editor
    GtkWidget* console_scroll_container = gtk_scrolled_window_new(NULL, NULL);
    gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW(console_scroll_container),
                                    GTK_POLICY_NEVER, GTK_POLICY_ALWAYS );

    GtkWidget *editor = gtk_text_view_new();
    all->editor=editor;
    cssDataToWidget(editor, "color : #DDDDDD;background-color: #1E1E1D;");

    GtkTextBuffer *buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(editor));
    gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(editor), GTK_WRAP_WORD);

    GtkTextIter iter;
    gtk_text_buffer_get_iter_at_offset(buffer, &iter, 0);
    
    //  CREATION COULEUR
    gtk_text_buffer_create_tag(buffer, "blue_fg","foreground", "blue", NULL);

    gtk_container_add(GTK_CONTAINER(console_scroll_container), editor);
    gtk_container_add( GTK_CONTAINER(top) ,console_scroll_container );

    //  setting some spacing
    gtk_container_set_border_width ( GTK_CONTAINER(top), 20);
    gtk_container_set_border_width ( GTK_CONTAINER(console_scroll_container), 10);

    g_signal_connect(buffer, "changed",G_CALLBACK(syntaxHighlight_keyWords_editor), all);

    return(top);
}