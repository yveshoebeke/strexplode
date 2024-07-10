/*
+-------------------------------------------------------------------------------+    
|                                                                               |
|    strexplode.h                                                               |
|                                                                               |
|    Splits a string into an array.                                             |
|       - params: address to resulting char array, subject string, delimiter.   |
|       - returns number of elements in resulting array.                        |
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
#include <stdlib.h>
#include <string.h>

int strexplode(char*** result_pntr, char instring[], char* delimiters){
    char** result;
    char* element;
    unsigned int index = 0, mem_cnt = 0, count;

    // determine memory allocation for the result array by counting delimiters
    for(int i = 0; i < strlen(delimiters); i++){
        char* astring = instring;
        for(count = 0; astring[count]; astring[count] == delimiters[i] ? count++ : *astring++);
        mem_cnt += count;
    }

    // allocate it
    *result_pntr = (char**)calloc(mem_cnt, sizeof(char**));
    if(*result_pntr == NULL){
        fprintf(stderr, "`*result_pntr` memory allocation failed (%lu bytes)\n", mem_cnt * sizeof(char**));
        free(*result_pntr);
        return -1;
    }

    // move allocated array address to result for processing.
    result = *result_pntr;

    // retrieve each element separated by the delimiter
    while((element = strtok_r(instring, delimiters, &instring))){
        if(strlen(element) == 0){ 
            continue;
        }
        result[index] = (char*)malloc(strlen(element) * sizeof(char*));
        if(result[index] == NULL){
            fprintf(stderr, "`result[%d]` memory allocation failed (%lu bytes)\n", index, strlen(element) * sizeof(char*));
            free(result);
            return -1;
        }
        // push it up the result stack and update the index count
        strcpy(result[index++], element);
    }

    return index;
}
