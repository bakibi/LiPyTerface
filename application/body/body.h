#include "left.h"
#include "right.h"

Container* body_constructor(Component *lnCol){

    Container *paned = new_Paned(HORIZENTAL,500);
    cssDataToWidget(paned->this, "background-color:#3F3F46");
    gtk_paned_set_position (GTK_PANED(paned->this), 500);

    //  Left Part
    GtkWidget *left = left_body();  
    //  Right Part
    GtkWidget *right = right_body(lnCol);  

    //	Adding the 2 Parts into panned container
    paned = Paned_add1(paned,left);
    paned = Paned_add2(paned,right);

    return( paned );
}