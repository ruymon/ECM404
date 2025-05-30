#include <stdio.h>

/*
 * Exercício 1 - Ponteiros
 *
 * Faça um programa que leia dois valores inteiros e chame uma função
 * que receba estes 2 valores de entrada e retorne o maior valor na primeira
 * variável e o menor valor na segunda variável.
 * Escreva o conteúdo das 2 variáveis na tela.
 */

void orderValues(int *val1, int *val2)
{
    if (*val1 < *val2)
    {
        int temp = *val1;
        *val1 = *val2;
        *val2 = temp;
    }
}

int main()
{
    int a, b;

    printf("Digite o primeiro valor inteiro: ");
    scanf("%d", &a);
    printf("Digite o segundo valor inteiro: ");
    scanf("%d", &b);

    orderValues(&a, &b);
    printf("Depois de ordenar: Primeiro valor = %d, Segundo valor = %d\n", a, b);

    return 0;
}