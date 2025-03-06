#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/** Enunciado - Em matemática, o número harmônico designado por H(n) define-se
 * como sendo a soma da série harmônica:
 *
 *                         H(n) = 1 + 1/2 + 1/3 + 1/4 + ... + 1/n
 *
 * @see https://pt.wikipedia.org/wiki/S%C3%A9rie_harm%C3%B3nica_(matem%C3%A1tica)
 *
 * Faça um programa que leia um valor n inteiro e positivo e
 * apresente o valor de H(n) com duas casas decimais
 *
 * Exemplos:
 *
 * Digite um valor para n: 10
 * 2.93
 *
 * Digite um valor para n: -1
 * Erro, n menor que 0!
 */

bool isNumberPositive(int number)
{
    return number > 0;
}

bool isInputValueValid(int value)
{
    if (!isNumberPositive(value))
    {
        printf("Erro, n menor ou igual a 0! \n");
        return false;
    }

    return true;
}

float calculateHarmonicNumber(int number)
{
    float iterator, harmonicNumber; // Necessário o `iterator` ser float por ser o divisor (denominador).

    for (iterator = 1.0; iterator <= number; iterator++)
    {
        harmonicNumber += (1 / iterator);
    }

    return harmonicNumber;
}

void main()
{
    int value;

    printf("Digite um valor para n: ");
    scanf("%i", &value);

    isInputValueValid(value) && printf("%.2f \n", calculateHarmonicNumber(value));

    return;
}
