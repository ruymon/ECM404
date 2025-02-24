#include <stdio.h>
#include <stdlib.h>

/* Enunciado:
 *
 * Elabore um programa que leia um numero de 5 digitos e, em seguida, exiba
 * o numero digitado com os digitos invertidos.
 *
 * Ex:
 *      Digite um numero: 54321
 *      12345
 *
 *      Digite um numero: 38271
 *      17283
 *
 */

int main(int argc, char *argv[])
{
  int five_digit_value;

  printf("Digite um numero: ");
  scanf("%i", &five_digit_value);

  // Todo: Refatorar isso para usar um laço.

  int fith_digit = five_digit_value / 10000;
  int fith_digit_remainder = (five_digit_value % 10000);

  int forth_digit = fith_digit_remainder / 1000;
  int forth_digit_remainder = fith_digit_remainder % 1000;

  int third_digit = forth_digit_remainder / 100;
  int third_digit_remainder = forth_digit_remainder % 100;

  int second_digit = third_digit_remainder / 10;
  int second_digit_remainder = third_digit_remainder % 10;

  int first_digit = second_digit_remainder / 1;

  printf("%i%i%i%i%i\n", first_digit, second_digit, third_digit, forth_digit, fith_digit);

  return 0;
}
