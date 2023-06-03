#include "playState.h"

PlayState_t *playStateCreate(char *name) {
    PlayState_t *state = malloc(sizeof(PlayState_t));
    state->render = playStateRender;
    state->update = playStateUpdate;
    state->onEnter = playStateOnEnter;
    state->onExit = playStateOnExit;
    state->name = malloc(sizeof(name) + 1);
    strcpy(state->name, name);
    return state;
}
