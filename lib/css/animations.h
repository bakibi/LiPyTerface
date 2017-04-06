void animation_fadeIn(GtkWidget *w)
{
    cssFileToWidget(w,"fadeIn");
    cssDataToWidget(w, " opacity: 1;");

}

void animation_fadeOut(GtkWidget *w)
{
    cssFileToWidget(w,"fadeOut");
    cssDataToWidget(w, " opacity: 0;");
}

