#include "app.h"
#include "states/playState/playState.h"

void load_assets(App_t *app);

int main() {
    App_t *app = appCreate(640, 480, "Raygame :D");

    load_assets(app);

    PlayState_t *playState = playStateCreate("play");
    REGISTER_STATE(app, playState);

    appSetState(app, "play");

    return appExecute(app);
}

void load_assets(App_t *app){
    Image img = LoadImage("assets/images/bot.png");
    appAddImage(app, &img, "me");
}