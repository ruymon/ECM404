/*
 * Enunciado:
 * Desenvolva um programa capaz de ler uma lista de nomes separados por vírgula
 * digitados por um usuário e, a seguir, armazená-los em um array de strings,
 * que deve ser exibido utilizando o procedimento exibe_nomes fornecido.
 * A quantidade de nomes digitados deve ser sempre 5 (definido por MAX_NOMES).
 *
 * Dica: pesquise pela função strtok
 *
 * Exemplo (**CUIDADO COM O ESPAÇO APÓS A VÍRGULA**):
 *
 *   Nomes: Matheus,Ana Julia,Marco Antonio,Joao,Victoria
 *   ['Matheus', 'Ana Julia', 'Marco Antonio', 'Joao', 'Victoria']
 *
 *   Nomes: Julio,Tiririca,Diego,Alexandre,Nicola
 *   ['Julio', 'Tiririca', 'Diego', 'Alexandre', 'Nicola']
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAMES 5
#define ARR_MAX_SIZE 100

void displayNames(char names[MAX_NAMES][ARR_MAX_SIZE]);

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
