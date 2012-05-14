#include "mml.h"

Color RGB24ToColor(RGB24 rgb)
{
	Color color;
	memset(&color, 0, sizeof(color));
	memcpy(&color, &rgb, sizeof(rgb));
	return color;
}

Color RGB32ToColor(RGB32 rgb)
{
	Color color;
	memset(&color, 0, sizeof(color));
	memcpy(&color, &rgb, sizeof(rgb));
	return color;
}

RGB24 ColorToRGB24(Color color)
{
	RGB24 rgb;
	memset(&rgb, 0, sizeof(rgb));
	memcpy(&rgb, &color, sizeof(rgb));
	return rgb;
}

RGB32 ColorToRGB32(Color color)
{
	RGB32 rgb;
	memset(&rgb, 0, sizeof(rgb));
	memcpy(&rgb, &color, sizeof(rgb));
	return rgb;
}
