#include "resourceManager.h"


unsigned int hash(const char* key) {
    unsigned int hashValue = 0;
    unsigned int length = strlen(key);

    for (int i = 0; i < length; i++) {
        hashValue = (hashValue * 31) + key[i] + i;
    }

    return hashValue % RESOURCE_HASHTABLE_SIZE;
}

ResourceManager_t *resourceNewManager(ResourceType_t type){
    ResourceManager_t *manager = malloc(sizeof(ResourceManager_t));
    for(int i = 0 ; i < RESOURCE_HASHTABLE_SIZE ; i++) {
        manager->data[i] = NULL;
    }
    return manager;
}

void resourceAdd(ResourceManager_t *manager, char *name, void *data){
    unsigned int index = hash(name);
    Resource_t *resource = malloc(sizeof(Resource_t));
    resource->resource = data;
    resource->name = malloc(sizeof(name) + 1);
    strcpy(resource->name, name);

    manager->data[index] = resource;
}

Resource_t *resourceGet(ResourceManager_t *manager, char *name){
    unsigned int index = hash(name);
    return manager->data[index];
}

void resourceFree(ResourceManager_t *manager){
    for(int i = 0 ; i < RESOURCE_HASHTABLE_SIZE ; i++){
        if(manager->data[i] != NULL){
            free(manager->data[i]->resource);
            free(manager->data[i]->name);
        }
        free(manager->data[i]);
    }
}