#ifndef BRIGHTNESS_H
#define BRIGHTNESS_H

#include <X11/Xatom.h>
#include <X11/Xlib.h>
#include <X11/extensions/Xrandr.h>

class Brightness
{
private:
    Display *dpy;
	Atom backlight;
	Window root;
	XRRScreenResources *resources;
	RROutput output;
	XRRPropertyInfo *info;
	double min, max;
	long value;


public:
    Brightness();
    void setBrightness(float percent);
};

#endif
