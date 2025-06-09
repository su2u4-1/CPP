#include <stdio.h>

int main() {
    int maxlinelength = -1, c = '\0';
    while (c != EOF) {
        int line = 0;
        while ((c = getchar()) != EOF && c != '\n')
            line++;
        if (line > maxlinelength)
            maxlinelength = line;
    }
    printf("%d\n", maxlinelength);
    return 0;
}
