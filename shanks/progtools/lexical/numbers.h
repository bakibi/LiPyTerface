
//                                                                            Prototypes

int if_null(void *var);
int est_chiffre(char *c);
int est_signe(char *c);
int est_virgule(char *c);
int est_operation(char *c);
float calcule(const char *str);





//                                                                          Implementation

//      Cette fonction test un pointeur est  ce qu il est NULL ou pas et retourne 1 Si c Vrai
int est_null(void *var)
{
    if(var == NULL)
    {
        printf("Erreur : Test sur Null\n");
        return 1;
    }
    return 0;
}//end of the function


//      Cette fonction test si un caractere est ce qu il est un chiffre ou pas si oui retourn sa valeur sinon 
//        il retourn -1
int est_chiffre(char *c)
{
    if(est_null(c)) 
        return -1;
    if('0'<= *c && *c<='9')
        return (int) (*c-'0');
    return -1;        
}//end of the function

//      Cette fonction test si un caractere est un signe (-) 1 ou (+) 2 et retourn sa valeur 
//      sinon retourn -1;  
int est_signe(char *c)
{
    if(est_null(c)) 
        return -1;
    if(*c == '+')
        return 2;
    if(*c == '-')
        return 1;
    return -1;               
}//end of the function

//      Cette fonction test si un caractere est une est_virgule return 1 si oui
//      sinon -1;
int est_virgule(char *c)
{
    if(est_null(c)) 
        return -1;
    if(*c == '.')
        return 1;
    return -1;
}//end of the function


//          Cette fonction verifie si un caractere est une operation et reourn sa valeur 
//          sinon retourn -1
int est_operation(char *c)
{
    if(est_null(c)) 
        return -1;
    if(*c == '+')
        return 0;
    if(*c == '-')
        return 1;
    if(*c == '/')
        return 2;
    if(*c == '*')
        return 3;
    if(*c == '%')
        return 4;
    return -1;
}//end of the function


//          Cette fonction donne le resultat d une operation arithmetique 
//          sinon Error Message
float calcule(const char *str)
{
                      
    int etat_nbr = 0;
                     // 0 debut
                     // 1 entier est entrer
                     // 2 virgule est entrer
                     // 3 dicimal est entrer
                     // -1 erreur 
                     // -2 after error
    int etat_op = 0;
                    //  0 debut
                    //  1                      
    float R = 0;
    float total = 0,p_entier = 0,p_virgule = 0;
    int taille =strlen(str);
    for (int i = 0; i < taille; i++)
    {
      
    }
  
    return R;
}