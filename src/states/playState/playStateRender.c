#include "playState.h"

void playStateRender(void *state) {
    ClearBackground(RAYWHITE);
    DrawText("Home (main state)", 20, 20, 25, DARKGRAY);
    DrawText("This state loaded dynamically using my game engine.", 20, 80, 20, DARKGRAY);
    DrawText("I'm a proud father :)", 20, 110, 20, DARKGRAY);
    DrawText("The infrastructure is raylib.", 20, 140, 20, DARKGRAY);
    DrawText("ECS - will be the architecture.", 20, 170, 20, DARKGRAY);
    DrawText("- Pedram", GetRenderWidth() - 200, 230, 15, DARKGRAY);
}