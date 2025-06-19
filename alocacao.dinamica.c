#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Quantos elementos você quer no vetor? ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        fprintf(stderr, "Entrada inválida.\n");
        return 1;
    }

    // aloca memória para n inteiros
    int *vetor = malloc(n * sizeof *vetor);
    if (vetor == NULL) {
        perror("Falha no malloc");
        return 1;
    }

    // leitura dos elementos
    for (int i = 0; i < n; i++) {
        printf("Digite vetor[%d]: ", i);
        scanf("%d", &vetor[i]);
    }

    // exibe o conteúdo
    printf("\nConteúdo do vetor:\n");
    for (int i = 0; i < n; i++) {
        printf("vetor[%d] = %d\n", i, vetor[i]);
    }

    // libera a memória antes de sair
    free(vetor);

    return 0;
}
