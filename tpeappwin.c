#include <gtk/gtk.h>

#include "tpeapp.h"
#include "tpeappwin.h"

struct _TpeAppWindow
{
    GtkApplicationWindow parent;

    GtkWidget *worst_label;
    GtkWidget *likely_label;
    GtkWidget *best_label;
    GtkWidget *labels_box;
};

G_DEFINE_TYPE(TpeAppWindow, tpe_app_window, GTK_TYPE_APPLICATION_WINDOW);

static void tpe_app_window_init(TpeAppWindow *win)
{
    win->worst_label = gtk_label_new("worst");
    win->likely_label = gtk_label_new("likely");
    win->best_label = gtk_label_new("best");

    win->labels_box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
    gtk_box_set_homogeneous(GTK_BOX(win->labels_box), true);
    gtk_box_append(GTK_BOX(win->labels_box), win->worst_label);
    gtk_box_append(GTK_BOX(win->labels_box), win->likely_label);
    gtk_box_append(GTK_BOX(win->labels_box), win->best_label);

    gtk_window_set_child(GTK_WINDOW(win), win->labels_box);
}

static void tpe_app_window_class_init(TpeAppWindowClass *class) {}

TpeAppWindow *tpe_app_window_new(TpeApp *app)
{
    return g_object_new(TPE_APP_WINDOW_TYPE, "application", app, NULL);
}
