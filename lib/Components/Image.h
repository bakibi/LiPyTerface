/**        Cette page est reserve au composant image                       **/



//          Fonction de creation d une instance image
//      Entree: le path
//      Sortie: le composant bien organise
Component *new_Image(const char *path,int size)
{
    Component *cp = new_Component();
        cp->type = IMAGE;
        cp->this = gtk_image_new_from_file(path);
        gtk_image_set_pixel_size(GTK_IMAGE(cp->this),size);
    return cp;
} //fin de la fonction


//          Fonction  pour changer une image
//      Entree: the path 
//      Sortie: Le composant bien modifiées
Component *Image_changeImage(Component *cp, const char *path,int size)
{
    gtk_image_set_from_file(GTK_IMAGE(cp->this),path);
    gtk_image_set_pixel_size(GTK_IMAGE(cp->this),size);
     return cp;
}//fin de la fonction

