#ifndef ACTIVATE_H
#define ACTIVATE_H

#include <gtk/gtk.h>

class Activate
{
    public:
        static void activate(GtkApplication* app, gpointer user_data);
};

#endif
