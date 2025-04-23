#include <stdio.h>

#define TAM 10 // Tamanho do tabuleiro
#define TAM_NAVIO 3 // Tamanho fixo dos navios

int main() {
    int tabuleiro[TAM][TAM] = {0};

    //~~~~~~~~~~~~~~~~ Coordenadas iniciais dos navios ~~~~~~~~~~~~~~~~//
    int linha_horizontal = 2, coluna_horizontal = 4;
    int linha_vertical = 5, coluna_vertical = 1;

    int i, sobreposicao = 0;

    //~~~~~~~~~~~~~~~~ POSICIONANDO NAVIO HORIZONTAL ~~~~~~~~~~~~~~~~~//
    if (coluna_horizontal + TAM_NAVIO <= TAM) {
        for (i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linha_horizontal][coluna_horizontal + i] != 0) {
                sobreposicao = 1;
                break;
            }
        }

        if (!sobreposicao) {
            for (i = 0; i < TAM_NAVIO; i++) {
                tabuleiro[linha_horizontal][coluna_horizontal + i] = 3;
            }
        } else {
            printf("Erro: sobreposição detectada ao posicionar navio horizontal.\n");
        }
    } else {
        printf("Erro: navio horizontal ultrapassa os limites do tabuleiro.\n");
    }

    //~~~~~~~~~~~~~~~~ POSICIONANDO NAVIO VERTICAL ~~~~~~~~~~~~~~~~~//
    sobreposicao = 0;

    if (linha_vertical + TAM_NAVIO <= TAM) {
        for (i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linha_vertical + i][coluna_vertical] != 0) {
                sobreposicao = 1;
                break;
            }
        }

        if (!sobreposicao) {
            for (i = 0; i < TAM_NAVIO; i++) {
                tabuleiro[linha_vertical + i][coluna_vertical] = 3;
            }
        } else {
            printf("Erro: sobreposição detectada ao posicionar navio vertical.\n");
        }
    } else {
        printf("Erro: navio vertical ultrapassa os limites do tabuleiro.\n");
    }
   
    //~~~~~~~~~~~~~~~~ Impressão do cabeçalho com letras ~~~~~~~~~~~~~~~~//
    printf("   ");
    for (char letra = 'A'; letra < 'A' + TAM; letra++) {
        printf(" %c", letra);
    }
    printf("\n");

    //~~~~~~~~~~~~~~~~ Impressão das linhas numeradas ~~~~~~~~~~~~~~~~//
    for (int l = 0; l < TAM; l++) {
        printf("%2d ", l + 1);
        for (int c = 0; c < TAM; c++) {
            printf(" %d", tabuleiro[l][c]);
        }
        printf("\n");
    }

    return 0;
}
