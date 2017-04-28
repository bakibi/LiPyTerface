




 char *calc_arithm(char *result,Lexemes *lex,Finale *f)
{
    
    int e = 0;
    
    ArbreA *a = new_ArbreA();
    //      1       operation
    //      2       (
    //      3       )
    //      4       nbr
    //      5       var
    Lexemes *tmp = lex;
    while(tmp)
    {   

        if(tmp->lex->type == 0)
            a = ArbreA_addV(a,atof(tmp->lex->value));
        else if(tmp->lex->type == -1)
            a = ArbreA_addV(a,atof(Finale_varValue(f,tmp->lex->value)));
        else if(tmp->lex->type == 1)
            a = ArbreA_addO(a,*(tmp->lex->value));
        else 
        {
            tmp = tmp->svt;
            Lexemes *tmp1 = NULL;
            while(tmp->lex->type != 5)
                {
                    tmp1=Lexemes_add(tmp1,new_Lexeme(tmp->lex->value));
                    tmp = tmp->svt;
                }
                char *result1= (char *)malloc(100) ;;
                a = ArbreA_addV(a,atof(calc_arithm(result1,tmp1,f)));
        }
        
        tmp = tmp->svt;
    }//fin while 
    strcpy(result,"");
    sprintf(result,"%f",ArbreA_evaluer(a));

    return result;
}