
Container* bottom_bodyBash(All *all)
{

    //  creation du frame
    Container *bottom = new_Frame("  Output  ",10);
    all->bottomFrame=bottom->this;
    cssDataToWidget(bottom->this, "color : #23D18B;background-color: #1E1E1D");

    //  edition du titre
    GtkWidget *titre = Frame_get_label(bottom);
    all->bottomTitre=titre;
    cssDataToWidget(titre, "color : #23D18B;font:Bold 20px");

    //  Creation Scroll Container
    Container *scrolled_output = new_Scroll(10);
    
    //  Creation de l'output (non éditable et curseur non visible)
    Component *output = new_TextView(TRUE);
    TextView_set_editable(output,FALSE);
    TextView_set_cursor_visible(output,FALSE);
    all->output=output->this;
    cssDataToWidget(output->this, "color : #DDDDDD;background-color: #1E1E1D;");

    //  Recuperer Le buffer
    GtkTextBuffer *buffer = TextView_get_buffer(output);

    //  Recuperer Le buffer l'iter sur la premiere position
    GtkTextIter iter =  TextView_get_iter(output, 0, 0);

    //  Creation des couleurs
    TextView_create_fg_color(output,"red");
    
    //  Afficher Message d'acceuil
    TextView_insert_text(output,iter, "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tBienvenue à Shanks v2.2 ! \n\n"
                                      "\t\t\t\t\t\t\t\t\t\t\t\tVous êtes sur le mode Bash cela vous permet d'écrire"
                                      " votre code ShankScript dans l'éditeur ci-dessus,\n \t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t"
                                      "puis l'éxecuter avec le bonton RUN disponible dans les options QUICK\n",
                                      "red_fg");

    //  Ajout de l'output au Scroll Container
    scrolled_output = Scroll_add(scrolled_output,output->this);
    
    //  Ajout du Scroll Container Au Bottom Frame Container
    bottom = Frame_add(bottom,scrolled_output->this);

    return(bottom);
}