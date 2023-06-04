#include "ecs/entity.h"

Entity_t *entityNew(){
    Entity_t *entity = malloc(sizeof(Entity_t));

    UUID4_STATE_T state;
    UUID4_T uuid;
    uuid4_seed(&state);
    uuid4_gen(&state, &uuid);
    char buffer[UUID4_STR_BUFFER_SIZE];
    if (!uuid4_to_s(uuid, buffer, sizeof(buffer)))
        exit(EXIT_FAILURE);
    char *id = truncateUUID(buffer, 8);
    entity->id = malloc(sizeof(id));
    strcpy(entity->id, id);

    return entity;
}