#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Definindo a estrutura do jogador
typedef struct {
    char nome[16];
    int pontuacoes[12];
    int pontuacaoFinal;
} Jogador;

// Função de comparação para qsort
int comparar(const void *a, const void *b) {
    Jogador *jogadorA = (Jogador *)a;
    Jogador *jogadorB = (Jogador *)b;

    // Ordenar por pontuação final decrescente
    if (jogadorB->pontuacaoFinal != jogadorA->pontuacaoFinal) {
        return jogadorB->pontuacaoFinal - jogadorA->pontuacaoFinal;
    }

    // Em caso de empate, ordenar por nome
    return strcmp(jogadorA->nome, jogadorB->nome);
}

int main() {
    int teste = 1;
    int J;

    while (1) {
        scanf("%d", &J);

        if (J == 0) {
            break; // Fim da entrada
        }

        Jogador jogadores[J];

        // Leitura dos dados dos jogadores
        for (int i = 0; i < J; i++) {
            scanf("%s", jogadores[i].nome);
            jogadores[i].pontuacaoFinal = 0;

            for (int j = 0; j < 12; j++) {
                scanf("%d", &jogadores[i].pontuacoes[j]);
            }

            // Ordena as pontuações para descartar a maior e a menor
            qsort(jogadores[i].pontuacoes, 12, sizeof(int), comparar);
            
            // Soma as pontuações restantes
            for (int k = 1; k < 11; k++) {
                jogadores[i].pontuacaoFinal += jogadores[i].pontuacoes[k];
            }
        }

        // Ordena os jogadores usando a função qsort
        qsort(jogadores, J, sizeof(Jogador), comparar);

        // Saída formatada
        printf("Teste %d\n", teste);

        for (int i = 0; i < J; i++) {
            printf("%d %d %s\n", i + 1, jogadores[i].pontuacaoFinal, jogadores[i].nome);
        }

        printf("\n");

        teste++;
    }

    return 0;
}
