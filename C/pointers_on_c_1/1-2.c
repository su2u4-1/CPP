#include <stdio.h>

int main(void) {
    int line = 0;
    int column = 0;
    char* str;
    char c;
    while (1) {
        while (1) {
            c = getchar();
            if (c == EOF || c == '\n')
                break;
            str[column++] = c;
        }
        printf("%d %s", line++, str);
        printf("\n");
        column = 0;
    }
}
