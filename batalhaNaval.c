#include <stdio.h>

// Tamanho fixo do tabuleiro e navios
#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

int main() {
    // Declaração da matriz do tabuleiro e inicialização com 0 (água)
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    // Coordenadas iniciais dos navios
    int linhaNavioHorizontal = 2;
    int colunaNavioHorizontal = 4;

    int linhaNavioVertical = 5;
    int colunaNavioVertical = 7;

    int i;

    // Verificação se o navio horizontal cabe no tabuleiro
    if (colunaNavioHorizontal + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        for (i = 0; i < TAMANHO_NAVIO; i++) {
            // Garante que a posição está livre
            if (tabuleiro[linhaNavioHorizontal][colunaNavioHorizontal + i] == 0) {
                tabuleiro[linhaNavioHorizontal][colunaNavioHorizontal + i] = 3;
            }
        }
    } else {
        printf("Erro: Navio horizontal fora dos limites do tabuleiro.\n");
        return 1;
    }

    // Verificação se o navio vertical cabe no tabuleiro
    if (linhaNavioVertical + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        for (i = 0; i < TAMANHO_NAVIO; i++) {
            // Verifica se há sobreposição
            if (tabuleiro[linhaNavioVertical + i][colunaNavioVertical] == 0) {
                tabuleiro[linhaNavioVertical + i][colunaNavioVertical] = 3;
            } else {
                printf("Erro: Sobreposição detectada ao posicionar navio vertical.\n");
                return 1;
            }
        }
    } else {
        printf("Erro: Navio vertical fora dos limites do tabuleiro.\n");
        return 1;
    }

    // Exibição do tabuleiro
    printf("Tabuleiro:\n");
    for (int linha = 0; linha < TAMANHO_TABULEIRO; linha++) {
        for (int coluna = 0; coluna < TAMANHO_TABULEIRO; coluna++) {
            printf("%d ", tabuleiro[linha][coluna]);
        }
        printf("\n");
    }

    return 0;
}
