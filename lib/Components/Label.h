/**                                   Cette page est consacré pour la creation du label **/



//          Fonction decreation d 'une nouvelle Labele
//      Entree: 
//      Sortie: un Compoennt bien modifie
Component *new_Label(const char *str)
{
    Component *cp = new_Component();
    cp->type = LABEL;
    gchar *utf8;
    utf8 = g_locale_to_utf8(str, -1, NULL, NULL, NULL);
    cp->this = gtk_label_new(utf8);

return (Component *)cp;
}//fin de la fonction