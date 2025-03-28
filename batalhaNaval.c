#include <stdio.h>

#define TAMANHO 10
#define TAM_NAVIO 3

//Verificar se acertou o navio
void registrarAtaque(int Tabuleiro[TAMANHO][TAMANHO], int linha, int coluna)
{
    if (linha >= 0 && linha < TAMANHO && coluna >= 0 < TAMANHO)
    {
        if (Tabuleiro[linha][coluna] == 3)
        {
            Tabuleiro[linha][coluna] = 5; // Acertou um navio!
        } else
        {
            Tabuleiro[linha][coluna] = 1; // Ataque comum.
        }
        
    }
    
}

//Ataque Especial CONE!
void ataqueCone(int Tabuleiro[TAMANHO][TAMANHO], int linha, int coluna)
{
    for (int i = 0; i < 3; i++)
    {
         for (int j = -i; j <= i; j++)
        {
            registrarAtaque(Tabuleiro, linha + i, coluna + j);
        }
            
    }     
}

//Ataque Especial CRUZ!
void ataqueCruz(int Tabuleiro[TAMANHO][TAMANHO], int linha, int coluna)
{
    int cruz[5][2] = {{0, 0}, {-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    for (int i = 0; i < 5; i++)
    {
        registrarAtaque(Tabuleiro, linha + cruz[i][0], coluna + cruz[i][1]);
    }
    
}

//Ataque Especial OCTAEDRO!
void ataqueOctaedro(int Tabuleiro[TAMANHO][TAMANHO], int linha, int coluna)
{
    int octaedro[13][2] = {{0, 0}, {-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-2, 0}, {2, 0}, {0, -2}, {0, 2}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
    for (int i = 0; i < 13; i++)
    {
        registrarAtaque(Tabuleiro, linha + octaedro[i][0], coluna + octaedro[i][1]);
    }
    
}

int main() {
    
    char Head[10] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    int Tabuleiro [TAMANHO][TAMANHO] = {0};
    int linha, coluna;

    //Posicionar Navios

    for (int i = 0; i < TAM_NAVIO; i++) Tabuleiro[1 + i][1] = 3;  // Vertical
    for (int i = 0; i < TAM_NAVIO; i++) Tabuleiro[2][5 + i] = 3;  // Horizontal
    for (int i = 0; i < TAM_NAVIO; i++) Tabuleiro[6 + i][0 + i] = 3;  // Diagonal 
    for (int i = 0; i < TAM_NAVIO; i++) Tabuleiro[7 - i][7 + i] = 3;  // Diagonal invertida
 
    //posicionar os ataques
    ataqueCone(Tabuleiro, 0, 2); //C1
    ataqueCruz(Tabuleiro, 7, 2); //C8
    ataqueOctaedro(Tabuleiro, 7, 7); //H6

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