/*
 * Enunciado:
 * Desenvolva um programa capaz de ler uma lista de nomes separados por vírgula
 * digitados por um usuário e, a seguir, armazená-los em um array de strings.
 * O array deve ser ordenado alfabeticamente e, em seguida, exibido utilizando o
 * procedimento exibe_nomes fornecido. A quantidade de nomes digitada deve ser
 * sempre 5 (definido por MAX_NOMES). O programa deve desconsiderar a diferença
 * entre letras maiúsculas e minúsculas.
 *
 * Dica: pesquise pela função strtok.
 *
 * Exemplo (**CUIDADO COM O ESPAÇO APÓS A VÍRGULA**):
 *
 *   Nomes: Julio,Tiririca,Diego,Alexandre,Nicola
 *   ['alexandre', 'diego', 'julio', 'nicola', 'tiririca']
 *
 *   Nomes: Matheus,Ana Julia,Marco Antonio,Joao,Victoria
 *   ['ana julia', 'joao', 'marco antonio', 'matheus', 'victoria']
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_NAMES 5
#define ARR_MAX_SIZE 100

void displayNames(char names[MAX_NAMES][ARR_MAX_SIZE]);
void orderNames(char names[MAX_NAMES][ARR_MAX_SIZE]);

void orderNames(char names[MAX_NAMES][ARR_MAX_SIZE])
{
  char temp[ARR_MAX_SIZE];
  for (int i = 0; i < MAX_NAMES - 1; ++i)
  {
    for (int j = i + 1; j < MAX_NAMES; ++j)
    {
      if (strcasecmp(names[i], names[j]) > 0)
      {
        strcpy(temp, names[i]);
        strcpy(names[i], names[j]);
        strcpy(names[j], temp);
      }
    }
  }
}

int main(int argc, char *argv[])
{
  char input[ARR_MAX_SIZE];
  const char delimiter[2] = ",";
  char names[MAX_NAMES][ARR_MAX_SIZE];
  char *token;

  printf("Nomes: ");
  fgets(input, ARR_MAX_SIZE, stdin);
  input[strcspn(input, "\n")] = '\0';

  int i = 0;
  token = strtok(input, delimiter);
  while (token != NULL && i < MAX_NAMES)
  {
    strcpy(names[i], token);
    token = strtok(NULL, delimiter);
    i++;
  }

  orderNames(names);
  displayNames(names);
  return 0;
}

void displayNames(char names[MAX_NAMES][ARR_MAX_SIZE])
{
  printf("[");
  for (int i = 0; i < MAX_NAMES; ++i)
  {
    printf("'%s'", names[i]);
    if (i != MAX_NAMES - 1)
      printf(", ");
  }
  printf("]\n");
}
