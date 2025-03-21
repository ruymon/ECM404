/**
 * Enunciado | Exercício 5
 *
 * @details
 * Desenvolva um programa capaz de ler os valores inteiros de uma matriz 3x3
 * e, a seguir, calcule e exiba sua determinante. O cálculo da determinante
 * deve ser feito pela função determinante, que recebe por referência uma
 * matriz 3x3 e retorna o valor inteiro referente à determinante.
 *
 * @example
 * Digite a linha 0: 2 3 4
 * Digite a linha 1: 1 3 4
 * Digite a linha 2: 5 6 7
 * -3
 *
 * @example
 * Digite a linha 0: 1 0 0
 * Digite a linha 1: 0 1 0
 * Digite a linha 2: 0 0 1
 * 1
 *
 */

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_MAX_SIZE 3

int calculateDeterminant(int matriz[ARRAY_MAX_SIZE][ARRAY_MAX_SIZE], int rowsCount, int columnsCount)
{
    int determinant = 0;

    for (int currentColumn = 0; currentColumn < columnsCount; currentColumn++)
    {
        int nextColumn = (currentColumn + 1) % columnsCount;
        int nextNextColumn = (currentColumn + 2) % columnsCount;
        
        int firstProduct = matriz[1][nextColumn] * matriz[2][nextNextColumn];
        int secondProduct = matriz[1][nextNextColumn] * matriz[2][nextColumn];
        int cofactor = firstProduct - secondProduct;
        
        determinant += matriz[0][currentColumn] * cofactor;
    }

    return determinant;
}

void main()
{
    int matrix[ARRAY_MAX_SIZE][ARRAY_MAX_SIZE];

    for (int currentRow = 0; currentRow < ARRAY_MAX_SIZE; currentRow++)
    {
        printf("Digite a linha %i: ", currentRow);

        for (int currentColumn = 0; currentColumn < ARRAY_MAX_SIZE; currentColumn++)
        {
            scanf("%i", &matrix[currentRow][currentColumn]);
        }
    }

    printf("%d", calculateDeterminant(matrix, ARRAY_MAX_SIZE, ARRAY_MAX_SIZE));
}
