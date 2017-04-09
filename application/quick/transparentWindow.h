static void screen_changed(GtkWidget *widget, GdkScreen *old_screen, gpointer user_data);

Fenetre* new_transparent_fenetre()
{
    Fenetre *trans = new_Fenetre("",NORMAL,new_Taille(100,100),P_NONE);
    g_signal_connect(G_OBJECT(trans->this), "delete-event", gtk_main_quit, NULL);
    gtk_widget_set_app_paintable(trans->this, TRUE);
    g_signal_connect(G_OBJECT(trans->this), "screen-changed", G_CALLBACK(screen_changed), NULL);
    gtk_window_set_decorated(GTK_WINDOW(trans->this), FALSE);
    screen_changed(trans->this, NULL, NULL);
    return (trans);
}

gboolean supports_alpha = FALSE;
static void screen_changed(GtkWidget *widget, GdkScreen *old_screen, gpointer userdata)
{
    GdkScreen *screen = gtk_widget_get_screen(widget);
    GdkVisual *visual = gdk_screen_get_rgba_visual(screen);
    if (!visual)
    {
        visual = gdk_screen_get_system_visual(screen);
        supports_alpha = FALSE;
    }
    else
        supports_alpha = TRUE;
    
    gtk_widget_set_visual(widget, visual);
}