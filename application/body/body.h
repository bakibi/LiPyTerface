#include "left.h"
#include "right.h"

Container* body_constructor(All *all){

    Container *paned = new_Paned(HORIZENTAL,500);
    cssDataToWidget(paned->this, "background-color:#3F3F46");
    all->paned=paned;
    gtk_paned_set_position (GTK_PANED(paned->this), 500);

    //  Left Part
    GtkWidget *left = left_body(all);  
    //  Right Part
    GtkWidget *right = right_body(all);  

    //	Adding the 2 Parts into panned container
    paned = Paned_add1(paned,left);
    paned = Paned_add2(paned,right);

    return( paned );
}