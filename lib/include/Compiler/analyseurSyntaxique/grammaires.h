


//      La strucure de donnees Grammaires c est une liste chainee
typedef struct Grammaires
{
    Grammaire *this;
    struct Grammaires *svt;
}Grammaires;



/* FIN */

//      Les prototypes des fonctions

Grammaires *new_Grammaires();
Grammaires *Grammaires_add(Grammaires *lis,Grammaire *a);
void Grammaires_toString(Grammaires *gr);




//      Les implementations

Grammaires *new_Grammaires()
{
    return NULL;
}



//ajouter un grammaire a la liste
Grammaires *Grammaires_add(Grammaires *lis,Grammaire *a)
{
    Grammaires *liste = (Grammaires *) malloc(sizeof(Grammaires));
    if(!liste)
        return NULL;
        
    liste->this =    a;
    liste->svt = NULL;       

    if(lis == NULL) return liste;

    Grammaires *tmp = lis;
    while(tmp->svt)
        tmp = tmp->svt;

    tmp->svt = liste;

    return lis;
}//eof






void Grammaires_toString(Grammaires *gr)
{
    Grammaires *tmp = gr;
    while(tmp)
    {
        Grammaire_toString(tmp->this);
        tmp = tmp->svt;
    } 
}