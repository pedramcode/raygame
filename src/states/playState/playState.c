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

void playStateRender(void *state) {
    ClearBackground(RAYWHITE);
    DrawText("Happy Happy Happy", 10, 10, 20, DARKGRAY);
}

void playStateUpdate(void *state) {}

void playStateOnEnter(void *state) {
    fprintf(stdout, "Play on enter\n");
}

void playStateOnExit(void *state) {
    fprintf(stdout, "Play on exit\n");
}