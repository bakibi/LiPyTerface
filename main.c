

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
    Container *c1 = new_FlowBox();
    Container *c = new_Stack();
    f = Fenetre_setContainer(f,c1);
    int i = 5;
    c = Stack_add(c,gtk_label_new("label 1"),"label1");
    c = Stack_add(c,gtk_label_new("label 2"),"label2");
    c = Stack_add(c,gtk_label_new("label 3"),"label3");
    
    c1 = FlowBox_add(c1,c->this,1);
    c1 = FlowBox_add(c1,Stack_getStackSwitch(c)->this,0);
    Fenetre_setVisible(f,1);
    f = Fenetre_setForegroundColor(f, 0.4, 0.5, 0.1, 1);
    gtk_main();

    return 0;
}
