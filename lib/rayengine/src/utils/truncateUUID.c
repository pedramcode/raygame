#include "utils/truncateUUID.h"

char* truncateUUID(const char* uuid, int length) {
    if (length <= 0 || length >= 36) {
        return NULL;
    }

    // Allocate memory for the truncated UUID
    char* truncatedUUID = (char*)malloc((length + 1) * sizeof(char));
    if (truncatedUUID == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }

    // Copy the desired characters to the truncated UUID
    strncpy(truncatedUUID, uuid, length);
    truncatedUUID[length] = '\0';

    return truncatedUUID;
}