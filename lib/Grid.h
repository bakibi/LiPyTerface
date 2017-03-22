/******** Cette page est reserve au composant Grid  **********/




//          Fonction de creation un Container de type Grid
//      Entree: NONE
//      Sortie: Container intialiser
Container *new_Grid()
{
    Container *c = (Container *)malloc(sizeof(Container));
    if(!c)
    {
        printf("Erreur ! Probleme d'allocation du composant Container");
        exit(-1);
    }
    c->type = GRID;
    c->this = gtk_grid_new();

    return (Container *)c;
}//fin de la fonction



//          Fonction d'ajout un composant a un grid
//      Entree: Le COntainer ou on va ajouter le composant
//              le Composant que vous voulez mettre
//              le gauche ,haut ,width,height
//      Sortie: Le Container avec le changement
Container *Grid_add(Container *c,GtkWidget *w,int gauche,int haut,int width,int height)
{  
    gtk_grid_attach(GTK_GRID(c->this),w,gauche,haut,width,height);
    return (Container *)c;
}//fin de la fonction 