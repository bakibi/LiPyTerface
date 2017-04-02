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
    ALL_setForegroundColor(console, 0, 1, 0, 1);

    GtkTextBuffer *buffer = gtk_text_buffer_new(NULL);

    gtk_text_view_set_buffer(console,buffer);
    gtk_text_buffer_set_text(GTK_TEXT_BUFFER(buffer),"> This is my first Command !\n>",-1);
    gtk_text_view_set_editable(GTK_TEXT_VIEW(console),FALSE);

    console_container = Box_addFirst(console_container,console,TRUE,TRUE,0);

    gtk_container_add( GTK_CONTAINER(right) ,GTK_WIDGET(console_container->this) );

    //  setting some spacing
    gtk_container_set_border_width ( GTK_CONTAINER(right), 10);
    gtk_container_set_border_width ( GTK_CONTAINER(console_container->this), 10);

    return(right);
}