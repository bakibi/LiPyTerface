

#include <stdio.h>
#include <stdlib.h>

#include <gtk/gtk.h>
#include <gdk/gdk.h>
#include "lib/lib.h"
#include "application/applicationMain.h"
#include "application/nameSpaceChooser/connexion.h"




int main(int argc , char** args)
{
    gtk_init(&argc,&args);

    //  Déclaration de quelques composants à cause de l'éreur (SEGMENTATION FAULT) et ajout à All
    All *all=(All*)malloc(sizeof(All));
    
    //connexionPopUp(all);
    //ApplicationMain(all);
    ApplicationMain(all);
    gtk_main();

    return 0;
}
