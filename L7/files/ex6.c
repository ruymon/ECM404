#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Exercício 6 - Arquivos
 *
 * Crie um programa que receba como entrada o número de alunos de uma disciplina.
 * Aloque dinamicamente dois vetores para armazenar as informações a respeito desses alunos.
 * O primeiro vetor contém o nome dos alunos e o segundo contém suas notas finais.
 * Crie um arquivo que armazene, a cada linha, o nome do aluno e sua nota final.
 * Use nomes com no máximo 40 caracteres. Se o nome não contém 40 caracteres,
 * complete com espaço em branco.
 */

#define MAX_NAME_LENGTH 40
#define MAX_STUDENTS 100
#define OUTPUT_FILENAME "students.txt"

typedef struct
{
    char name[MAX_NAME_LENGTH];
    float grade;
} Student;

int main()
{
    int studentsCount;

    printf("Digite o número de alunos: ");
    scanf("%i", &studentsCount);

    if (studentsCount <= 0 || studentsCount > MAX_STUDENTS)
    {
        printf("Número de alunos inválido. Deve ser entre 1 e %i.\n", MAX_STUDENTS);
        return 1;
    }

    Student *students = malloc(studentsCount * sizeof(Student));
    if (students == NULL)
    {
        perror("Erro ao alocar memória para os alunos");
        return 1;
    }

    for (int i = 0; i < studentsCount; i++)
    {
        printf("Digite o nome do aluno %i: ", i + 1);
        setbuf(stdin, NULL);
        fgets(students[i].name, MAX_NAME_LENGTH, stdin);
        students[i].name[strcspn(students[i].name, "\n")] = '\0';

        for (int j = strlen(students[i].name); j < MAX_NAME_LENGTH - 1; j++)
        {
            students[i].name[j] = ' ';
        }
        students[i].name[MAX_NAME_LENGTH - 1] = '\0';

        printf("Digite a nota final do aluno %i: ", i + 1);
        scanf("%f", &students[i].grade);
    }

    FILE *file = fopen(OUTPUT_FILENAME, "w");
    if (file == NULL)
    {
        perror("Erro ao abrir o arquivo para escrita");
        free(students);
        return 1;
    }
    for (int i = 0; i < studentsCount; i++)
    {
        fprintf(file, "%s %.2f\n", students[i].name, students[i].grade);
    }
    fclose(file);
    free(students);
    printf("Dados dos alunos salvos no arquivo '%s'.\n", OUTPUT_FILENAME);

    return 0;
}
