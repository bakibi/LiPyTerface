static void screen_changed(GtkWidget *widget, GdkScreen *old_screen, gpointer user_data);
static gboolean draw(GtkWidget *widget, cairo_t *new_cr, gpointer user_data);
static void clicked(GtkWindow *win, GdkEventButton *event, gpointer user_data);

Fenetre* quick_constructor()
{
    Fenetre *quick = new_Fenetre("Quick",NORMAL,new_Taille(100,100),P_CENTER);
    gtk_window_set_decorated(GTK_WINDOW(quick->this),FALSE);

    gtk_widget_set_app_paintable(quick->this, TRUE);

    g_signal_connect(G_OBJECT(quick->this), "draw", G_CALLBACK(draw), NULL);
    g_signal_connect(G_OBJECT(quick->this), "screen-changed", G_CALLBACK(screen_changed), NULL);

    gtk_window_set_decorated(GTK_WINDOW(quick->this), FALSE);
    gtk_widget_add_events(quick->this, GDK_BUTTON_PRESS_MASK);
    g_signal_connect(G_OBJECT(quick->this), "button-press-event", G_CALLBACK(clicked), NULL);

    GtkWidget* fixed_container = gtk_fixed_new();
    gtk_container_add(GTK_CONTAINER(quick->this), fixed_container);
    GtkWidget* button = gtk_button_new_with_label("button1");
    gtk_widget_set_size_request(button, 100, 100);
    gtk_container_add(GTK_CONTAINER(fixed_container), button);

    screen_changed(quick->this, NULL, NULL);
    
    //  test

    Container *vBox= new_Box(VERTICAL,0, FALSE);
    quick = Fenetre_setContainer(quick,vBox);

    Component *btn = new_Button_image("../../img/add.png"); 

    //Component *btn = new_Button("(+)");

    Box_addFirst(vBox, btn->this, FALSE, FALSE, 0);

    return (quick);
}

gboolean supports_alpha = FALSE;
static void screen_changed(GtkWidget *widget, GdkScreen *old_screen, gpointer userdata)
{
    /* To check if the display supports alpha channels, get the visual */
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

static gboolean draw(GtkWidget *widget, cairo_t *cr, gpointer userdata)
{
   cairo_t *new_cr = gdk_cairo_create(gtk_widget_get_window(widget));

    if (supports_alpha)
        cairo_set_source_rgba (new_cr, 0.5, 1.0, 0.50, 0); /* transparent */
    else
        cairo_set_source_rgb (new_cr, 1.0, 1.0, 1.0); /* opaque white */

    /* draw the background */
    cairo_set_operator (new_cr, CAIRO_OPERATOR_SOURCE);
    cairo_paint (new_cr);

    cairo_destroy(new_cr);

    return FALSE;
}

static void clicked(GtkWindow *win, GdkEventButton *event, gpointer user_data)
{
    /* toggle window manager frames */
    gtk_window_set_decorated(win, !gtk_window_get_decorated(win));
} 