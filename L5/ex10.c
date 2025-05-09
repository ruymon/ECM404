/*
 * Enunciado:
 * Desenvolva um programa capaz de ler uma string digitada pelo usuário e,
 * a seguir, exibir o maior palíndromo possível dentro da string digitada.
 * Caso não haja nenhum palíndromo possível, o programa deve alertar o usuário.
 * O programa deve desconsiderar diferenças entre letras minúsculas e letras
 * maiúsculas.
 *
 * Exemplos:
 *
 *   Digite uma string: tiririca
 *   iriri
 *
 *   Digite uma string: I have a racecar
 *   racecar
 *
 *   Digite uma string: Cuidado com o Diego
 *   dad
 *
 *   Digite uma string: Alexandre
 *   Não existe nenhum palíndromo possível
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

void toLowerString(char s[MAX]);
int isPalindrome(char s[MAX]);
void substring(char dest[MAX], char src[MAX], int start, int end);
void findLargestPalindrome(char input[MAX], char result[MAX]);

int main(int argc, char *argv[])
{
  char input[MAX];
  char largestPalindrome[MAX];

  printf("Digite uma string: ");
  fgets(input, MAX, stdin);
  input[strcspn(input, "\n")] = '\0';

  findLargestPalindrome(input, largestPalindrome);

  if (strlen(largestPalindrome) > 0)
  {
    printf("%s\n", largestPalindrome);
  }
  else
  {
    printf("Não existe nenhum palíndromo possível\n");
  }

  return 0;
}

void toLowerString(char s[MAX])
{
  for (int i = 0; s[i] != '\0'; i++)
  {
    s[i] = tolower(s[i]);
  }
}

int isPalindrome(char s[MAX])
{
  int len = strlen(s);
  for (int i = 0; i < len / 2; i++)
  {
    if (s[i] != s[len - i - 1])
      return 0;
  }
  return 1;
}

void substring(char dest[MAX], char src[MAX], int start, int end)
{
  int j = 0;
  for (int i = start; i <= end; i++)
  {
    dest[j++] = src[i];
  }
  dest[j] = '\0';
}

void findLargestPalindrome(char input[MAX], char result[MAX])
{
  char lowerInput[MAX];
  char temp[MAX];
  int maxLength = 0;

  strcpy(lowerInput, input);
  toLowerString(lowerInput);

  for (int i = 0; i < strlen(lowerInput); i++)
  {
    for (int j = i; j < strlen(lowerInput); j++)
    {
      substring(temp, lowerInput, i, j);
      if (isPalindrome(temp) && strlen(temp) > maxLength)
      {
        maxLength = strlen(temp);
        substring(result, input, i, j);
      }
    }
  }

  if (maxLength == 0)
  {
    result[0] = '\0';
  }
}