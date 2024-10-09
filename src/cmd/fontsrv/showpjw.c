#include <u.h>
#include <libc.h>
#include <draw.h>
#include <event.h>

void eresized(int);

void
main(void)
{
	initdraw(nil, nil, nil);

	einit(Emouse);
	eresized(0);
	for(;;)
		emouse();
}

void
eresized(int new)
{
	Point p;
	int i;
	char buf[100];
	char *sample = "1234567890abcdef[];{}->>==lLgUnknown char: \xe1\x88\xb4";

	if(new && getwindow(display, Refnone) < 0)
		sysfatal("getwindow: %r");

	p = addpt(screen->r.min, Pt(10, 10));
	draw(screen, screen->r, display->white, nil, ZP);
	for(i=10; i<=50; i+=i/10) {
		sprint(buf, "/mnt/font/LucidaGrande/%da/font", i);
		font = openfont(display, buf);
		sprint(buf, "%d: %s", i, sample);
		string(screen, p, display->black, ZP, font, buf);
		p.y += stringsize(font, buf).y;
	}
	flushimage(display, 1);
}
