/*          you should put the application 's code here '         */

#include "header/header.h"
#include "body/body.h"
#include "bodyBash/bodyBash.h"
#include "footer/footer.h"

#include "quick/quick.h"

void ApplicationMain()
{   
    //  Déclaration de quelques composants à cause de l'éreur (SEGMENTATION FAULT) et ajout à All
    All *all=(All*)malloc(sizeof(All));
    all->footer = new_Box(HORIZENTAL, 0, FALSE);
    all->lnCol = new_StatusBar();

    //  Le programme va débuter avec le mode Interpréteur et le thème Sombre
    all->isDark=TRUE;
    all->isBash=FALSE;

    //  Notre fenetre
    Fenetre *f = new_Fenetre("LyPyTerface",NORMAL,new_Taille(500,500),P_CENTER);
    all->f=f;
    cssDataToWidget(f->this,"background-color:#3F3F46");
    Fenetre_agrandir(f);
    Fenetre_setIcon(f,"logo.png","logo");

    Container *vBox= new_Box(VERTICAL,0, FALSE);
    all->MainContainer = vBox;
    f = Fenetre_setContainer(f,vBox);

    //  Header
    GtkWidget *header = header_constructor(all);
    //  body
    Container *body = body_constructor(all);
    //  Footer
    Container *footer = footer_constructor(all);

    //  quick
    Fenetre *quick = quick_constructor(all);

    //  bodyBash (Body en mode Bash)
    Container *bodyBash = bodyBash_constructor(all);

    //  Ajout des Containers au vBox   
    Box_addFirst(vBox, header               ,FALSE  ,FALSE  ,0);
    Box_addFirst(vBox, body->this           ,TRUE   ,TRUE   ,0);
    Box_addFirst(vBox, bodyBash->this,      TRUE, TRUE, 0);
    Box_addLast (vBox, footer->this         ,FALSE  ,FALSE  ,0);

    //  Cacher/Montrer les Composant 
    Fenetre_setVisible(f,1);
    Fenetre_setVisible(quick,1);
    gtk_widget_set_visible (bodyBash->this, FALSE);

    //  SIGNAUX
    g_signal_connect(all->f->this, "key-release-event", G_CALLBACK(keyListener_pressed), all);
    g_signal_connect(all->f->this, "key-press-event", G_CALLBACK(keyListener_releassed), all);

    //  Permet de detecter la touche 'ctrl'
    gtk_widget_add_events(f->this, GDK_BUTTON_PRESS_MASK);
    g_signal_connect(G_OBJECT(f->this), "key-press-event", G_CALLBACK(accelerator),all);

    //  charger l'historique du fichier dans la memoire
    all->histo=charger_historique_fichier();

}//end of Function