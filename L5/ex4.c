/*
 * Enunciado:
 * Desenvolva um programa capaz de ler uma string digitada pelo usuário e,
 * a seguir, implemente a estratégia de criptografia ZENIT - POLAR.
 * A estratégia em questão consiste em substituir os caracteres da string
 * da seguinte maneira:
 *
 *            Z <-> P
 *            E <-> O
 *            N <-> L
 *            I <-> A
 *            T <-> R
 *
 * O programa deve desconsiderar a diferença entre letras maiúsculas e
 * letras minúsculas.
 *
 * Exemplos:
 *
 *   Digite uma string: polar
 *   zenit
 *
 *   Digite uma string: zenit
 *   polar
 *
 *   Digite uma string: ZeNit
 *   polar
 *
 *   Digite uma string: seu ou, e ratataci!
 *   sou eu, o tiririca!
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

void encryptString(char *str)
{
  for (int i = 0; str[i]; i++)
  {
    switch (str[i])
    {
    case 'z':
      str[i] = 'p';
      break;
    case 'e':
      str[i] = 'o';
      break;
    case 'n':
      str[i] = 'l';
      break;
    case 'i':
      str[i] = 'a';
      break;
    case 't':
      str[i] = 'r';
      break;
    case 'p':
      str[i] = 'z';
      break;
    case 'o':
      str[i] = 'e';
      break;
    case 'l':
      str[i] = 'n';
      break;
    case 'a':
      str[i] = 'i';
      break;
    case 'r':
      str[i] = 't';
      break;
    default:
      break;
    }
  }
}

int main(int argc, char *argv[])
{
  char str[MAX];

  printf("Digite uma string: ");
  fgets(str, MAX, stdin);
  str[strcspn(str, "\n")] = '\0';
  lowerString(str);

  encryptString(str);

  printf("%s\n", str);

  return 0;
}
