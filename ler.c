#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 5;                  // tamanho do vetor
    int vetor[5];               // declaração de um vetor de inteiros

    // Leitura dos elementos
    for (int i = 0; i < n; i++) {
        printf("Digite o elemento [%d]: ", i);
        scanf("%d", &vetor[i]); // note o & para passar o endereço do elemento
    }

    // Exibição dos elementos lidos
    printf("\nConteúdo do vetor:\n");
    for (int i = 0; i < n; i++) {
        printf("vetor[%d] = %d\n", i, vetor[i]);
    }

    return 0;
}
