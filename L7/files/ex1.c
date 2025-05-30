#include <stdio.h>

/*
 * Exercício 1 - Arquivos
 *
 * Escreva um programa que:
 * a. Crie/abra um arquivo texto de nome “arq.txt”
 * b. Permita que o usuário grave diversos caracteres nesse arquivo, até que o usuário entre com o caractere ‘0’
 * c. Feche o arquivo
 * d. Agora, abra e leia o arquivo, caractere por caractere, e escreva na tela todos os caracteres armazenados.
 */

int main()
{
  FILE *file;
  char ch;

  file = fopen("arq.txt", "w");
  if (file == NULL)
  {
    perror("Erro ao abrir o arquivo");
    return 1;
  }

  printf("Digite caracteres para gravar no arquivo (digite '0' para sair):\n");
  while (1)
  {
    ch = getchar();
    if (ch == '0')
    {
      break;
    }
    fputc(ch, file);
  }

  fclose(file);

  file = fopen("arq.txt", "r");
  if (file == NULL)
  {
    perror("Erro ao abrir o arquivo para leitura");
    return 1;
  }

  printf("Conteúdo do arquivo:\n");
  while ((ch = fgetc(file)) != EOF)
  {
    putchar(ch);
  }

  fclose(file);
  printf("\nArquivo lido com sucesso.\n");
  return 0;
}
