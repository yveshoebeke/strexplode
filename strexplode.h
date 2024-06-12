#ifndef _STREXPLODE_H_
#define _STREXPLODE_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_BUFFER_WIDTH 100

char** strexplode(char* string, char delimeter, int* count) {
    char** result;
    char buffer[MAX_BUFFER_WIDTH];
    int word_count;
    int word_length;
    int result_idx = 0;
    int buffer_idx = 0;

    // get word count
    for(int i = 0; i < strlen(string); i++){
        if(string[i] == delimeter) {
            word_count += 1;
        }
    }
    *count = word_count;

    // allocate mem for result
    result = (char**)malloc((word_count + 1) * sizeof(char*));
    if (result == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return result;
    }

    // allocate mem for each word and allocate value
    for(int i = 0; i < strlen(string) + 1; i++){
        if(string[i] != delimeter && string[i] != 0) {
            buffer[buffer_idx++] = string[i];
            word_length++;
        } else {
            buffer[buffer_idx] = 0;
            result[result_idx] = (char*)malloc((word_length + 1) * sizeof(char));
            if(result[result_idx] == NULL){
                fprintf(stderr, "Memory allocation failed\n");
                return result;
            }
            strcpy(result[result_idx], buffer);
            result_idx++;
            buffer_idx = 0;
            word_length = 0;
        }
    }

    return result;
}

#endif /* _STREXPLODE_H_ */
