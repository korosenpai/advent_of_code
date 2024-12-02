#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    int total_calibration = 0;

    FILE* fpointer = fopen("./inp.in", "r");
    char line[255];

    while (fgets(line, 255, fpointer) != NULL) {
        printf("-- %s", line);
        char line_numbers[20] = "";
        
        for (int i = 0; i < strlen(line); i++) {
            if (isdigit(line[i])) {
                printf("%c\n", line[i]);
                strncat(line_numbers, &line[i], 1);
            }
        }
        printf("%s\n", line_numbers);
        break;
    }

    fclose(fpointer);


    return 0;
}
