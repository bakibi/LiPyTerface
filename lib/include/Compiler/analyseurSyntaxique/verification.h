

//      Les prototypes des fonction en bas
int verifier_parentheses(Lexemes *lex);
int verifier_quotation(Lexemes *lex);
int verifier_brackets(Lexemes *lex);
int verifier_squares(Lexemes *lex);
int verifier_declaration(Lexemes *lex);
Lexeme *verifier_arithmetique(Lexemes *lex);
Lexemes *rassembler_nbr(Lexemes *lex);
int verifier_nombre(const char *nbr);
int verifier_affectation(Lexemes *lex);
int verifier_affichage(Lexemes *lex);
Lexemes *rassembler_chaine(Lexemes *lex);

//      verifier les parentheses
int verifier_parentheses(Lexemes *lex)
{
    Lexemes *tmp = lex;
    PileSyn *pile = new_PileSyn();
    int v = 0;
    int v_chaine = 0;
    int v_avant = 0;
    while(tmp)
    {
        v=tmp->lex->type;
            if(v == 19 && v_avant!=20)
                v_chaine = 1-v_chaine;
        if(v==4  || v==5)
        {
            if(v_chaine==0)
            {
                if(pile == NULL) pile = PileSyn_empiler(pile,v);
                 else if(v==5 && pile->v==4) pile = PileSyn_depiler(pile);
                 else pile = pile = PileSyn_empiler(pile,v);
            }
        }//fin if
        tmp = tmp->svt;
        v_avant = v;
    }//fin while
    if(pile==NULL)
        return 1;
    return 0;        
}//eof






//          Verifier les quotes
int verifier_quotation(Lexemes *lex)
{
    Lexemes *tmp = lex;
    PileSyn *pile = new_PileSyn();
    int v = 0;
    int c = 0;
    int v_avant = 0;
    while(tmp)
    {
        v=tmp->lex->type;
        if(v==19)
        {
            if(v_avant!=20)
            c++;
        }//fin if
        tmp = tmp->svt;
        v_avant = v;
    }//fin while
    if(c%2 ==0 && c!=1  )
        return 1;
    return 0;        
}//eof












//      verifier les brackets
int verifier_brackets(Lexemes *lex)
{
    Lexemes *tmp = lex;
    PileSyn *pile = new_PileSyn();
    int v = 0;
     int v_chaine = 0;
    int v_avant = 0;
    while(tmp)
    {
        v=tmp->lex->type;
          if(v == 19 && v_avant!=20)
                v_chaine = 1-v_chaine;
        if(v==23  || v==24)
        {
            if(v_chaine==0)
            {
                if(pile == NULL) pile = PileSyn_empiler(pile,v);
                else if(v==23 && pile->v==24) pile = PileSyn_depiler(pile);
                else pile = pile = PileSyn_empiler(pile,v);
            }
        }//fin if
        tmp = tmp->svt;
        v_avant = v;
    }//fin while
    if(pile==NULL)
        return 1;
    return 0;        
}//eof






//      verifier les squares
int verifier_squares(Lexemes *lex)
{
    Lexemes *tmp = lex;
    PileSyn *pile = new_PileSyn();
    int v = 0;
   int v_chaine = 0;
    int v_avant = 0;
    while(tmp)
    {
        v=tmp->lex->type;
       if(v == 19 && v_avant!=20)
                v_chaine = 1-v_chaine;
        if(v==6  || v==7)
        {
             if(v_chaine==0)
            {
            if(pile == NULL) pile = PileSyn_empiler(pile,v);
            else if(v==6 && pile->v==7) pile = PileSyn_depiler(pile);
            else pile = pile = PileSyn_empiler(pile,v);
            }
        }//fin if
        tmp = tmp->svt;
         v_avant = v;
    }//fin while
    if(pile==NULL)
        return 1;
    return 0;        
}//eof







//  verifier si un lexemes est pour la declaration
int verifier_declaration(Lexemes *lex)
{
       Lexemes *tmp = lex;
       if( tmp ->svt == NULL) return 0;
        int v = -5;
        int e = 0; // debut
                        // = ---> 1
                        // value --->2
                        // , ---> 3
                        //  var  -->4

                        //  name --->1
                        //  " ----->  2
                        //   val --->3
                        //  ,  ---> 4;
                        // = ---> 5
                        //  + ----> 6
        if(strcmp(tmp->lex->value,"var") == 0)
        {
            tmp = tmp->svt;
            while(tmp)
            {
                v = tmp->lex->type ;
                if(v != 25 && v!=0 && v!=15 && v!=-1)
                    return 0;//cas derreur
                if(e == 0 && (v ==25 || v == 0 || v == 15))
                    return 0;
                if(e == 1 && (v == 25 || v == 15))
                    return 0;
                if(e == 2 && (v == 15 || v == -1))
                    return 0;
                if(e == 3 && (v == 25 || v == 0 || v == 15))
                    return 0;
                if(e == 4 && (v== 0))
                    return 0;
                
                if(v == 0)
                    e = 2;
                if(v == -1)
                    e = 4;
                if(v == 25)
                    e = 3;
                if(v == 15)
                    e = 1;
                if(e == 2 && verifier_nombre(tmp->lex->value) == 0)
                    return 0;

                tmp = tmp->svt;
            }//fin while
            if (e == 1 ||  e == 3)
                return 0;
        }
        else
        {
            
            tmp = tmp->svt;
            while(tmp)
            {

                v = tmp->lex->type;
                if((e == 0  || e == 4) && (v == 19 || v == -2 || v == 25 || v == 1))
                    return 0;
                else if(e == 1 && (v != 25 && v != 15))
                    return 0;
                else if(e == 2 && (v!= -2 && v!= 25 && v!=1))
                    return 0;
                else if (e == 3 && v!=19)
                    return 0;
                else if(e == 5 && (v!=19 && v!=-1))
                    return 0;
                else if( e== 6 && (v!=19 && v!=-1))
                    return 0;


               if(tmp->lex->type == -1) e = 1;
               else if(tmp->lex->type == 19) e = 2;
               else if (tmp->lex->type == -2) e = 3;
               else if (tmp->lex->type == 25) e = 4;
               else if (tmp->lex->type == 15) e = 5;
               else if (tmp->lex->type == 1 && strcmp(tmp->lex->value,"+")== 0) e = 6;
               else return 0;
                tmp = tmp->svt;
            }//end of while     
            if(e == 4 || e == 5 || e == 6)
                return 0;
        }//end of else


    return 1;
}







  Lexeme *verifier_arithmetique(Lexemes *lex)
  {


      Lexemes *tmp = lex;
      int v = -5;
      int e = 0; // debut
                    // + - ---> 1
                    // * / % ----> 2
                    // var / nmbre ----> 3
      while(tmp)
      {
          v = tmp->lex->type;
          if(v == -1 || v == 0 || v == 1 || v == 4 || v == 5)
             { 
                 if(e == 0 && v == 1 && ( strcmp(tmp->lex->value,"*") == 0 || strcmp(tmp->lex->value,"/") == 0 || strcmp(tmp->lex->value,"%") == 0))
                    return tmp->lex;//cas d erreur debut avec 
                if(e == 1 && v == 1 && ( strcmp(tmp->lex->value,"*") == 0 || strcmp(tmp->lex->value,"/") == 0 || strcmp(tmp->lex->value,"%") == 0))
                    return tmp->lex;//cas de 4+*5
                if(e == 2 && v == 1 && ( strcmp(tmp->lex->value,"*") == 0 || strcmp(tmp->lex->value,"/") == 0 || strcmp(tmp->lex->value,"%") == 0))
                    return tmp->lex; // cas de 4**5

                 if(v == 1 && ( strcmp(tmp->lex->value,"*") == 0 || strcmp(tmp->lex->value,"/") == 0 || strcmp(tmp->lex->value,"%") == 0))
                    e = 2;
                else if(v == 1)
                    e = 1;
                else e  = 3;   
                if(tmp->lex->type == 0 && verifier_nombre(tmp->lex->value)==0)
                     return tmp->lex;
                 tmp = tmp->svt;
             }
          else 
             return tmp->lex;
      }// fin while

      return NULL;
  }//eof






//rassembler_nbr 
  Lexemes *rassembler_nbr(Lexemes *lex)
  {
    Lexemes *nv = NULL;
    char nbr[500] = "";
    int e = 0;
    Lexemes *tmp = lex;
    while(tmp)
    {   
        if(tmp->lex->type !=0 && e == 0 )
            nv = Lexemes_add(nv,tmp->lex);
        else if(tmp->lex->type !=0 && e != 0 )
        {
            nv = Lexemes_add(nv,new_Lexeme(nbr));
            nv = Lexemes_add(nv,tmp->lex);
            e = 0;
        }
        else
        {
            if(e == 0)
                strcpy(nbr,"");
            strcat(nbr,tmp->lex->value);
            e = 1;
        }

        tmp = tmp->svt;
    }
    if(e == 1)
         nv = Lexemes_add(nv,new_Lexeme(nbr));

    return nv;
  }//eof








  int verifier_nombre(const char *nbr)
  {

      int taille = strlen(nbr);
      int e =0;
      for(int i =0;i<taille;i++)
      {
            if(nbr[i] =='.')    e++;

      }
      return e<=1;
  }//eof








  int verifier_affectation(Lexemes *lex)
  {
      int r = 1;
     
      Lexemes *tmp = lex;
      tmp = tmp->svt; // on est ici a = 
      if(tmp->svt == NULL)
        return 0;
        tmp = tmp->svt; // on est ici apres =
       int e = 0;
    int v = -5;
    //      1       -->     " du debut
    //      2       -->     " de la fin
    //      3       -->     +   du debut
    //      4       -->     + de la fin
    //      5       -->     other
    while(tmp)
    {   
        
        if((e == 0 || e == 4) && tmp->lex->type == 19) e = 1;
        else if (e == 1 && v!=20 && tmp->lex->type == 19) e = 2;
        else if (e == 2 && tmp->lex->type == 1) e =3;
        else if ((e == 3 || e == 5) && tmp->lex->type == 1) e = 4;
        else if( e == 3) e = 5;
     
        if(e == 2 && tmp->svt == NULL)
            return 1;
        else if(e == 2 && tmp->svt->lex->type != 1)
            return 0;
        else if((e == 3 || e == 4) && strcmp(tmp->lex->value,"+")!=0)
            return 0;
      else if (e == 5)
      {
          Lexemes *tt = new_Lexemes();
          while(tmp)
          {
              if( tmp->svt !=NULL && tmp->svt->lex->type == 1 && strcmp(tmp->svt->lex->value,"+") == 0 )
                break; 
              tt = Lexemes_add(tt,new_Lexeme(tmp->lex->value));
              tmp = tmp->svt;
          }//end while
          if(tmp == NULL )
            return  verifier_arithmetique(tt) == NULL;
        if(verifier_arithmetique(tt) != NULL)
            return 0;
      }
        
            
        v = tmp->lex->type;
        tmp  = tmp->svt;
    }//eof

    if (e == 3 || e == 4 || e == 2)
        return 0;//false
      return 1;
  }//eof





  //    verification d un afichage est c qu il est corrent ou pas 
  int verifier_affichage(Lexemes *lex)
  {

    Lexemes *tmp = lex;
    int e = 0;
    int v = -5;
    //      1       -->     " du debut
    //      2       -->     " de la fin
    //      3       -->     +   du debut
    //      4       -->     + de la fin
    //      5       -->     other
    while(tmp)
    {   
        
        if((e == 0 || e == 4) && tmp->lex->type == 19) e = 1;
        else if (e == 1 && v!=20 && tmp->lex->type == 19) e = 2;
        else if (e == 2 && tmp->lex->type == 1) e =3;
        else if ((e == 3 || e == 5) && tmp->lex->type == 1) e = 4;
        else if( e == 3) e = 5;
     
        if(e == 2 && tmp->svt == NULL)
            return 1;
        else if(e == 2 && tmp->svt->lex->type != 1)
            return 0;
        else if((e == 3 || e == 4) && strcmp(tmp->lex->value,"+")!=0)
            return 0;
      else if (e == 5)
      {
          Lexemes *tt = new_Lexemes();
          while(tmp)
          {
              if( tmp->svt !=NULL && tmp->svt->lex->type == 1 && strcmp(tmp->svt->lex->value,"+") == 0 )
                break; 
              tt = Lexemes_add(tt,new_Lexeme(tmp->lex->value));
              tmp = tmp->svt;
          }//end while
          if(tmp == NULL )
            return  verifier_arithmetique(tt) == NULL;
        if(verifier_arithmetique(tt) != NULL)
            return 0;
      }
        
            
        v = tmp->lex->type;
        tmp  = tmp->svt;
    }//eof

    if (e == 3 || e == 4 || e == 2)
        return 0;//false
      return 1;
  }//eof









//  rassembler toutes les chaines de caractères
  Lexemes *rassembler_chaine(Lexemes *lex)
  {
     Lexemes *nv = NULL;
    char chaine[5000] = "";
    int e = 0;
    int v = -3;
    //      1   en chaine 
    //      2   fin de la chaine
    //      3   debut de la chaine
    //      4   rien
    Lexemes *tmp = lex;
    while(tmp)
    {   

        if(tmp->lex->type !=19 && (e ==4 || e == 0))    //quand il  y a rien
            nv = Lexemes_add(nv,tmp->lex);
        else if(tmp->lex->type !=19 && e == 2 ) // on vient de sortir de la chaine de la caa
        {
           
            Lexeme *ll = new_Lexeme(chaine);
            ll->type = -2;
            nv = Lexemes_add(nv,ll);
             nv = Lexemes_add(nv,new_Lexeme("\""));
            nv = Lexemes_add(nv,tmp->lex);
            e = 4;
        }
        else if(tmp->lex->type ==19 && (e ==4 || e == 0)  )//quand on rencontre le primier " d une chaine
        {
            e = 1;//    changement d etat 
            nv = Lexemes_add(nv,tmp->lex);  //on ajoute le " a la liste
             strcpy(chaine,"");//on vide la chiane
        }
        else if( e == 1 && tmp->lex->type !=19 )// quand on est en le milieu de la chaine 
        {

            strcat(chaine,tmp->lex->value);
            strcat(chaine," "); // espace
            e = 1;
        }
        else if (e == 1) // qunad on est au milieu et on rencontre un "
        {
            if(v == 20) strcat(chaine,"\"");
            else
                 e = 2;

        }//end of if
        v = tmp->lex->type;
        tmp = tmp->svt;
    }//end of while
    if(e !=0 && e!=4)
         {
             Lexeme *ll = new_Lexeme(chaine);
             ll->type = -2;
             nv = Lexemes_add(nv,ll);
             nv = Lexemes_add(nv,new_Lexeme("\""));
         }

    return nv;
  }//eof
