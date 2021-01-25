#include <gtk/gtk.h>

#include <iostream>
#include "activate.h"

#include "brightness.h"

int main(int argc, char *argv[])
{
	GtkApplication *app;
	int status;

	Brightness brightnessController;
	brightnessController.setBrightness(100);

	app = gtk_application_new("org.gtk.example", G_APPLICATION_FLAGS_NONE);
	g_signal_connect(app, "activate", G_CALLBACK (Activate::activate), NULL);

	status = g_application_run(G_APPLICATION (app), argc, argv);
	g_object_unref(app);

	return status;
}
