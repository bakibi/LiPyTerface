Container* right_body(All *all)
{
    //  creation du frame
    Container *right = new_Frame("  Console  ",10);
    all->rightFrame=right->this;
    cssDataToWidget(right->this, "color : #23D18B;background-color: #1E1E1D");

    //  edition du titre
    GtkWidget *titre = Frame_get_label(right);
    all->rightTitre=titre;
    cssDataToWidget(titre, "color : #23D18B;font:Bold 30px");
    
    //  Creation Scroll Container
    Container *scrolled_console = new_Scroll(10);

    //  Creation de la console
    Component *console = new_TextView(TRUE);
    all->console=console->this;
    cssDataToWidget(console->this, "color : #0F0;background-color: #1E1E1D;");

    //  Recuperer Le buffer
    GtkTextBuffer *buffer = TextView_get_buffer(console);
    
    //  Recuperer Le buffer l'iter sur la premiere position
    GtkTextIter iter =  TextView_get_iter(console, 0, 0);

    //  Creation des couleurs
    TextView_create_fg_color(console,"red");
    TextView_create_fg_color(console,"orange");
    TextView_create_fg_color(console,"black");
    TextView_create_bg_color(console,"lightgray");

    //  Afficher Message d'acceuil
    TextView_insert_text(console,iter, "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tBienvenue à Shanks v2.2 ! \n\n"
                                      "\t\t\t\t\tVous êtes sur le mode Interpreteur cela vous permet de réaliser"
                                      " votre application ou de faire des traitement rapide\n \t\t\t\t\t\t\t"
                                      "en écrivant votre code ShankScript commande par commande et de "
                                      "voir le résultat immédiatement \n\n",
                                      "red_fg");

    //  Insertion du premier prefixe console en orange
    iter = TextView_get_iter_end(console);
    TextView_insert_text(console,iter,"ilisi@shanks:~# ","orange_fg");
    
    //  Ajout de la Console au Scroll Container
    scrolled_console = Scroll_add(scrolled_console,console->this);
    
    //  Ajout du Scroll Container Au Right Frame Container
    right = Frame_add(right,scrolled_console->this);

    //  SIGNAUX
    //g_signal_connect(buffer, "changed",G_CALLBACK(update_lnCol), all->lnCol->this);
    g_signal_connect(buffer, "mark_set", G_CALLBACK(mark_set_callback), all);

    return(right);
}