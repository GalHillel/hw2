#include <stdio.h>
#include "my_mat.c"

int main() {
    char des;
    int a = 1, i, j = 0;
    while (a) {
        scanf("%c", &des);
        switch (des) {
            case 'A':
                insert();
                break;

            case 'B':
                scanf("%i %i", &i, &j);
                (isLinked(i, j)) ? printf("True\n") : printf("False\n");
                break;

            case 'C':
                scanf("%i %i", &i, &j);
                printf("%i\n", findMin(i, j));
                break;

            case 'D':
                a = 0;
                break;
        }
    }
    return 0;
}