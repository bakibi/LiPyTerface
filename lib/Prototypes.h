




//      SD  :   FOR ALL COMPONANT
void cssDataToWidget(GtkWidget *w, gchar *css );

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
Container *new_Box(int type, int espace, gboolean homogeneous);
Container *Box_addFirst(Container *c,GtkWidget *w, gboolean expand, gboolean fill, int padding);
Container *Box_addLast(Container *c,GtkWidget *w, gboolean expand, gboolean fill, int padding);


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
Container *Stack_getStackSidebar(Container *cc);



//      SD  :   Fixed
Container *new_Fixed();
Container *Fixed_add(Container *c,GtkWidget *w,int x,int y);
Container *Fixed_move(Container *c,GtkWidget *w,int x,int y);



//      SD  :   Paned
Container *new_Paned(int Orientation,int positionSeparateur);
Container *Paned_add1(Container *c,GtkWidget *w);
Container *Paned_add2(Container *c,GtkWidget *w);
Container *Paned_setHandPosition(Container *c, int position);
Container *Paned_setHandVisible(Container *c,int v);


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
Fenetre *Fenetre_addCssFile(Fenetre *f,const char *path);
void Fenetre_agrandir(Fenetre *f);



//      SD  :   Component
Component *new_Component();


//      SD  :   Label
Component *new_Label(const char *str,int position,int isSelectable);
Component *Label_setMarkup(const char *debut,Component *l,const char *fin);
char *Label_getText(Component *l);
Component *Label_setText(Component *l,const char *str);



//      SD  :   Image
Component *new_Image(const char *path,int size);
Component *Image_changeImage(Component *cp, const char *path,int size);


//      SD  :   InfoBar
Component *new_InfoBar(const char *msg,gboolean setClose,int type);



//      SD  :   StatusBar
Component *new_StatusBar();
Component *StatusBar_empilerMSG(Component *cp,const char *msg,int id);
Component *StatusBar_depilerMsg(Component *cp,int id);