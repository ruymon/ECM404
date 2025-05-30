#include <stdio.h>

/*
 * Exercício 2 - Ponteiros
 * Crie um programa que contenha um array de float contendo 10 elementos.
 * Imprima o endereço de cada posição desse array.
 */

#define ARR_SIZE 10
int main()
{
    float arr[ARR_SIZE];
    int i;

    printf("Endereços de cada posição do array:\n");
    for (i = 0; i < ARR_SIZE; i++)
    {
        // Use %p format specifier to print the address
        printf("Endereço do vetor[%d]: %p\n", i, (void *)&arr[i]);
    }

    return 0;
}