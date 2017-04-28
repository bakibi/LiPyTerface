//      La Grammaire
typedef struct Grammaire
{
    char type;
        //  Affichage 0
        //Arithmetique 1
        // Declaration 2
        //  Predicat 3 
        //Affectation 4
        //IF_ELSE 5
        //FOR 6
        //Fonction 7
    Lexemes *content;
    char *errors;
    char *warnings;
    //all the content        
}Grammaire;


//      Les prototypes des fonctions
Grammaire *new_Grammaire(char type,Lexemes *content);
void Grammaire_toString(Grammaire *g);


//      Les implementations






Grammaire *new_Grammaire(char type,Lexemes *content)
{
    Grammaire *gr = NULL;
    Lexemes *pt = content;
    if(pt == NULL) return NULL;
    
    gr = (Grammaire *)malloc(sizeof(Grammaire));
    gr->type = type;
    gr->content = content;
    
    return gr;
}//end of function



void Grammaire_toString(Grammaire *g)
{
    if(g!=NULL) 
    {
        switch(g->type)
        {
            case 0:printf("Affichage\n");break;
            case 1:printf("Arithmetique\n");break;
            case 2:printf("Declaration\n");break;
            case 3:printf("Predicat\n");break;
            case 4:printf("Affectation\n");break;
            case 5:printf("IF_ELSE\n");break;
            case 6:printf("FOR\n");break;
        }
         Lexemes *pt = g->content;
         while(pt)
         {
             printf("%s ",pt->lex->value);
             pt = pt->svt;
         }   
         printf("\n");

    }
}//eof