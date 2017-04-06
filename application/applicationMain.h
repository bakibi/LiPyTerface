/*          you should put the application 's code here '         */

#include "header/header.h"
#include "body/body.h"
#include "footer/footer.h"

#include "quick/quick.h"

void ApplicationMain()
{
    //  DECLARING SOME WIDGETS , because of SEGMENTAION FAULT and adding them to ALL
    All *all=(All*)malloc(sizeof(All));

    all->isDark=TRUE;
    all->isBash=FALSE;

    all->footer = new_Box(HORIZENTAL, 0, FALSE);
    all->lnCol = new_StatusBar();

    //  Notre fenetre
    Fenetre *f = new_Fenetre("LyPyTerface",NORMAL,new_Taille(500,500),P_CENTER);
    all->f=f;
    cssDataToWidget(f->this,"background-color:#3F3F46");
    Fenetre_agrandir(f);
    Fenetre_setIcon(f,"logo.png","logo");

    Container *vBox= new_Box(VERTICAL,0, FALSE);
    f = Fenetre_setContainer(f,vBox);

    //  Header
    GtkWidget *header = header_constructor();
    //  body
    Container *body = body_constructor(all);
    //  Footer
    Container *footer = footer_constructor(all);

    //  quick
    Fenetre *quick = quick_constructor(all);
  
    //  Add Components to vBox    
    Box_addFirst(vBox,header        ,FALSE  ,FALSE  ,0);
    Box_addFirst(vBox,body->this    ,TRUE   ,TRUE   ,0);
    Box_addLast (vBox,footer->this  ,FALSE  ,FALSE  ,0);

    //  Making Things Visible
    Fenetre_setVisible(f,1);
    Fenetre_setVisible(quick,1);

    
    
}//end of Function