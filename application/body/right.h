GtkWidget* right_body()
{
    GtkWidget *right = gtk_frame_new("  Console  ");
    ALL_setBackgroundColor(right, 0.117, 0.117, 0.117, 1);
    ALL_setForegroundColor(right, 1, 1, 1, 1);

    GtkWidget *titre = gtk_frame_get_label_widget(right);
    gtk_widget_override_font(titre , pango_font_description_from_string("Bold 20"));
    ALL_setForegroundColor(titre, 0, 0.6, 0.8, 1);

    Container *console_container =  new_Box(HORIZENTAL, 0, FALSE);

    GtkWidget *console = gtk_text_view_new();
    ALL_setBackgroundColor(console, 0.117, 0.117, 0.117, 1);
    ALL_setForegroundColor(console, 1, 1, 1, 1);

    GtkTextBuffer *buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(console));
    GtkTextIter iter;

    //  START TEST

    gtk_text_buffer_create_tag(buffer, "blue_fg","foreground", "blue", NULL);
    gtk_text_buffer_create_tag(buffer, "green_fg","foreground", "green", NULL);
    gtk_text_buffer_create_tag(buffer, "red_fg","foreground", "red", NULL);

    gtk_text_buffer_get_iter_at_offset(buffer, &iter, 0);
 
    gtk_text_buffer_insert_with_tags_by_name(buffer, &iter, "\n>", -1, "red_fg", NULL);
    gtk_text_buffer_insert_with_tags_by_name(buffer, &iter, " // Ceci est un commentaire", -1, "green_fg", NULL);
    gtk_text_buffer_insert_with_tags_by_name(buffer, &iter, "\n>", -1, "red_fg", NULL);
    gtk_text_buffer_insert_with_tags_by_name(buffer, &iter, " int ", -1, "blue_fg", NULL);
    gtk_text_buffer_insert(buffer, &iter, "x = 0 ;", -1);
    gtk_text_buffer_insert_with_tags_by_name(buffer, &iter, "\n>", -1, "red_fg", NULL);
    
    //  END TEST

    console_container = Box_addFirst(console_container,console,TRUE,TRUE,0);
    gtk_container_add( GTK_CONTAINER(right) ,GTK_WIDGET(console_container->this) );

    //  setting some spacing
    gtk_container_set_border_width ( GTK_CONTAINER(right), 10);
    gtk_container_set_border_width ( GTK_CONTAINER(console_container->this), 10);

    return(right);
}