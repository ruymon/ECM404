/*
 * Enunciado:
 * Repita o exercício 2, mas agora o seu programa deve implementar um
 * algoritmo de ordenação para ordenar e exibir a lista de alunos em ordem
 * crescente de média.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
#define NUM_NOTAS 4
#define NOME_ARQUIVO "notas.csv"

typedef struct
{
  char nome[MAX];
  float notas[NUM_NOTAS];
  float media;
} Aluno;

typedef struct SLista
{
  Aluno aluno;
  struct SLista *prox;
} TLista;

Aluno ler_aluno(char linha[MAX]);
void exibe_aluno(Aluno a);
float calcula_media(float *notas);
int ler_alunos(TLista *alunos);
TLista *cria_lista();
TLista *destroi_lista(TLista *alunos);
void insere_no_fim(TLista *alunos, Aluno aluno);
void ordena_lista(TLista *alunos);
void troca_alunos(Aluno *a, Aluno *b);
void exibe_lista(TLista *alunos);

int main(int argc, char *argv[])
{
  TLista *lista_de_alunos = cria_lista();
  int total_alunos = ler_alunos(lista_de_alunos);

  if (total_alunos > 0)
  {
    printf("--- Lista Original ---\n");
    exibe_lista(lista_de_alunos);

    ordena_lista(lista_de_alunos);

    printf("\n--- Lista Ordenada por Media ---\n");
    exibe_lista(lista_de_alunos);
  }

  lista_de_alunos = destroi_lista(lista_de_alunos);

  return EXIT_SUCCESS;
}

void troca_alunos(Aluno *a, Aluno *b)
{
  Aluno temp = *a;
  *a = *b;
  *b = temp;
}

void ordena_lista(TLista *alunos)
{
  // Se a lista está vazia ou tem apenas um elemento, já está ordenada.
  if (alunos == NULL || alunos->prox == NULL || alunos->prox->prox == NULL)
  {
    return;
  }

  TLista *i, *j;

  for (i = alunos->prox; i != NULL; i = i->prox)
  {
    for (j = i->prox; j != NULL; j = j->prox)
    {
      if (i->aluno.media > j->aluno.media)
      {
        troca_alunos(&(i->aluno), &(j->aluno));
      }
    }
  }
}

int ler_alunos(TLista *alunos)
{
  FILE *arquivo = fopen(NOME_ARQUIVO, "r");
  if (arquivo == NULL)
  {
    perror("Erro ao abrir o arquivo 'notas.csv'");
    return 0;
  }

  char linha[MAX];
  while (fgets(linha, MAX, arquivo) != NULL)
  {
    linha[strcspn(linha, "\r\n")] = 0;

    Aluno novo_aluno = ler_aluno(linha);
    insere_no_fim(alunos, novo_aluno);
  }

  fclose(arquivo);
  return 1;
}

Aluno ler_aluno(char entrada[MAX])
{
  Aluno a;
  const char *delimitador = ",";

  char *copia_entrada = strdup(entrada);
  char *token = strtok(copia_entrada, delimitador);
  if (token != NULL)
  {
    strncpy(a.nome, token, MAX - 1);
    a.nome[MAX - 1] = '\0';
  }

  for (int i = 0; i < NUM_NOTAS; i++)
  {
    token = strtok(NULL, delimitador);
    a.notas[i] = (token != NULL) ? atof(token) : 0.0f;
  }

  free(copia_entrada);

  a.media = calcula_media(a.notas);
  return a;
}

TLista *cria_lista()
{
  TLista *cabeca = (TLista *)malloc(sizeof(TLista));
  if (cabeca == NULL)
    exit(EXIT_FAILURE);
  cabeca->prox = NULL;
  return cabeca;
}

TLista *destroi_lista(TLista *alunos)
{
  TLista *atual = alunos;
  TLista *proximo_no;
  while (atual != NULL)
  {
    proximo_no = atual->prox;
    free(atual);
    atual = proximo_no;
  }
  return NULL;
}

void insere_no_fim(TLista *alunos, Aluno aluno)
{
  TLista *novo_no = (TLista *)malloc(sizeof(TLista));
  if (novo_no == NULL)
    exit(EXIT_FAILURE);

  novo_no->aluno = aluno;
  novo_no->prox = NULL;

  TLista *aux = alunos;
  while (aux->prox != NULL)
  {
    aux = aux->prox;
  }
  aux->prox = novo_no;
}

float calcula_media(float *notas)
{
  float soma = 0.0f;
  for (int i = 0; i < NUM_NOTAS; i++)
  {
    soma += notas[i];
  }
  return soma / NUM_NOTAS;
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