/*
 * Enunciado:
 * Desenvolva um programa capaz de ler uma string digitada pelo usuário e,
 * a seguir, solicite ao usuário que digite um caractere a ser buscado na
 * string digitada. O programa deve informar ao usuário se o caractere foi
 * encontrado ou não. O programa deve desconsiderar a diferença entre maiúsculas
 * e minúsculas. Utilize o algoritmo de busca que achar melhor.
 *
 * Exemplos:
 *
 *   Digite uma string: teste!
 *   Digite a chave: !
 *   Caractere ! encontrado na posição 5.
 *
 *   Digite uma string: Ola, Mundo!
 *   Digite a chave: M
 *   Caractere m encontrado na posição 5.
 *
 *   Digite uma string: Ola, Mundo!
 *   Digite a chave: m
 *   Caractere m encontrado na posição 5.
 *
 *   Digite uma string: Ola, Mundo!
 *   Digite a chave: b
 *   Caractere b não foi encontrado.
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

int getKeyPositionInString(char str[], char key[])
{
  int stringLength = strlen(str);
  int keyPosition = strcspn(str, key);

  if (stringLength == keyPosition)
  {
    return -1;
  }

  return keyPosition;
}

int main(int argc, char *argv[])
{
  char str[MAX];
  char key[MAX];

  printf("Digite uma string: ");
  fgets(str, MAX, stdin);
  str[strcspn(str, "\n")] = '\0';
  lowerString(str);

  printf("Digite a chave: ");
  fgets(key, MAX, stdin);
  key[strcspn(key, "\n")] = '\0';
  lowerString(key);

  int keyPosition = getKeyPositionInString(str, key);
  printf(keyPosition != -1 ? "Caractere %s encontrado na posição %i." : "Caractere %s não foi encontrado.", key, keyPosition);

  return 0;
}
