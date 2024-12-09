#pragma once

#include <gtk/gtk.h>

#define TPE_APP_TYPE (tpe_app_get_type())
G_DECLARE_FINAL_TYPE(TpeApp, tpe_app, TPE, APP, GtkApplication)

TpeApp *tpe_app_new(void);
