// Testing getchar() and putchar() functions

#include <stdio.h>

int main(){
    char c;
    c = getchar();

    while (c != EOF) {
        if (c == ' ')
            c = '_';
        
        putchar(c);
        c = getchar();
    }

    return 0;
}