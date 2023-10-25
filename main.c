#include <gtk/gtk.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char* read_file(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    rewind(file);

    char* file_contents = (char*)malloc(file_size + 1);
    if (file_contents == NULL) {
        fclose(file);
        return NULL;
    }
    fread(file_contents, 1, file_size, file);
    file_contents[file_size] = '\0';
    fclose(file);
    return file_contents;
}

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);
    
    const char* filename = "h.txt";
    char* file_contents = read_file(filename);
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Kantan_簡単");
    gtk_window_set_default_size(GTK_WINDOW(window), 1000, 500);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    GtkWidget *text_view = gtk_text_view_new();
    gtk_container_add(GTK_CONTAINER(window), text_view);
    GtkTextBuffer *buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(text_view));
    char* placeholder_text = file_contents;
    gtk_text_buffer_set_text(buffer, placeholder_text, -1);
    gtk_widget_show_all(window);
    gtk_main();
    free(file_contents); 
    return 0;
}
