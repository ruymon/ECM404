#include <stdio.h>
#include <stdlib.h>

/* Enunciado:
 *
 * Elabore um programa que leia dois numero inteiros
 * troque os valores entre as variáveis e os imprima
 *
 * Ex:
 *      Digite um numero: 5
 *      Digite um numero: 7
 *      7 5
 *
 */

int main(int argc, char *argv[])
{
  int first_number, second_number;

  printf("Digite um numero: ");
  scanf("%i", &first_number);

  printf("Digite um numero: ");
  scanf("%i", &second_number);

  // Variável pivô.
  int temp = first_number;
  first_number = second_number;
  second_number = temp;

  printf("%i %i\n", first_number, second_number);

  return 0;
}
