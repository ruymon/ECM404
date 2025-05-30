#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
 * Exercício 5 - Arquivos
 * Faça um programa que receba dois arquivos do usuário e crie um terceiro arquivo com o conteúdo dos dois arquivos recebidos juntos (o conteúdo do primeiro seguido do conteúdo do segundo).
 */

#define FILENAME_MAX_LENGTH 100
#define OUTPUT_FILENAME "output.txt"
int main()
{
    FILE *file1, *file2, *outputFile;
    char filename1[FILENAME_MAX_LENGTH];
    char filename2[FILENAME_MAX_LENGTH];
    char ch;

    printf("Digite o nome do primeiro arquivo (com extensão): ");
    setbuf(stdout, NULL);
    fgets(filename1, FILENAME_MAX_LENGTH, stdin);
    filename1[strcspn(filename1, "\n")] = '\0';

    printf("Digite o nome do segundo arquivo (com extensão): ");
    setbuf(stdout, NULL);
    fgets(filename2, FILENAME_MAX_LENGTH, stdin);
    filename2[strcspn(filename2, "\n")] = '\0';

    outputFile = fopen(OUTPUT_FILENAME, "w");
    if (outputFile == NULL)
    {
        perror("Erro ao criar o arquivo de saída!");
        return 1;
    }

    file1 = fopen(filename1, "r");
    if (file1 == NULL)
    {
        perror("Erro ao abrir o primeiro arquivo!");
        fclose(outputFile);
        return 1;
    }

    while ((ch = fgetc(file1)) != EOF)
    {
        fputc(ch, outputFile);
    }

    fclose(file1);
    fclose(outputFile);

    outputFile = fopen(OUTPUT_FILENAME, "a");
    if (outputFile == NULL)
    {
        perror("Erro ao abrir o arquivo de saída para escrita!");
        return 1;
    }
    file2 = fopen(filename2, "r");
    if (file2 == NULL)
    {
        perror("Erro ao abrir o segundo arquivo!");
        fclose(outputFile);
        return 1;
    }
    while ((ch = fgetc(file2)) != EOF)
    {
        fputc(ch, outputFile);
    }
    fclose(file2);
    fclose(outputFile);

    printf("Conteúdo dos arquivos '%s' e '%s' foi combinado no arquivo '%s'.\n", filename1, filename2, OUTPUT_FILENAME);

    return 0;
}
