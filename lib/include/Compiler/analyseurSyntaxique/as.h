


 Grammaires *as(Lexemes *all1,char *errors)
 {
     Lexemes *all = rassembler_nbr(all1);
     Grammaires *liste  = new_Grammaires();
     if(all == NULL) return NULL;
    Lexemes *tmp = all;

    // Lanalyse commence ici
    if(verifier_parentheses(all)==0)
        {
            const char *e="Erreur Syntaxique : il y a une erreur par rapport au parentheses () .\n";
            strcat(errors,e);
        }

     if(verifier_quotation(all)==0)
        {
            const char e[]="Erreur Syntaxique : il y a une erreur par rapport au quotes \"\" .\n";
            strcat(errors,e);
        }

     if(verifier_brackets(all)==0)
        {
            const char *e = "Erreur Syntaxique : il y a une erreur par rapport au brackets {} .\n";
            strcat(errors,e);
        }
    
    if(verifier_squares(all)==0)
        {
            const char e[] = "Erreur Syntaxique : il y a une erreur par rapport au squares [] .\n";
            strcat(errors,e);
        }
        
        //  etape de conversion les lexemes en grammaires strucutree
     while(tmp)
     {
         if(tmp->lex->type == 21) ;// quand ; apparait sauter a l'autre lexeme'

         else if(tmp->lex->type==-1 &&(tmp->svt == NULL || tmp->svt->lex->type==21)) // affichage   21 --> ;
        {
             Lexemes *l = new_Lexemes();
             l = Lexemes_add(l,tmp->lex);
            Grammaire *g = new_Grammaire(0,l);
            liste = Grammaires_add(liste,g);
        }
        else
        {
            if(tmp->lex->type==19) // le cas si la commande commence par un ""
            {
                 Lexemes *l = new_Lexemes();
                 int fin = 0;
                 int v = 0;
                 int v_avant = 0;
                 int d = 0;
                while(tmp!=NULL &&  fin==0)
                {
                    v =tmp->lex->type;
                    l = Lexemes_add(l,tmp->lex);
                    if(d!=0 && v==19 && v_avant!=20)
                        fin = 1;
                    d++;
                    tmp =tmp->svt;
                    v_avant = v;
                }
                 while(tmp!=NULL && tmp->lex->type != 21)// jusqu au null ou ;
                {
                    l = Lexemes_add(l,tmp->lex);
                    tmp =tmp->svt;
                }
                Grammaire *g = new_Grammaire(0,l);
                liste = Grammaires_add(liste,g);
            }
         
             else if(tmp->lex->type == -1 && tmp->svt!=NULL && tmp->svt->lex->type == 15)//le cas d une affectation
            {
                Lexemes *l = new_Lexemes();
                while(tmp!=NULL && tmp->lex->type != 21)
                {
                    l = Lexemes_add(l,tmp->lex);
                    tmp =tmp->svt;
                }
                Grammaire *g = new_Grammaire(4,l);
                liste = Grammaires_add(liste,g);
            }//fin cas affectation

           else  if(tmp->lex->type == 0 || tmp->lex->type == 1 || (tmp->lex->type == -1 && tmp->svt->lex->type == 1) || 
                                  tmp->lex->type == 4 || tmp->lex->type == 5            ) // si ça commence par une ope ou un nombre
            {
                 Lexemes *l = new_Lexemes();
                while(tmp!=NULL && tmp->lex->type != 21)// jusqu au null ou ;
                {
                    l = Lexemes_add(l,tmp->lex);
                    tmp =tmp->svt;
                }
                Grammaire *g = new_Grammaire(1,l);
                liste = Grammaires_add(liste,g);
            }//fin cas  par une ope ou un nombre

          else  if(tmp->lex->type == 3)// si c est pour une declaration
            {
                if(strcmp(tmp->lex->value,"var" ) == 0 || strcmp(tmp->lex->value,"str" ) == 0)
                {
                     Lexemes *l = new_Lexemes();
                while(tmp!=NULL && tmp->lex->type != 21)// jusqu au null ou ;
                {
                    l = Lexemes_add(l,tmp->lex);
                    tmp =tmp->svt;
                }
                Grammaire *g = new_Grammaire(2,l);
                liste = Grammaires_add(liste,g);
                }
            }
            else    //autre 
            {
                  Lexemes *l = new_Lexemes();
                while(tmp!=NULL && tmp->lex->type != 21)// jusqu au null ou ;
                {
                    l = Lexemes_add(l,tmp->lex);
                    tmp =tmp->svt;
                }
                Grammaire *g = new_Grammaire(0,l); // le cas daffichage
                liste = Grammaires_add(liste,g);
            }
            
        }//fin else
        if(tmp)
            tmp = tmp->svt;
                    
     }//end of while
     return liste;
 }//eof
