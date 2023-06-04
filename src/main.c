#include "app.h"
#include "states/playState/playState.h"

void load_assets(App_t *app);

int main() {
    App_t *app = appCreate(640, 480, "Raygame :D");

    PlayState_t *playState = playStateCreate("play");
    REGISTER_STATE(app, playState);

    appSetState(app, "play");

    return appExecute(app);
}
