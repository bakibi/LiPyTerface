

// la fonction de l analyse Semantique
 char *calc_arithm(char *result,Lexemes *lex,Finale *f);

Grammaires *ase(Grammaires *tout,char *errors,char *warnings,char *output)
{
    Grammaires *tmp  = tout;
    Finale *f = new_Finale();
    while(tmp)
    {
        
        if(tmp->this->type == 0)//  la cas si on a une affichage
            {
                if(Finale_varExists(f,tmp->this->content->lex->value) == 0 && Finale_strExists(f,tmp->this->content->lex->value) == 0)
                    {
                        strcat(errors,"Erreur Semantique : la variable \"");
                        strcat(errors,tmp->this->content->lex->value);
                        strcat(errors,"\" n'est pas encore declare ,elle ne peut pas etre afficher.\n");
                    }
                    else // si elle est declarer
                    {
                        if(Finale_varExists(f,tmp->this->content->lex->value))
                            {
                                strcat(output,Finale_varValue(f,tmp->this->content->lex->value));
                                strcat(output,"\n");
                            }
                        else
                            {
                                strcat(output,Finale_strValue(f,tmp->this->content->lex->value));
                                strcat(output,"\n");
                            }
                    }
            }// fin cas de declaration
            else if( tmp->this->type == 1)//le cas de arithmetique
            {
                if(verifier_arrithmetique(tmp->this,f,errors) == 1)
                    {
                       char *resultz = (char *)malloc(100) ;
                       resultz = calc_arithm(resultz,tmp->this->content->svt->svt,f);
                       strcat(output,resultz);
                        strcat(output,"\n");
                    }
            }//fin arithmetique
            else if (tmp->this->type == 2) //le cas d une declaration
            {
              f=  verifier_decclaration(tmp->this,f,errors,warnings);
            }
        tmp = tmp->svt;
    }
    return NULL;
}