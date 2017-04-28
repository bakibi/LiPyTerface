



//      Les prototypes
char *readFromFile(char *s,const char *file);



//      les implentations

char *readFromFile(char *s,const char *file)
{
      s = (char *)malloc(9000);
     FILE *f = fopen(file,"r");
     if(f == NULL)
     {
         printf("\n\t Probleme :Le fichier et introuvable ou il est utilises par un autre programme !\t");   
         return NULL;
     }
     char c ;
     int i=0;
     while((c = fgetc(f))!=EOF)
     {
         s[i] = c;
         i++;
     }
     s[i] = '\0';
     fclose(f);
     return s;
}//eof