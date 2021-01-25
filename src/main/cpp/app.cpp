#include <gtk/gtk.h>

#include <iostream>
#include <stdio.h>

#include "activate.h"
#include "brightness.h"


int main(int argc, char *argv[])
{
	GtkApplication *app;
	int status;

	Brightness brightnessController;
	brightnessController.setBrightness(atof(argv[1]));


	app = gtk_application_new("org.gtk.example", G_APPLICATION_FLAGS_NONE);
	g_signal_connect(app, "activate", G_CALLBACK (Activate::activate), NULL);

	int argd;
	char **argx;

	status = g_application_run(G_APPLICATION (app), argd, argx);
	g_object_unref(app);

	return status;
}
