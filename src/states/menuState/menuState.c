#include "menuState.h"

MenuState_t *menuStateCreate(char *name) {
    MenuState_t *state = malloc(sizeof(MenuState_t));
    state->render = menuStateRender;
    state->update = menuStateUpdate;
    state->onEnter = menuStateOnEnter;
    state->onExit = menuStateOnExit;
    state->name = malloc(sizeof(name) + 1);
    strcpy(state->name, name);
    return state;
}

void menuStateRender(void *state) {
    ClearBackground(RAYWHITE);
    DrawText("Menu page!", 10, 10, 20, DARKGRAY);
}

void menuStateUpdate(void *state) {}

void menuStateOnEnter(void *state) {
    fprintf(stdout, "Menu on enter\n");
}

void menuStateOnExit(void *state) {
    fprintf(stdout, "Menu on enter\n");
}