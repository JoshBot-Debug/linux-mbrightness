#include "brightness.h"
#include <iostream>
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

	std::cout << value << std::endl;

	// XRRScreenConfiguration *r = XRRGetScreenInfo(dpy, root);
	// RROutput r = XRRGetOutputPrimary(dpy, root);
	
	// std::cout << r << std::endl;

    XRRChangeOutputProperty(
        dpy, output, backlight, XA_INTEGER,
		32, PropModeReplace, (unsigned char *) &value, 1
    );

    XFlush(dpy);
	XSync(dpy, False);
}