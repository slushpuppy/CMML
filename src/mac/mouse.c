#include "mouse.h"
#include "os.h"

void mouseMove(uint32_t x, uint32_t y)
{
	CGPoint point;
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
	CGPoint point;
	memset(&point, 0, sizeof(point));
	
	CGEventRef event;
	memset(event, 0, sizeof(event));
	
	event = CGEventCreate(NULL);
	point = CGEventGetLocation(event);
	CFRelease(event);
	
	*x = point.x;
	*y = point.y;
}

static inline void _b2b(mouseButton button, bool up, CGMouseButton *b, CGEventType *t)
{
	switch (button) {
		case mouseLeft:
			*b = kCGMouseButtonLeft;
			*t = (up) ? kCGEventLeftMouseUp : kCGEventLeftMouseDown;
			break;
		case mouseRight:
			*b = kCGMouseButtonRight;
			*t = (up) ? kCGEventRightMouseUp : kCGEventRightMouseDown;
			break;
		case mouseMiddle:
			*b = kCGMouseButtonMiddle;
			*t = (up) ? kCGEventMiddleMouseUp : kCGEventMiddleMouseDown;
			break;
		default: _b2b(mouseLeft, up, b, t);
	}
}

static inline void _mouseEvent(CGMouseButton button, CGEventType type)
{
	CGEventRef event;
	memset(&event, 0, sizeof(event));

	CGPoint point;
	memset(&point, 0, sizeof(point));

	event = CGEventCreate(NULL);
	point = CGEventGetLocation(event);
	CFRelease(event);

	memset(&event, 0, sizeof(event));

	event = CGEventCreateMouseEvent(NULL, type, point, button);
	CGEventPost(kCGHIDEventTap, event);
	CFRelease(event);
}

void mouseDown(mouseButton button)
{
	CGMouseButton b = kCGMouseButtonLeft;
	CGEventType t = kCGEventNull;
	
	_b2b(button, false, &b, &t);
	
	_mouseEvent(b, t);	
}

void mouseUp(mouseButton button)
{
	CGMouseButton b = kCGMouseButtonLeft;
	CGEventType t = kCGEventNull;
	
	_b2b(button, true, &b, &t);

	_mouseEvent(b, t);
}
