#include <stdio.h>

// =============================
// Função recursiva para movimentar a Torre (linha reta horizontal)
// Recebe o número de casas restantes para mover
void moverTorre(int casasRestantes) {
    if (casasRestantes == 0) {
        return; // condição de parada da recursão
    }
    printf("Direita\n");
    moverTorre(casasRestantes - 1); // chamada recursiva diminuindo 1 casa
}

// =============================
// Função recursiva para movimentar o Bispo na diagonal (com loops aninhados)
// Para cada casa na vertical (cima), move na horizontal (direita) também, simulando diagonal
// verticalRestantes = número de passos vertical para cima
// horizontalRestantes = número de passos horizontal para direita
void moverBispoRecursivo(int verticalRestantes, int horizontalRestantes) {
    // Condição de parada: quando um dos movimentos acabar
    if (verticalRestantes == 0 || horizontalRestantes == 0) {
        return;
    }

    // Loop aninhado: para cada passo vertical, o loop horizontal faz os movimentos horizontais
    // Aqui usamos loops para deixar o bispo se mover diagonalmente
    for (int v = 0; v < verticalRestantes; v++) {
        for (int h = 0; h < horizontalRestantes; h++) {
            printf("Cima Direita\n");
            // Como queremos simular movimento diagonal casa a casa,
            // a recursividade é chamada após um passo para baixo.
            // Mas para simplificar, essa função vai apenas imprimir as direções diagonal,
            // usando recursão apenas no primeiro passo para evitar excesso.
            return moverBispoRecursivo(verticalRestantes - 1, horizontalRestantes - 1);
        }
    }
}

// Alternativa mais clara usando loops aninhados e recursão no nível superior
void moverBispo(int passos) {
    if (passos == 0) return;

    // Loop externo para vertical (cima)
    for (int v = 0; v < passos; v++) {
        // Loop interno para horizontal (direita)
        for (int h = 0; h < passos; h++) {
            if (v == h) { // para garantir que só imprime quando vertical e horizontal andam juntos (diagonal)
                printf("Cima Direita\n");
            }
        }
    }
}

// =============================
// Função recursiva para movimentar a Rainha (linha reta horizontal)
// Recebe o número de casas restantes para mover
void moverRainha(int casasRestantes) {
    if (casasRestantes == 0) {
        return; // condição de parada da recursão
    }
    printf("Esquerda\n");
    moverRainha(casasRestantes - 1);
}

// =============================
// Função para movimentar o Cavalo usando loops aninhados complexos
// Movimento em "L": 2 casas para cima e 1 para a direita
// Utiliza break e continue para controlar fluxo
void moverCavalo() {
    int passosVerticais = 2;
    int passosHorizontais = 1;

    printf("Movimento do Cavalo:\n");

    // Loop para passos verticais (para cima)
    for (int v = 1; v <= passosVerticais; v++) {
        printf("Cima\n");

        // Se ainda não terminou os passos verticais, continue para próxima iteração
        if (v < passosVerticais) {
            continue;
        }

        // Quando chegar no último passo vertical, faz o passo horizontal (direita)
        int h = 0;
        while (h < passosHorizontais) {
            // Condição fictícia para demonstrar controle de fluxo com break
            if (h > 0) {
                break; // não deve acontecer, pois só 1 passo horizontal
            }
            printf("Direita\n");
            h++;
        }
    }
}

int main() {
    // Definições das casas para cada peça
    const int casasTorre = 5;
    const int casasBispo = 5;
    const int casasRainha = 8;

    // Movimento da Torre (recursivo)
    printf("Movimento da Torre:\n");
    moverTorre(casasTorre);

    printf("\n");

    // Movimento do Bispo (recursivo + loops aninhados)
    // Opção clara usando loops aninhados para diagonal
    printf("Movimento do Bispo:\n");
    moverBispo(casasBispo);

    printf("\n");

    // Movimento da Rainha (recursivo)
    printf("Movimento da Rainha:\n");
    moverRainha(casasRainha);

    printf("\n");

    // Movimento do Cavalo (loops aninhados complexos)
    moverCavalo();

    return 0;
}
