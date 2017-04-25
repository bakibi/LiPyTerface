

void cssDataToWidget(GtkWidget *w, gchar *css )
{
    GtkStyleContext *context;
    GtkCssProvider *provider;

    context = gtk_widget_get_style_context (w);
    provider = gtk_css_provider_new ();
    //  attribution d'une classe pour le widget
    gtk_style_context_add_class(context,"tmp");
    //  construction code css
    const gchar *cssFullCode = g_strconcat( ".tmp{" , css , "}", NULL);
    //  ajout du code css construit au widget
    gtk_css_provider_load_from_data (GTK_CSS_PROVIDER (provider), cssFullCode, -1, NULL);
    gtk_style_context_add_provider (context,GTK_STYLE_PROVIDER (provider),GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
    g_object_unref (provider);
}

void cssHoverDataToWidget(GtkWidget *w, gchar *css )
{
    GtkStyleContext *context;
    GtkCssProvider *provider;

    context = gtk_widget_get_style_context (w);
    provider = gtk_css_provider_new ();
    //  attribution d'une classe pour le widget
    gtk_style_context_add_class(context,"tmp");
    //  construction code css
    const gchar *cssFullCode = g_strconcat( ".tmp:hover{" , css , "}", NULL);
    //  ajout du code css construit au widget
    gtk_css_provider_load_from_data (GTK_CSS_PROVIDER (provider), cssFullCode, -1, NULL);
    gtk_style_context_add_provider (context,GTK_STYLE_PROVIDER (provider),GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
    g_object_unref (provider);
}

void cssActiveDataToWidget(GtkWidget *w, gchar *css )
{
    GtkStyleContext *context;
    GtkCssProvider *provider;

    context = gtk_widget_get_style_context (w);
    provider = gtk_css_provider_new ();
    //  attribution d'une classe pour le widget
    gtk_style_context_add_class(context,"tmp");
    //  construction code css
    const gchar *cssFullCode = g_strconcat( ".tmp:active{" , css , "}", NULL);
    //  ajout du code css construit au widget
    gtk_css_provider_load_from_data (GTK_CSS_PROVIDER (provider), cssFullCode, -1, NULL);
    gtk_style_context_add_provider (context,GTK_STYLE_PROVIDER (provider),GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
    g_object_unref (provider);
}

void cssFileToWidget(GtkWidget *w, gchar *classe )
{
    GtkStyleContext *context;
    GtkCssProvider *provider;

    context = gtk_widget_get_style_context (w);
    provider = gtk_css_provider_new ();
    //  attribution d'une classe pour le widget
    gtk_style_context_add_class(context,classe);
    //  recuperation du fichier w3css

    GFile *file = g_file_new_for_path ("lib/css/myCss.css");
    //  ajout du code css au widget selon la classe choisi
    gtk_css_provider_load_from_file(GTK_CSS_PROVIDER (provider),file,NULL);
    //  ajout du code css construit au widget
    gtk_style_context_add_provider (context,GTK_STYLE_PROVIDER (provider),GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
    g_object_unref (provider);
}