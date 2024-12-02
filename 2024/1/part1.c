#include <inttypes.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// https://adventofcode.com/2024/day/1

int qsort_compare( const void* a, const void* b) {
    int int_a = * ( (int*) a );
    int int_b = * ( (int*) b );

    if ( int_a == int_b ) return 0;
    else if ( int_a < int_b ) return -1;
    else return 1;
}

int main() {

    FILE* fptr = fopen("input.in", "r");

    int* left_side_arr = malloc(sizeof(*left_side_arr) * BUFSIZ); // hold all values
    int* right_side_arr = malloc(sizeof(*right_side_arr) * BUFSIZ);

    size_t lines = 0;
    char* buff = malloc(sizeof(*buff) * 100);
    while (fgets(buff, 100, fptr)) {
        // char* token = strtok(buff, " "); // split string
        // while (token != NULL) {
        //     printf("--%s--\n", token);
        //     token = strtok(NULL, " "); // continue tokenization
        // }
        char* left_side = strtok(buff, " ");
        char* right_side = strtok(NULL, " ");

        left_side_arr[lines] = strtoimax(left_side, NULL, 10);
        right_side_arr[lines] = strtoimax(right_side, NULL, 10);


        lines++;

    }
    free(buff);


    // sort arrays smaller to larger
    qsort(left_side_arr, lines, sizeof(*left_side_arr), qsort_compare);
    qsort(right_side_arr, lines, sizeof(*right_side_arr), qsort_compare);


    long sum = 0;

    for (int i = 0; i < lines; i++) {
        sum += abs(left_side_arr[i] - right_side_arr[i]);
    }
    printf("[RES]: %ld\n", sum);


    free(left_side_arr);
    free(right_side_arr);

    fclose(fptr);


    return 0;
}
