#include <stdio.h>
#include <stdlib.h> // Required for EXIT_SUCCESS, though not strictly needed for this simple case

/*
 * Exercício 6 - Ponteiros
 * Implemente um programa que permita a entrada de valores de um array
 * cujo tamanho máximo é definido pela constante MAX.
 * A quantidade de valores armazenado no vetor será definida pelo usuário
 * (quando digitar -100, a leitura para).
 *
 * É obrigatório o uso da subrotina ler_vetor, que recebe como
 * parâmetros um ponteiro que aponta para o início do vetor
 * e um ponteiro para um valor inteiro que representa o tamanho real do vetor.
 */

#define MAX 100

void ler_vetor(int *vetor, int *tamanho_real)
{
    int i = 0;
    int valor_lido;

    printf("Digite os valores do array (digite -100 para parar):\n");

    while (i < MAX)
    {
        printf("Valor [%d]: ", i);
        scanf("%d", &valor_lido);

        if (valor_lido == -100)
        {
            break;
        }

        *(vetor + i) = valor_lido;
        i++;
    }

    *tamanho_real = i;
}

int main()
{
    int my_array[MAX];
    int real_size = 0;
    int i;

    ler_vetor(my_array, &real_size);

    printf("\nValores lidos no array (tamanho real: %d):\n", real_size);

    for (i = 0; i < real_size; i++)
    {
        printf("%d ", my_array[i]);
    }
    printf("\n");

    return 0;
}