#include "top.h"
#include "bottom.h"

Container* bodyBash_constructor(All *all)
{
    Container *bodyBash = new_Paned(VERTICAL,500);
    all->bodyBash=bodyBash;
    cssDataToWidget(bodyBash->this, "color : #23D18B;background-color: #1E1E1D");
    
    GtkWidget *top      = top_bodyBash(all);
    GtkWidget *bottom   = bottom_bodyBash(all);

    //	Adding the 2 Parts into panned container
    bodyBash = Paned_add1(bodyBash,top);
    bodyBash = Paned_add2(bodyBash,bottom);

    return( bodyBash );
}