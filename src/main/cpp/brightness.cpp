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