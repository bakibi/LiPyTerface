
//                                                          Analyse semantique
/*      Ce fichier contient tout les fonction qui vont permetre de verifier pendant l'analyse semantique */

//      les prototypes 
int verifier_arrithmetique(Grammaire *gr,Finale *f,char *errors);
int verifier_decclaration(Grammaire *gr,Finale *f,char *errors,char *warnings);
int verifier_nom_var(const char *nom);
int verifier_affec(Grammaire *gr,Finale *f,char *errors);



//      les implentations





int verifier_nom_var(const char *nom)
{
    if(Lexeme_estKey(nom) == 1 )
        return 0;
    
    if(*nom<='0'  && *nom<='9' )
        return 0;
    return 1;
}//eof






// verifier le contenu du calcul arithmetique
int verifier_arrithmetique(Grammaire *gr,Finale *f,char *errors)
{
    Lexemes *tmp = gr->content;

    int r = 0;
    int e = 0;
    //      0       ->      debut
    //      1       ->      +   or  -
    //      2       ->      *   /   or  %
    //      3       ->      nbr
    //      4       ->      var
    //      5       ->      (
    //      6       ->      )
    while(tmp)
    {

        if(e ==5 && tmp->lex->type == 5) 
            {
                strcat(errors,"Erreur semantique : Vous ne pouvez pas faire () .\n");
                r++;
            }
          if(e ==6 && tmp->lex->type !=1 &&  tmp->lex->type != 2 &&  tmp->lex->type != 5  )  
          {
              strcat(errors,"Erreur semantique : Apres ) vous devez mettre une operation .\n");
                r++;
          }
          if((e == 1 || e == 2) &&   tmp->lex->type == 5 )
          {
               strcat(errors,"Erreur semantique : Apres une operation vous ne pouvez pas fermer une pare ) .\n");
                r++;
          }
          if(  tmp->lex->type ==-1 && Finale_varExists(f,tmp->lex->value) == 0)
          {
              strcat(errors,"Erreur semantique : La variable  \"");
              strcat(errors,tmp->lex->value);
              strcat(errors,"\" n'est pas encore declarer .\n");
                r++;
          }

        
        //  le changement d'etat
        if(tmp->lex->type == 1 && (strcmp(tmp->lex->value,"+") == 0 || strcmp(tmp->lex->value,"-") == 0 ))    e = 1;
        else if(tmp->lex->type == 1)    e = 2;
        else if(tmp->lex->type == 0)    e = 3;
        else if(tmp->lex->type == -1)   e = 4;
        else if(tmp->lex->type == 4)    e = 5;
        else if(tmp->lex->type == 5)    e = 6;
        tmp = tmp->svt;//suivant
    }
    if( e == 1 || e == 2)
        {
            strcat(errors,"Erreur semantique : Le calcul arithmetique ne doit pas se terminer par une opeartion .\n");
                r++;
        }

    if(r == 0)
        return 1;//true
    return 0;//false   
}//eof

















// fonction de verification d une verifier_decclaration
int verifier_decclaration(Grammaire *gr,Finale *f,char *errors,char *warnings)
{

    Lexemes *tmp = gr->content;

    int r = 0;
    int e = 0;
    //      0       ->      debut
    //      1       ->      var
    //      2       ->      =
    //      3       ->      value
    //      4       ->      ,
    //      5       ->      var_aff

    
    tmp = tmp->svt;
    while(tmp)
    {

        

        if(tmp->lex->type == -1 && e!=2) e = 1;
        else if(tmp->lex->type == 0) e = 3;
        else if(tmp->lex->type == 15) e = 2;
        else if(tmp->lex->type == 25) e = 4;
        else if(e == 2 && tmp->lex->type == -1 ) e =5;
        else ;

        if(e == 1 && (tmp->svt == NULL || tmp->svt->lex->type == 25)) // on a une nouvelle declaration
        {
            
            if(verifier_nom_var(tmp->lex->value))
               {
                   if(Finale_varExists(f,tmp->lex->value) || Finale_strExists(f,tmp->lex->value))
                   {
                        strcat(warnings,"warnings : La  variable  \"");
                        strcat(warnings,tmp->lex->value);
                        strcat(warnings,"\" a ete deja declarer .\n");
                   }
                   else
                    f = Finale_addVar(f,tmp->lex->value,"0");
               }
            else 
            {
                strcat(errors,"Erreur semantique : Le nom de la  variable  \"");
               strcat(errors,tmp->lex->value);
               strcat(errors,"\" n'est pas correcte .\n");
                r++;
            }
        }
        else  if (e==1)// autre si la declaration suit l affecataon
        {
            if(verifier_nom_var(tmp->lex->value))
               {
                   if(Finale_varExists(f,tmp->lex->value) || Finale_strExists(f,tmp->lex->value)) // si la varialbe existe
                   {
                        strcat(warnings,"warnings : La  variable  \"");
                        strcat(warnings,tmp->lex->value);
                        strcat(warnings,"\" a ete deja declarer .\n");
                   }
                   else  // si la vairble n'existe pas
                    {
                        Lexeme *aff = tmp->svt->svt->lex;
                        if(aff->type == -1) // le cas si l'aafectaion sefait par une variable
                        {
                            if(Finale_strExists(f,aff->value))// si la varibel est declarer de type str
                            {
                                strcat(errors,"Erreur semantique : La variable  \"");
                                strcat(errors,aff->value);
                                strcat(errors,"\" est de type str, erreur de l'affecation  .\n");
                                 r++;
                            }
                            else if(Finale_varExists(f,aff->value) == 0)//si la varible nest pas encore declarer
                            {
                                 strcat(errors,"Erreur semantique : La variable  \"");
                                strcat(errors,aff->value);
                                strcat(errors,"\" n'est pas encore declarer .\n");
                                 r++;
                            }
                            else // sinon on ajoute la variable
                            {
                               f= Finale_addVar(f,tmp->lex->value,Finale_varValue(f,aff->value));
                            }
                        } //fin  le cas si l'aafectaion sefait par une variable
                        else // affecatation par un nombre
                        {
                             f=Finale_addVar(f,tmp->lex->value,aff->value);
                        }
                    }
               }
            else 
            {
                strcat(errors,"Erreur semantique : Le nom de la  variable  \"");
               strcat(errors,tmp->lex->value);
               strcat(errors,"\" n'est pas correcte .\n");
                r++;
            }
        }
        

        tmp = tmp->svt;
    }
    if(r==0)
        return 1;//true
    return 0;
}//eof










int verifier_affec(Grammaire *gr,Finale *f,char *errors)
{
    Lexemes *tmp = gr->content;

    if(Finale_varExists(f,tmp->lex->value) == 0 && Finale_strExists(f,tmp->lex->value) == 0 )
    {
        strcat(errors,"Erreur semantique : la variable  \"");
        strcat(errors,tmp->lex->value);
        strcat(errors,"\" n'est pas declare .\n");
        return 0;
    }
    else if(Finale_varExists(f,tmp->lex->value) ) // cas d une varible var
    {
        tmp = tmp->svt;
        tmp = tmp->svt;
        Grammaire *g = new_Grammaire(4,tmp);
        if(verifier_arrithmetique(g,f,errors) == 0)
            return 0;
        else return 1;
    }
    else // cas d une str
    {
        
    }
    return 1;

}//eof