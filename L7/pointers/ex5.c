#include <stdio.h>

/*
 * Exercício 5 - Ponteiros
 * Implemente um programa que leia dois valores inteiros (A e B).
 * A seguir, troque os seus valores utilizando a subrotina troca_valores.
 * A subrotina deve receber dois ponteiros para inteiros e trocar os seus valores de lugar.
 */

void switchValues(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int A, B;

    printf("Digite o valor de A: ");
    scanf("%d", &A);
    printf("Digite o valor de B: ");
    scanf("%d", &B);

    printf("Antes da troca: A = %d, B = %d\n", A, B);

    switchValues(&A, &B);

    printf("Depois da troca: A = %d, B = %d\n", A, B);

    return 0;
}