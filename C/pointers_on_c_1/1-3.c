#include <stdio.h>

int main(void) {
    int column = 0;
    signed char checksum = -1;
    char* str;
    int c;
    while (1) {
        c = getchar();
        if (c == EOF)
            break;
        checksum += c;
        str[column++] = c;
    }
    printf("%s\n%d\n", str, checksum);
}
