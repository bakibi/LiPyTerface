/*          you should put the application 's code here '         */

#include "header/header.h"
#include "body/body.h"
#include "footer/footer.h"

void ApplicationMain()
{
    Fenetre *f = new_Fenetre("ma premiere fenetre",NORMAL,new_Taille(500,500),P_CENTER);
    ALL_setBackgroundColor(f->this, 0.145, 0.145, 0.152, 1);
    Fenetre_agrandir(f);

    Container *vBox= new_Box(VERTICAL,0, FALSE);
    f = Fenetre_setContainer(f,vBox);

    //  Header
    GtkWidget *header = header_constructor();
    //  body
    Container *body = body_constructor();
    //  Footer
    Container *footer = footer_constructor();

    //  Add Components to vBox    
    Box_addFirst(vBox,header        ,FALSE  ,FALSE  ,0);
    Box_addFirst(vBox,body->this    ,TRUE   ,TRUE   ,0);
    Box_addLast (vBox,footer->this  ,FALSE  ,FALSE  ,0);

    //  Making the window visible Visible
    Fenetre_setVisible(f,1);

}//end of Function