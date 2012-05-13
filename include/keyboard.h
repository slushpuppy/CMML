#ifndef __keyboard_h_
#define __keyboard_h_

#include "mml.h"

extern void keyboardDown(keyboardKey key);
extern void keyboardUp(keyboardKey key);

extern void keyboardPress(keyboardKey key);

extern uint32_t keyboardSend(char *str);

#endif
