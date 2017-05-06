Container* left_body(All *all)
{
    //  creation du frame
    Container *left = new_Frame("  Interface  ",10);
    all->leftFrame=left->this;
    cssDataToWidget(left->this, "color : #23D18B;background-color: #252526;padding:10px;");
    
    //  edition du titre
    GtkWidget *titre = Frame_get_label(left);
    all->leftTitre=titre;
    cssDataToWidget(titre, "color : #0098FF;font-size:30px;font-weight:bolder;");
    
    //  Creation Flow Container
    Container *flow     =   new_FlowBox(10);  
    cssDataToWidget(flow->this,"background-color:#FFF;");
    
    //  creation des boutons
    Component *iterface_fenetre = new_Button_image("interface/fenetre.jpg","Creer Une fenêtre");
    Component *iterface_bouton = new_Button_image("interface/bouton.jpg","Creer Un Bouton");
    Component *iterface_input = new_Button_image("interface/input.png","Creer Un Champ de Texte");
    Component *iterface_label = new_Button_image("interface/label.png","Creer Un Label");
    Component *iterface_textview = new_Button_image("interface/textview.png","Creer Un TextView");
    
    //Ajout des bouton au Flow 
    FlowBox_add(flow,iterface_fenetre->this,-1);
    FlowBox_add(flow,iterface_bouton->this,-1);
    FlowBox_add(flow,iterface_input->this,-1);
    FlowBox_add(flow,iterface_label->this,-1);
    FlowBox_add(flow,iterface_textview->this,-1);
    
    //  Ajout du Flow au left Frame
    left = Frame_add(left,flow->this);

    //  SIGNAUX
    g_signal_connect(G_OBJECT(iterface_fenetre->this), "clicked", G_CALLBACK(interfaceDialog_fenetre), all);

    return (left);
}