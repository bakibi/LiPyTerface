GtkWidget* left_body(All *all)
{
    GtkWidget *left = gtk_frame_new("  Interface  ");
    all->leftFrame=left;
    cssDataToWidget(left, "color : #23D18B;background-color: #252526");

    GtkWidget *titre = gtk_frame_get_label_widget(GTK_FRAME(left));
    all->leftTitre=titre;
    cssDataToWidget(titre, "color : #23D18B;font:Bold 30px");
    
    Container *flow     =   new_FlowBox();  
    cssDataToWidget(flow->this,"background-color:#FFF;");

    Component *iterface_fenetre = new_Button_image("interface/fenetre.jpg");
    cssDataToWidget(iterface_fenetre->this, "background-color:rgba(0,0,0,0);border: 0px");
    gtk_widget_set_tooltip_text (iterface_fenetre->this, utf8("Creer Une fenêtre"));
    Component *iterface_bouton = new_Button_image("interface/bouton.jpg");
    cssDataToWidget(iterface_bouton->this, "background-color:rgba(0,0,0,0);border: 0px");
    gtk_widget_set_tooltip_text (iterface_bouton->this, utf8("Creer Un Bouton"));
    Component *iterface_input = new_Button_image("interface/input.png");
    cssDataToWidget(iterface_input->this, "background-color:rgba(0,0,0,0);border: 0px");
    gtk_widget_set_tooltip_text (iterface_input->this, utf8("Creer Un Champ de Texte"));
    Component *iterface_label = new_Button_image("interface/label.png");
    cssDataToWidget(iterface_label->this, "background-color:rgba(0,0,0,0);border: 0px");
    gtk_widget_set_tooltip_text (iterface_label->this, utf8("Creer Un Label"));
    Component *iterface_textview = new_Button_image("interface/textview.png");
    cssDataToWidget(iterface_textview->this, "background-color:rgba(0,0,0,0);border: 0px");
    gtk_widget_set_tooltip_text (iterface_textview->this, utf8("Creer Un TextView"));

    FlowBox_add(flow,iterface_fenetre->this,-1);
    FlowBox_add(flow,iterface_bouton->this,-1);
    FlowBox_add(flow,iterface_input->this,-1);
    FlowBox_add(flow,iterface_label->this,-1);
    FlowBox_add(flow,iterface_textview->this,-1);

    gtk_container_add( GTK_CONTAINER(left) , flow->this );

    //  setting some spacing
    gtk_container_set_border_width ( GTK_CONTAINER(left), 10);
    gtk_container_set_border_width ( GTK_CONTAINER(flow->this), 10);

    //  SIGNAUX
    g_signal_connect(G_OBJECT(iterface_fenetre->this), "clicked", 
      G_CALLBACK(interfaceDialog_fenetre), all);


    return (left);
}