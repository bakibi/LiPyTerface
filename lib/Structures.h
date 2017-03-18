/*
    La Structure Taille :
*/
typedef struct Taille
{
    int x;  //  horizontal
    int y;  //  Vertical
}Taille;
//--------------------------------------

/*
    La structure Container :
*/
enum {BOX,GRID,LISTBOX,FLOWBOX,STACK,BUTTONBOX,EXPANDER,FIXED,NOTEBOOK,PANED};
enum {VERTICAL,HORIZENTAL};
typedef struct Container
{
    GtkWidget *this;            //  L'identifiant du Container
    int type;                   //  Quelle container tu as choisi

}Container;

//---------------------------------------



/* 
    La Structure Fenetre :
*/
typedef struct Fenetre
{
    GtkWidget *this;                //  l'identité de la fenetre
    Container *container;              //  container de la fenetre                                                     
    char titre[15];                 //  le titre de la fenetre    
    int type;                       //  le type de la fenetre 
    Taille *t;                      //  la taille de la fenetre
    int position;                   //  la position de la fenetre

} Fenetre;
//--------------------------------------------