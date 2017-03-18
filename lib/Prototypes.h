



//      SD  :   Taille
Taille *new_Taille(int x,int y);
int Taille_getX(Taille *t);
int Taille_getY(Taille *t);
Taille *Taille_setX(Taille *t,int x);
Taille *Taille_setY(Taille *t,int y);
Taille  *Taille_cloner(Taille *t1);


//      SD  :   Container
Container *new_Container(int type,int direction,char *name);



//      SD  :   Fenetre
Fenetre *new_Fenetre(const char *titre,int type,Taille *t,int position,int decoration);
Fenetre *Fenetre_setContainer(Fenetre *f,Container *c);
Fenetre *Fenetre_setTitre(Fenetre *f,const char *nvtitre);
char *Fenetre_getTitre(Fenetre *f);
Fenetre *Fenetre_setTaille(Fenetre *f,Taille *t);
Taille *Fenetre_getTaille(Fenetre *f);
Fenetre *Fenetre_setPosition(Fenetre *f,int position);
int Fenetre_getPosition(Fenetre *f);
Fenetre *Fenetre_destroy(Fenetre *f);
void Fenetre_setVisible(Fenetre *f,int verite);