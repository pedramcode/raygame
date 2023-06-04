#ifndef RAYGAME_RESOURCEMANAGER_H
#define RAYGAME_RESOURCEMANAGER_H

#include <string.h>
#include <malloc.h>

#define RESOURCE_HASHTABLE_SIZE 1024

typedef enum {
    TEXTURE,
    FONT,
    WAVE,
    SOUND,
    MUSIC
} ResourceType_t;

typedef struct {
    void *resource;
    char *name;
} Resource_t;

typedef struct {
    ResourceType_t type;
    Resource_t *data[RESOURCE_HASHTABLE_SIZE];
} ResourceManager_t;


ResourceManager_t *resourceNewManager(ResourceType_t type);
void resourceAdd(ResourceManager_t *manager, char *name, void *data);
Resource_t *resourceGet(ResourceManager_t *manager, char *name);

#endif //RAYGAME_RESOURCEMANAGER_H
