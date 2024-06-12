#include <stdio.h>
#include "strexplode.h"

int main() {
    // parameters for the function
    char* instring = "now the time has come for all good men to come to the aid of their country";
    char delimeter = ' ';
    int word_count;
    // show it to the people
    printf("Given:\nSubject string: `%s`\nDelimeter: `%c`\n\nResult:\n\n", instring, delimeter);
    // do it
    char** result = strexplode(instring, delimeter, &word_count);
    // show the labor
    printf("word count: %d\n", word_count);
    for(int i=0; i < word_count; i++){
        printf("[%d] `%s`\n", i, result[i]);
    }
    // thst's it
    printf("\ndone\n\n");

    return 0;
}
