#include "app.h"

void appAddImage(App_t *app, Image *img, char *name) {
    resourceAdd(app->images, name, (void *) img);
}

void appAddFont(App_t *app, Font *font, char *name) {
    resourceAdd(app->fonts, name, (void *) font);
}

void appAddWave(App_t *app, Wave *wave, char *name) {
    resourceAdd(app->waves, name, (void *) wave);
}

void appAddSound(App_t *app, Sound *sound, char *name) {
    resourceAdd(app->sounds, name, (void *) sound);
}

void appAddMusic(App_t *app, Music *music, char *name) {
    resourceAdd(app->musics, name, (void *) music);
}


Image *appGetImage(App_t *app, char *name) {
    Resource_t *r = resourceGet(app->images, name);
    if (r == NULL) return NULL;
    return (Image *) r;
}

Font *appGetFont(App_t *app, char *name) {
    Resource_t *r = resourceGet(app->fonts, name);
    if (r == NULL) return NULL;
    return (Font *) r;
}

Wave *appGetWave(App_t *app, char *name) {
    Resource_t *r = resourceGet(app->waves, name);
    if (r == NULL) return NULL;
    return (Wave *) r;
}

Sound *appGetSound(App_t *app, char *name) {
    Resource_t *r = resourceGet(app->sounds, name);
    if (r == NULL) return NULL;
    return (Sound *) r;
}

Music *appGetMusic(App_t *app, char *name) {
    Resource_t *r = resourceGet(app->musics, name);
    if (r == NULL) return NULL;
    return (Music *) r;
}