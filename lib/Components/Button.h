/** cette page est didie à la creation et manipulation  Un bouton **/



//          Function de creation d un boutton
//      Entree:
//      Sortie:
Component *new_Button(const char *label)
{
    Component *cp = new_Component();
    cp->type = BUTTON;
    cp->this = gtk_button_new_with_label(label);
    return cp;
}//fin de la fonction

//          Function de creation d'un boutton image
//      Entree:
//      Sortie:
Component *new_Button_image(const char *imageFile,gchar *tooltip )
{
    Component *cp = new_Component();
    cp->type = BUTTON;
    cp->this = gtk_button_new();

    const gchar *filepath = g_strconcat( "img/", imageFile, NULL);
    GtkWidget *image = gtk_image_new_from_file(filepath);
    gtk_button_set_image(GTK_BUTTON(cp->this), image);

    cssDataToWidget(cp->this, "background-color:rgba(0,0,0,0);border: 0px");
    gtk_button_set_relief (GTK_BUTTON(cp->this) ,GTK_RELIEF_NONE);

    if(tooltip)
        gtk_widget_set_tooltip_text (cp->this, utf8(tooltip));

    return cp;
}//fin de la fonction

    
//          Atribition d'une image à un bouton
//      Entree:
//      Sortie:

void Button_set_image(Component *btn,const char *imageFile)
{
    const gchar *filepath = g_strconcat( "img/", imageFile, NULL);
    
    GtkWidget *image = gtk_image_new_from_file(filepath);
    
    gtk_button_set_image(GTK_BUTTON(btn->this),image);
    
}//fin de la fonction