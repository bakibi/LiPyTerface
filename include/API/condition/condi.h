

//  La structure de donnees 

typedef struct Condition
{
    int type;   // 0 : not
                    // 1 : unitaite
                    // 2 : ET
                    // 3 : OR
    int value;

} Condition;


//      les prototypes des fonction
Condition *new_Condition(int value);
Condition *new_Not(Condition *cn);
Condition *new_Or(Condition *cn1,Condition *cn2);
Condition *new_And(Condition *c1,Condition *cn2);

//      Les implemetnations des fonctions


















//      Cette fonction cree une nouvelle Condition
Condition *new_Condition(int value)
{
    Condition *cn = (Condition *)malloc(sizeof(Condition));
    if(!cn) return NULL;
    cn->type = 1;
    cn->value = value;
    return cn;
}//eof


















//      Cette fonction cree une condition de type Not
Condition *new_Not(Condition *cn)
{
    Condition *c = (Condition *)malloc(sizeof(Condition));
    if(!c) return NULL;
    c->type = 0;
    c->value = 1-cn->value;
    return c;
}//eof












//      Cette fonction cree une condition de type AND
Condition *new_And(Condition *cn1,Condition *cn2)
{
    Condition *c = (Condition *)malloc(sizeof(Condition));
    if(!c) return NULL;
    c->type = 2;
    c->value = cn1->value && cn2->value;
    return c;
}//eof
















//      Cette fonction cree une condition de type OR
Condition *new_Or(Condition *cn1,Condition *cn2)
{
    
    Condition *c = (Condition *)malloc(sizeof(Condition));
    if(!c) return NULL;
    c->type = 3;
    c->value = cn1->value || cn2->value;
    return c;
}//eof