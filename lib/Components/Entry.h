Component *new_Entry(const char *placeholder)
{
    Component *cp = new_Component();
    cp->type = ENTRY;
    cp->this = gtk_entry_new();
    if(placeholder) 
    {
        gtk_entry_set_placeholder_text( GTK_ENTRY(cp->this) ,placeholder );
    }
    return (Component *)cp;
}//fin de la fonction

//  retourne buffer du text entry
GtkEntryBuffer* Entry_get_buffer(Component *entry) 
{
    GtkEntryBuffer *buffer;
    buffer = gtk_entry_get_buffer(GTK_ENTRY(entry->this));

    return buffer;
}

const gchar* Entry_get_text(Component *entry)
{
    const gchar *text = gtk_entry_get_text(GTK_ENTRY(entry->this));
    return(text);
}

void Entry_set_text(Component *entry,const gchar *text)
{
    gtk_entry_set_text (GTK_ENTRY(entry->this),text);
}

int Entry_get_text_length(Component *entry)
{
    int n = gtk_entry_get_text_length (GTK_ENTRY(entry->this));
    return (n);
}

