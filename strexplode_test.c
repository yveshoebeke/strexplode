#include <stdio.h>
#include "strexplode.h"

int main(void) {
    char** result_array;
    // parameters for the function
    char* instring = "  now the time has come for all   good   men to come to the aid of their country ";
    char delimiter = ' ';

    char* commaseparated = "McDonnell Douglas,Airbus,Piper,Boeing,Embraer,Bombardier Aerospace,Cessna,Beechcraft,Grumman,Lockheed";
    int element_count;

    // show it to the people
    printf("Example 1:\nSeparate all words in a string into an array:\n");
    printf("Given:\n- Subject string: `%s`\n(note: starting, ending and sequential/duplicated delimiters are eliminated)\n- Delimiter: `%c`\n- Result:\n", instring, delimiter);
    // do it
    element_count = strexplode(&result_array, instring, delimiter);
    // show the result
    printf("word count: %d\n", element_count);
    for(int i=0; i < element_count; i++){
        printf("[%d] `%s`\n", i, result_array[i]);
    }

    // show comma separated to array
    printf("\nExample 2:\nComma separated list to array:\n");
    printf("Given:\n- Subject string: `%s`\n- Delimiter: `%c`\n- Result:\n", commaseparated, ',');
    element_count = strexplode(&result_array, commaseparated, ',');
    // show the result
    printf("array element count: %d\n", element_count);
    for(int i=0; i < element_count; i++){
        printf("[%d] `%s`\n", i, result_array[i]);
    }

    // that's it
    printf("\ndone\n");

    return 0;
}
