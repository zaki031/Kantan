#include <gtk/gtk.h>

int main(int argc, char *argv[]) {
    GtkWidget *window;
    GtkWidget *label;
    gtk_init(&argc, &argv);
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_default_size(GTK_WINDOW(window), 800, 600);

    label = gtk_label_new("Kantan (簡単),   A simple, easy to use text editor");
    gtk_container_add(GTK_CONTAINER(window), label);
    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}
 