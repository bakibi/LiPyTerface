
/*                              All the key words of the interpretor                        */


//          All the kind of variables
enum Var {WALOU,VAR,STRING,BOOLEAN,LIST,PILE,FIL,ARBRE};
//          Operators
enum Oper {PLUS,MOINS,DIV,MUL,MOD};
//          Operator of condition
enum Cond {IF,ELSEIF,ELSE,SWITCH,CASE};
//          Compare 
enum Comp {EGAL,DIFF,SUP,INF,SUPE,INFE};
//          Operator of boucling 
enum Boucle {FOR,WHILE};
//      Printing
enum Screen {PRINT,PRINTLN};


//          Var : SD
typedef struct variable
{
    int ID;
    enum Var type;
    int *int_value;
    float *float_value;
    float *complex_a_value,*complex_b_value;
    char *string_value;
    int *boolean_value;
    Pile *pile_value;
    File *file_value;
    Liste *liste_value;
    Arbre *arbre_value;
}variable;




//          Oper : SD
typedef struct operateur
{
    int ID;
    enum Oper type;
    variable *a;
    variable *b;
    variable *result;
}operateur;


//          Compare : SD
typedef struct compare
{
    int ID;
    enum Comp type;
    int value;
}compare;

//          Condition : SD
typedef struct condition
{
    int ID;
    enum Cond type;
    int Value;
}condition;
    