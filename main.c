

#include <stdio.h>
#include <stdlib.h>

#include <gtk/gtk.h>
#include <gdk/gdk.h>
#include "lib/lib.h"

int main(int argc , char** args)
{
    gtk_init(&argc,&args);
    Fenetre *f = new_Fenetre("ma premiere fenetre",NORMAL,new_Taille(500,500),P_CENTER,0);
    Fenetre_setIcon(f,"icon.PNG","mon icon");
    Container *c = new_Grid();
    f = Fenetre_setContainer(f,c);
    c = Grid_add(c,gtk_label_new("label1"),0,0,1,1);
    c = Grid_add(c,gtk_label_new("label2"),1,0,1,1);
    c = Grid_add(c,gtk_label_new("label3"),0,1,2,1);
    Fenetre_setVisible(f,1);
    gtk_main();
    return 0;
}
