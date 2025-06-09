#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLS 20
#define MAX_INPUT 1000

int read_column_number(int columns[], int max);
void rearrange(char* output, char const* input, int n_columns, int const columns[]);

int main(void) {
    int n_columns, columns[MAX_COLS];
    char input[MAX_INPUT], output[MAX_INPUT];

    n_columns = read_column_number(columns, MAX_COLS);
    while (gets(input) != NULL) {
        printf("Input: %s\n", input);
        rearrange(output, input, n_columns, columns);
        printf("Output: %s\n", output);
    }

    return EXIT_SUCCESS;
}

int read_column_number(int columns[], int max) {
    int num = 0, ch;

    while (num < max && scanf("%d", &columns[num]) == 1 && columns[num] >= 0)
        num++;
    if (num % 2 != 0) {
        columns[num] = MAX_INPUT;
    }
    while ((ch = getchar()) != EOF && ch != '\n');
    return num;
}

void rearrange(char* output, char const* input, int n_columns, int const columns[]) {
    int col, output_col = 0;

    for (col = 0; col < n_columns; col += 2) {
        int start_col = columns[col];
        int nchars = columns[col + 1] - start_col + 1;
        if (columns[col] > columns[col + 1]) {
            start_col = columns[col + 1];
            nchars = columns[col] - start_col + 1;
        }
        if (start_col >= strlen(input) || output_col == MAX_INPUT - 1)
            break;
        if (output_col + nchars > MAX_INPUT - 1)
            nchars = MAX_INPUT - output_col - 1;
        strncpy(output + output_col, input + start_col, nchars);
        output_col += nchars;
    }
    output[output_col] = '\0';
}
