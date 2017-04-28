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
enum {BOX,GRID,LISTBOX,FLOWBOX,STACK,BUTTONBOX,EXPANDER,FIXED,NOTEBOOK,PANED,STACKSWITCHER,STACKSIDEBAR,FRAME,SCROLL};
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
enum {NORMAL,POP};
enum {P_NONE,P_CENTER,P_MOUSE,P_CENTER_ON_PARENT};
typedef struct Fenetre
{
    GtkWidget *this;                //  l'identité de la fenetre
    Container *container;              //  container de la fenetre                                                     
    char *titre;                 //  le titre de la fenetre    
    int type;                       //  le type de la fenetre 
    Taille *t;                      //  la taille de la fenetre
    int position;                   //  la position de la fenetre

} Fenetre;
//--------------------------------------------





/* 
    La Structure Component :
*/
enum {LABEL,IMAGE,SPINNER,INFOBAR,PROGRESSBAR,STATUSBAR,ACCELLABEL,
            BUTTON,CHECKBOX,RADIOBUTTON,TOGGLEBUTTON,LINKBUTTON,MENUBUTTON,SWITCH,
            ENTRY,ENTRYBUFFER,ENTRYCOMPLETION,SCALE,SPINBUTTON,SEARCHENTRY,SEARCHBAR,EDITABLE,
            TEXTVIEW, COMBOBOX};
typedef struct Component
{
    GtkWidget *this;                //  l'identité de la fenetre
   int type ;                               //  le type du composant
} Component;
//--------------------------------------------

typedef struct Quick
{
    Fenetre *f;
    Component *run;
    Component *upload;
    Component *show;
    Component *mode;
    Component *theme;
    Component *search;
    Component *quit;
    gboolean isShown;
}Quick;

typedef struct historique
{
    gchar cmd[20][100];
    int rang_actuel;
}historique;

typedef struct All
{
    Fenetre *f;
    gboolean isDark;
    gboolean isBash;

    //  Main vBox Container
        Container *MainContainer;
        //body
        Container *body;
            //left
            GtkWidget *leftFrame,*leftTitre;
            //right
            GtkWidget *rightFrame,*rightTitre,*console;
        //footer
            Container *footer;
            Component *mode, *theme, *lnCol;
        //quick
        Quick *quick;
        //bodyBash
        Container *bodyBash;
            //top
            GtkWidget *topFrame,*topTitre,*editor;
            //bottom
            GtkWidget *bottomFrame,*bottomTitre,*output;
    //Historique
    historique histo;
}All;

