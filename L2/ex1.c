#include <stdio.h>
#include <stdlib.h>

/**
 * Enunciado | Exercício 1
 *
 * @details
 * Faça um programa que receba dois números e mostre qual deles
 * é o maior. Caso os números sejam iguais, o programa deve informar o usuário.
 *
 * Os números devem ser sempre exibidos com apenas duas casas após a vírgula.
 *
 * @example
 * Digite um numero: 5
 * Digite um numero: 7.5
 * 7.50 > 5.00
 *
 * @example
 * Digite um numero: 5
 * Digite um numero: 5
 * Numeros iguais!
 */

void main()
{
  float first_number, second_number;

  printf("Digite um numero: ");
  scanf("%f", &first_number);

  printf("Digite um numero: ");
  scanf("%f", &second_number);

  (first_number == second_number) && printf("Numeros iguais! \n");
  (first_number > second_number) ? printf("%.2f > %.2f \n", first_number, second_number) : printf("%.2f > %.2f \n", second_number, first_number);

  return;
}
