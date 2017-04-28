#include "transparentWindow.h"

gint signal_handler_event(GtkWidget *widget, GdkEventButton *event, gpointer data);

Fenetre* quick_constructor(All *all)
{
    Quick *quick = (Quick*)malloc(sizeof(Quick));
    all->quick=quick;

    //  initiation fenetre
    quick->f = new_transparent_fenetre();
    gtk_window_set_keep_above(GTK_WINDOW(quick->f->this), TRUE);
    gtk_window_move (GTK_WINDOW(quick->f->this), 1220, 50);
    

    //  initation bouton plus
    quick->show = new_Button_image("quick/show.png","Afficher les Options");

    //  initation des options
    quick->run    = new_Button_image("quick/run.png",NULL);
    quick->upload = new_Button_image("quick/upload.png",NULL);
    quick->mode   = new_Button_image("quick/bash.png",NULL);
    quick->theme  = new_Button_image("quick/lightTheme.png",NULL);
    quick->search  = new_Button_image("quick/search.png",NULL);
    quick->quit   = new_Button_image("quick/quit.png",NULL);

    //  Rendre les options invisible
    cssDataToWidget(quick->run->this	  , "opacity: 0");
    cssDataToWidget(quick->mode->this	  , "opacity: 0");
    cssDataToWidget(quick->theme->this	, "opacity: 0");
    cssDataToWidget(quick->search->this	, "opacity: 0");
    cssDataToWidget(quick->quit->this	  , "opacity: 0");
    cssDataToWidget(quick->upload->this	  , "opacity: 0");
    
    //  Ajout des boutons au contenaire de quick
    Box_addLast (quick->f->container, quick->show->this   , FALSE, FALSE, 0 );
    Box_addFirst(quick->f->container, quick->run->this    , FALSE, FALSE, 5 );
    Box_addFirst(quick->f->container, quick->upload->this , FALSE, FALSE, 10);
    Box_addFirst(quick->f->container, quick->search->this , FALSE, FALSE, 0 );
    Box_addFirst(quick->f->container, quick->mode->this   , FALSE, FALSE, 0 );
    Box_addFirst(quick->f->container, quick->theme->this  , FALSE, FALSE, 0 );
    Box_addFirst(quick->f->container, quick->quit->this   , FALSE, FALSE, 0 );

    //  Indiquer que quick n'est pas afficher
    quick->isShown = FALSE;

    //  LES SIGNANX
    
    //  Bouton Quit permet de quitter le programme
    g_signal_connect(G_OBJECT(quick->quit->this), "clicked", G_CALLBACK(dialog_quit_confirmation), all);
    //  Bouton show permet de montrer les option de quick
     g_signal_connect(G_OBJECT(quick->show->this), "clicked", G_CALLBACK(show_clicked), all);
    //  Bouton theme permet de changer de theme
    g_signal_connect(G_OBJECT(quick->theme->this), "clicked", G_CALLBACK(theme_clicked), all);
    //  Bouton mode permet de changer de mode
    g_signal_connect(G_OBJECT(quick->mode->this), "clicked", G_CALLBACK(mode_clicked), all);
    //  Bouton search permet de rechercher un mot clé
    g_signal_connect(G_OBJECT(quick->search->this), "clicked", G_CALLBACK(recherche_dialog), all);  
    //  Bouton mode permet d'ouvrir un fichier bash
    g_signal_connect(G_OBJECT(quick->upload->this), "clicked", G_CALLBACK(upload_clicked), all);
    //  Bouton run permet d'executer le bash
    g_signal_connect(G_OBJECT(quick->run->this), "clicked", G_CALLBACK(run_clicked), all);

    //  Permet de detecter la touche 'ctrl'
    gtk_widget_add_events(quick->f->this, GDK_BUTTON_PRESS_MASK);
    g_signal_connect(G_OBJECT(quick->f->this), "key-press-event", G_CALLBACK(accelerator),all);

    //  Permet de detercter le double clique et d'éxecuter une fonxtions
    g_signal_connect(G_OBJECT(quick->show->this),"button_press_event",G_CALLBACK(signal_handler_event),all);
    g_signal_connect(G_OBJECT(quick->show->this),"button_release_event",G_CALLBACK(signal_handler_event),all);

    return (quick->f);
}

