/********* **                   Cette page est dedié au container Paned                       ***********/



//              Cette fonction cree une instance du type container Paned
//          Entree: VERTICAL or HORIZENTAL
//          Sortie: Un container bien modifié
Container *new_Paned(int Orientation, int positionSeparateur)
{
    Container *c = (Container *)malloc(sizeof(Container));
    if(!c)
    {
        printf("Erreur! probleme d'allocation en Container\n");
        exit(-1);
    }
    c->type = PANED;
    if(Orientation == VERTICAL)
    {
        c->this = gtk_paned_new(GTK_ORIENTATION_VERTICAL);
    }
    else 
    {
        c->this = gtk_paned_new(GTK_ORIENTATION_HORIZONTAL);
    }

    gtk_paned_set_position (GTK_PANED(c->this), positionSeparateur);
    c =   Paned_setHandVisible(c,1);

     return (Container *)c;
}//fin de la fonction


//          Cette fonction ajoute un element au top ou left to the Paned
//      Entree: le widget a ajouter
//      Sortie: le container bien modifier
Container *Paned_add1(Container *c,GtkWidget *w)
{
    gtk_paned_add1(GTK_PANED(c->this),w);
    return (Container *)c;
}//fin de la fonction


//          Cette fonction ajoute un element au bottom ou right to the Paned
//      Entree: le widget a ajouter
//      Sortie: le container bien modifier
Container *Paned_add2(Container *c,GtkWidget *w)
{
    gtk_paned_add2(GTK_PANED(c->this),w);
    
    
    return (Container *)c;
}//fin de la fonction


Container *Paned_setHandPosition(Container *c, int position)
{
    gtk_paned_set_position(GTK_PANED(c->this),position);
    return (Container *)c;
}//fin de la fonction

Container *Paned_setHandVisible(Container *c,int v)
{
   if(v == 0) gtk_paned_set_wide_handle(GTK_PANED(c->this),FALSE)  ;
   else gtk_paned_set_wide_handle(GTK_PANED(c->this),TRUE)  ;
   return (Container *)c;
}