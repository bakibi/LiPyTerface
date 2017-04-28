/*      Ici se trouce toutes les fonctionnalie d un arbre arithetique */

typedef struct ArbreA
{
    float val;  // la valeur
    char op;        // l operation
    struct ArbreA *fg,*fd;  //le fils gauche et le fils droit
}ArbreA;

//      Prototypes

ArbreA *new_ArbreA();
ArbreA *init_ArbreAV(float v);
ArbreA *init_ArbreAO(char o);
ArbreA *ArbreA_addV(ArbreA *a,float v);
int priority_calc(char op);
ArbreA  *ArbreA_addO(ArbreA *a,char op);
void ArbreA_toString(ArbreA *a);
float ArbreA_evaluer(ArbreA *a);
//      Implementation













//          Creer un nouveau Arbre arithmetique
ArbreA *new_ArbreA()
{
    return NULL;
}//eof












//      Initatisation
ArbreA *init_ArbreAV(float v)
{
    ArbreA *a = (ArbreA *)malloc(sizeof(ArbreA));
    a->fg = a->fd = NULL;
    a->op = 0;
    a->val = v;
    return a;
}//eof



















ArbreA *init_ArbreAO(char o)
{
    ArbreA *a = (ArbreA *)malloc(sizeof(ArbreA));
    a->fg = a->fd = NULL;
    a->op = o;
    a->val = 0;
    return a;
}//eof














ArbreA *ArbreA_addV(ArbreA *a,float v)
{
    //si le noeud est vide
    if( a == NULL) return init_ArbreAV(v);
    //sinon on place la valeur dans le fils droite
    else    a->fd = ArbreA_addV(a->fd,v);
    //on routourn le noeud
    return a;
}













// Cette fonction retourne la valeur en entier d une signe
int priority_calc(char op)
{
    if(op == '+' || op == '-') return 1;
    if(op == '*' || op == '/') return 2;
    else return 3;
}












//Cette fonction permet d'ajouter une operation
ArbreA  *ArbreA_addO(ArbreA *a,char op)
{
    //si le noeud et vide
    if(a == NULL)
    {
         a = init_ArbreAO(op);
        // si c est singe + ou -
        if(priority_calc(op) == 1)  a->fg = init_ArbreAV(0);
        //  si c est une operation de type * or / 
        else a->fg = init_ArbreAV(1);
        //on retourn 
        return  a;
    }

    //le cas si le noued contient une valeur
    if(a->op == 0)
    {
        ArbreA *a_nv = init_ArbreAO(op);
        a_nv->fg = a;
        return a_nv;
    }

    // sinon reste le cas ou le noeud contient une operation alors la on t7een
    int p_init = priority_calc(a->op);
    int p_nv = priority_calc(op);
     ArbreA *a_nv = init_ArbreAO(op);

    //La on traite les cas
    // 1 si les 2 prio sans egau ou le primier est sup
    if(p_init >= p_nv)
    {
        a_nv->fg = a;
        return a_nv;
    }
    else
    {
        a->fd = ArbreA_addO(a->fd,op);
    }
//on retourn a la fin
return a;
}//eof















//  affiche le contenu de l arbre en mode infixe
void ArbreA_toString(ArbreA *a)
{
    if (a == NULL) return ;
    
    ArbreA_toString(a->fg);
    if(a->op == 0) printf("%f\t",a->val);
    else printf("%c\t",a->op);
    ArbreA_toString(a->fd);
}//eof























// Cette fonction permet de donner la valeur exact d un arbre
float ArbreA_evaluer(ArbreA *a)
{
    //si le noeud est vide
    if(a == NULL) return 0;
    //si le noeud contient unevaleur
    if(a->op == 0) return a->val;
    //le cas si le noeud contient une operation
    switch (a->op)
    {
        case '+' : return ArbreA_evaluer(a->fg) + ArbreA_evaluer(a->fd);break;
        case '-' : return ArbreA_evaluer(a->fg) - ArbreA_evaluer(a->fd);break;
        case '*' : return ArbreA_evaluer(a->fg) * ArbreA_evaluer(a->fd);break;
        case '/' : return ArbreA_evaluer(a->fg) / ArbreA_evaluer(a->fd);break;
        case '%' : return (int)ArbreA_evaluer(a->fg) % (int)ArbreA_evaluer(a->fd);break;
    }
    //end
}//eof





