#ifndef RAYGAME_ENTITY_H
#define RAYGAME_ENTITY_H

#include "malloc.h"
#include <stdlib.h>
#include <string.h>
#include "utils/uid.h"

typedef struct {
    char *id;
} Entity_t;

Entity_t *entityNew();

#endif //RAYGAME_ENTITY_H
