/***                                             Cette page est consaccré au Conponent                         ***/


//          Fonction de creation d'un component
//      Entree: none
//      Sortie: Un component
Component *new_Component()
{
    Component *cp =(Component *)malloc(sizeof(Component));
    if(!cp)
    {
        printf("Erreur dans compoenent ! erreur d'allocation de memoire \n");
        exit(-1);
    } 
    cp->this = NULL;
    cp->type = -1;
    return (Component *)cp;
}//fin de la Fonction


//          Fonction qui mais
