//  Charger historique depuis fichier
historique charger_historique_fichier()
{
    
    historique histo;

    histo.rang_actuel=0;

    FILE *file;
    file = fopen("historique.txt", "r");

    int i=0;        
    gchar line[256];

    while (fgets(line, sizeof(line), file))
    {
        strcpy( histo.cmd[i] , line );
        strtok(histo.cmd[i++], "\n");
    }

    fclose(file);

    return histo;
}

//  enregistrer historique dans un fichier
void enregistrer_historique_fichier(historique histo)
{
    histo.rang_actuel=19;

    FILE *file;
    file = fopen("historique.txt", "w");

    for (int i = 0; i < 20; i++)
        fprintf(file,"%s\n", histo.cmd[i]);

    fclose(file);
}
