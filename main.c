#include <gtk/gtk.h>

static void print_result(GtkWidget *widget, gpointer data)
{
    g_print("button clicked");
}

static void activate(GtkApplication *app, gpointer user_data)
{
    GtkWidget *window = gtk_application_window_new(app);

    gtk_window_set_title(GTK_WINDOW(window), "Window");
    gtk_window_set_default_size(GTK_WINDOW(window), 800, 400);

    GtkWidget *button = gtk_button_new_with_label("calculate");
    g_signal_connect(button, "clicked", G_CALLBACK(print_result), NULL);

    GtkWidget *foo = gtk_label_new("foo");
    GtkWidget *bar = gtk_label_new("bar");
    GtkWidget *baz = gtk_label_new("baz");

    GtkWidget *h_box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
    gtk_box_append(GTK_BOX(h_box), foo);
    gtk_box_append(GTK_BOX(h_box), bar);
    gtk_box_append(GTK_BOX(h_box), baz);

    GtkWidget *v_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_box_append(GTK_BOX(v_box), h_box);
    gtk_box_append(GTK_BOX(v_box), button);

    gtk_window_set_child(GTK_WINDOW(window), v_box);
    gtk_window_present(GTK_WINDOW(window));
}

int main(int argc, char **argv)
{
    GtkApplication *app =
        gtk_application_new(NULL, G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    int const status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    return status;
}
