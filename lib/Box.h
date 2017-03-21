/*       Cette page est reservé au compososant  de Box     */





//          Fonction de creation une Box
//      Entree: type : soit Horizental Soit vertical
//              espace:
//      Sortie:
Container *new_Box(int type,int espace)
{
    Container *c = (Container *)malloc(sizeof(Container));
    if(!c)
    {
        printf("Erreur ! Probleme d'allocation du composant Container");
        exit(-1);
    }
    c->type = BOX;
    if( type == VERTICAL )
    {
        c->this = gtk_box_new(GTK_ORIENTATION_VERTICAL,espace); 
    }
    else {

        c->this = gtk_box_new(GTK_ORIENTATION_HORIZONTAL,espace); 
    }

    return (Container *)c; 
}//la fin de la fonction


//          Fonction d'ajout dans un BOX en premier position
//      Entree: le Container ou on va mettre le composant
//              widget à mettre
//              padding     
//      Sortie: le Container avec l'element ajoute
Container *Box_addFirst(Container *c,GtkWidget *w,int padding)
{
    gtk_box_pack_start(GTK_BOX(c->this),w,FALSE,FALSE,padding);
    
    return (Container *)c;
}//fin de la fonction




//          Fonction d'ajout dans un BOX en dernier position
//      Entree: le Container ou on va mettre le composant
//              widget à mettre
//              padding     
//      Sortie: le Container avec l'element ajoute
Container *Box_addLast(Container *c,GtkWidget *w,int padding)
{
    gtk_box_pack_end(GTK_BOX(c->this),w,FALSE,FALSE,padding);
    
    return (Container *)c;
}//fin de la fonction


