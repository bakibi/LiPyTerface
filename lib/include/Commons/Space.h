

//          La strucutre de donnees Space 
//                  ----> c'est ici ou le tavail ce fait

typedef struct Space
{
    char *name;  //le nom de l'espace'
    LesCommande *all; //tout les commande sous forme d'une liste
    char *fileVar;  //le ficheir qui contient les Var
    char *fileStr; // le fichier qui contient   les Str
    Finale *f;      // les variables 
}Space;


//      Les prototypes 

Space *new_Space(const char *name);
Space *Space_delete(Space *sp);
Commande *Space_compile(Space *sp,const char *cmd);

//      Les implementations




//      Cette fonction cree un nouveau espace de travail
Space *new_Space(const char *name)
{
    Space *sp = (Space *)malloc(sizeof(Space));
    if(!sp) return NULL;
    sp->name = NULL;
    sp->all = NULL;
    sp->fileVar = NULL;
    sp->fileStr = NULL;
    sp->f = new_Finale();
    sp->name = (char *)malloc(strlen(name));
    strcpy(sp->name,name); //on cp le nom dans la structure
    sp->fileVar = (char *)malloc(strlen(name)+20);
    sp->fileStr = (char *)malloc(strlen(name)+20);
    char *dossier =(char *)malloc(20);
    strcpy(dossier,"mkdir system/");strcat(dossier,name);
    //system(dossier);
    strcpy(sp->fileVar,"system/");strcat(sp->fileVar,name);strcat(sp->fileVar,"/fileVar");
    strcpy(sp->fileStr,"system/");strcat(sp->fileStr,name);strcat(sp->fileStr,"/fileStr");
  //  FILE *f1 = fopen(sp->fileVar,"w+");fclose(f1);
   // FILE *f2 = fopen(sp->fileStr,"w+");fclose(f2);

    return sp;
}//eof




//      Supprimer un espace de travail
Space *Space_delete(Space *sp)
{
    if(sp==NULL) return NULL;
    char *f1 = (char *)malloc(25);
    char *f2 = (char *)malloc(25);
    strcpy(f1,"rm system/");strcat(f1,sp->name);strcat(f1,"/fileVar");
    strcpy(f2,"rm system/");strcat(f2,sp->name);strcat(f2,"/fileStr");
    system(f1);system(f2);
     char *dossier =(char *)malloc(20);
    strcpy(dossier,"rmdir system/");strcat(dossier,sp->name);
   // system(dossier);
    free(sp->name);
    free(sp->fileVar);
    free(sp->fileStr);
    free(sp);
    return NULL;
}//eof





//  ajouter une comande à un Space
Commande *Space_compile(Space *sp,const char *c)
{
    int test = 0;
    Commande *cmd = new_Commande(c);
    cmd = Commande_interpreter(cmd,&test,sp->f);
    if(test == 1)
    sp->all = LesCommande_add(sp->all,cmd);
    return cmd;
}//all