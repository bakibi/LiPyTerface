



//      SD  :   Taille
Taille *new_Taille(int x,int y);
int Taille_getX(Taille *t);
int Taille_getY(Taille *t);
Taille *Taille_setX(Taille *t,int x);
Taille *Taille_setY(Taille *t,int y);
Taille  *Taille_cloner(Taille *t1);


//      SD  :   Container
Container *new_Container();

//      SD  :   Box
Container *new_Box(int type,int espace);
Container *Box_addFirst(Container *c,GtkWidget *w,int padding);
Container *Box_addLast(Container *c,GtkWidget *w,int padding);


//      SD  :   GRID
Container *new_Grid();
Container *Grid_add(Container *c,GtkWidget *w,int gauche,int haut,int width,int height);

//      SD  :   FLOWBOX
Container *new_FlowBox();
Container *FlowBox_add(Container *c,GtkWidget *w,int position);


//      SD  :   STACK
Container *new_Stack();
Container *Stack_add(Container *c,GtkWidget *w,const char *nom);
Container *Stack_getStackSwitch(Container *cc);
Container *Stack_setVisibleChild(Container *c,GtkWidget *w);


//      SD  :   Fenetre
Fenetre *new_Fenetre(const char *titre,int type,Taille *t,int position);
Fenetre *Fenetre_setContainer(Fenetre *f,Container *c);
Fenetre *Fenetre_setTitre(Fenetre *f,const char *nvtitre);
char *Fenetre_getTitre(Fenetre *f);
Fenetre *Fenetre_setTaille(Fenetre *f,Taille *t);
Taille *Fenetre_getTaille(Fenetre *f);
Fenetre *Fenetre_setPosition(Fenetre *f,int position);
int Fenetre_getPosition(Fenetre *f);
Fenetre *Fenetre_destroy(Fenetre *f);
void Fenetre_setVisible(Fenetre *f,int verite);
void Fenetre_setIcon(Fenetre *f,const char *filepath,const char *name);
Fenetre *Fenetre_setBackgroundColor(Fenetre *f,float red,float green,float blue,float opacity);
Fenetre *Fenetre_setForegroundColor(Fenetre *f,float red,float green,float blue,float opacity);
Fenetre *Fenetre_addCssFile(Fenetre *f,const char *path);
void Fenetre_agrandir(Fenetre *f);