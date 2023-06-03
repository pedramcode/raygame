#include "app.h"

App_t *app_create(int width, int height, char *title){
    App_t *app = (App_t*) malloc(sizeof(App_t));
    app->width = width;
    app->height = height;
    app->title = malloc(strlen(title)+1);
    strcpy(app->title, title);
    InitWindow(width, height, title);
    return app;
}

int app_execute(App_t *app){
    SetTargetFPS(60);

    while(!WindowShouldClose()){
        BeginDrawing();

        ClearBackground(RAYWHITE);
        DrawText("Happy Happy Happy", 10, 10, 20, DARKGRAY);

        EndDrawing();
    }

    CloseWindow();
    free(app->title);
    return 0;
}