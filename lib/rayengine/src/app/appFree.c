#include "app.h"

void appFree(App_t *app){
    for(int i = 0 ; i < app->stateCount ; i++){
        free(app->states[i]);
    }
    free(app->title);
    free(app->currentStateName);

    resourceFree(app->textures);
    resourceFree(app->fonts);
    resourceFree(app->waves);
    resourceFree(app->sounds);
    resourceFree(app->musics);

    free(app);
}