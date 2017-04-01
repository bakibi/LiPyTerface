/*          you should put the application 's code here '         */




void ApplicationMain()
{







Fenetre *f = new_Fenetre("ma premiere fenetre",NORMAL,new_Taille(500,500),P_CENTER);

    Fenetre_setIcon(f,"./img/icon.PNG","mon icon");
    Container *c1 = new_Paned(HORIZENTAL);

    f = Fenetre_setContainer(f,c1);
    Component *img,*i;
    img = new_Image("./img/icon.png",0);
    i = new_StatusBar();
    i = StatusBar_empilerMSG(i,"massage 1 ",12);
       i = StatusBar_empilerMSG(i,"massage 2",120);
   
    c1 = Paned_add1(c1,img->this);
    c1 = Paned_add2(c1,i->this);

 ALL_setForegroundColor(c1->this,0.2,0.9,0.9,1);         
 ALL_setBackgroundColor(c1->this,0.8,0.8,0.4,1);                                

    Fenetre_setVisible(f,1);
   



}//end of Function