#ifndef RAYGAME_APP_H
#define RAYGAME_APP_H

#include <stdbool.h>
#include <malloc.h>
#include <raylib.h>
#include <string.h>
#include <stateAbstract.h>

#define REGISTER_STATE(app,state) (appAddState(app, (StateAbstract_t *) state))

typedef struct {
    bool isRunning;
    int width;
    int height;
    char *title;

    void **states;
    size_t stateCount;
    char *currentStateName;
} App_t;

App_t *appCreate(int width, int height, char *title);
void appAddState(App_t *app, StateAbstract_t *state);
StateAbstract_t *appGetCurrentState(App_t *app);
void *appGetCurrentStateRawPointer(App_t *app);
void appSetState(App_t *app, char *name);
int appExecute(App_t *app);
void appFree(App_t *app);

#endif //RAYGAME_APP_H
