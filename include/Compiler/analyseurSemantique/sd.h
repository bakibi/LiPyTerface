
       /*-----------------------------------------*/

//  strucutre variable

typedef struct S_var
{
    char nom[30];
    char value[200];
}S_var;


//      la liste
typedef struct L_S_var
{
    S_var this;
    struct L_S_var *svt;
}L_S_var;



                    /*--------------------------------------*/

//      structure chaine
typedef struct S_str
{
    char nom[30];
    char value[1000];
}S_str;


//      la liste de chaine 
typedef struct L_S_str
{
    S_var this;
    struct L_S_str *svt;
}L_S_str;

                /*--------------------------------------------*/