#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Enunciado - Faça um programa que receba um número inteiro e, a seguir,
 * exibe todos os seus possíveis divisores separados apenas por um espaço.
 *
 * Exemplos:
 *
 * Digite um numero: 7
 * 1 7
 *
 * Digite um numero: 12
 * 1 2 3 4 6 12
 */

bool isFullyDivisable(int dividend, int divisor)
{
    return (dividend % divisor) == 0;
}

void main()
{
    int value, iteration;

    printf("Digite um numero: ");
    scanf("%i", &value);

    for (iteration = 1; iteration <= value; iteration++)
    {
        isFullyDivisable(value, iteration) && printf("%i ", iteration);
    }

    return;
}
