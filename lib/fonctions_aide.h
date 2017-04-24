//  transforme chaine en format utf8
char* utf8(char *chaine)
{
    return(g_locale_to_utf8 (chaine,-1,0,0,0));
}

//  retourne commande qui vient d'etre saisi
gchar* retourner_commande(GtkTextBuffer *buffer)
{
    GtkTextIter start_cmd, end_cmd;

    gtk_text_buffer_get_iter_at_mark(buffer, &start_cmd, gtk_text_buffer_get_insert(buffer));
    gtk_text_buffer_get_iter_at_mark(buffer, &end_cmd, gtk_text_buffer_get_insert(buffer));

    gtk_text_iter_set_line (&start_cmd, -1);
    gtk_text_iter_set_line_offset (&start_cmd,16);

    gtk_text_iter_forward_to_end (&end_cmd);

    gchar *text = gtk_text_buffer_get_text(buffer, &start_cmd, &end_cmd, FALSE);

    return text;
}

//  RESET MENU 
void reset(GtkWidget *widget, gpointer data) {

  All *all = data;

  //  reset de la console
  GtkTextBuffer *buffer1 = gtk_text_view_get_buffer(GTK_TEXT_VIEW(all->console));
  gtk_text_buffer_set_text(buffer1,"",-1);

  //  reset de l'editeur
  GtkTextBuffer *buffer2 = gtk_text_view_get_buffer(GTK_TEXT_VIEW(all->editor));
  gtk_text_buffer_set_text(buffer2,"",-1);

  //  reset du Output
  GtkTextBuffer *buffer3 = gtk_text_view_get_buffer(GTK_TEXT_VIEW(all->output));
  gtk_text_buffer_set_text(buffer3,"",-1);
}