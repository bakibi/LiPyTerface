
//                                                                            Prototypes

int if_null(void *var);
int est_chiffre(char *c);
int est_signe(char *c);
int est_virgule(char *c);
int est_operation(char *c);
float calcule(char str[]);





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
float calcule(char str[])
{
                      
    int etat_nbr = 0;
                     // 0 debut
                     // 1 entier est entree
                     // 2 virgule est entree
                     // 3 dicimal est entree
                     // -1 erreur 
                     // -2 after error
    int etat_op = 0;
                    //  0 debut
                    //  1     * /
                    //  2      + -                  
    float R = 0;
    int av = 0,nb_pl = 0;
                    // av == 0 si avant virgule
                    //  av == 1 apres virgule
    float total = 0,p_entier = 0,p_virgule = 0,p_signe = 1;
    int taille =strlen(str);
    Arbre *a = new_Arbre();


    for (int i = 0; i < taille; i++)
    {
        if(est_chiffre(&str[i]) != -1)
        {
            if(av == 0)
            {
                int  cc = (int) (str[i] - '0');
                p_entier *=10;
                p_entier +=cc; 
            }//pas encore saisie la virgule
            if(av == 1)
            {
                int  cc = (int) (str[i] - '0');
                nb_pl++;
                p_virgule +=  (int) pow(10,-nb_pl)  * cc;
            }//apres virgule
        }//fin cas si un chiffre
         else if(est_signe(&str[i]) != -1)
        {
            if(etat_nbr == 0)
            {
                if(str[i] == '+') p_signe = 1;
                else p_signe = -1;
                
            }//si on vient de sasir le signe

            if(est_chiffre(&str[i-1]) != -1)
            {
                 float res = p_signe*(p_entier + p_virgule);
                a = Arbre_add(a,2,res,0);
                a = Arbre_add(a,1,0,str[i]);

                  //renitialisation des donnees et parametres
                 p_signe = 1;
                p_entier = p_virgule = 0;
                av = 0;
                etat_nbr = etat_op = 0;
            }

            
        }//fin cas si une signe
        else if(est_operation(&str[i]) != -1)
        {
            float res = p_signe*(p_entier + p_virgule);
            a = Arbre_add(a,2,res,0);
            a = Arbre_add(a,1,0,str[i]);

            
            //renitialisation des donnees et parametres
            p_signe = 1;
            p_entier = p_virgule = 0;
            av = 0;
            etat_nbr = etat_op = 0;
        }//fin cas si une operation
         else if(est_virgule(&str[i]) != -1)
        {
            av = 1;
        }//fin cas si une virgule
         else
         {
             printf("Erreur dans le calcule arithmetique \n");
             return -1;
         }//fin cas sinon  
    }//fin boulce for

     float res = p_signe*(p_entier + p_virgule);
              a = Arbre_add(a,2,res,0);
   R = Arbre_evaluer(a);
    return R;//return le Resultat si tout ça passe bien
}