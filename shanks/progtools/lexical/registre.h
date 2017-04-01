
/*                              All the key words of the interpretor                        */


//          All the kind of variables
enum Var {WALOU,VAR,STRING,BOOLEAN,LIST,PILE,FILE};
//          Operators
enum Oper {PLUS,MOINS,DIV,MUL,MOD};
//          Operator of condition
enum Cond {IF,ELSEIF,ELSE,SWITCH,CASE};
//          Operator of boucling 
enum Boucle {FOR,WHILE};
//      Printing
enum Screen {PRINT,PRINTLN};




//          Var : SD
typedef struct variable
{
    int type;
    int *int_value;
    float *float_value;
    float *complex_a_value,*complex_b_value;
    char *string_value;
    int *boolean_value;
}variable;



//          Oper : SD
typedef struct operateur
{

}
