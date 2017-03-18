/****   Cette page est reservé au compososant  de LA FENTERE        ***/




//          LES SETTERS ET LES GETTERS


//          Fonction de creation de la Fenetre
//      Entree:
//      Sortie:Une nouvelle Fenetre
Fenetre *new_Fenetre(const char *titre,int type,Taille *t,int position,int decoration,int argc ,char **args)
{
    gtk_init(&argc,&args);         //   On initialise notre Gtk Session
    Fenetre *f = (Fenetre *)malloc(sizeof(Fenetre));
    if(!f)
    {
        printf("Erreur ! Allocation de memoire Fenetre ");
        exit(-1);
    }

   


    
}//Fin de la fonction

