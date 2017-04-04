/*          you should put the application 's code here '         */

#include "header/header.h"
#include "body/body.h"
#include "footer/footer.h"

#include "quick/quick.h"

void ApplicationMain()
{
    //  DECLARING SOME WIDGETS
    Component *lnCol = new_StatusBar();

    Fenetre *f = new_Fenetre("LyPyTerface",NORMAL,new_Taille(500,500),P_CENTER);
    cssDataToWidget(f->this,"background-color:#3F3F46");
    Fenetre_agrandir(f);

    Container *vBox= new_Box(VERTICAL,0, FALSE);
    f = Fenetre_setContainer(f,vBox);

    //  Header
    GtkWidget *header = header_constructor();
    //  body
    Container *body = body_constructor(lnCol);
    //  Footer
    Container *footer = footer_constructor(lnCol);

    //  quick
    Fenetre *quick = quick_constructor();
  
    //  Add Components to vBox    
    Box_addFirst(vBox,header        ,FALSE  ,FALSE  ,0);
    Box_addFirst(vBox,body->this    ,TRUE   ,TRUE   ,0);
    Box_addLast (vBox,footer->this  ,FALSE  ,FALSE  ,0);

    //  Making Things Visible
    Fenetre_setVisible(f,1);
    Fenetre_setVisible(quick,1);

}//end of Function