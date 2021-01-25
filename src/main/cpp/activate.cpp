#include <gtk/gtk.h>

#include "activate.h"
#include "brightness.h"

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

    box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    gtk_container_add(GTK_CONTAINER(window), box);

	range = gtk_scale_new_with_range(GTK_ORIENTATION_HORIZONTAL,0,100,1);
    gtk_container_add(GTK_CONTAINER(box), range);

    g_signal_connect(range, "value-changed", G_CALLBACK (Brightness::change), NULL);


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