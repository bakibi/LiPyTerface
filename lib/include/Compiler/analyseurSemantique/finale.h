

// la structure de donnees 

typedef struct Finale
{
    L_S_var *l1;
    L_S_str *l2;
}Finale;

//      Les prototypes
Finale *new_Finale();
Finale *Finale_addVar(Finale *f,const char *name,const char *value);
int  Finale_varExists(Finale *f,const char *name);
const char *Finale_varValue(Finale *f,const char *name);
Finale *Finale_varChange(Finale *f,const char *name,const char *value);
Finale *Finale_addStr(Finale *f,const char *name,const char *value);
int  Finale_strExists(Finale *f,const char *name);
const char *Finale_strValue(Finale *f,const char *name);
Finale *Finale_strChange(Finale *f,const char *name,const char *value);
//      les implementations



//      creation
Finale *new_Finale()
{
    Finale *tmp = (Finale *)malloc(sizeof(Finale));
    if(tmp== NULL) return NULL;
    tmp->l1 = NULL;
    tmp->l2 = NULL;
    return tmp;
}//eof




//      si la var exixiste vraimment
int  Finale_varExists(Finale *f,const char *name)
{
    if (f == NULL) return 0;
    L_S_var *tmp = f->l1;
    while(tmp)
    {
        if(strcmp(tmp->this.nom,name) == 0)
            return 1;
        tmp = tmp->svt;
    }//while
    return 0;
}//eof



//      adding une variable de type var
Finale *Finale_addVar(Finale *f,const char *name,const char *value)
{
    if(f == NULL)   return NULL;
    L_S_var *pt = (L_S_var *) malloc(sizeof(L_S_var));
    if(pt == NULL) return NULL;
    strcpy(pt->this.nom,name);
    strcpy(pt->this.value,value);
    pt->svt = f->l1;
    f->l1 = pt;
    return f;
}//eof


//  return value of a existing variable
const char *Finale_varValue(Finale *f,const char *name)
{
    
    L_S_var *tmp = f->l1;
    while(tmp)
    {
        if(strcmp(tmp->this.nom,name) == 0)
            {
                return tmp->this.value;
                
            }
        tmp = tmp->svt;
    }//while
    return "";
}//eof


Finale *Finale_varChange(Finale *f,const char *name,const char *value)
{
    if(f == NULL) return NULL;
     L_S_var *tmp = f->l1;
    while(tmp)
    {
        if(strcmp(tmp->this.nom,name) == 0)
            {
                strcpy(tmp->this.value,value);
                return f;
            }
        tmp = tmp->svt;
    }//while
    return f;
}//eof




 /*********   STR **********/
//      si la str exixiste vraimment
int  Finale_strExists(Finale *f,const char *name)
{
    if (f == NULL) return 0;
    L_S_str *tmp = f->l2;
    while(tmp)
    {
        if(strcmp(tmp->this.nom,name) == 0)
            return 1;
        tmp = tmp->svt;
    }//while
    return 0;
}//eof




//      fonction ajouter une chaine de caractere a la finale
Finale *Finale_addStr(Finale *f,const char *name,const char *value)
{
    if(f == NULL)   return NULL;
    L_S_str *pt = (L_S_str *) malloc(sizeof(L_S_str));
    if(pt == NULL) return NULL;
    strcpy(pt->this.nom,name);
    strcpy(pt->this.value,value);
    pt->svt = f->l2;
    f->l2 = pt;
    return f;
}//eof


//      la valeur de la variable de type str
const char *Finale_strValue(Finale *f,const char *name)
{
    L_S_str *tmp = f->l2;
    while(tmp)
    {
        if(strcmp(tmp->this.nom,name) == 0)
                return tmp->this.value;
        tmp = tmp->svt;
    }//while
    return "";
}//eof



Finale *Finale_strChange(Finale *f,const char *name,const char *value)
{
    if(f == NULL) return NULL;
     L_S_str *tmp = f->l2;
    while(tmp)
    {
        if(strcmp(tmp->this.nom,name) == 0)
            {
                strcpy(tmp->this.value,value);
                return f;
            }
        tmp = tmp->svt;
    }//while
    return f;
}//eof