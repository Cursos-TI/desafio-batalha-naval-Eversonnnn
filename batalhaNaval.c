#include <stdio.h>

// Tamanho fixo do tabuleiro e dos navios
#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define OCUPADO 3

// Função para verificar se todas as posições estão livres
int posicoes_livres(int tabuleiro[10][10], int linhas[], int colunas[]) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linhas[i]][colunas[i]] != 0) {
            return 0; // encontrou posição já ocupada
        }
    }
    return 1; // todas as posições estão livres
}

// Função para marcar posições do navio no tabuleiro
void posicionar_navio(int tabuleiro[10][10], int linhas[], int colunas[]) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linhas[i]][colunas[i]] = OCUPADO;
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    // Coordenadas para o navio horizontal
    int linhaH = 1, colunaH = 2;
    int navioH_linhas[TAMANHO_NAVIO] = {linhaH, linhaH, linhaH};
    int navioH_colunas[TAMANHO_NAVIO] = {colunaH, colunaH+1, colunaH+2};

    // Coordenadas para o navio vertical
    int linhaV = 3, colunaV = 7;
    int navioV_linhas[TAMANHO_NAVIO] = {linhaV, linhaV+1, linhaV+2};
    int navioV_colunas[TAMANHO_NAVIO] = {colunaV, colunaV, colunaV};

    // Coordenadas para o navio diagonal ↘ (linha e coluna aumentam)
    int linhaD1 = 0, colunaD1 = 0;
    int navioD1_linhas[TAMANHO_NAVIO] = {linhaD1, linhaD1+1, linhaD1+2};
    int navioD1_colunas[TAMANHO_NAVIO] = {colunaD1, colunaD1+1, colunaD1+2};

    // Coordenadas para o navio diagonal ↙ (linha aumenta, coluna diminui)
    int linhaD2 = 0, colunaD2 = 9;
    int navioD2_linhas[TAMANHO_NAVIO] = {linhaD2, linhaD2+1, linhaD2+2};
    int navioD2_colunas[TAMANHO_NAVIO] = {colunaD2, colunaD2-1, colunaD2-2};

    // Verificações e posicionamentos
    if (colunaH + TAMANHO_NAVIO <= TAMANHO_TABULEIRO && posicoes_livres(tabuleiro, navioH_linhas, navioH_colunas)) {
        posicionar_navio(tabuleiro, navioH_linhas, navioH_colunas);
    }

    if (linhaV + TAMANHO_NAVIO <= TAMANHO_TABULEIRO && posicoes_livres(tabuleiro, navioV_linhas, navioV_colunas)) {
        posicionar_navio(tabuleiro, navioV_linhas, navioV_colunas);
    }

    if (linhaD1 + TAMANHO_NAVIO <= TAMANHO_TABULEIRO &&
        colunaD1 + TAMANHO_NAVIO <= TAMANHO_TABULEIRO &&
        posicoes_livres(tabuleiro, navioD1_linhas, navioD1_colunas)) {
        posicionar_navio(tabuleiro, navioD1_linhas, navioD1_colunas);
    }

    if (linhaD2 + TAMANHO_NAVIO <= TAMANHO_TABULEIRO &&
        colunaD2 - (TAMANHO_NAVIO - 1) >= 0 &&
        posicoes_livres(tabuleiro, navioD2_linhas, navioD2_colunas)) {
        posicionar_navio(tabuleiro, navioD2_linhas, navioD2_colunas);
    }

    // Impressão do tabuleiro
    printf("Tabuleiro Batalha Naval (0 = água, 3 = navio):\n\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
