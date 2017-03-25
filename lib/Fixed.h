/*******          Cette page est consacre au Container Fixed                    ********/


//          Fonction de creation du Fixed
//      Entree:None
//      Sortie:a Container bien initialiser
Container *new_Fixed()
{
    Container *c = (Container *)malloc(sizeof(Container));
    if(!c)
    {
        printf("Erreur ! Probleme d'allocation du composant Container");
        exit(-1);
    }
    c->type = FIXED;
    c->this = gtk_fixed_new();

    return (Container *)c;
}//fin de la fonction



//          Fonction qui ajoute un element a un container FIXED
//      Entree: element à ajouter
//              X,y la position
//      Sortie: Un container bien modifie
Container *Fixed_add(Container *c,GtkWidget *w,int x,int y)
{
    gtk_fixed_put(GTK_FIXED(c->this),w,x,y);
    return (Container *)c;
}//fin de la fonction





//          Fonction qui bouge un element a un container FIXED
//      Entree: element à ajouter
//              X,y la position
//      Sortie: Un container bien modifie
Container *Fixed_move(Container *c,GtkWidget *w,int x,int y)
{
    gtk_fixed_move(GTK_FIXED(c->this),w,x,y);
    return (Container *)c;
}//fin de la fonction