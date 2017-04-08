

//              mots-clées

char *keyWords[2] = {"var","string"};
int nbr_keyWords = 2;




//              Prototype
int is_keyWord(char str[]);
void lexical_compile(char str[]);

//              function

//      Cette fonction verifie si un mot est une keywords
int is_keyWord(char str[])
{
    for(int i = 0;i<nbr_keyWords;i++)
    {
        if(strcmp(str,keyWords[i]) == 0)
            return 1;
        
    }//end for

    return 0;
}//end of the function


//      Cette fonction retourne tout les mots lexicaux qui sont dans la commande
void lexical_compile(char str[])
{
        int length = strlen(str);
        int d = 0,f = 0;
        
        for (int i = 0; i < length; i++)
        {
            strncasecmp()
        }
}//end of the function


