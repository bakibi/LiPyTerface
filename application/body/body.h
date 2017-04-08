#include "left.h"
#include "right.h"

Container* body_constructor(All *all){

    Container *body = new_Paned(HORIZENTAL,500);
    all->body = body;
    cssDataToWidget(body->this, "background-color:#3F3F46");
    
    gtk_paned_set_position (GTK_PANED(body->this), 500);

    //  Left Part
    GtkWidget *left = left_body(all);  
    //  Right Part
    GtkWidget *right = right_body(all);  

    //	Adding the 2 Parts into panned container
    body = Paned_add1(body,left);
    body = Paned_add2(body,right);

    return( body );
}