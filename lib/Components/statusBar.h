/**                                           Status bar                                              **/



//          Fonction de ceration d un status bar
//      Entree:
//      Sortie:
Component *new_StatusBar()
{
    Component *cp = new_Component();
    cp->type = STATUSBAR;
    cp->this = gtk_statusbar_new();
    return cp;
} //end of the function

//          Fonction pour ajouter un message avec un id
Component *StatusBar_empilerMSG(Component *cp,const char *msg,int id)
{
    gtk_statusbar_push(GTK_STATUSBAR(cp->this),id,msg);    
    return cp;
}//fin de la Fonction


//          Fonction pour supprimer un message de la bar
Component *StatusBar_depilerMsg(Component *cp,int id)
{   
    gtk_statusbar_pop(GTK_STATUSBAR(cp->this),id);
    return cp;
}//fin de la fonction