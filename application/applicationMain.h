/*          you should put the application 's code here '         */




void ApplicationMain()
{







Fenetre *f = new_Fenetre("ma premiere fenetre",NORMAL,new_Taille(500,500),P_CENTER);

    Fenetre_setIcon(f,"img/icon.PNG","mon icon");
    Container *c1 = new_Paned(HORIZENTAL);

    f = Fenetre_setContainer(f,c1);

    c1 = Paned_add1(c1,gtk_label_new("label 1"));
    c1 = Paned_add2(c1,gtk_label_new("label 2"));
   
    Fenetre_setVisible(f,1);
    f = Fenetre_setForegroundColor(f, 0.4, 0.5, 0.1, 1);
    f = Fenetre_setBackgroundColor(f, 1, 0.5, 0.1, 1);



}//end of Function