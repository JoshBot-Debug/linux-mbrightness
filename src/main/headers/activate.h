#ifndef ACTIVATE_H
#define ACTIVATE_H

#include <gtk/gtk.h>
#include <gdk/gdkkeysyms.h>
#include "brightness.h"

class Activate
{

    public:
        static Brightness brightness;
        static void show(GtkApplication* app, gpointer user_data);
        static void handleChange(GtkRange *range);
        static void keyboardEvent(GtkWidget *widget, GdkEventKey *event, gpointer data);
};

#endif
