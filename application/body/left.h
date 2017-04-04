GtkWidget* left_body()
{
    GtkWidget *left = gtk_frame_new("  Interface  ");
    cssDataToWidget(left, "color : #23D18B;background-color: #252526");

    GtkWidget *titre = gtk_frame_get_label_widget(GTK_FRAME(left));
    cssDataToWidget(titre, "color : #23D18B;font:Bold 30px");


    Container *flow     =   new_FlowBox();  

    GtkWidget *btn1     =   gtk_button_new_with_label("Fenetre");
    GtkWidget *btn2     =   gtk_button_new_with_label("Bouton");
    GtkWidget *btn3     =   gtk_button_new_with_label("Label");
    GtkWidget *btn4     =   gtk_button_new_with_label("Container");
    GtkWidget *btn5     =   gtk_button_new_with_label("Entry");
    GtkWidget *btn6     =   gtk_button_new_with_label("Fenetre");
    GtkWidget *btn7     =   gtk_button_new_with_label("Bouton");
    GtkWidget *btn8     =   gtk_button_new_with_label("Label");
    GtkWidget *btn9     =   gtk_button_new_with_label("Container");
    GtkWidget *btn10    =   gtk_button_new_with_label("Entry");

    FlowBox_add(flow,btn1,-1);
    FlowBox_add(flow,btn2,-1);
    FlowBox_add(flow,btn3,-1);
    FlowBox_add(flow,btn4,-1);
    FlowBox_add(flow,btn5,-1);
    FlowBox_add(flow,btn6,-1);
    FlowBox_add(flow,btn7,-1);
    FlowBox_add(flow,btn8,-1);
    FlowBox_add(flow,btn9,-1);
    FlowBox_add(flow,btn10,-1);

    gtk_container_add( GTK_CONTAINER(left) , flow->this );

    //  setting some spacing
    gtk_container_set_border_width ( GTK_CONTAINER(left), 10);
    gtk_container_set_border_width ( GTK_CONTAINER(flow->this), 10);

    return (left);
}