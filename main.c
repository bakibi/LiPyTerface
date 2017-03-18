

#include <stdio.h>
#include <stdlib.h>

#include <gtk/gtk.h>
#include "lib/lib.h"

int main(int argc , char** args)
{
    gtk_init(&argc,&args);
  Fenetre *f = new_Fenetre("ma premiere fenetre",NORMAL,new_Taille(100,100),P_CENTER,0);
  Fenetre_setVisible(f,1);
  gtk_main();

    return 0;
}
