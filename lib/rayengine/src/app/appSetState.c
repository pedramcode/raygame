#include "app.h"

void appSetState(App_t *app, char *name) {
    unsigned char found = 0;
    for (int i = 0; i < app->stateCount; i++) {
        StateAbstract_t *state = (StateAbstract_t *) app->states[i];
        if (strcmp(state->name, name) == 0) {
            found = 1;
            break;
        }
    }

    if (found == 0) {
        fprintf(stderr, "State not found %s\n", name);
        return;
    }

    if (appGetCurrentState(app) != NULL)
        appGetCurrentState(app)->onExit(appGetCurrentStateRawPointer(app));
    app->currentStateName = malloc(sizeof(name) + 1);
    strcpy(app->currentStateName, name);
    appGetCurrentState(app)->onEnter(appGetCurrentStateRawPointer(app));
}