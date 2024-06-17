#include <stdio.h>
#include "strexplode.h"

int main() {
    // parameters for the function
    char* instring = "  now the time has come for all   good   men to come to the aid of their country";
    char delimiter = ' ';
    int word_count;
    // show it to the people
    printf("Given:\nSubject string: `%s`\n(note: sequential delimiters)\ndelimiter: `%c`\n\nResult:\n\n", instring, delimiter);
    // do it
    char** result = strexplode(instring, delimiter, &word_count);
    // show the result
    printf("word count: %d\n", word_count);
    for(int i=0; i < word_count; i++){
        printf("[%d] `%s`\n", i, result[i]);
    }
    // that's it
    printf("\ndone\n\n");

    return 0;
}
