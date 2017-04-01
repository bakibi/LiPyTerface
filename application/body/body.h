#include "left.h"
#include "right.h"

Container* body_constructor(){

    Container *paned = new_Paned(HORIZENTAL,500);
    ALL_setBackgroundColor(paned->this, 0.145, 0.145, 0.152, 1);
    gtk_paned_set_position (GTK_PANED(paned->this), 500);

    //  Left Part
    GtkWidget *left = left_body();  
    //  Right Part
    GtkWidget *right = right_body();  

    //	Adding the 2 Parts into panned container
    paned = Paned_add1(paned,left);
    paned = Paned_add2(paned,right);

    return( paned );
}