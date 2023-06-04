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

    app->images = resourceNewManager(IMAGE);
    app->fonts = resourceNewManager(FONT);
    app->waves = resourceNewManager(WAVE);
    app->sounds = resourceNewManager(SOUND);
    app->musics = resourceNewManager(MUSIC);

    return app;
}