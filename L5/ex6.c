/*
 * Enunciado:
 * Desenvolva um programa capaz de ler duas palavras digitadas pelo usuário e,
 * a seguir, deve informá-lo se as palavras formam um anagrama. O programa deve
 * desconsiderar a diferença entre letras maiúsculas e letras minúsculas.
 *
 * Exemplos:
 *
 * Digite uma palavra: bored
 * Digite uma palavra: robed
 * bored é anagrama de robed
 *
 * Digite uma palavra: bored
 * Digite uma palavra: robbed
 * bored não é anagrama de robbed
 *
 * Digite uma palavra: ooi
 * Digite uma palavra: oii
 * ooi não é anagrama de oii
 *
 * Digite uma palavra: ooi
 * Digite uma palavra: ioo
 * ooi é anagrama de ioo
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX 100

void lowerString(char *str)
{
  for (int i = 0; str[i]; i++)
  {
    str[i] = tolower(str[i]);
  }
}

void sortString(char *str)
{
  int length = strlen(str);
  for (int i = 0; i < length - 1; i++)
  {
    for (int j = i + 1; j < length; j++)
    {
      if (str[i] > str[j])
      {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
      }
    }
  }
}

bool isAnagram(char firstStr[], char secondStr[])
{
  char strA[MAX], strB[MAX];

  strcpy(strA, firstStr);
  strcpy(strB, secondStr);

  sortString(strA);
  sortString(strB);

  if (strcmp(strA, strB) != 0)
  {
    return false;
  }

  return true;
}

int main(int argc, char *argv[])
{
  char firstStr[MAX], secondStr[MAX];

  printf("Digite uma palavra: ");
  fgets(firstStr, MAX, stdin);
  firstStr[strcspn(firstStr, "\n")] = '\0';
  lowerString(firstStr);

  printf("Digite uma palavra: ");
  fgets(secondStr, MAX, stdin);
  secondStr[strcspn(secondStr, "\n")] = '\0';
  lowerString(secondStr);

  printf("%s%s é anagrama de %s\n", firstStr, isAnagram(firstStr, secondStr) ? "" : "não", secondStr);

  return 0;
}
