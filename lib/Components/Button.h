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