#include <stdio.h>

/*
 * Exercício 4 - Ponteiros
 * Escreva uma função que receba um array de inteiros V e
 * os endereços de duas variáveis inteiras, min e max,
 * e armazene nessas variáveis o valor mínimo e máximo do array.
 */

void findMinMax(int V[], int size, int *min, int *max)
{
    int i;

    *min = V[0];
    *max = V[0];

    for (i = 1; i < size; i++)
    {
        if (V[i] < *min)
        {
            *min = V[i];
        }

        if (V[i] > *max)
        {
            *max = V[i];
        }
    }
}

int main()
{
    int array[] = {5, 1, 9, 2, 7, 3, 8, 4, 6, 0};
    int arraySize = sizeof(array) / sizeof(array[0]);
    int minimumValue, maximumValue;

    findMinMax(array, arraySize, &minimumValue, &maximumValue);

    printf("Array: ");
    for (int i = 0; i < arraySize; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
    printf("Valor mínimo do array: %d\n", minimumValue);
    printf("Valor máximo do array: %d\n", maximumValue);

    return 0;
}