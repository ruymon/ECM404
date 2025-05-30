#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "agenda.txt"

typedef struct
{
  char nome[50];
  char phone[15];
  int dayOfBirth;
  int monthOfBirth;
} Contact;

void inserirContato();
void listarContatos();
void pesquisarContato();
void removerContato();
void listarPorInicial();
void listarAniversariantes();

int main()
{
  int menuOption;

  while (1)
  {
    printf("\nMenu:\n");
    printf("1. Inserir contato\n");
    printf("2. Remover contato\n");
    printf("3. Pesquisar contato pelo nome\n");
    printf("4. Listar todos os contatos\n");
    printf("5. Listar contatos por letra inicial\n");
    printf("6. Imprimir aniversariantes do mês\n");
    printf("7. Sair\n\n");

    printf("Escolha uma opção: ");
    scanf("%d", &menuOption);
    getchar(); // limpar \n do buffer

    switch (menuOption)
    {
    case 1:
      inserirContato();
      break;
    case 2:
      removerContato();
      break;
    case 3:
      pesquisarContato();
      break;
    case 4:
      listarContatos();
      break;
    case 5:
      listarPorInicial();
      break;
    case 6:
      listarAniversariantes();
      break;
    case 7:
      return 0;
    default:
      printf("Opção inválida. Tente novamente.\n");
    }
  }

  return 0;
}

void inserirContato()
{
  FILE *file = fopen(FILENAME, "a");
  if (file == NULL)
  {
    printf("Erro ao abrir o arquivo.\n");
    return;
  }

  Contact contact;

  printf("Inserir contato:\n");

  printf("Nome: ");
  fgets(contact.nome, sizeof(contact.nome), stdin);
  contact.nome[strcspn(contact.nome, "\n")] = '\0';

  printf("Telefone: ");
  fgets(contact.phone, sizeof(contact.phone), stdin);
  contact.phone[strcspn(contact.phone, "\n")] = '\0';

  printf("Dia do aniversário: ");
  scanf("%d", &contact.dayOfBirth);
  printf("Mês do aniversário: ");
  scanf("%d", &contact.monthOfBirth);
  getchar(); // limpar buffer

  fwrite(&contact, sizeof(Contact), 1, file);
  fclose(file);

  printf("Contato inserido com sucesso!\n");
}

void listarContatos()
{
  FILE *file = fopen(FILENAME, "rb");
  if (file == NULL)
  {
    printf("Erro ao abrir o arquivo.\n");
    return;
  }

  Contact contact;

  printf("Lista de contatos:\n");
  while (fread(&contact, sizeof(Contact), 1, file))
  {
    printf("Nome: %s\n", contact.nome);
    printf("Telefone: %s\n", contact.phone);
    printf("Aniversário: %02d/%02d\n", contact.dayOfBirth, contact.monthOfBirth);
    printf("-------------------------\n");
  }

  fclose(file);
}

void pesquisarContato()
{
  FILE *file = fopen(FILENAME, "rb");
  if (file == NULL)
  {
    printf("Erro ao abrir o arquivo.\n");
    return;
  }

  Contact contact;
  char nomeBusca[50];
  int encontrado = 0;

  printf("Nome do contato: ");
  fgets(nomeBusca, sizeof(nomeBusca), stdin);
  nomeBusca[strcspn(nomeBusca, "\n")] = '\0';

  while (fread(&contact, sizeof(Contact), 1, file))
  {
    if (strcmp(contact.nome, nomeBusca) == 0)
    {
      printf("Contato encontrado:\n");
      printf("Nome: %s\n", contact.nome);
      printf("Telefone: %s\n", contact.phone);
      printf("Aniversário: %02d/%02d\n", contact.dayOfBirth, contact.monthOfBirth);
      encontrado = 1;
      break;
    }
  }

  if (!encontrado)
  {
    printf("Contato não encontrado.\n");
  }

  fclose(file);
}

void removerContato()
{
  FILE *file = fopen(FILENAME, "rb");
  if (file == NULL)
  {
    printf("Erro ao abrir o arquivo.\n");
    return;
  }

  FILE *temp = fopen("temp.txt", "wb");
  if (temp == NULL)
  {
    printf("Erro ao criar arquivo temporário.\n");
    fclose(file);
    return;
  }

  Contact contact;
  char nomeRemover[50];
  int removido = 0;

  printf("Nome do contato a ser removido: ");
  fgets(nomeRemover, sizeof(nomeRemover), stdin);
  nomeRemover[strcspn(nomeRemover, "\n")] = '\0';

  while (fread(&contact, sizeof(Contact), 1, file))
  {
    if (strcmp(contact.nome, nomeRemover) != 0)
    {
      fwrite(&contact, sizeof(Contact), 1, temp);
    }
    else
    {
      removido = 1;
    }
  }

  fclose(file);
  fclose(temp);

  remove(FILENAME);
  rename("temp.txt", FILENAME);

  if (removido)
    printf("Contato removido com sucesso!\n");
  else
    printf("Contato não encontrado.\n");
}

void listarPorInicial()
{
  FILE *file = fopen(FILENAME, "rb");
  if (file == NULL)
  {
    printf("Erro ao abrir o arquivo.\n");
    return;
  }

  Contact contact;
  char initial;

  printf("Letra inicial: ");
  scanf(" %c", &initial);
  getchar();

  while (fread(&contact, sizeof(Contact), 1, file))
  {
    if (contact.nome[0] == initial)
    {
      printf("Nome: %s\n", contact.nome);
      printf("Telefone: %s\n", contact.phone);
      printf("Aniversário: %02d/%02d\n", contact.dayOfBirth, contact.monthOfBirth);
      printf("-------------------------\n");
    }
  }

  fclose(file);
}

void listarAniversariantes()
{
  FILE *file = fopen(FILENAME, "rb");
  if (file == NULL)
  {
    printf("Erro ao abrir o arquivo.\n");
    return;
  }

  Contact contact;
  int month;

  printf("Mês (1-12): ");
  scanf("%d", &month);
  getchar();

  while (fread(&contact, sizeof(Contact), 1, file))
  {
    if (contact.monthOfBirth == month)
    {
      printf("Nome: %s\n", contact.nome);
      printf("Telefone: %s\n", contact.phone);
      printf("Aniversário: %02d/%02d\n", contact.dayOfBirth, contact.monthOfBirth);
      printf("-------------------------\n");
    }
  }

  fclose(file);
}