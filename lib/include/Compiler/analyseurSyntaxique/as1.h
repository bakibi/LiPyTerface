

//      C'est la deuxieme etape d  une analyse syntaxique
int as1(Grammaires *all,char *errors)
{

    Grammaires *tmp = all;
    
    while(tmp)
    {
        
        if(tmp->this->type == 0) //le cas d un affichage
        {
                
            Lexemes *le = tmp->this->content;
            Lexemes *tp = le;
            if(le->lex->type == -1 && le->svt != NULL)// le cas d un affichage normal d une variable
                    strcat(errors,"Erreur Syntaxique : probleme dans l'affichage .\n");
            else if (Lexeme_estKey(le->lex->value))
                     strcat(errors,"Erreur Syntaxique : probleme dans l'affichage usage d un nom de variable incorret.\n");
            else if(le->lex->type == 19)// le cas d une affichage d une chaine de caractere ""
            {
                
               if(verifier_affichage(tp) == 0)
                          strcat(errors,"Erreur Syntaxique : probleme dans l'affichage de la chaine de caractere . \n");
            }
        }//fin le cas d un affichage
        else if(tmp->this->type == 1) //le cas d un calcul arithmetique
        {
            Lexemes *le = tmp->this->content;
            Lexemes *tp = le;
            Lexeme *result = verifier_arithmetique(tp);
            if(result != NULL)
                strcat(errors,"Erreur Syntaxique : probleme dans le calcul arithmetique  . \n");
        }
        else if (tmp->this->type == 2) //le cas declaration
        {
             Lexemes *le = tmp->this->content;
            Lexemes *tp = le;
            int r= verifier_declaration(tp);
            if(r == 0)
                strcat(errors,"Erreur Syntaxique : probleme dans la declaration des variables . \n");

        }//fin cas declaration
        else if(tmp->this->type == 4) // l affectation
        {
             Lexemes *le = tmp->this->content;
            Lexemes *tp = le;
             int r= verifier_affectation(tp);
            if(r == 0)
                strcat(errors,"Erreur Syntaxique : probleme dans la affectation . \n");
        }

        tmp = tmp->svt;
    }




    return 1;
}