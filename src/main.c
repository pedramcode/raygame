#include "app.h"

int main(){
    App_t *app = app_create(640, 480, "Raygame :D");
    return app_execute(app);
}