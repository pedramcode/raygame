#include "app.h"

void appAddState(App_t *app, StateAbstract_t *state) {
    app->stateCount++;
    app->states = realloc(app->states, sizeof(StateAbstract_t *) * app->stateCount);
    app->states[app->stateCount - 1] = state;
    state->appPtr = app;
//    app->currentStateName = state->name;
}