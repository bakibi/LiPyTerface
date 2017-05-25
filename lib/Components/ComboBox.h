Component *new_Combo_Box_tab(gchar *tab[],int taille, int active)
{
    Component *cp = new_Component();
    cp->type = COMBOBOX;

    cp->this = gtk_combo_box_text_new ();

    for(int i=0 ; i<taille ; i++) 
        gtk_combo_box_text_append_text( GTK_COMBO_BOX_TEXT(cp->this) ,tab[i] );

    gtk_combo_box_set_active(GTK_COMBO_BOX(cp->this), active);
    
    return (Component *)cp;

   
}//fin de la fonction

Component *new_Combo_Box_List(GSList *list, int active)
{
    Component *cp = new_Component();
    cp->type = COMBOBOX;

    cp->this = gtk_combo_box_text_new ();

    for (GSList *iterator = list; iterator; iterator = iterator->next)
    {
        gchar *tmp = utf8((gchar*)iterator->data);
        if(tmp)
            gtk_combo_box_text_append_text( GTK_COMBO_BOX_TEXT(cp->this) ,tmp );
    }

    gtk_combo_box_set_active(GTK_COMBO_BOX(cp->this), active);
    
    return (Component *)cp;
}//fin de la fonction