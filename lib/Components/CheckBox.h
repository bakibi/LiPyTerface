Component *new_CheckBox(const char *label)
{
    Component *cp = new_Component();
    cp->type = CHECKBOX;

    if(label)
        cp->this = gtk_check_button_new_with_label(label);
    else 
        cp->this = gtk_check_button_new();
    return cp;
}