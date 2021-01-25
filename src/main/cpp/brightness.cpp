#include "brightness.h"

Brightness::Brightness()
{
    screen = 0;
    o = 0;
    dpy = XOpenDisplay(NULL);
	backlight = XInternAtom (dpy, "Backlight", True);
	root = RootWindow(dpy, screen);
	resources = XRRGetScreenResources(dpy, root);
	output = resources->outputs[o];
	info = XRRQueryOutputProperty(dpy, output, backlight);
	min = info->values[0];
	max = info->values[1];
}


void Brightness::setBrightness(int percent)
{
    value = (percent/100) * (max - min) + min;

    XRRChangeOutputProperty(dpy, output, backlight, XA_INTEGER,
					32, PropModeReplace, (unsigned char *) &value, 1);

    XFlush(dpy);
	XSync(dpy, False);
}
