#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_COMPONENTES 20

// Estrutura que representa um componente da torre
typedef struct {
    char nome[30];
    char tipo[20];
    int prioridade;
} Componente;

// Função para exibir todos os componentes
void mostrarComponentes(Componente lista[], int n) {
    printf("\n=== COMPONENTES DA TORRE ===\n");
    for (int i = 0; i < n; i++) {
        printf("Nome: %s | Tipo: %s | Prioridade: %d\n",
               lista[i].nome, lista[i].tipo, lista[i].prioridade);
    }
}

// Bubble Sort por nome
int bubbleSortNome(Componente lista[], int n) {
    int comparacoes = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            comparacoes++;
            if (strcmp(lista[j].nome, lista[j + 1].nome) > 0) {
                Componente temp = lista[j];
                lista[j] = lista[j + 1];
                lista[j + 1] = temp;
            }
        }
    }
    return comparacoes;
}

// Insertion Sort por tipo
int insertionSortTipo(Componente lista[], int n) {
    int comparacoes = 0;
    for (int i = 1; i < n; i++) {
        Componente chave = lista[i];
        int j = i - 1;
        while (j >= 0 && strcmp(lista[j].tipo, chave.tipo) > 0) {
            lista[j + 1] = lista[j];
            j--;
            comparacoes++;
        }
        lista[j + 1] = chave;
        comparacoes++;
    }
    return comparacoes;
}

// Selection Sort por prioridade
int selectionSortPrioridade(Componente lista[], int n) {
    int comparacoes = 0;
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            comparacoes++;
            if (lista[j].prioridade < lista[min].prioridade) {
                min = j;
            }
        }
        if (min != i) {
            Componente temp = lista[i];
            lista[i] = lista[min];
            lista[min] = temp;
        }
    }
    return comparacoes;
}

// Busca binária por nome (após ordenação por nome)
int buscaBinariaPorNome(Componente lista[], int n, char chave[]) {
    int inicio = 0, fim = n - 1;
    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        int cmp = strcmp(lista[meio].nome, chave);
        if (cmp == 0) return meio;
        else if (cmp < 0) inicio = meio + 1;
        else fim = meio - 1;
    }
    return -1;
}

// Função para medir tempo de execução e comparações
void medirTempo(int (*algoritmo)(Componente[], int), Componente lista[], int n, const char* nomeAlgoritmo) {
    clock_t inicio = clock();
    int comparacoes = algoritmo(lista, n);
    clock_t fim = clock();
    double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

    printf("\n--- %s ---\n", nomeAlgoritmo);
    printf("Comparações realizadas: %d\n", comparacoes);
    printf("Tempo de execução: %.6f segundos\n", tempo);
    mostrarComponentes(lista, n);
}

int main() {
    Componente componentes[MAX_COMPONENTES];
    int total = 0;
    char componenteChave[30];

    printf("=== MONTAGEM DA TORRE DE RESGATE ===\n");
    printf("Quantos componentes deseja cadastrar (máx %d)? ", MAX_COMPONENTES);
    scanf("%d", &total);
    getchar(); // Limpa o buffer

    for (int i = 0; i < total; i++) {
        printf("\nComponente %d:\n", i + 1);
        printf("Nome: ");
        fgets(componentes[i].nome, 30, stdin);
        componentes[i].nome[strcspn(componentes[i].nome, "\n")] = '\0';

        printf("Tipo: ");
        fgets(componentes[i].tipo, 20, stdin);
        componentes[i].tipo[strcspn(componentes[i].tipo, "\n")] = '\0';

        printf("Prioridade (1 a 10): ");
        scanf("%d", &componentes[i].prioridade);
        getchar(); // Limpa o buffer
    }

    int opcao;
    printf("\nEscolha o critério de ordenação:\n");
    printf("1 - Nome (Bubble Sort)\n");
    printf("2 - Tipo (Insertion Sort)\n");
    printf("3 - Prioridade (Selection Sort)\n");
    printf("Opção: ");
    scanf("%d", &opcao);
    getchar();

    switch (opcao) {
        case 1:
            medirTempo(bubbleSortNome, componentes, total, "Bubble Sort por Nome");
            break;
        case 2:
            medirTempo(insertionSortTipo, componentes, total, "Insertion Sort por Tipo");
            break;
        case 3:
            medirTempo(selectionSortPrioridade, componentes, total, "Selection Sort por Prioridade");
            break;
        default:
            printf("Opção inválida.\n");
            return 1;
    }

    // Busca binária (apenas se ordenado por nome)
    if (opcao == 1) {
        printf("\nDigite o nome do componente-chave para ativar a torre: ");
        fgets(componenteChave, 30, stdin);
        componenteChave[strcspn(componenteChave, "\n")] = '\0';

        int posicao = buscaBinariaPorNome(componentes, total, componenteChave);
        if (posicao != -1) {
            printf("\n✅ Componente-chave encontrado: %s\n", componentes[posicao].nome);
        } else {
            printf("\n❌ Componente-chave não encontrado.\n");
        }
    }

    printf("\n🏁 Montagem final concluída. Boa sorte na fuga!\n");
    return 0;
}