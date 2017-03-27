/** cette page est didie au Infobar **/



//          Fonction de creation d une instance Infobar
//      Entree: msg le message vouloir afficher
//                  setClose est TRUE si vous voulez avoir un bouuton de fermeture
//                  type 1 (info)  2 (warning) 3(question) 4 (error) 5 (other)
//      Sortie:
Component *new_InfoBar(const char *msg,gboolean setClose,int type)
{
    Component *cp = new_Component();
    cp->type = INFOBAR;
    cp->this = gtk_info_bar_new();
    gtk_info_bar_set_show_close_button(GTK_INFO_BAR(cp->this),setClose);

    if(type == 1)
        gtk_info_bar_set_message_type(GTK_INFO_BAR(cp->this),GTK_MESSAGE_INFO);
     if(type == 2)
        gtk_info_bar_set_message_type(GTK_INFO_BAR(cp->this),GTK_MESSAGE_WARNING);
     if(type == 3)
        gtk_info_bar_set_message_type(GTK_INFO_BAR(cp->this),GTK_MESSAGE_QUESTION);
     if(type == 4)
        gtk_info_bar_set_message_type(GTK_INFO_BAR(cp->this),GTK_MESSAGE_ERROR);
     else 
        gtk_info_bar_set_message_type(GTK_INFO_BAR(cp->this),GTK_MESSAGE_OTHER);
    return cp;
}//end of function