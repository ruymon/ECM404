#include <stdio.h>

/*
 * Exercício 3 - Ponteiros
 * Crie um programa que contenha uma matriz de float
 * contendo 3 linhas e 3 colunas.
 * Imprima o endereço de cada posição dessa matriz.
 */

#define MATRIX_SIZE 3
int main()
{
    float matrix[MATRIX_SIZE][MATRIX_SIZE];
    int i, j;

    printf("Endereços de cada posição da matriz:\n");

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("Endereço de my_matrix[%d][%d]: %p\n", i, j, (void *)&matrix[i][j]);
        }
    }

    return 0;
}