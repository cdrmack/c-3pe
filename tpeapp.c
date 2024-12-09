#include <gtk/gtk.h>

#include "tpeapp.h"
#include "tpeappwin.h"

struct _TpeApp
{
    GtkApplication parent;
};

G_DEFINE_TYPE(TpeApp, tpe_app, GTK_TYPE_APPLICATION);

static void tpe_app_init(TpeApp *app) {}

static void tpe_app_activate(GApplication *app)
{
    TpeAppWindow *win;

    win = tpe_app_window_new(TPE_APP(app));
    gtk_window_set_title(GTK_WINDOW(win), "Window");
    gtk_window_set_default_size(GTK_WINDOW(win), 400, 200);
    gtk_window_present(GTK_WINDOW(win));
}

static void tpe_app_class_init(TpeAppClass *class)
{
    G_APPLICATION_CLASS(class)->activate = tpe_app_activate;
}

TpeApp *tpe_app_new(void)
{
    return g_object_new(TPE_APP_TYPE, "application-id", NULL, "flags",
                        G_APPLICATION_HANDLES_OPEN, NULL);
}
