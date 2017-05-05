/*

L 'analyseur lexicale

*/


Lexemes *al(const char *phrase)
{
    Lexemes *liste = new_Lexemes();
    int taille = strlen(phrase);
    int i=0,j=0;
    char mots[2000];
    int mot_en_cours = 0;

    
    for(i=0;i<taille;i++)
    {
        if(estUnDelimiteur(phrase[i]))
        {
               if(phrase[i] == ' ' || phrase[i] == '\n' || phrase[i] == '\t')
                {
                    if(mot_en_cours == 1)
                    {
                         mots[j] = '\0';
                        liste = Lexemes_add(liste,new_Lexeme(mots));
                         j = 0;
                        mot_en_cours = 0;
                        continue;
                    }// si il y a un mots en saisie en cours 
                    else 
                        continue;
                }//si il ya un espace ou un retour à la ligne
                
                mots[j] = '\0';
                if(mot_en_cours == 1)
                    {
                        liste = Lexemes_add(liste,new_Lexeme(mots));
                         liste = Lexemes_add(liste,new_Lexeme(retourDelimiteur(phrase[i])));
                    }// si il ya un mot en coureur
                else 
                {
                      liste = Lexemes_add(liste,new_Lexeme(retourDelimiteur(phrase[i])));
                    
                       
                }               
                
                j = 0;
                mot_en_cours = 0;
        }
        else 
        {
            mots[j] = phrase[i];
            mot_en_cours = 1;
            j++;    
        }
    }
            
    if(mot_en_cours ==1)
    {
        mots[j] = '\0';
        liste = Lexemes_add(liste,new_Lexeme(mots));
    }
    return liste;
}

