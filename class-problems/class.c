#include <stdio.h>
#include <stdlib.h>

/**
 * Problema
 *
 * @details
 * Crie um programa que leia as notas de uma turma de 8 alunos e,
 * depois imprima as notas que são maior que a média da turma.
 */

#define ARRAY_MAX 8

void main()
{
  int array[ARRAY_MAX];
  int classAverage = 0;

  for (int i = 0; i < ARRAY_MAX; i++)
  {
    printf("Digite a nota dos aluno %i: ", i + 1);
    scanf("%i", &array[i]);

    classAverage += array[i];
  }

  classAverage /= ARRAY_MAX;

  printf("Notas acima da media da turma (%i): ", classAverage);
  for (int i = 0; i < ARRAY_MAX; i++)
  {
    if (array[i] > classAverage)
    {
      printf("%i ", array[i]);
    }
  }
}