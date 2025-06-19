#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    printf("Quantos elementos você quer inicialmente? ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        fprintf(stderr, "Entrada inválida para n.\n");
        return EXIT_FAILURE;
    }

    // 1) Aloca inicialmente
    int *vet = malloc(n * sizeof *vet);
    if (!vet) {
        perror("malloc falhou");
        return EXIT_FAILURE;
    }

    // 2) Leitura dos n elementos
    for (int i = 0; i < n; i++) {
        printf("Digite vet[%d]: ", i);
        scanf("%d", &vet[i]);
    }

    // 3) Pede um novo tamanho
    printf("\nQuantos elementos agora quer no total? ");
    if (scanf("%d", &m) != 1 || m <= 0) {
        fprintf(stderr, "Entrada inválida para m.\n");
        free(vet);
        return EXIT_FAILURE;
    }

    // 4) Expande (ou encolhe) o bloco
    int *tmp = realloc(vet, m * sizeof *vet);
    if (!tmp) {
        perror("realloc falhou");
        free(vet);   // o bloco antigo ainda existe, então libera
        return EXIT_FAILURE;
    }
    vet = tmp;      // só trocar se realocou com sucesso

    // 5) Se m > n, ler valores adicionais
    if (m > n) {
        for (int i = n; i < m; i++) {
            printf("Digite vet[%d]: ", i);
            scanf("%d", &vet[i]);
        }
    }

    // 6) Mostra todo o vetor
    printf("\nConteúdo final do vetor (%d elementos):\n", m);
    for (int i = 0; i < m; i++) {
        printf("vet[%d] = %d\n", i, vet[i]);
    }

    // 7) Libera a memória
    free(vet);
    return EXIT_SUCCESS;
}
