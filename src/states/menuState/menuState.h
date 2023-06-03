#ifndef RAYGAME_MENUSTATE_H
#define RAYGAME_MENUSTATE_H

#include "stateAbstract.h"
#include <malloc.h>
#include <string.h>
#include <raylib.h>

typedef struct {
    STATE_IMPL
} MenuState_t;

void menuStateRender(void* state);
void menuStateUpdate(void* state);
void menuStateOnEnter(void* state);
void menuStateOnExit(void* state);

MenuState_t *menuStateCreate(char *name);

#endif //RAYGAME_MENUSTATE_H
