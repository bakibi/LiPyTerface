

//      la structure de donnees Lexeme
typedef struct Lexeme
{
    int taille;
    int type;
    /*
        -2 chaine de caractere
        -1  Value
        0   Nombre
        1   Operation
        3   Mot clées
        4   (
        5   )
        6   [
        7   ]
        8   ==
        9   !=
        10  <
        11  <=
        12  >
        13  >=
        14  !
        15  =
        16  &&
        17  ||   
        18  @
        19 "
        20 \
        21 ;
        22 .
        23 {
        24 }
        25 ,
    */

    char *value;
}Lexeme;

//      Les prototypes des fonctions

Lexeme *new_Lexeme(char const *l);
int Lexeme_estKey(char const *t);
int Lexeme_estNum(char const *t);
const char  *Lexeme_toString(Lexeme *l);
int estUnDelimiteur(char c);
const char *retourDelimiteur(char c);




//      Les implementations des fonctions 










//  Cette fonction prend en parametre une chaine de caratere et deduit de une lexeme
Lexeme *new_Lexeme(char const *l)
{
    Lexeme *lem = (Lexeme *) malloc(sizeof(Lexeme));
    if(!lem) return NULL;
    
    int taille = strlen(l);
    lem->taille = taille;
    lem->value =(char *) malloc(taille+1);
    strcpy(lem->value,l);

     if(Lexeme_estKey(l))
            {
                lem->type = 3;
            return lem;
            }
    else if(Lexeme_estNum(l))
            {lem->type = 0;
            return lem;
            }
   else  if(taille == 1)
    {
    
        if( (strcmp(l,"+") == 0) || (strcmp(l,"-") == 0) || (strcmp(l,"*") == 0) || (strcmp(l,"/") == 0) || (strcmp(l,"%") == 0)   )
            {
             //printf("gdgdfd");
                lem->type = 1;
            }
       else if(strcmp(l,"(") == 0 )//
            lem->type = 4;            
        else if(strcmp(l,")") == 0 )//
            lem->type = 5;
        else if(strcmp(l,"[") == 0 )//
            lem->type = 6;
        else if(strcmp(l,"]") == 0 )//
            lem->type = 7;       
        else if(strcmp(l,"<") == 0 )
            lem->type = 10; 
        else if(strcmp(l,">") == 0 )
            lem->type = 12;   
        else if(strcmp(l,"!") == 0 )
            lem->type = 14;
        else if(strcmp(l,"=") == 0 )
            lem->type = 15;     
        else if(strcmp(l,"@") == 0 )
            lem->type = 18;
        else if(strcmp(l,"\"") == 0 )
            lem->type = 19;        
        else if(strcmp(l,"\\") == 0 )
            lem->type = 20;        
        else if(strcmp(l,";") == 0)
            lem->type  = 21;
        else if(strcmp(l,".") == 0)
            lem->type  = 22;    
        else if(strcmp(l,"{") == 0)
            lem->type  = 23;
        else if(strcmp(l,"}") == 0)
            lem->type  = 24;                
        else if(strcmp(l,",") == 0)
            lem->type  = 25;   
        else 
            lem->type = -1;
         return lem;   
            
    }//si la taille de la lexeme == 1
    if(taille == 2)
    {
        if(strcmp(l,"==") == 0 )
            lem->type = 8;
        else if(strcmp(l,"!=") == 0 )
            lem->type = 9;
        else if(strcmp(l,"<=") == 0 )
            lem->type = 11;
        else if(strcmp(l,">=") == 0 )
            lem->type = 13;
        else if(strcmp(l,"&&") == 0 )
            lem->type = 16;
        else if(strcmp(l,"||") == 0 )
            lem->type = 17;
        else 
            lem->type = -1;
       return lem; 
            
    }//si la taille de la lexem == 2
    else
    { 
            lem->type = -1;            
        
    }//si la taille est superieur à 2
    return (Lexeme *) lem;
}//eof








//      Cette foction verifie si un str est un mots
int Lexeme_estKey(char const *t)
{

    const char mots[11][10] = 
                                    {
                                      "var",
                                      "str",
                                      "for",
                                      "while",
                                      "if",
                                      "else"
                                      "switch",
                                      "case",  
                                      "function",
                                      "return",
                                      "class"
                                    };
                                    
    for(int i=0;i<11;i++)
        if(strcmp(t,mots[i]) == 0)
            return 1;
    return 0;                                    
}//eof

int Lexeme_estNum(char const *t)
{
    int taille = strlen(t);
    for (int i=0;i<taille;i++)
        if( !('0'<=t[i] && t[i]<='9') && t[i] !='.' )
            return 0;
    return 1;
}//eof



const char  *Lexeme_toString(Lexeme *l)
{
    char *res = NULL;
    char tt[2];
     if(l == NULL) return NULL;
     res = (char *)malloc(l->taille + 7);
     sprintf(tt, "%d", l->type);
     strcpy(res,l->value);
     strcat(res,"\t\t");
     strcat(res,tt);
     

     return res;
}//eof






int estUnDelimiteur(char c)
{
    int taille = 24;
    char tab[] = {'\n', ' ' , '\t' , '(' , ')' , '[' , ']' , '{' , '}' , '=' , '<' , '>' , '\"' , ',' , '@' , ';' ,'+','-','*','\\','/','%',';','.'};
    
    for(int i=0;i<24;i++)
        if(c == tab[i])
            return 1;
    return 0;
}//eof





const char *retourDelimiteur(char c)
{
    int taille = 24;
    char *tab[] = {"\n", " " , "\t" , "(" , ")" , "[" , "]" , "{" , "}" , "=" , "<" , ">" , "\"" , "," , "@" , ";" , "+" , "-" , "*" , "\\" ,"/" ,"%",";","."  };
    char tab1[] = {'\n', ' ' , '\t' , '(' , ')' , '[' , ']' , '{' , '}' , '=' , '<' , '>' , '\"' , ',' , '@' , ';' ,'+','-','*','\\','/','%',';','.'};
    int v = 0;
     for(int i=0;i<24;i++)
        if(c == tab1[i])
            v = i;
    return &tab[v][0];

}//eof