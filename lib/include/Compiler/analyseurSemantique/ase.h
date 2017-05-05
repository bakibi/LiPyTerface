

// la fonction de l analyse Semantique
 char *calc_arithm(char *result,Lexemes *lex,Finale *f);


//la fonction du analyse arithmetique
Grammaires *ase(Grammaires *tout,char *errors,char *warnings,char *output,Finale *f)
{
    Grammaires *tmp  = tout;
    
    while(tmp)
    {
        
        if(tmp->this->type == 0)//  la cas si on a une affichage
            {
                if(tmp->this->content->lex->type == 19)//le cas d une chaine de caractere
                {

                }
                else if(Finale_varExists(f,tmp->this->content->lex->value) == 0 && Finale_strExists(f,tmp->this->content->lex->value) == 0)
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
                       resultz = calc_arithm(resultz,tmp->this->content,f);
                       strcat(output,resultz);
                        strcat(output,"\n");
                    }
            }//fin arithmetique
            else if (tmp->this->type == 2) //le cas d une declaration
            {
              verifier_decclaration(tmp->this,f,errors,warnings);
            }
            else if (tmp->this->type == 4) //le cas d une affectation
            {
                Lexemes *th = tmp->this->content;
                char result[1000] = "";
                if(verifier_affec(tmp->this,f,errors) == 1)
                {
                    f =  Finale_varChange(f,th->lex->value,calc_arithm(result,th->svt->svt,f));
                }
                else if(verifier_affec(tmp->this,f,errors) == 2)
                {

                }
            }// le cas de l'affecation'

        tmp = tmp->svt;
    }
    return NULL;
}