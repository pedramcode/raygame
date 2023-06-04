#ifndef RAYGAME_APP_H
#define RAYGAME_APP_H

#include <stdbool.h>
#include <malloc.h>
#include "raylib.h"
#include <string.h>
#include "stateAbstract.h"
#include "resourceManager.h"

#define REGISTER_STATE(app, state) (appAddState(app, (StateAbstract_t *) state))

typedef struct {
    bool isRunning;
    int width;
    int height;
    char *title;

    ResourceManager_t *images;
    ResourceManager_t *fonts;
    ResourceManager_t *waves;
    ResourceManager_t *sounds;
    ResourceManager_t *musics;

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

void appAddImage(App_t *app, Image *img, char *name);

void appAddFont(App_t *app, Font *font, char *name);

void appAddWave(App_t *app, Wave *wave, char *name);

void appAddSound(App_t *app, Sound *sound, char *name);

void appAddMusic(App_t *app, Music *music, char *name);

Image *appGetImage(App_t *app, char *name);

Font *appGetFont(App_t *app, char *name);

Wave *appGetWave(App_t *app, char *name);

Sound *appGetSound(App_t *app, char *name);

Music *appGetMusic(App_t *app, char *name);

#endif //RAYGAME_APP_H
