#include "transparentWindow.h"

void quick_clicked(GtkWidget *widget, gpointer data);

Fenetre* quick_constructor(All *all)
{
    Quick *quick = (Quick*)malloc(sizeof(Quick));
    all->quick=quick;
    //  initiation fenetre
    quick->f = new_transparent_fenetre();
    gtk_window_set_keep_above(GTK_WINDOW(quick->f->this), TRUE);
    gtk_window_move (GTK_WINDOW(quick->f->this), 1220, 350);
    //  initation bouton plus
    quick->show = new_Button_image("quick/show.png");
    cssDataToWidget(quick->show->this, "background-color:rgba(0,0,0,0);border: 0px");
    gtk_button_set_relief (GTK_BUTTON(quick->show->this) ,GTK_RELIEF_NONE);

    //  initation des options
    quick->mode   = new_Button_image("quick/bash.png");
    cssDataToWidget(quick->mode->this, "background-color:rgba(0,0,0,0);border: 0px");
    gtk_button_set_relief (GTK_BUTTON(quick->mode->this) ,GTK_RELIEF_NONE);
    quick->theme  = new_Button_image("quick/lightTheme.png");
    cssDataToWidget(quick->theme->this, "background-color:rgba(0,0,0,0);border: 0px");
    gtk_button_set_relief (GTK_BUTTON(quick->theme->this) ,GTK_RELIEF_NONE);
    quick->quit   = new_Button_image("quick/quit.png");
    cssDataToWidget(quick->quit->this, "background-color:rgba(0,0,0,0);border: 0px");
    gtk_button_set_relief (GTK_BUTTON(quick->quit->this) ,GTK_RELIEF_NONE);

    //  intiation show booleen
    quick->isShown = FALSE;

    //  adding the plus botton to the box
    Box_addLast(quick->f->container, quick->show->this, FALSE, FALSE, 0);
    //    adding the options to the box
    Box_addFirst(quick->f->container, quick->mode->this, FALSE, FALSE, 0);
    Box_addFirst(quick->f->container, quick->theme->this, FALSE, FALSE, 0);
    Box_addFirst(quick->f->container, quick->quit->this, FALSE, FALSE, 0);
    //  hiding the options
    cssDataToWidget(quick->mode->this, " opacity: 0;");
    cssDataToWidget(quick->theme->this, " opacity: 0;");
    cssDataToWidget(quick->quit->this, " opacity: 0;");

    //  LES SIGNANX
    
    //  Bouton Quit permet de quitter le programme
    g_signal_connect(G_OBJECT(quick->quit->this), "clicked", 
      G_CALLBACK(gtk_main_quit), NULL);
    //  Bouton show permet de montrer les option de quick
     g_signal_connect(G_OBJECT(quick->show->this), "clicked", 
      G_CALLBACK(show_clicked), quick);
    //  Bouton theme permet de changer de theme
     g_signal_connect(G_OBJECT(quick->theme->this), "clicked", 
      G_CALLBACK(theme_clicked), all);
      //  Bouton mode permet de changer de mode
     g_signal_connect(G_OBJECT(quick->mode->this), "clicked", 
      G_CALLBACK(mode_clicked), all);

    return (quick->f);
}

