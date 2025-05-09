/*
 * Enunciado:
 * Desenvolva um programa capaz de ler uma string digitada pelo usuário e,
 * a seguir, ler um intervalo separado por vírgula que deve ser utilizado para
 * gerar uma substring que começa no início do intervalo digitado e termina no
 * índice final (intervalo fechado).
 *
 * Exemplos:
 *
 * Digite uma string: Oi, eu sou o Goku!
 * Intervalo: 0, 9
 * Oi, eu sou
 *
 * Digite uma string: 0123456789
 * Intervalo: 3,7
 * 34567
 *
 * Digite uma string: Estruturas de Dados
 * Intervalo: 3, 12
 * ruturas de
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int main(int argc, char *argv[])
{
  char str[MAX];
  char stepStr[MAX];
  int start, end;

  printf("Digite uma string: ");
  fgets(str, MAX, stdin);
  str[strcspn(str, "\n")] = '\0';

  printf("Intervalo: ");
  fgets(stepStr, MAX, stdin);
  stepStr[strcspn(stepStr, "\n")] = '\0';

  char *token = strtok(stepStr, ",");
  if (token != NULL)
    start = atoi(token);

  token = strtok(NULL, ",");
  if (token != NULL)
    end = atoi(token);

  for (int i = start; i <= end; ++i)
  {
    printf("%c", str[i]);
  }

  printf("\n");

  return 0;
}
