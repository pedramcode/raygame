#ifndef RAYGAME_APP_H
#define RAYGAME_APP_H

#include <stdbool.h>
#include <malloc.h>
#include <raylib.h>
#include <string.h>

typedef struct {
    bool is_running;
    int width;
    int height;
    char *title;
} App_t;

App_t *app_create(int width, int height, char *title);
int app_execute(App_t *app);

#endif //RAYGAME_APP_H
