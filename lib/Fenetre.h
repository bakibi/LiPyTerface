/****   Cette page est reservé au compososant  de LA FENTERE        ***/







//          Fonction de creation de la Fenetre
//      Entree:
//      Sortie:Une nouvelle Fenetre
Fenetre *new_Fenetre(const char *titre,int type,Taille *t,int position,int decoration)
{

    Fenetre *f = (Fenetre *)malloc(sizeof(Fenetre));
    if(!f)
    {
        printf("Erreur ! Allocation de memoire Fenetre \n");
        exit(-1);
    }







}//Fin de la fonction

//          LES SETTERS ET LES GETTERS
//  FONCTION Container
Fenetre *Fenetre_setContainer(Fenetre *f,Container *c)
{
    if(!f->container)
    {
        
    }
}
