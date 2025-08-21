/*
 * Enunciado:
 * Crie uma lista ligada de alunos, em que cada aluno deve consistir de um
 * struct contendo o seu nome, 4 notas e a média do aluno. O programa
 * principal deve pedir para que o usuário digite o nome e as 4 notas de
 * 3 alunos, para a seguir exibir a lista ligada completa (use exibe_lista).
 *
 * Exemplos:
 *
 * Aluno: Rodrigo 2 3 4 5
 * Aluno: Alexandre 10 10 8 9
 * Aluno: Diego 7 8 10 10
 * (Rodrigo | 3.50) -> (Alexandre | 9.25) -> (Diego | 8.75)
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
#define NUM_NOTAS 4
#define NUM_ALUNOS 3

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

Aluno ler_aluno();
void exibe_aluno(Aluno a);
float calcula_media(float *notas);

TLista *cria_lista();
TLista *destroi_lista(TLista *alunos);
void insere_no_fim(TLista *alunos, Aluno aluno);

void exibe_lista(TLista *alunos);
void ler_string(char *s);

int main(int argc, char *argv[])
{
  TLista *lista_de_alunos = cria_lista();

  for (int i = 0; i < NUM_ALUNOS; i++)
  {
    printf("--- Aluno %d ---\n", i + 1);
    Aluno novo_aluno = ler_aluno();
    insere_no_fim(lista_de_alunos, novo_aluno);
  }

  printf("\n--- Lista de Alunos ---\n");
  exibe_lista(lista_de_alunos);

  // Libera a memória alocada para a lista
  lista_de_alunos = destroi_lista(lista_de_alunos);

  return EXIT_SUCCESS;
}

Aluno ler_aluno()
{
  Aluno a;

  printf("Digite o nome do aluno: ");
  ler_string(a.nome);

  printf("Digite as %d notas do aluno: ", NUM_NOTAS);
  for (int i = 0; i < NUM_NOTAS; i++)
  {
    scanf("%f", &a.notas[i]);
  }

  a.media = calcula_media(a.notas);
  return a;
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
    proximo_no = atual->prox; // Guarda a referência para o próximo
    free(atual);              // Libera o nó atual
    atual = proximo_no;       // Move para o próximo
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

  // Percorre a lista até encontrar o último nó
  TLista *aux = alunos;
  while (aux->prox != NULL)
  {
    aux = aux->prox;
  }

  aux->prox = novo_no;
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

void ler_string(char *s)
{
  scanf("\n"); // Limpa o buffer do teclado (consome o '\n' de leituras anteriores)
  fgets(s, MAX, stdin);
  size_t tam = strlen(s);
  if (s[tam - 1] == '\n')
    s[tam - 1] = '\0';
}