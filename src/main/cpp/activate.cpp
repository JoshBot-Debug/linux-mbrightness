#include <gtk/gtk.h>
#include <gdk/gdkkeysyms.h>

#include "activate.h"

Brightness Activate::brightness;

void Activate::show(GtkApplication* app, gpointer user_data)
{
    GtkWidget *window;
    GtkWidget *box; 
    GtkWidget *range;
    GtkStyleContext *context;
    GtkCssProvider *cssProvider;

    window = gtk_application_window_new (app);
    gtk_window_set_default_size (GTK_WINDOW (window), 300, 50);
    gtk_window_set_decorated(GTK_WINDOW (window), false);
    gtk_window_set_skip_taskbar_hint(GTK_WINDOW (window), false);
    gtk_window_set_resizable(GTK_WINDOW (window), false);

    gtk_widget_add_events(window, GDK_KEY_PRESS_MASK);
    g_signal_connect (G_OBJECT (window), "key_press_event", G_CALLBACK (keyboardEvent), NULL);

    box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    gtk_container_add(GTK_CONTAINER(window), box);


	range = gtk_scale_new_with_range(GTK_ORIENTATION_HORIZONTAL,0,100,1);

    gtk_container_add(GTK_CONTAINER(box), range);

    g_signal_connect(range, "value-changed", G_CALLBACK (handleChange), NULL);


    cssProvider = gtk_css_provider_new();
    gtk_css_provider_load_from_path(cssProvider, "src/main/css/theme.css", NULL);
    
    context = gtk_widget_get_style_context(GTK_WIDGET(window));                                     
    gtk_style_context_add_provider(context, GTK_STYLE_PROVIDER(cssProvider), GTK_STYLE_PROVIDER_PRIORITY_USER);

    context = gtk_widget_get_style_context(GTK_WIDGET(box));                                     
    gtk_style_context_add_provider(context, GTK_STYLE_PROVIDER(cssProvider), GTK_STYLE_PROVIDER_PRIORITY_USER);

    context = gtk_widget_get_style_context(GTK_WIDGET(range));                                      
    gtk_style_context_add_provider(context, GTK_STYLE_PROVIDER(cssProvider), GTK_STYLE_PROVIDER_PRIORITY_USER);

    gtk_widget_show_all(window);
}


void Activate::handleChange(GtkRange *range){
    double r = gtk_range_get_value(range);
    brightness.setBrightness((r/100));
}

void Activate::keyboardEvent(GtkWidget *widget, GdkEventKey *event, gpointer data){
    // double r = gtk_range_get_value(range);
    // brightness.setBrightness((r/100));

        printf("GDK_KEY_Control_L event");
    if (event->keyval == GDK_KEY_space){
    }
}
