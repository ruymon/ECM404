#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

/*
 * Exercício 4 - Arquivos
 * Faça um programa que receba do usuário um arquivo texto, crie outro arquivo contendo o texto do arquivo de entrada, mas com as vogais substituídas por ‘*’.
 */

#define FILENAME_MAX_LENGTH 100
#define OUTPUT_FILENAME "output.txt"

char replaceVowelWithAsterisk(char ch)
{
    char parsedCh = tolower(ch);
    switch (parsedCh)
    {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
        return '*';

    default:
        return ch;
    }
}
int main()
{
    FILE *inputFile, *outputFile;
    char inputFilename[FILENAME_MAX_LENGTH];
    char ch;

    printf("Digite o nome do arquivo (com extensão): ");
    setbuf(stdout, NULL);
    fgets(inputFilename, sizeof(inputFilename), stdin);
    inputFilename[strcspn(inputFilename, "\n")] = '\0';

    inputFile = fopen(inputFilename, "r");
    if (inputFile == NULL)
    {
        perror("Erro ao abrir o arquivo!");
        return 1;
    }

    outputFile = fopen(OUTPUT_FILENAME, "w");
    if (outputFile == NULL)
    {
        perror("Erro ao criar o arquivo de saída!");
        fclose(inputFile);
        return 1;
    }

    while ((ch = fgetc(inputFile)) != EOF)
    {
        char modifiedChar = replaceVowelWithAsterisk(ch);
        fputc(modifiedChar, outputFile);
    }

    fclose(inputFile);
    fclose(outputFile);
    printf("Arquivo '%s' copiado para '%s' com as vogais substituídas por '*'.\n", inputFilename, OUTPUT_FILENAME);

    return 0;
}
