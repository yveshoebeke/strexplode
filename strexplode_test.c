#include <stdio.h>
#include "strexplode.h"

int main(void) {
    char** result_array;    // resulting array of elements
    int element_count;      // resulting number of elements

    // ========== part 1 ===========
    // show words (space separated)
    char instring[] = "now is the time for all good men to come to the aid of their country";
    char* delimiter = " ";

    printf("Example 1:\nSeparate all words in a string into an array:\n");
    printf("Given:\n- Subject string: `%s`\n(note: starting, ending and sequential/duplicated delimiters are eliminated)\n- Delimiter: `%s`\n- Result:\n", instring, delimiter);

    // do it
    element_count = strexplode(&result_array, instring, delimiter);

    // show the result
    printf("word count: %d\n", element_count);
    for(int i=0; i < element_count; i++){
        printf("[%d] `%s`\n", i, result_array[i]);
    }

    // ========== part 2 ===========
    // show comma separated to array
    char commaseparated[] = "McDonnell Douglas,Airbus,Piper,Boeing,,Embraer,Bombardier Aerospace,Cessna,Beechcraft,Grumman,Lockheed";

    printf("\nExample 2:\nComma separated list to array:\n");
    printf("Given:\n- Subject string: `%s`\n- Delimiter: `%s`\n- Result:\n", commaseparated, ",");

    // do it
    element_count = strexplode(&result_array, commaseparated, ",");
    // show the result
    printf("array element count: %d\n", element_count);
    for(int i=0; i < element_count; i++){
        printf("[%d] `%s`\n", i, result_array[i]);
    }

    // that's it
    printf("\ndone\n");

    return 0;
}
