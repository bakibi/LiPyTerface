

//                              Prototypes

Arbre *new_Arbre();
Arbre *Arbre_load(char type,float value,char op);
int is_in(char t[],int n,char c);
int compare_priority(char op,char op1);
Arbre *Arbre_add(Arbre *a,char type,float value,char op);
void Arbre_toString(Arbre *a);
float Arbre_evaluer(Arbre *a);


//                              Fonctions

//      init a function
Arbre *new_Arbre()
{
    Arbre *a = NULL;
    return (Arbre *) a;
}//end of function



//      this function help in ading function
Arbre *Arbre_load(char type,float value,char op)
{
   Arbre  *a = (Arbre *)malloc(sizeof(Arbre));
        if( a == NULL)
            return NULL;
        if(type == 1)
            {
                    a->fg == NULL;
                    a->fd == NULL;
                    a->op = op ;
                    a->v = 0;
            }
            else
            {
                    a->fg == NULL;
                    a->fd == NULL;
                    a->op = 0 ;
                    a->v = value;  
            }
}//end of the function

int is_in(char t[],int n,char c)
{
    int i=0;
    for ( i = 0; i < n; i++)
    {
        if(t[i] == c)
            return 1;   
    }
    return 0;
}//end of the function


int compare_priority(char op,char op1)
{
    if(op == op1)
        return 0;
    char t2[] = {'+','-'};
    char t1[] = {'*','/'};
    char t3[] = {'%'};
    if(is_in(t1,2,op)  && is_in(t1,2,op1) )
        return 0;
    if(is_in(t2,2,op)  && is_in(t2,2,op1))
        return 0;
    
    if(op == t3[0])
        return 1;

    if(op1 == t3[0])
        return -1;

     if(is_in(t1,2,op))
        return 1;

     if(is_in(t1,2,op1))
        return -1;
              
        
}


//      add_function
//          type == 1           operation
//          type == 2            value of a term    
Arbre *Arbre_add(Arbre *a,char type,float value,char op)
{
    if( a   ==  NULL)
    {
        
        Arbre *a1 = Arbre_load(type,value,op);
                    //the return 
                    return (Arbre *)a1;
    }//end if is included

    //si on va inserer une operation
    if( type == 1)
    {
            //si le noeud contient un nombre ya t7enn
            if(a->op == 0)
            {
                Arbre *a1 = Arbre_load(type,value,op);
                a1->fg = a;
                return (Arbre *)a1;

            }

            //si le noeud contient une operation alors la il faut tester
            //les priorite
            int cp = compare_priority(a->op,op);
            if(cp==0)
            {
                 Arbre *a1 = Arbre_load(type,value,op);
                a1->fg = a;
                return (Arbre *)a1;
            }//si ils ont la mm opreartio an
            if(cp==1)
            {
                 Arbre *a1 = Arbre_load(type,value,op);
                 a1->fg = a;
                 return (Arbre *)a1;
            }//si l'operation du debut est sup a la 2ieme'
            if(cp == -1)
            {
                 Arbre *a1 = Arbre_load(type,value,op);
                 a1->fg = a->fd;
                 a->fd = a1;
                 return (Arbre *)a;
            }//si l'operation du debut est inf a la 2ieme '

            

    }//si on veut inserer une operation
    else//si on veut inserer un nombre float
    {
         a->fd =    Arbre_add(a->fd,type,value,op);
    }
    
    return (Arbre *)a;
}//end of function


//Cette fonction affiche le contenu d'une fenetre on prefixant
void Arbre_toString(Arbre *a)
{
    if(a == NULL)
        return ;
        Arbre_toString(a->fg);
    if(a->op == 0)
        printf("%f\t",a->v);
    else
        printf("%c\t",a->op);

    Arbre_toString(a->fd);
    return;         
}//end of the function


//this function give a result of the arithmztic equation
float Arbre_evaluer(Arbre *a)
{
    if(a==NULL)
         return 0;

    if (a->op == 0)
        return a->v;

     if(a->op == '+')
     {
        return Arbre_evaluer(a->fg) + Arbre_evaluer(a->fd);
     }   
     if(a->op == '-')
     {
         return Arbre_evaluer(a->fg) - Arbre_evaluer(a->fd);
     }   
      if(a->op == '*')
     {
         return Arbre_evaluer(a->fg) * Arbre_evaluer(a->fd);
     }   
          if(a->op == '/')
     {
         return Arbre_evaluer(a->fg) / Arbre_evaluer(a->fd);
     }   
          if(a->op == '%')
     {
         return (int)Arbre_evaluer(a->fg)%(int)Arbre_evaluer(a->fd);
     }   
}