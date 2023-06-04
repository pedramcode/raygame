#include "ecs/entity.h"

Entity_t *entityNew(){
    Entity_t *entity = malloc(sizeof(Entity_t));

    entity->id = malloc(11);
    strcpy(entity->id, generateRandomString(10));

    return entity;
}