

//      La structutre de donnees

typedef struct  Lexemes
{
    Lexeme *lex;
    struct Lexemes *svt;
}Lexemes;


//  Les prototypes des fonctions


Lexemes *new_Lexemes();
Lexemes *Lexemes_add(Lexemes *lis,Lexeme *l);




//      les impementation des fonction






// Fonction de creation des lexemes en les tronsformant en une liste chainee
Lexemes *new_Lexemes()
{
     
    return NULL;
}//eof








//      cette fonction permet de ajouter dnas la iste
Lexemes *Lexemes_add(Lexemes *lis,Lexeme *l)
{
    Lexemes *liste = (Lexemes *) malloc(sizeof(Lexeme));
    if(!liste)
        return NULL;
        
    liste->lex =    l;
    liste->svt = NULL;       

    if(lis == NULL) return liste;

    Lexemes *tmp = lis;
    while(tmp->svt)
        tmp = tmp->svt;

    tmp->svt = liste;

    return lis;
}//eof


//      afficher tout les lexemes
void Lexemes_toString(Lexemes *liste)
{
    printf("\n");
     Lexemes *tmp = liste;
   while(tmp)
   {
       printf("%s\n",Lexeme_toString(tmp->lex));
       tmp = tmp->svt;
   }
}