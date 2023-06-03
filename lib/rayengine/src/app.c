#include "app.h"

App_t *appCreate(int width, int height, char *title) {
    App_t *app = (App_t *) malloc(sizeof(App_t));
    app->width = width;
    app->height = height;
    app->title = malloc(strlen(title) + 1);
    strcpy(app->title, title);
    InitWindow(width, height, title);

    app->stateCount = 0;
    app->states = malloc(sizeof(StateAbstract_t *) * app->stateCount);
    app->currentStateName = NULL;
    return app;
}

int appExecute(App_t *app) {
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();

        StateAbstract_t *state = appGetCurrentState(app);
        if (state != NULL) {
            state->update(appGetCurrentStateRawPointer(app));
            state->render(appGetCurrentStateRawPointer(app));
        }

        EndDrawing();
    }

    CloseWindow();
    free(app->title);
    return 0;
}

void appAddState(App_t *app, StateAbstract_t *state) {
    app->stateCount++;
    app->states = realloc(app->states, sizeof(StateAbstract_t *) * app->stateCount);
    app->states[app->stateCount - 1] = state;
    state->appPtr = app;
//    app->currentStateName = state->name;
}

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

void *appGetCurrentStateRawPointer(App_t *app) {
    if (app->currentStateName == NULL) {
        return NULL;
    }
    for (int i = 0; i < app->stateCount; i++) {
        StateAbstract_t *state = (StateAbstract_t *) app->states[i];
        if (strcmp(state->name, app->currentStateName) == 0) {
            return app->states[i];
        }
    }
    return NULL;
}

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

void appFree(App_t *app){
    for(int i = 0 ; i < app->stateCount ; i++){
        free(app->states[i]);
    }
    free(app->currentStateName);
    free(app);
}