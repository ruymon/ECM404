/*
 * Enunciado:
 *    Crie uma lista ligada de alunos, em que cada aluno deve consistir de um
 *    struct contendo o seu RA, 4 notas e a m�dia do aluno. O programa
 *    principal deve pedir para que o usu�rio digite o RA e as 4 notas de
 *    3 alunos, para a seguir exibir a lista ligada completa (use exibe_lista).
 *
 * Exemplos:
 *
 *    Aluno: Rodrigo 2 3 4 5
 *    Aluno: Alexandre 10 10 8 9
 *    Aluno: Diego 7 8 10 10
 *    (Rodrigo | 3.50) -> (Alexandre | 9.25) -> (Diego | 8.75)
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct
{
  char nome[MAX];
  float notas[4];
  float media;
} Aluno;

typedef struct SLista
{
  Aluno aluno;
  struct SLista *prox;
} TLista;

/* Fun��es recomendadas (n�o precisa implementar nenhuma delas se n�o quiser)
 */
Aluno ler_aluno();
void exibe_aluno(Aluno a);
float calcula_media(float *notas);

TLista *cria_lista();
TLista *destroi_lista(TLista *alunos);
void insere_no_fim(TLista *alunos, Aluno aluno);

/* Fun��es para uso livre */
void exibe_lista(TLista *alunos); // exibe uma lista de alunos
void ler_string(char *s);         // le uma string de forma "segura"

int main(int argc, char *argv[])
{

  return EXIT_SUCCESS;
}

Aluno ler_aluno()
{
}

float calcula_media(float *notas)
{
}

TLista *cria_lista()
{
}

TLista *destroi_lista(TLista *alunos)
{
}

void insere_no_fim(TLista *alunos, Aluno aluno)
{
}

void exibe_aluno(Aluno a)
{
  printf("(%s | %.2f)", a.nome, a.media);
}

void exibe_lista(TLista *alunos)
{
  TLista *aux = alunos->prox;
  while (aux != NULL)
  {
    exibe_aluno(aux->aluno);
    if (aux->prox != NULL)
      printf(" -> ");
    aux = aux->prox;
  }
  printf("\n");
}

void ler_string(char *s)
{
  scanf("\n");
  fgets(s, MAX, stdin);
  size_t tam = strlen(s);
  if (s[tam - 1] == '\n')
    s[tam - 1] = '\0';
}
