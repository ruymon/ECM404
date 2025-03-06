#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * Enunciado | Exercício 2
 *
 * @details
 * Faça um programa que receba um número inteiro digitado pelo
 * usuário e retorna se o número é par ou ímpar.
 *
 * @example
 * Digite um numero: 5
 * Impar
 *
 * @example
 * Digite um numero: 4
 * Par
 */

bool isNumberOdd(int number)
{
  return (number % 2) == 0;
}

void main()
{
  int value;

  printf("Digite um numero: ");
  scanf("%i", &value);

  printf(isNumberOdd(value) ? "Par \n" : "Impar \n");

  return;
}