#ifndef ACTIVATE_H
#define ACTIVATE_H

#include <gtk/gtk.h>
#include "brightness.h"

class Activate
{

    public:
        static Brightness brightness;
        static void show(GtkApplication* app, gpointer user_data);
        static void handleChange(GtkRange *range);
};

#endif
