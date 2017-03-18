/*
    La Structure Taille :
*/
typedef struct Taille
{
    int x;  //  horizontal
    int y;  //  Vertical
}Taille;



/* La Structure Fenetre :
*/
typedef struct Fenetre
{
    GtkWidget *this;                //  l'identité de la fenetre
    GtkWidget *container;              //  container de la fenetre                                                     
    char titre[15];                 //  le titre de la fenetre    
    int type;                       //  le type de la fenetre 
    Taille *t;                      //  la taille de la fenetre
    int position;                   //  la position de la fenetre

} Fenetre;