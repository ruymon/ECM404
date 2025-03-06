#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Enunciado - Faça um programa que leia um numero inteiro positivo par e,
 * a seguir, exiba todos os numeros pares de 0 ate o numero digitado em ordem
 * crescente, separados apenas por um espaco.
 *
 * Exemplos:
 *
 * Numero: 5
 * Digite um numero par!
 *
 * Numero: -5
 * Digite um numero positivo!
 *
 * Numero: 6
 * 0 2 4 6
 *
 * Numero: 14
 * 0 2 4 6 8 10 12 14
 */

bool isNumberOdd(int number)
{
    return (number % 2) == 0;
}

bool isNumberPositive(int number)
{
    return number > 0;
}

bool isInputValueValid(int value)
{
    if (!isNumberPositive(value))
    {
        printf("Digite um numero positivo! \n");
        return false;
    }

    if (!isNumberOdd(value))
    {
        printf("Digite um numero par! \n");
        return false;
    }

    return true;
}

void main()
{
    int value, iterator;

    printf("Numero: ");
    scanf("%i", &value);

    if (!isInputValueValid(value))
        return;

    for (iterator = 0; iterator <= value; iterator++)
    {
        isNumberOdd(iterator) && printf("%i ", iterator);
    }

    return;
}
