#include <stdio.h>

int main() {
    
    char linha[10] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    int Tabuleiro [10][10] = {0};

    //Navio na Vertical B2, B3 e B4.
    Tabuleiro [1][1] = 3;
    Tabuleiro [2][1] = 3;
    Tabuleiro [3][1] = 3;

    //Navio na Horizontal F3, G3 e H3.
    Tabuleiro [2][5] = 3;
    Tabuleiro [2][6] = 3;
    Tabuleiro [2][7] = 3;

    printf("   *TABULEIRO BATALHA NAVAL* \n  \n");
    printf("   "); // Espaçamento para alinhar as colunas com a variável "linha"

    //cabeçalho
    for (int j = 0; j < 10; j++)
    {
        printf(" %c ", linha[j]);
    }
    printf("\n");

    //Exibição do Tabuleiro
    for (int i = 0; i < 10; i++)
    {
        printf("%2d ", i + 1); // Adicionando uma coluna de indice numerica.
        for (int j = 0; j < 10; j++)
        {
            printf(" %d ", Tabuleiro[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}