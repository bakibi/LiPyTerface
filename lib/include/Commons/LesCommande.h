



//  la structure de donnes 
typedef struct LesCommande
{
    Commande *cmd;
    struct LesCommande *svt;

}LesCommande;



//      les prototypes 
LesCommande *new_LesCommande();
LesCommande *LesCommande_add(LesCommande *lc,Commande *cmd);


//      les implementation



//      creer une nouvelle commande
LesCommande *new_LesCommande()
{
    return NULL;
}//eof

//  ajouter une commande
LesCommande *LesCommande_add(LesCommande *lc,Commande *cmd1)
{
    LesCommande *c = (LesCommande *)malloc(sizeof(LesCommande));
    if(!c) return NULL;
    c->cmd = cmd1;
    c->svt =lc;
    return c;
}//eof



