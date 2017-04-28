GtkWidget* header_constructor(All *all)
{
    GtkWidget *menuBar  =   gtk_menu_bar_new();
    
    //  ACCEUIL
    GtkWidget *acceuilMenu  =   gtk_menu_new();
    GtkWidget *acceuil      =   gtk_menu_item_new_with_mnemonic("_Acceuil");   
    GtkWidget *nouveau      =   gtk_menu_item_new_with_mnemonic("_Nouveau"); 
    GtkWidget *montrerQuick =   gtk_menu_item_new_with_mnemonic("_Montrer/Cacher Quick"); 
    GtkWidget *sep1         =   gtk_separator_menu_item_new();
    GtkWidget *quitter      =   gtk_menu_item_new_with_mnemonic("_Quitter");
    
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(acceuil),acceuilMenu);   
    gtk_menu_shell_append(GTK_MENU_SHELL(acceuilMenu),nouveau);
    gtk_menu_shell_append(GTK_MENU_SHELL(acceuilMenu),montrerQuick);
    gtk_menu_shell_append(GTK_MENU_SHELL(acceuilMenu),sep1);
    gtk_menu_shell_append(GTK_MENU_SHELL(acceuilMenu),quitter);

    
    //  AIDE
    GtkWidget *aidelMenu    =   gtk_menu_new();
    GtkWidget *aide         =   gtk_menu_item_new_with_mnemonic("_Aide");   
    GtkWidget *manuel       =   gtk_menu_item_new_with_mnemonic("_Manuel"); 
    GtkWidget *raccourcis   =   gtk_menu_item_new_with_mnemonic("_Raccourcis"); 
    GtkWidget *sep2         =   gtk_separator_menu_item_new();
    GtkWidget *apropos      =   gtk_menu_item_new_with_mnemonic("_Apropos de nous");
    
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(aide),aidelMenu);   
    gtk_menu_shell_append(GTK_MENU_SHELL(aidelMenu),manuel);
    gtk_menu_shell_append(GTK_MENU_SHELL(aidelMenu),raccourcis);
    gtk_menu_shell_append(GTK_MENU_SHELL(aidelMenu),sep2);
    gtk_menu_shell_append(GTK_MENU_SHELL(aidelMenu),apropos);

    //  AJOUTER LES MENUS AU MENUBAR
    gtk_menu_shell_append(GTK_MENU_SHELL(menuBar),acceuil);
    gtk_menu_shell_append(GTK_MENU_SHELL(menuBar),aide);

    //  LES SIGNAUX

    g_signal_connect(G_OBJECT(nouveau), "activate", G_CALLBACK(reset), all);
    g_signal_connect(G_OBJECT(montrerQuick), "activate", G_CALLBACK(show_clicked), all);
    g_signal_connect(G_OBJECT(quitter), "activate", G_CALLBACK(dialog_quit_confirmation_from_menu), all);   

    g_signal_connect(G_OBJECT(raccourcis), "activate", G_CALLBACK(dialog_raccourcis), all);
    g_signal_connect(G_OBJECT(apropos), "activate", G_CALLBACK(menuDialog_apropos), all);

    return(menuBar);
}