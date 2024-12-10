#include <gtk/gtk.h>

#include "tpeapp.h"
#include "tpeappwin.h"

struct _TpeAppWindow
{
    GtkApplicationWindow parent;
};

G_DEFINE_TYPE(TpeAppWindow, tpe_app_window, GTK_TYPE_APPLICATION_WINDOW);

static void tpe_app_window_init(TpeAppWindow *win)
{
    // TODO
}

static void tpe_app_window_class_init(TpeAppWindowClass *class)
{
    // TODO
}

TpeAppWindow *tpe_app_window_new(TpeApp *app)
{
    return g_object_new(TPE_APP_WINDOW_TYPE, "application", app, NULL);
}
