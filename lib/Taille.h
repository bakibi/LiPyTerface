/*  Cette page est reservé pour l'utilité Taille   */


//          Les Fonctions :
//  Fonction de creation d'Objet
//      Entree: x,y
//      Sortie: Taille Object
Taille *new_Taille(int x,int y)
{
    Taille *t = (Taille *)malloc(sizeof(Taille));
    if(!t)
    {
        printf("Erreur ! Allocation en l'objet Taille .\n");
        exit(-1);
    }
    t->x = x;
    t->y = y;

    return (Taille *)t;
}//fin de la fct


//  Fonction Getter de Taille
//  Fonction get_x
int Taille_getX(Taille *t)
{
    if(!t)
    {
        printf("Erreur ! Allocation en l'objet Taille .\n");
        exit(-1);
    }
    return t->x;
}

//  Fonction get_y
int Taille_getY(Taille *t)
{
    if(!t)
    {
        printf("Erreur ! Allocation en l'objet Taille .\n");
        exit(-1);
    }
    return t->y;
}


//  Fonction Setter de Taille
//  Fonction set_x
Taille *Taille_setX(Taille *t,int x)
{
    if(!t)
    {
        printf("Erreur ! Allocation en l'objet Taille .\n");
        exit(-1);
    }
    t->x = x;
    return (Taille *)t;
}

//  Fonction set_y
int Taille_setY(Taille *t,int y)
{
    if(!t)
    {
        printf("Erreur ! Allocation en l'objet Taille .\n");
        exit(-1);
    }
    t->y = y;
    return (Taille *)t;
}


//      Fonction clone : cette fonction clone un objet (ses valeurs à un nouveau objet)
//  Entree  :   Taille qu on veut cloner
//  Sortie  :   Nouvelle taille 
Taille  *Taille_cloner(Taille *t1)
{
    Taille *t = (Taille *)malloc(sizeof(Taille));
    if(!t)
    {
        printf("Erreur ! Allocation en l'objet Taille .\n");
        exit(-1);
    }
    t->x = t1->x;
    t->y = t1->y;
    return (Taille *)t;
}
