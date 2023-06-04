#include "app.h"

StateAbstract_t *appGetCurrentState(App_t *app) {
    if (app->currentStateName == NULL) {
        return NULL;
    }
    for (int i = 0; i < app->stateCount; i++) {
        StateAbstract_t *state = (StateAbstract_t *) app->states[i];
        if (strcmp(state->name, app->currentStateName) == 0) {
            return state;
        }
    }
    return NULL;
}