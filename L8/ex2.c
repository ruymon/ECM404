/*
 * Enunciado:
 *    Repita o exercício anterior, mas agora utilize como entrada o arquivo
 *    notas.csv. A quantidade de alunos pode ser diferente de 3.
 *
 * Exemplo de linha:
 *    Rodrigo,1,2,3,4
 *
 *    Note que o separador utilizado é a vírgula
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
  char nome[MAX];
  float notas[4];
  float media;
} Aluno;

typedef struct SLista {
  Aluno aluno;
  struct SLista* prox;
} TLista;

/* Funções recomendadas (não precisa implementar nenhuma delas se não quiser)
 */
Aluno ler_aluno(char linha[MAX]);
void exibe_aluno(Aluno a);
float calcula_media(float* notas);

int ler_alunos(TLista *alunos);

TLista* cria_lista();
TLista* destroi_lista(TLista* alunos);
void insere_no_fim(TLista *alunos, Aluno aluno);

/* Funções para uso livre */
void exibe_lista(TLista* alunos); // exibe uma lista de alunos

int main (int argc, char *argv[])
{

  return EXIT_SUCCESS;
}

int ler_alunos(TLista *alunos) {
}

void insere_no_fim(TLista *alunos, Aluno aluno) {
}

TLista* cria_lista() {
}

TLista* destroi_lista(TLista* alunos) {
}

float calcula_media(float* notas) {
}

Aluno ler_aluno(char entrada[MAX]) {
}

void exibe_aluno(Aluno a) {
  printf("(%s | %.2f)", a.nome, a.media);
}

void exibe_lista(TLista* alunos) {
  TLista *aux = alunos->prox;
  while(aux != NULL) {
    exibe_aluno(aux->aluno);
    if( aux->prox != NULL ) printf(" -> ");
    aux = aux->prox;
  }
  printf("\n");
}
