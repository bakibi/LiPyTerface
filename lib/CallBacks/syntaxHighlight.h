void syntaxHighlight_keyWords_editor(GtkTextBuffer *buffer)
{
    gchar *keys[]={"int","str","float","var","if","for","else"};

    GtkTextIter start_find, end_find;
    GtkTextIter start_match, end_match;

    gtk_text_buffer_get_start_iter(buffer, &start_find);
    gtk_text_buffer_get_end_iter(buffer, &end_find);

    gtk_text_buffer_remove_tag_by_name(buffer, "blue_fg", &start_find, &end_find);

    for(int i=0;i<7;i++)
    {
        while (gtk_text_iter_forward_search(&start_find, keys[i], 
                    GTK_TEXT_SEARCH_TEXT_ONLY | GTK_TEXT_SEARCH_VISIBLE_ONLY, 
                    &start_match, &end_match, NULL)) 
        {
            gtk_text_buffer_apply_tag_by_name(buffer, "blue_fg",&start_match, &end_match);
            gint offset = gtk_text_iter_get_offset(&end_match);
            gtk_text_buffer_get_iter_at_offset(buffer, &start_find, offset);
        }
    }
}