

//      La stucture de donnees 
typedef struct PileSyn
{
    char v;
    struct PileSyn *svt;
}PileSyn;

//      les prototypes 
PileSyn *new_PileSyn();
PileSyn *PileSyn_empiler(PileSyn *p,char c);
PileSyn *PileSyn_depiler(PileSyn *p);


//      les implementation













//      Creation d une nouvelle Pile 
PileSyn *new_PileSyn()
{
    return NULL;
}//eof







//      Empiler
PileSyn *PileSyn_empiler(PileSyn *p,char c)
{
    PileSyn *tmp = (PileSyn *)malloc(sizeof(PileSyn));
    if(!tmp) return NULL;
    tmp->v = c;
    tmp->svt = p;
    return tmp;
}//eof















PileSyn *PileSyn_depiler(PileSyn *p)
{
    if(p == NULL) return NULL;
    PileSyn *tmp = p;
    p = p->svt;
    free(tmp);
    return p;
}//eof

