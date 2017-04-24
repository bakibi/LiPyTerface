
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
    cssDataToWidget(console, "color : #0F0;background-color: #1E1E1D;");

    GtkTextBuffer *buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(console));
    gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(console), GTK_WRAP_WORD);
    

    GtkTextIter iter;
    gtk_text_buffer_get_iter_at_offset(buffer, &iter, 0);

    //  CREATION DEs COULEURs
    gtk_text_buffer_create_tag(buffer, "blue_fg","foreground", "blue", NULL);
    gtk_text_buffer_create_tag(buffer, "black_fg","foreground", "black", NULL);
    gtk_text_buffer_create_tag(buffer, "green_fg","foreground", "green", NULL);
    gtk_text_buffer_create_tag(buffer, "red_fg","foreground", "red", NULL);
    gtk_text_buffer_create_tag(buffer, "gray_bg","background", "lightgray", NULL); 
    gtk_text_buffer_create_tag(buffer, "orange_fg","foreground", "orange", NULL); 

    gtk_text_buffer_insert_with_tags_by_name(buffer, &iter, "ilisi@shanks:~# ", -1, "orange_fg", NULL);

    gtk_container_add(GTK_CONTAINER(console_scroll_container), console);
    gtk_container_add( GTK_CONTAINER(right) ,console_scroll_container );

    //  setting some spacing
    gtk_container_set_border_width ( GTK_CONTAINER(right), 10);
    gtk_container_set_border_width ( GTK_CONTAINER(console_scroll_container), 10);

    //  SIGNALS
    g_signal_connect(buffer, "changed",G_CALLBACK(update_lnCol), all->lnCol->this);
    g_signal_connect(buffer, "mark_set", G_CALLBACK(mark_set_callback), all);

    

    return(right);
}