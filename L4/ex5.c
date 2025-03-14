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
    /**
     * Observação para eu do futuro:
     *
     * Por mais que o exercício garantiu que a matriz é 3x3,
     * implicando, portanto, que a determinante poderia ser
     * calculada pelo método de Sarrus, apliquei nesse
     * algorítimo a expansão de Laplace pois possibilita
     * a resolução de uma determinante de matriz n dimensional.
     */
}

void main()
{
    printf("Hello world!\n");
}
