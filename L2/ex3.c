#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * Enunciado | Exercício 3
 *
 * @details
 * Faça um programa que receba um número inteiro e, a seguir,
 * exibe todos os seus possíveis divisores separados apenas por um espaço.
 *
 * @example
 * Digite um numero: 7
 * 1 7
 *
 * @example
 * Digite um numero: 12
 * 1 2 3 4 6 12
 *
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

    // iteration has to start at 1 because you cant divide by zero...
    for (iteration = 1; iteration <= value; iteration++)
    {
        isFullyDivisable(value, iteration) && printf("%i ", iteration);
    }

    return;
}
