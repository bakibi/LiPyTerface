//  Fonction Creation TextView Component 
Component *new_TextView(gboolean wrapWord)
{
    Component *cp = new_Component();
    cp->type = TEXTVIEW;

    cp->this = gtk_text_view_new();

    if(wrapWord)
        gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(cp->this), GTK_WRAP_WORD);
    
    return cp;
}//fin de la fonction



//  Fonction Modifier droit de l'edition
void TextView_set_editable(Component *tv, gboolean option)
{   
    gtk_text_view_set_editable(GTK_TEXT_VIEW(tv->this), option);

}//fin de la fonction



//  Fonction Cacher/Montrer le curseur
void TextView_set_cursor_visible(Component *tv, gboolean option)
{   
    gtk_text_view_set_cursor_visible(GTK_TEXT_VIEW(tv->this), option);

}//fin de la fonction



//  Fonction Recuperation du Buffer
GtkTextBuffer* TextView_get_buffer(Component *tv)
{
    GtkTextBuffer *buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(tv->this));
    return buffer;
}//fin de la fonction



//  Fonction Recuperation d'un Iter apartir d'une position
GtkTextIter TextView_get_iter(Component *tv, int line, int col)
{   
    GtkTextBuffer *buffer = gtk_text_view_get_buffer( GTK_TEXT_VIEW(tv->this) );

    GtkTextIter iter;
    gtk_text_buffer_get_iter_at_line_offset( buffer, &iter, line, col );

    return iter;
}//fin de la fonction



//  Fonction Creation couleur Foreground
void TextView_create_fg_color(Component *tv, gchar *couleur )
{   
    GtkTextBuffer *buffer = gtk_text_view_get_buffer( GTK_TEXT_VIEW(tv->this) );

    gtk_text_buffer_create_tag(buffer, g_strconcat( couleur , "_fg" , NULL),"foreground", couleur, NULL);

}//fin de la fonction



//  Fonction Creation couleur background
void TextView_create_bg_color(Component *tv, gchar *couleur)
{   
    GtkTextBuffer *buffer = gtk_text_view_get_buffer( GTK_TEXT_VIEW(tv->this) );
    
    gtk_text_buffer_create_tag(buffer, g_strconcat( couleur , "_bg" , NULL),"background", couleur, NULL);

}//fin de la fonction



//  Fonction Insertion Text
void TextView_insert_text(Component *tv, GtkTextIter iter, gchar* text, gchar *nom_couleur)
{   
    GtkTextBuffer *buffer = gtk_text_view_get_buffer( GTK_TEXT_VIEW(tv->this) );
    
    if(nom_couleur)
        gtk_text_buffer_insert_with_tags_by_name(buffer, &iter, utf8(text), -1, nom_couleur, NULL);
    else
        gtk_text_buffer_insert (buffer, &iter, utf8(text), -1);

}//fin de la fonction



//  Fonction Poser iter à la derniere position
GtkTextIter TextView_get_iter_end(Component *tv)
{   
    GtkTextBuffer *buffer = gtk_text_view_get_buffer( GTK_TEXT_VIEW(tv->this) );

    GtkTextIter iter;
    gtk_text_buffer_get_end_iter (buffer, &iter);

    return iter;
}//fin de la fonction
