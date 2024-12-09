#include <gtk/gtk.h>

#include "tpeapp.h"

int main(int argc, char **argv)
{
    return g_application_run(G_APPLICATION(tpe_app_new()), argc, argv);
}
