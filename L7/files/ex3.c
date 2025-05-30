#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

/*
 * Exercício 3 - Arquivos
 * Faça um programa que receba do usuário um arquivo texto e um caractere e mostre na tela quantas vezes aquele caractere ocorre dentro do arquivo.
 */

#define FILENAME_MAX_LENGTH 100
int main()
{
    FILE *file;
    char filename[FILENAME_MAX_LENGTH];
    char ch;
    char targetChar;
    int appearanceCount = 0;

    printf("Digite o nome do arquivo (com extensão): ");
    setbuf(stdout, NULL);
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = '\0';

    file = fopen(filename, "r");
    if (file == NULL)
    {
        perror("Erro ao abrir o arquivo!");
        return 1;
    }

    printf("Digite o caractere a ser contado: ");
    setbuf(stdout, NULL);
    scanf("%c", &targetChar);

    while ((ch = fgetc(file)) != EOF)
    {
        if (tolower(ch) == tolower(targetChar))
        {
            appearanceCount++;
        }
    }

    fclose(file);

    printf("O caractere '%c' aparece %d vez(es) no arquivo %s.\n", targetChar, appearanceCount, filename);

    return 0;
}
