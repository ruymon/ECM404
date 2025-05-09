/*
 * Enunciado:
 * Desenvolva um programa capaz de ler uma string digitada pelo usuário e,
 * a seguir, informe-o se o valor digitado se trata de um palíndromo ou não.
 * O programa deve desconsiderar diferença entre maiúsculas e minúsculas.
 *
 * Exemplos:
 *
 *  Digite uma string: racecar
 *  É palíndromo
 *
 *  Digite uma string: oi
 *  Não é palíndromo
 *
 *  Digite uma string: RaceCar
 *  É palíndromo
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX 100

bool isPalindrome(char str[])
{
  int leftPointer = 0;
  int rightPointer = strlen(str) - 1;

  while (leftPointer < rightPointer)
  {
    if (tolower(str[leftPointer]) != tolower(str[rightPointer]))
    {
      return false;
    }

    leftPointer++;
    rightPointer--;
  }

  return true;
}

int main(int argc, char *argv[])
{
  char str[MAX];

  printf("Digite uma string: ");
  fgets(str, MAX, stdin);
  str[strcspn(str, "\n")] = '\0'; // remove o '\n'

  printf(isPalindrome(str) ? "É palíndromo" : "Náo é palíndromo");

  return 0;
}
