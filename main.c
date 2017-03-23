

#include <stdio.h>
#include <stdlib.h>

#include <gtk/gtk.h>
#include <gdk/gdk.h>
#include "lib/lib.h"



int main(int argc , char** args)
{
    gtk_init(&argc,&args);
    Fenetre *f = new_Fenetre("ma premiere fenetre",NORMAL,new_Taille(0,0),P_CENTER);
    Fenetre_setIcon(f,"icon.PNG","mon icon");
    Container *c = new_FlowBox();
    f = Fenetre_setContainer(f,c);
    c = FlowBox_add(c,gtk_label_new("label1"),0);
    c = FlowBox_add(c,gtk_label_new("label2"),1);
    c = FlowBox_add(c,gtk_label_new("label3"),2);
    Fenetre_agrandir(f);
    Fenetre_setVisible(f,1);
    f = Fenetre_setForegroundColor(f, 0.4, 0.5, 0.1, 1);
    gtk_main();
    return 0;
}
