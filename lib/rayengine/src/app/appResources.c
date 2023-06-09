#include "app.h"

void appAddTexture(App_t *app, Texture2D *texture, char *name) {
    resourceAdd(app->textures, name, (void *) texture);
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


Texture2D *appGetTexture(App_t *app, char *name) {
    Resource_t *r = resourceGet(app->textures, name);
    if (r == NULL) return NULL;
    return (Texture2D *) r->resource;
}

Font *appGetFont(App_t *app, char *name) {
    Resource_t *r = resourceGet(app->fonts, name);
    if (r == NULL) return NULL;
    return (Font *) r->resource;
}

Wave *appGetWave(App_t *app, char *name) {
    Resource_t *r = resourceGet(app->waves, name);
    if (r == NULL) return NULL;
    return (Wave *) r->resource;
}

Sound *appGetSound(App_t *app, char *name) {
    Resource_t *r = resourceGet(app->sounds, name);
    if (r == NULL) return NULL;
    return (Sound *) r->resource;
}

Music *appGetMusic(App_t *app, char *name) {
    Resource_t *r = resourceGet(app->musics, name);
    if (r == NULL) return NULL;
    return (Music *) r->resource;
}