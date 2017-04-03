

//                              Prototypes

Arbre *new_Arbre();
Arbre *Arbre_load(char type,float value,char op);
int is_in(char t[],int n,char c);
int compare_priority(char op,char op1);
Arbre *Arbre_add(Arbre *a,char type,float value,char op);


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
                return (Arbre *)a;

            }

            //si le noeud contient une operation alors la il faut tester
            //les priorite
            int cp = compare_priority(a->op,op);

    }
    
    return (Arbre *)a;
}//end of function