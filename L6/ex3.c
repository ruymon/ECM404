#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Enunciado:
 *
 * Crie uma estrutura para representar um aluno com matrícula, nome e três notas.
 * Leia os dados de 5 alunos. Exiba o nome e notas do aluno com maior média.
 * Utilize funções para:
 * - leitura de estrutura individual;
 * - leitura do vetor;
 * - cálculo da média;
 * - comparar médias de dois alunos;
 * - exibir os dados no formato:
 *   "Nome: <NOME> - Matricula: <MATRICULA> P1 <NOTA1> - P2 <NOTA2> - P3 <NOTA3> - MEDIA <MEDIA>"
 */

#define MAX_STUDENTS 5
#define MAX_NAME_LENGTH 50

typedef struct
{
  int id;
  char name[MAX_NAME_LENGTH];
  float grade1;
  float grade2;
  float grade3;
} Student;

void clearBuffer()
{
  int c;
  while ((c = getchar()) != '\n' && c != EOF)
    ;
}

void readStudent(Student *student, int index)
{
  printf("Aluno %i\n", index + 1);

  printf("Matricula: ");
  scanf("%i", &student->id);
  clearBuffer();

  printf("Nome: ");
  scanf("%49s", student->name);
  clearBuffer();

  printf("Nota 1: ");
  scanf("%f", &student->grade1);
  clearBuffer();

  printf("Nota 2: ");
  scanf("%f", &student->grade2);
  clearBuffer();

  printf("Nota 3: ");
  scanf("%f", &student->grade3);
  clearBuffer();

  printf("\n");
}

void readStudents(Student students[])
{
  for (int i = 0; i < MAX_STUDENTS; i++)
  {
    readStudent(&students[i], i);
  }
}

float calculateAverage(Student student)
{
  return (student.grade1 + student.grade2 + student.grade3) / 3.0;
}

int compareAverages(Student s1, Student s2)
{
  float avg1 = calculateAverage(s1);
  float avg2 = calculateAverage(s2);

  if (avg1 > avg2)
    return 1;
  if (avg1 < avg2)
    return -1;
  return 0;
}

void displayStudent(Student student)
{
  float average = calculateAverage(student);

  printf("Nome: %s - Matricula: %i P1 %.2f - P2 %.2f - P3 %.2f - MEDIA %.2f\n",
         student.name, student.id, student.grade1, student.grade2, student.grade3, average);
}

int main(int argc, char *argv[])
{
  Student students[MAX_STUDENTS];

  readStudents(students);

  int bestIndex = 0;

  for (int i = 1; i < MAX_STUDENTS; i++)
  {
    if (compareAverages(students[i], students[bestIndex]) > 0)
    {
      bestIndex = i;
    }
  }

  printf("Aluno com maior media:\n");
  displayStudent(students[bestIndex]);

  return 0;
}