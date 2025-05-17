#include <stdio.h>
#include <string.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define TAMANHO_HABILIDADE 5
#define NAVIO 3
#define HABILIDADE 5

// Função auxiliar para verificar posições livres
int posicoes_livres(int tabuleiro[10][10], int linhas[], int colunas[]) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linhas[i]][colunas[i]] != 0) return 0;
    }
    return 1;
}

// Função para posicionar navios
void posicionar_navio(int tabuleiro[10][10], int linhas[], int colunas[]) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linhas[i]][colunas[i]] = NAVIO;
    }
}

// Função para imprimir o tabuleiro com visual amigável
void imprimir_tabuleiro(int tabuleiro[10][10]) {
    printf("Tabuleiro:\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            if (tabuleiro[i][j] == 0) printf(". ");
            else if (tabuleiro[i][j] == NAVIO) printf("N ");
            else if (tabuleiro[i][j] == HABILIDADE) printf("* ");
        }
        printf("\n");
    }
    printf("\n");
}

// Função para criar matriz de habilidade CONE
void criar_matriz_cone(int matriz[5][5]) {
    memset(matriz, 0, sizeof(int) * 25); // zera a matriz

    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (j >= 2 - i && j <= 2 + i) {
                matriz[i][j] = 1;
            }
        }
    }
}

// Função para criar matriz de habilidade CRUZ
void criar_matriz_cruz(int matriz[5][5]) {
    memset(matriz, 0, sizeof(int) * 25);

    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (i == 2 || j == 2) {
                matriz[i][j] = 1;
            }
        }
    }
}

// Função para criar matriz de habilidade OCTAEDRO (losango)
void criar_matriz_octaedro(int matriz[5][5]) {
    memset(matriz, 0, sizeof(int) * 25);

    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (abs(i - 2) + abs(j - 2) <= 2) {
                matriz[i][j] = 1;
            }
        }
    }
}

// Aplica a matriz de habilidade ao tabuleiro, respeitando limites
void aplicar_habilidade(int tabuleiro[10][10], int matriz[5][5], int origem_linha, int origem_coluna) {
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            int linha_tab = origem_linha - 2 + i;
            int coluna_tab = origem_coluna - 2 + j;

            // Verifica se está dentro dos limites
            if (linha_tab >= 0 && linha_tab < TAMANHO_TABULEIRO &&
                coluna_tab >= 0 && coluna_tab < TAMANHO_TABULEIRO &&
                matriz[i][j] == 1) {
                // Só sobrescreve água
                if (tabuleiro[linha_tab][coluna_tab] == 0) {
                    tabuleiro[linha_tab][coluna_tab] = HABILIDADE;
                }
            }
        }
    }
}

int main() {
    int tabuleiro[10][10] = {0};

    // Posiciona navios
    int l1[] = {1, 1, 1}, c1[] = {2, 3, 4}; // horizontal
    int l2[] = {5, 6, 7}, c2[] = {7, 7, 7}; // vertical
    int l3[] = {0, 1, 2}, c3[] = {0, 1, 2}; // diagonal ↘
    int l4[] = {0, 1, 2}, c4[] = {9, 8, 7}; // diagonal ↙

    if (posicoes_livres(tabuleiro, l1, c1)) posicionar_navio(tabuleiro, l1, c1);
    if (posicoes_livres(tabuleiro, l2, c2)) posicionar_navio(tabuleiro, l2, c2);
    if (posicoes_livres(tabuleiro, l3, c3)) posicionar_navio(tabuleiro, l3, c3);
    if (posicoes_livres(tabuleiro, l4, c4)) posicionar_navio(tabuleiro, l4, c4);

    // Criação e aplicação das habilidades
    int matriz_cone[5][5], matriz_cruz[5][5], matriz_octa[5][5];

    criar_matriz_cone(matriz_cone);
    criar_matriz_cruz(matriz_cruz);
    criar_matriz_octaedro(matriz_octa);

    aplicar_habilidade(tabuleiro, matriz_cone, 4, 2);     // Cone centrado em (4,2)
    aplicar_habilidade(tabuleiro, matriz_cruz, 6, 6);     // Cruz centrado em (6,6)
    aplicar_habilidade(tabuleiro, matriz_octa, 2, 7);     // Octaedro centrado em (2,7)

    imprimir_tabuleiro(tabuleiro);

    return 0;
}
