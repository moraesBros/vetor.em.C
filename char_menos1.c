#include <stdio.h>

int main(void) {
    // declarando e inicializando o vetor de caracteres
    char al[] = {'a','b','c','d'};  

    // percorre do índice 0 até o penúltimo caractere
    for (int i = 0; i < (int)sizeof(al) - 1; i++) {
        printf("al[%d] = %c\n", i, al[i]);
    }

    return 0;
}
