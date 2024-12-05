#include <gtk/gtk.h>

static void print_result(GtkWidget *widget, gpointer data)
{
    g_print("button clicked");
}

static void create_labels(GtkWidget *labels_box)
{
    GtkWidget *worst = gtk_label_new("worst");
    GtkWidget *likely = gtk_label_new("likely");
    GtkWidget *best = gtk_label_new("best");

    gtk_box_set_homogeneous(GTK_BOX(labels_box), true);
    gtk_box_append(GTK_BOX(labels_box), worst);
    gtk_box_append(GTK_BOX(labels_box), likely);
    gtk_box_append(GTK_BOX(labels_box), best);
}

static void create_inputs(GtkWidget *input_box)
{
    GtkWidget *worst_input = gtk_entry_new();
    GtkWidget *likely_input = gtk_entry_new();
    GtkWidget *best_input = gtk_entry_new();

    gtk_box_set_homogeneous(GTK_BOX(input_box), true);
    gtk_box_append(GTK_BOX(input_box), worst_input);
    gtk_box_append(GTK_BOX(input_box), likely_input);
    gtk_box_append(GTK_BOX(input_box), best_input);
}

static void activate(GtkApplication *app, gpointer user_data)
{
    GtkWidget *window = gtk_application_window_new(app);

    gtk_window_set_title(GTK_WINDOW(window), "Window");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 200);

    GtkWidget *labels_box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
    create_labels(labels_box);

    GtkWidget *inputs_box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
    create_inputs(inputs_box);

    GtkWidget *empty = gtk_label_new("");

    GtkWidget *button = gtk_button_new_with_label("calculate");
    g_signal_connect(button, "clicked", G_CALLBACK(print_result), NULL);

    GtkWidget *v_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_box_append(GTK_BOX(v_box), labels_box);
    gtk_box_append(GTK_BOX(v_box), inputs_box);
    gtk_box_append(GTK_BOX(v_box), empty);
    gtk_box_append(GTK_BOX(v_box), button);

    gtk_widget_set_margin_start(v_box, 10);
    gtk_widget_set_margin_end(v_box, 10);
    gtk_widget_set_margin_top(v_box, 10);
    gtk_widget_set_margin_bottom(v_box, 10);

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
