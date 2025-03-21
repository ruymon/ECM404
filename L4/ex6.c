/**
 * Enunciado | Exercício 6
 *
 * @details
 * Desenvolva um programa capaz de ler os valores inteiros de uma matriz 3x3
 * e, a seguir
 *
 * @example
 * Digite a linha 0: 1 2 3
 * Digite a linha 1: 4 5 6
 * Digite a linha 2: 7 8 9
 * [[1, 4, 7],
 * [2, 5, 8],
 * [3, 6, 9]]
 *
 * @example
 * Digite a linha 0: 1 0 0
 * Digite a linha 1: 0 1 0
 * Digite a linha 2: 0 0 1
 * [[1, 0, 0],
 * [0, 1, 0],
 * [0, 0, 1]]
 *
 */

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_MAX_SIZE 3

void displayMatrix(int matrix[ARRAY_MAX_SIZE][ARRAY_MAX_SIZE], int rowsCount, int columnsCount)
{
    printf("[");
    for (int displayRow = 0; displayRow < rowsCount; displayRow++)
    {
        printf("[");
        for (int displayColumn = 0; displayColumn < columnsCount; displayColumn++)
        {
            printf((displayColumn == columnsCount - 1 ? "%i" : "%i, "), matrix[displayRow][displayColumn]);
        }
        printf(displayRow == rowsCount - 1 ? "]" : "],\n");
    }
    printf("]");
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

    displayMatrix(matrix, ARRAY_MAX_SIZE, ARRAY_MAX_SIZE);
}
