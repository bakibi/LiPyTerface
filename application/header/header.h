GtkWidget* header_constructor()
{
    GtkWidget *menuBar  =   gtk_menu_bar_new();
    
    GtkWidget *fileMenu =   gtk_menu_new();
    GtkWidget *new      =   gtk_menu_item_new_with_mnemonic("_New");   
    GtkWidget *open     =   gtk_menu_item_new_with_mnemonic("_Open");  
    GtkWidget *sep1     =   gtk_separator_menu_item_new();
    GtkWidget *quit    =   gtk_menu_item_new_with_mnemonic("_Quitter");
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(new),fileMenu);   
    gtk_menu_shell_append(GTK_MENU_SHELL(fileMenu),open);
    gtk_menu_shell_append(GTK_MENU_SHELL(fileMenu),sep1);
    gtk_menu_shell_append(GTK_MENU_SHELL(fileMenu),quit);
    
    gtk_menu_shell_append(GTK_MENU_SHELL(menuBar),new);

    return(menuBar);
}