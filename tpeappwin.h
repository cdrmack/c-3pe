#pragma once

#include <gtk/gtk.h>

#include "tpeapp.h"

#define TPE_APP_WINDOW_TYPE (tpe_app_window_get_type())
G_DECLARE_FINAL_TYPE(TpeAppWindow, tpe_app_window, TPE, APP_WINDOW,
                     GtkApplicationWindow)

TpeAppWindow *tpe_app_window_new(TpeApp *app);
