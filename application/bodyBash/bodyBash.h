#include "top.h"
#include "bottom.h"

Container* bodyBash_constructor(All *all)
{
    //  Creation d'un Paned Container
    Container *bodyBash = new_Paned(VERTICAL,800);
    all->bodyBash=bodyBash;
    cssDataToWidget(bodyBash->this, "color : #23D18B;background-color: #1E1E1D");
    
    //  Creation Partie Haut
    Container *top      = top_bodyBash(all);
    //  Creation Partie Bas
    Container *bottom   = bottom_bodyBash(all);

    //	Ajout des 2 parties au Paned Container
    bodyBash = Paned_add1(bodyBash,top->this);
    bodyBash = Paned_add2(bodyBash,bottom->this);

    return( bodyBash );
}