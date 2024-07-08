#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "strexplode.h"

void cr_to_continue() {
    printf("\nhit <CR> to continue > ");
    int ch = getchar();
}

// get file size
unsigned long get_file_size(char* fname) {
    FILE *fp;
    unsigned long size;

    fp = fopen(fname, "r");
    if(fp == NULL) {
        fprintf(stderr, "unable to open file: %s\n", fname);
        return 0;
    }
    fseek(fp, 0L, SEEK_END);
    size = ftell(fp) * sizeof(char);
    fclose(fp);
    return size;
}

unsigned long int fill_buffer(char* fn, char** buf, unsigned long sz){
    // adjust buffer size
    *buf = (char*)malloc(sz);
    // read the file
    int fd = open(fn, O_RDONLY);
    if (fd == -1) {
        printf("file can't be opened \n");
        return 1;
    }
    unsigned long int bytesread = read(fd, *buf, sz);
    close(fd);
    // return bytes read
    return bytesread;
}

int main(void) {
    char** result_array;
    char* fname = "data/longtest.txt";
    unsigned long int size, bytesread, element_count;
    char* buffer;
    
    // get size
    size = get_file_size(fname);
    bytesread = fill_buffer(fname, &buffer, size);
    printf("\nFile: [%s] - size: [%lu] - bytes read: [%lu]", fname, size, bytesread);

    // do the splitting
    element_count = strexplode(&result_array, buffer, " ");
    if(element_count == -1){
        free(buffer);
        free(result_array);
        return 1;
    }

    // show the result
    printf(" - word count: [%lu]\n", element_count);
    for(int i=0; i < element_count; i++){
        if(i % 1000 == 0){ cr_to_continue(); }
        printf("[%d] `%s`\n", i, result_array[i]);
    }

    free(buffer);
    free(result_array);

    // that's it
    printf("\ndone\n");

    return 0;
}
