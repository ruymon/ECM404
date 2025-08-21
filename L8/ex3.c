/*
 * Enunciado:
 *    Repita o exerc�cio anterior, mas agora o programa principal deve pedir
 *    ao usu�rio que digite um nome para ser buscado na lista de alunos.
 *    O programa deve implementar um algoritmo de busca na lista ligada para
 *    encontrar e exibir o aluno com o nome informado. Caso o aluno n�o seja
 *    encontrado, o usu�rio deve ser alertado.
 *
 * Exemplos:
 *
 *    Digite o aluno a ser buscado: Rodrigo
 *    Aluno encontrado: (Rodrigo | 2.50)
 *
 *    Digite o aluno a ser buscado: Alexandre
 *    Aluno encontrado: (Alexandre | 9.25)
 *
 *    Digite o aluno a ser buscado: Oi
 *    O aluno n�o foi encontrado...
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

/* Fun��es recomendadas (n�o precisa implementar nenhuma delas se n�o quiser)
 */
Aluno ler_aluno(char linha[MAX]);
void exibe_aluno(Aluno a);
float calcula_media(float* notas);

int ler_alunos(TLista* alunos);

TLista* cria_lista();
TLista* destroi_lista(TLista* alunos);
void insere_no_fim(TLista *alunos, Aluno aluno);

int busca_aluno(TLista* alunos, char aluno[MAX]);

/* Fun��es para uso livre */
void exibe_lista(TLista* alunos); // exibe uma lista de alunos
void ler_string(char* s); // le uma string de forma "segura"

int main (int argc, char *argv[])
{

  return EXIT_SUCCESS;
}

int busca_aluno(TLista* alunos, char aluno[MAX]) {
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

void ler_string(char* s) {
  scanf("\n");
  fgets(s, MAX, stdin);
  size_t tam = strlen(s);
  if( s[tam-1] == '\n' ) s[tam-1] = '\0';
}
