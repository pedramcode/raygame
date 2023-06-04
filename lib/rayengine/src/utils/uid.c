#include "utils/uid.h"

char* generateRandomString(int length) {
    static const char charset[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char* randomString = (char*)malloc((length + 1) * sizeof(char));

    if (randomString == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }

    srand(time(NULL));

    for (int i = 0; i < length; ++i) {
        int index = rand() % (sizeof(charset) - 1);
        randomString[i] = charset[index];
    }

    randomString[length] = '\0';

    return randomString;
}