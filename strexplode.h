#ifndef STREXPLODE_H
#define STREXPLODE_H
/*
+-------------------------------------------------------------------------------+    
|                                                                               |
|    strexplode.h                                                               |
|                                                                               |
|    Splits a string into an array.                                             |
|                                                                               |
|    repository    - https://github.com/yveshoebeke/strexplode                  |
|    license       - https://github.com/yveshoebeke/strexplode/blob/LICENSE     |
|    documentation - https://github.com/yveshoebeke/strexplode/wiki             |
|                                                                               |
|    author        - Yves Hoebeke                                               |
|    email         - yves.hoebeke@bytesupply.com                                |
|    web           - https://yveshoebeke.github.io                              |
|                                                                               |
|    date: 19-07-2024                                                           |
|                                                                               |
+-------------------------------------------------------------------------------+    
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DELIMITERS_CONSIDERED 2

char** strexplode(char* instring, char delimiter, int* count) {
    char** result;
    char* buffer;
    char delimiters[DELIMITERS_CONSIDERED] = {delimiter, '\0'};
    const unsigned long Subject_Length = strlen(instring) * sizeof(char);
    unsigned int word_count = 0, result_idx = 0, buffer_idx = 0;

    // set subject string length bytes aside for work buffer (to be freed later)
    buffer = (char*)malloc(Subject_Length);
    if (buffer == NULL) {
        fprintf(stderr, "Buffer - Memory allocation failed\n");
        *count = -1;
        return result;
    }

    // get word count
    for(int i = 0; i < strlen(instring); i++){
        if(instring[i] == delimiters[0] || instring[i] == delimiters[1]) {
            if(i > 0 && instring[i-1] != delimiters[0]){
                word_count += 1;
            }
        }
    }

    // allocate mem for result array for number of elements (words) found.
    result = (char**)malloc(word_count * sizeof(char*));
    if (result == NULL) {
        fprintf(stderr, "Result array - Memory allocation failed\n");
        free(buffer);
        *count = -1;
        return result;
    }

    // allocate mem for each word element (and commit value) to result array.
    for(int i = 0; i < strlen(instring) + 1; i++){
        if(instring[i] != delimiters[0] && instring[i] != delimiters[1]) {
            buffer[buffer_idx++] = instring[i];
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

    // set return count [see issues]
    if(result[0] == NULL){
        // [ISSUE 1]
        *count = 0;
    } else if(result[word_count] == NULL) {
        // [ISSUE 2]
        *count = word_count;
    } else {
        *count = word_count + 1;
    }

    return result;
}

#endif /* STREXPLODE_H */
