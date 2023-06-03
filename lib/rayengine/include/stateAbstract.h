#ifndef RAYGAME_STATEABSTRACT_H
#define RAYGAME_STATEABSTRACT_H

#define STATE_IMPL \
    char *name;                   \
    void (*render)(void*);         \
    void (*update)(void*);         \
    void (*onEnter)(void*);        \
    void (*onExit)(void*);        \
    void *appPtr;

#define GET_APP(_state) ((App_t *) (((StateAbstract_t*)_state)->appPtr))

typedef struct {
    STATE_IMPL
} StateAbstract_t;

#endif //RAYGAME_STATEABSTRACT_H
