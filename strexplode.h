#ifndef _STREXPLODE_H_
#define _STREXPLODE_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DELIMITERS_ALLOWED 2

char** strexplode(char* string, char delimiter, int* count) {
    char** result;
    char* buffer;
    char delimiters[DELIMITERS_ALLOWED] = {delimiter, '\0'};
    const unsigned int subject_length = strlen(string);
    unsigned int word_count = 0, result_idx = 0, buffer_idx = 0;

    // set subject string length bytes aside for work buffer (to be freed later)
    buffer = (char*)malloc(subject_length * sizeof(char));
    if (buffer == NULL) {
        fprintf(stderr, "Buffer - Memory allocation failed\n");
        *count = -1;
        return result;
    }

    // get word count
    for(int i = 0; i < strlen(string); i++){
        if(string[i] == delimiters[0] || string[i] == delimiters[1]) {
            if(i > 0 && string[i-1] != delimiters[0]){
                word_count += 1;
            }
        }
    }

    // set return count [see issues]
    *count = word_count + 1;

    // allocate mem for result array for number of elements (words) found.
    result = (char**)malloc((word_count + 1) * sizeof(char*));
    if (result == NULL) {
        fprintf(stderr, "Result array - Memory allocation failed\n");
        free(buffer);
        *count = -1;
        return result;
    }

    // allocate mem for each word element (and commit value) to result array.
    for(int i = 0; i < strlen(string) + 1; i++){
        if(string[i] != delimiters[0] && string[i] != delimiters[1]) {
            buffer[buffer_idx++] = string[i];
        } else {
            buffer[buffer_idx] = 0;
            // skip if nothing in buffer, occurs when sequential delimiters are present.
            if(strlen(buffer) > 0){
                result[result_idx] = (char*)malloc(strlen(buffer) * sizeof(char));
                if(result[result_idx] == NULL){
                    fprintf(stderr, "Result array element - Memory allocation failed\n");
                    free(buffer);
                    *count = -1;
                    return result;
                }
                strcpy(result[result_idx], buffer);
                result_idx++;
            }

            buffer_idx = 0;
        }
    }

    free(buffer);

    return result;
}

#endif /* _STREXPLODE_H_ */
