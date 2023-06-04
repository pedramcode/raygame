#include "app.h"

void appFree(App_t *app){
    for(int i = 0 ; i < app->stateCount ; i++){
        free(app->states[i]);
    }
    free(app->title);
    free(app->currentStateName);
    free(app);
}