/*
 * Enunciado:
 * Desenvolva um programa capaz de ler uma palavra digitada pelo usuário e,
 * a seguir, deve exibir uma string contendo os caracteres da palavra digitada
 * em ordem alfabética. Utilize o algoritmo de ordenação que preferir.
 * O programa deve desconsiderar a diferença entre letras maiúsculas e
 * letras minúsculas.
 *
 * Exemplos:
 *
 *   Digite uma palavra: ola
 *   alo
 *
 *   Digite uma palavra: alo
 *   alo
 *
 *   Digite uma palavra: RaceCar
 *   aaccerr
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

void lowerString(char *str)
{
  for (int i = 0; str[i]; i++)
  {
    str[i] = tolower(str[i]);
  }
}

void sortAlphabetical(char *str)
{
  int strLength = strlen(str);

  for (int i = 0; i < strLength; i++)
  {
    for (int j = i + 1; j < strLength; j++)
    {
      if (str[i] > str[j])
      {
        char temp = str[j];

        str[j] = str[i];
        str[i] = temp;
      }
    }
  }
}

int main(int argc, char *argv[])
{
  char str[MAX];

  printf("Digite uma palavra: ");
  fgets(str, MAX, stdin);
  str[strcspn(str, "\n")] = '\0';

  lowerString(str);
  sortAlphabetical(str);

  printf("%s\n", str);

  return 0;
}
