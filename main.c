#include <gtk/gtk.h>

typedef struct App
{
    // labels
    GtkWidget *worst_label;
    GtkWidget *likely_label;
    GtkWidget *best_label;

    // input fields
    GtkWidget *worst_input;
    GtkWidget *likely_input;
    GtkWidget *best_input;

    // button
    GtkWidget *calculate_button;

    // box
    GtkWidget *v_box;
} App;

static void print_result(GtkWidget *widget, gpointer data)
{
    g_print("button clicked\n");

    GtkEntry *entry = GTK_ENTRY(data);
    GtkEntryBuffer *buffer = gtk_entry_get_buffer(entry);
    g_print("buffer %s\n", gtk_entry_buffer_get_text(buffer));
}

static void app_init(App *app)
{
    app->worst_label = gtk_label_new("worst");
    app->likely_label = gtk_label_new("likely");
    app->best_label = gtk_label_new("best");

    app->worst_input = gtk_entry_new();
    app->likely_input = gtk_entry_new();
    app->best_input = gtk_entry_new();

    app->calculate_button = gtk_button_new_with_label("calculate");
    g_signal_connect(app->calculate_button, "clicked", G_CALLBACK(print_result),
                     app->worst_input);

    app->v_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
}

static void app_set_layout(App *app)
{
    GtkWidget *labels_box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
    gtk_box_set_homogeneous(GTK_BOX(labels_box), true);
    gtk_box_append(GTK_BOX(labels_box), app->worst_label);
    gtk_box_append(GTK_BOX(labels_box), app->likely_label);
    gtk_box_append(GTK_BOX(labels_box), app->best_label);

    GtkWidget *inputs_box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
    gtk_box_set_homogeneous(GTK_BOX(inputs_box), true);
    gtk_box_append(GTK_BOX(inputs_box), app->worst_input);
    gtk_box_append(GTK_BOX(inputs_box), app->likely_input);
    gtk_box_append(GTK_BOX(inputs_box), app->best_input);

    GtkWidget *empty = gtk_label_new("");

    gtk_box_append(GTK_BOX(app->v_box), labels_box);
    gtk_box_append(GTK_BOX(app->v_box), inputs_box);
    gtk_box_append(GTK_BOX(app->v_box), empty);
    gtk_box_append(GTK_BOX(app->v_box), app->calculate_button);

    gtk_widget_set_margin_start(app->v_box, 10);
    gtk_widget_set_margin_end(app->v_box, 10);
    gtk_widget_set_margin_top(app->v_box, 10);
    gtk_widget_set_margin_bottom(app->v_box, 10);
}

static void activate(GtkApplication *gtk_app, gpointer user_data)
{
    GtkWidget *window = gtk_application_window_new(gtk_app);

    gtk_window_set_title(GTK_WINDOW(window), "Window");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 200);

    App app = {0};
    app_init(&app);
    app_set_layout(&app);

    gtk_window_set_child(GTK_WINDOW(window), app.v_box);
    gtk_window_present(GTK_WINDOW(window));
}

int main(int argc, char **argv)
{
    GtkApplication *gtk_app =
        gtk_application_new(NULL, G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(gtk_app, "activate", G_CALLBACK(activate), NULL);
    int const status = g_application_run(G_APPLICATION(gtk_app), argc, argv);
    g_object_unref(gtk_app);

    return status;
}
