#ifndef RAYGAME_ENTITY_H
#define RAYGAME_ENTITY_H

#include "malloc.h"
#include "utils/uuid4.h"
#include "utils/truncateUUID.h"
#include <stdlib.h>

typedef struct {
    char *id;
} Entity_t;

Entity_t *entityNew();

#endif //RAYGAME_ENTITY_H
