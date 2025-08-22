/*
 * Enunciado:
 * Repita o exercício anterior, mas agora utilize como entrada o arquivo
 * notas.csv. A quantidade de alunos pode ser diferente de 3.
 *
 * Exemplo de linha:
 * Rodrigo,1,2,3,4
 *
 * Note que o separador utilizado é a vírgula
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

void exibe_lista(TLista *alunos);

int main(int argc, char *argv[])
{
  TLista *lista_de_alunos = cria_lista();

  int total_alunos = ler_alunos(lista_de_alunos);

  if (total_alunos > 0)
  {
    printf("Foram lidos %d alunos do arquivo '%s'.\n\n", total_alunos, NOME_ARQUIVO);
    printf("--- Lista de Alunos ---\n");
    exibe_lista(lista_de_alunos);
  }

  lista_de_alunos = destroi_lista(lista_de_alunos);

  return EXIT_SUCCESS;
}

int ler_alunos(TLista *alunos)
{
  FILE *arquivo = fopen(NOME_ARQUIVO, "r");
  if (arquivo == NULL)
  {
    perror("Erro ao abrir o arquivo");
    return 0; // Retorna 0 se o arquivo não pôde ser aberto
  }

  char linha[MAX];
  int contador = 0;

  while (fgets(linha, MAX, arquivo) != NULL)
  {
    size_t tam = strlen(linha);
    if (tam > 0 && linha[tam - 1] == '\n')
      linha[tam - 1] = '\0';

    Aluno novo_aluno = ler_aluno(linha);
    insere_no_fim(alunos, novo_aluno);
    contador++;
  }

  fclose(arquivo);
  return contador;
}

Aluno ler_aluno(char entrada[MAX])
{
  Aluno a;
  const char *delimitador = ",";

  char *token = strtok(entrada, delimitador);
  if (token != NULL)
  {
    strcpy(a.nome, token);
  }

  for (int i = 0; i < NUM_NOTAS; i++)
  {
    token = strtok(NULL, delimitador);
    if (token != NULL)
    {
      a.notas[i] = atof(token);
    }
    else
    {
      a.notas[i] = 0.0f; // Caso falte uma nota
    }
  }

  a.media = calcula_media(a.notas);

  return a;
}

TLista *cria_lista()
{
  TLista *cabeca = (TLista *)malloc(sizeof(TLista));
  if (cabeca == NULL)
  {
    perror("Erro de alocacao de memoria");
    exit(EXIT_FAILURE);
  }
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
  {
    perror("Erro de alocacao de memoria");
    exit(EXIT_FAILURE);
  }
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
  TLista *aux = alunos->prox; // Pula o nó cabeça
  while (aux != NULL)
  {
    exibe_aluno(aux->aluno);
    if (aux->prox != NULL)
      printf(" -> ");
    aux = aux->prox;
  }
  printf("\n");
}