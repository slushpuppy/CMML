#include "mouse.h"

#include <string.h>

void mouseMove(uint32_t x, uint32_t y)
{
	GCPoint point;
	memset(&point, 0, sizeof(point));
	
	point.x = x; point.y = y;
	
	CGEventRef event;
	memset(&event, 0, sizeof(event));
	
	event = CGEventCreateMouseEvent(NULL, kCGEventMouseMoved, point, 0);
	
	CGEventPost(kCGHIDEventTap, event);
	CFRelease(event);
}

void mousePos(uint32_t *x, uint32_t *y)
{
	GCPoint point;
	memset(&point, 0, sizeof(point));
	
	GCEventRef event;
	memset(event, 0, sizeof(event));
	
	GCEventCreate(NULL);
	point = GCEventGetLocation(event);
	CFRelease(event);
	
	*x = point.x;
	*y = point.y;
}

static void _b2b(mouseButton button, int up, CGMouseButton *b, CGEventType *t)
{
	switch (button) {
		case mouseLeft:
			*b = kCGMouseButtonLeft;
			if (up) 
				*t = kCGEventLeftMouseUp;
			else 
				*t = kCGEventLeftMouseDown;
			break;
		case mouseRight:
			*b = kCGMouseButtonRight;
			if (up)
				*t = kCGEventRightMouseUp;
			else
				*t = kCGEventRightMouseDown;
			break;
		case mouseMiddle:
			*b = kCGMouseButtonMiddle;
			if (up)
				*t = kCGEventMiddleMouseUp;
			else
				*t = kCGEventMiddleMouseDown;
			break;
		default: _b2b(mouseLeft, up, b, t);
	}
}

void mouseDown(mouseButton button)
{
	CGMouseButton b = kCGMouseButtonLeft;
	CGEventType t = kCGEventNull;
	
	_b2b(button, 0, &b, &t);
	
	CGEventRef event;
	memset(&event, 0, sizeof(event));
	
	CGPoint point;
	memset(&point, 0, sizeof(point));
	
	mousePos(&point.x, &point.y);
	
	event = CGEventCreateMouseEvent(NULL, t, point, b);
	CGEventPost(kCGHIDEventTap, event);
	CFRelease(event);
}

void mouseUp(mouseButton button)
{
	CGMouseButton b = kCGMouseButtonLeft;
	CGEventType t = kCGEventNull;
	
	_b2b(button, 1, &b, &t);
	
	CGEventRef event;
	memset(&event, 0, sizeof(event));
	
	CGPoint point;
	memset(&point, 0, sizeof(point));
	
	mousePos(&point.x, &point.y);
	
	event = CGEventCreateMouseEvent(NULL, t, point, b);
	CGEventPost(kCGHIDEventTap, event);
	CFRelease(event);
}
