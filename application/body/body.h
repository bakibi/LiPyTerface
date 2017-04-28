#include "left.h"
#include "right.h"

Container* body_constructor(All *all){

    //  Creation d'un Paned Container
    Container *body = new_Paned(HORIZENTAL,300);
    all->body = body;
    cssDataToWidget(body->this, "background-color:#3F3F46");
    
    //  Creation Partie Gauche
    Container *left = left_body(all);  
    //  Creation Partie Droite
    Container *right = right_body(all);  

    //	Ajout des 2 parties au Paned Container
    body = Paned_add1(body,left->this);
    body = Paned_add2(body,right->this);

    return( body );
}