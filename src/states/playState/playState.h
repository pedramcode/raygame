#ifndef RAYGAME_PLAYSTATE_H
#define RAYGAME_PLAYSTATE_H

#include "stateAbstract.h"
#include <malloc.h>
#include <string.h>
#include <raylib.h>
#include "app.h"

typedef struct {
    STATE_IMPL
} PlayState_t;

void playStateRender(void* state);
void playStateUpdate(void* state);
void playStateOnEnter(void* state);
void playStateOnExit(void* state);

PlayState_t *playStateCreate(char *name);

#endif //RAYGAME_PLAYSTATE_H
