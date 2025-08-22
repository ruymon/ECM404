/*
 * Enunciado:
 * Repita o exercício anterior, mas agora o programa principal deve pedir
 * ao usuário que digite um nome para ser buscado na lista de alunos.
 * O programa deve implementar um algoritmo de busca na lista ligada para
 * encontrar e exibir o aluno com o nome informado. Caso o aluno não seja
 * encontrado, o usuário deve ser alertado.
 *
 * Exemplos:
 *
 * Digite o aluno a ser buscado: Rodrigo
 * Aluno encontrado: (Rodrigo | 3.50)
 *
 * Digite o aluno a ser buscado: Oi
 * O aluno nao foi encontrado...
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
int busca_aluno(TLista *alunos, char nome_busca[MAX]);
void exibe_lista(TLista *alunos);
void ler_string(char *s);

int main(int argc, char *argv[])
{
  TLista *lista_de_alunos = cria_lista();
  int total_alunos = ler_alunos(lista_de_alunos);

  if (total_alunos > 0)
  {
    char nome_para_buscar[MAX];
    printf("A lista de alunos foi carregada.\n");
    printf("Digite o nome do aluno a ser buscado: ");
    ler_string(nome_para_buscar);

    busca_aluno(lista_de_alunos, nome_para_buscar);
  }

  lista_de_alunos = destroi_lista(lista_de_alunos);

  return EXIT_SUCCESS;
}

int busca_aluno(TLista *alunos, char nome_busca[MAX])
{
  TLista *aux = alunos->prox;

  while (aux != NULL)
  {
    if (strcmp(aux->aluno.nome, nome_busca) == 0)
    {
      printf("Aluno encontrado: ");
      exibe_aluno(aux->aluno);
      printf("\n");
      return 1;
    }
    aux = aux->prox;
  }

  printf("O aluno '%s' nao foi encontrado...\n", nome_busca);
  return 0;
}

void ler_string(char *s)
{
  fgets(s, MAX, stdin);
  s[strcspn(s, "\n")] = '\0';
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
  return 1; // Retorna 1 para indicar sucesso na leitura (se o arquivo abriu)
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
    a.nome[MAX - 1] = '\0'; // Garante terminação nula
  }

  for (int i = 0; i < NUM_NOTAS; i++)
  {
    token = strtok(NULL, delimitador);
    a.notas[i] = (token != NULL) ? atof(token) : 0.0f;
  }

  free(copia_entrada); // Libera a memória alocada por strdup

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