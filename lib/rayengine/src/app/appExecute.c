#include "app.h"


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
    appFree(app);
    return 0;
}