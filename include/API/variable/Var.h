
/* La structure de donnees */

typedef struct Var 
{
    float value;
    char *name;
    int type;  // (0) int (1) float
}Var;

//      Les prototypes

Var *new_Var(const char *name,int type);
int Var_exists(const char *name);
int Var_update(const char *name,float value,int type);
int Var_remove(const char *name1);


//      Les implementation des fonctions














// creation d une nouvelle variable
Var *new_Var(const char *name,int type)
{
    Var  *v = (Var *)malloc(sizeof(Var));
    v->value = 0;
    v->type = type;
    v->name = (char *)malloc(strlen(name));
    strcpy(v->name,name);
    // enregistrement dans le fichier
    FILE *fichier = NULL;
    fichier = fopen("values.tmp","a+");
    if(!fichier) return NULL;

    fprintf(fichier,"%s %d %f\n",v->name,v->type,v->value);

    fclose(fichier);// fermer le fichier
    return v;
}//eof











//  Cette fonction permet de verifier si une variable a été creer ou pas
int Var_exists(const char *name1)
{
    FILE *fichier = NULL;
    float value = 0;
    int type = 0;
    char name[30];
    fichier = fopen("values.tmp","r");
    if(fichier == NULL) return 0;
    rewind(fichier);
    // on parcours le fichier jusqua ce qu on trouve la var
    while(!feof(fichier))
    {
        
        fscanf(fichier,"%s %d %f\n",name,&type,&value );
        if(strcmp(name,name1) == 0) return 1;
    } //eow
    fclose(fichier);
 // sinon on a pas trouve la var
    return 0;
}//eof



















//  Cette fonction permet de changer la valeur d'une variable
int Var_update(const char *name1,float value1,int type1)
{
   
    if(Var_exists(name1))
    {
         FILE *f1 = fopen("values.tmp","r");
         FILE *wpp = fopen("wpp","w+");
        float value = 0;
         int type = 0;
        char name[30];
         if(!f1 || !wpp) return 0;
         while(!feof(f1))
        {
            fscanf(f1,"%s %d %f\n",name,&type,&value);
            if(strcmp(name,name1) == 0) 
                fprintf(wpp,"%s %d %f\n",name,type1,value1);
            else
                fprintf(wpp,"%s %d %f\n",name,type,value);
       } //eow

        fclose(f1);
        fclose(wpp);

        // maintenant on fait la mise à jour au variable
         f1 = fopen("values.tmp","w+");
         wpp = fopen("wpp","r");
         while(!feof(wpp))
         {
              fscanf(wpp,"%s %d %f\n",name,&type,&value);
              fprintf(f1,"%s %d %f\n",name,type,value);
         }
        fclose(f1);
        fclose(wpp);
        remove("wpp");
        return 1;
    }
    return 0;
}//eof



























//  Cette fonction permet de supprimer une variable
int Var_remove(const char *name1)
{
    if(Var_exists(name1))
    {
        FILE *f1 = fopen("values.tmp","r");   
        FILE *wpp = fopen("wpp","w+");
        float value = 0;
         int type = 0;
        char name[30];
        // copier dans un fichier tompore
        while(!feof(f1))
        {
            fscanf(f1,"%s %d %f\n",name,&type,&value);
            if(strcmp(name,name1) != 0)
                fprintf(wpp,"%s %d %f\n",name,type,value);
        }
        fclose(f1);
        fclose(wpp);
        // rendre les var dans le fichier values.tmp
        f1 = fopen("values.tmp","w+");
        wpp = fopen("wpp","r");
        while(!feof(wpp))
        {
            fscanf(wpp,"%s %d %f\n",name,&type,&value);
            fprintf(f1,"%s %d %f\n",name,type,value);
        }
        fclose(f1);
        fclose(wpp);
        remove("wpp");
        return 1;
    }
    return 0;
}//eof