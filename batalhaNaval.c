#include <stdio.h>

#define TAMANHO 10
#define TAM_NAVIO 3


int main() {
    
    char Head[10] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    int Tabuleiro [TAMANHO][TAMANHO] = {0};
    int Soma = 'i' + 'j';

    //Navio na Vertical B2, B3 e B4.

    for (int i = 0; i < TAM_NAVIO; i++)
    {
        Tabuleiro[1+i][1] = 3;
    }
    

    //Navio na Horizontal F3, G3 e H3.

    for (int i = 0; i < TAM_NAVIO; i++)
    {
        Tabuleiro[2][5+i] = 3;
    }

    //Navio na Diagonal C3,D4,E5

    for (int i = 0; i < TAM_NAVIO; i++)
    {
        Tabuleiro[2+i][2+i] = 3;
    }

    //Navio na Diagonal Invertida J8,I9,H10

    for (int i = 0; i < TAM_NAVIO; i++)
    {   
        Tabuleiro[9-i][7+i] = 3;
    }
    

    

    printf("   *TABULEIRO BATALHA NAVAL* \n\n");
    printf("   "); // Espaçamento para alinhar as colunas com a variável "linha"

    //cabeçalho
    for (int j = 0; j < 10; j++)
    {
        printf(" %c ", Head[j]);
    }
    printf("\n");

    //Exibição do Tabuleiro
    for (int i = 0; i < TAMANHO; i++)
    {
        printf("%2d ", i + 1); // Adicionando uma coluna de indice numerica.
        for (int j = 0; j < TAMANHO; j++)
        {
            printf(" %d ", Tabuleiro[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}