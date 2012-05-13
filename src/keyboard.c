#include "keyboard.h"

void keyboardPress(keyboardKey key)
{
	keyboardDown(key);
	keyboardUp(key);
}

