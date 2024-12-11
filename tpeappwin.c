#include <gtk/gtk.h>

#include "tpeapp.h"
#include "tpeappwin.h"

struct _TpeAppWindow
{
    GtkApplicationWindow parent;

    // labels
    GtkWidget *worst_label;
    GtkWidget *likely_label;
    GtkWidget *best_label;
    GtkWidget *labels_box;

    // input fields
    GtkWidget *worst_input;
    GtkWidget *likely_input;
    GtkWidget *best_input;
    GtkWidget *inputs_box;

    // button
    GtkWidget *calculate_button;

    // box
    GtkWidget *v_box;
};

G_DEFINE_TYPE(TpeAppWindow, tpe_app_window, GTK_TYPE_APPLICATION_WINDOW);

static void print_result(GtkWidget *widget, gpointer data)
{
    g_print("button clicked\n");
}

static void tpe_app_window_init(TpeAppWindow *win)
{
    // v_box
    win->v_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);

    gtk_widget_set_margin_start(win->v_box, 10);
    gtk_widget_set_margin_end(win->v_box, 10);
    gtk_widget_set_margin_top(win->v_box, 10);
    gtk_widget_set_margin_bottom(win->v_box, 10);

    gtk_window_set_child(GTK_WINDOW(win), win->v_box);

    // labels
    win->worst_label = gtk_label_new("worst");
    win->likely_label = gtk_label_new("likely");
    win->best_label = gtk_label_new("best");
    win->labels_box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);

    gtk_box_set_homogeneous(GTK_BOX(win->labels_box), true);
    gtk_box_append(GTK_BOX(win->labels_box), win->worst_label);
    gtk_box_append(GTK_BOX(win->labels_box), win->likely_label);
    gtk_box_append(GTK_BOX(win->labels_box), win->best_label);

    // input fields
    win->worst_input = gtk_entry_new();
    win->likely_input = gtk_entry_new();
    win->best_input = gtk_entry_new();
    win->inputs_box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);

    gtk_box_set_homogeneous(GTK_BOX(win->inputs_box), true);
    gtk_box_append(GTK_BOX(win->inputs_box), win->worst_input);
    gtk_box_append(GTK_BOX(win->inputs_box), win->likely_input);
    gtk_box_append(GTK_BOX(win->inputs_box), win->best_input);

    // button
    win->calculate_button = gtk_button_new_with_label("calculate");
    g_signal_connect(win->calculate_button, "clicked", G_CALLBACK(print_result),
                     win->worst_input);

    gtk_box_append(GTK_BOX(win->v_box), win->labels_box);
    gtk_box_append(GTK_BOX(win->v_box), win->inputs_box);
    gtk_box_append(GTK_BOX(win->v_box), win->calculate_button);
}

static void tpe_app_window_class_init(TpeAppWindowClass *class) {}

TpeAppWindow *tpe_app_window_new(TpeApp *app)
{
    return g_object_new(TPE_APP_WINDOW_TYPE, "application", app, NULL);
}
