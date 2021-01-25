#include "brightness.h"

Brightness::Brightness()
{
    dpy = XOpenDisplay(NULL);
	backlight = XInternAtom (dpy, "Backlight", True);
	root = RootWindow(dpy, 0);
	resources = XRRGetScreenResources(dpy, root);
	output = resources->outputs[0];
	info = XRRQueryOutputProperty(dpy, output, backlight);
	min = info->values[0];
	max = info->values[1];
}

static Brightness *getInstance() {
    if (!Brightness::instance)
    Brightness::instance = new Brightness;
    return Brightness::instance;
}

void Brightness::setBrightness(float percent)
{
    value = percent * (max - min) + min;

    XRRChangeOutputProperty(
        dpy, output, backlight, XA_INTEGER,
		32, PropModeReplace, (unsigned char *) &value, 1
    );

    XFlush(dpy);
	XSync(dpy, False);
}


void Brightness::change(GtkRange *range, gpointer  user_data)
{
    Brightness *brightness = Brightness::getInstance();
    double r = gtk_range_get_value(range);
    brightness->setBrightness(0.5);
}
