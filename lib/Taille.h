/*  Cette page est reservé pour l'utilité Taille   */

/*
    La Structure Taille :
*/
typedef struct Taille
{
    int x;  //  horizontal
    int y;  //  Vertical
}Taille;



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
int Taille_get_x(Taille *t)
{
    if(!t)
    {
        printf("Erreur ! Allocation en l'objet Taille .\n");
        exit(-1);
    }
    return t->x;
}

//  Fonction get_y
int Taille_get_y(Taille *t)
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
Taille *Taille_set_x(Taille *t,int x)
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
int Taille_set_y(Taille *t,int y)
{
    if(!t)
    {
        printf("Erreur ! Allocation en l'objet Taille .\n");
        exit(-1);
    }
    t->y = y;
    return (Taille *)t;
}
