void menuDialog_apropos(GtkWidget *widget, gpointer data) {

	GdkPixbuf *pixbuf = gdk_pixbuf_new_from_file("img/logo-sm.png", NULL);
	const gchar *names[] ={ "LAGHEZALI Mohamed Reda","ELKAISSI Souhail", NULL}; 

	GtkWidget *dialog = gtk_about_dialog_new();
	gtk_about_dialog_set_program_name(GTK_ABOUT_DIALOG(dialog), "Shanks");
	gtk_window_set_position(GTK_WINDOW(dialog), GTK_WIN_POS_CENTER);

	gtk_about_dialog_set_version(GTK_ABOUT_DIALOG(dialog), "version 1.7");

	gtk_about_dialog_set_copyright(GTK_ABOUT_DIALOG(dialog), utf8("(C) Tous les droits sont réservés") );
	
	gtk_about_dialog_set_comments(GTK_ABOUT_DIALOG(dialog),
			"Shanks est un logiciel pc qui a comme objectif de realiser des interface graphique" 
			"mais aussi des calcule arithmétique et la manipulation des structures. Tous ça en"
			"suivant un et un seul langage que les créateurs ont baptisé 'ShankScript'.");

	gtk_about_dialog_set_authors (GTK_ABOUT_DIALOG(dialog), names);

	gtk_about_dialog_set_website(GTK_ABOUT_DIALOG(dialog),"http://www.fstm.ac.ma");
	gtk_about_dialog_set_website_label (GTK_ABOUT_DIALOG(dialog), "Notre Site Web");

	gtk_about_dialog_set_logo(GTK_ABOUT_DIALOG(dialog), pixbuf);

	gtk_about_dialog_set_license (GTK_ABOUT_DIALOG(dialog),"Logiciel Libre - Open Source");

	
	
	g_object_unref(pixbuf), pixbuf = NULL;
	gtk_dialog_run(GTK_DIALOG(dialog));
	gtk_widget_destroy(dialog);
}