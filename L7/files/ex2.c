#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
 * Exercício 2 - Arquivos
 * Faça um programa que receba do usuário um arquivo texto e mostra na tela quantas linhas esse arquivo possui.
 */

int main()
{
    FILE *file;
    char filename[100];
    char ch;
    int lineCount = 1;

    printf("Digite o nome do arquivo (com extensão): ");
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = '\0';

    file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo %s.\n", filename);
        return 1;
    }

    while ((ch = fgetc(file)) != EOF)
    {
        if (ch == '\n')
        {
            lineCount++;
        }
    }

    fclose(file);

    printf("O arquivo %s possui %d linha(s).\n", filename, lineCount);
    return 0;
}
