/**
 *  Enunciado | Exercício 1
 *
 * @details
 * Desenvolva um programa capaz de ler n valores inteiros e os
 * insira em um array. A leitura deve ser feita em uma única linha, separando
 * os valores por espaço. A leitura deve ser encerrada quando um
 * valor -100 é lido. Após a leitura ser realizada, o programa deve utilizar
 * o procedimento exibe_array para exibir o array em uma única linha
 * e entre colchetes.
 *
 *  @example
 *  Digite os valores para o array: 1 2 3 4 5 6 7 8 -100
 *  [1, 2, 3, 4, 5, 6, 7, 8]
 *
 * @example
 *  Digite os valores para o array: 1 2 3 4 -100
 *  [1, 2, 3, 4]
 *
 */

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_MAX 100

void showArray(int array[], int array_size);

void showArray(int array[], int array_size)
{
    printf("[");

    for (int i = 0; i < array_size; i++)
    {
        if (i == array_size - 1)
        {
            printf("%d", array[i]);
        }
        else
        {
            printf("%d, ", array[i]);
        }
    }

    printf("]\n");
}

void main()
{
    int array[ARRAY_MAX];
    int i = 0;

    printf("Digite os valores para o array: ");

    while (1)
    {
        scanf("%i", &array[i]);

        if (array[i] == -100)
        {
            break;
        }

        i++;
    }

    showArray(array, i);
}
