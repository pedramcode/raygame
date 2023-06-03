#include "app.h"
#include "states/playState/playState.h"
#include "states/menuState/menuState.h"

int main() {
    App_t *app = appCreate(640, 480, "Raygame :D");

    PlayState_t *playState = playStateCreate("play");
    ADD_STATE(app, playState);

    MenuState_t *menuState = menuStateCreate("menu");
    ADD_STATE(app, menuState);

    appSetState(app, "play");

    return appExecute(app);
}