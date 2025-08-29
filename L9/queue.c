#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Create a new product node
Product *createProduct(int id, const char *name, float price, int count)
{
  Product *newNode = (Product *)malloc(sizeof(Product));
  if (!newNode)
  {
    printf("Memory allocation failed!\n");
    exit(1);
  }
  newNode->id = id;
  strncpy(newNode->name, name, NAME_MAX_CHAR - 1);
  newNode->name[NAME_MAX_CHAR - 1] = '\0';
  newNode->price = price;
  newNode->inventoryCount = count;
  newNode->next = NULL;
  return newNode;
}

void clear(Product *headNode)
{
  Product *current = headNode->next;
  Product *nextNode;

  while (current != NULL)
  {
    nextNode = current->next;
    free(current);
    current = nextNode;
  }
  headNode->next = NULL;
}

int isEmpty(Product *headNode)
{
  return headNode->next == NULL;
}

void enqueue(Product *headNode, Product *newNode)
{
  newNode->next = NULL;
  Product *temp = headNode;
  while (temp->next != NULL)
  {
    temp = temp->next;
  }
  temp->next = newNode;
}

Product *dequeue(Product *headNode)
{
  if (isEmpty(headNode))
  {
    printf("Queue is empty.\n");
    return NULL;
  }

  Product *firstNode = headNode->next;
  headNode->next = firstNode->next;
  firstNode->next = NULL;
  return firstNode;
}

void printQueue(Product *headNode)
{
  if (isEmpty(headNode))
  {
    printf("Queue is empty.\n");
    return;
  }

  Product *current = headNode->next;
  printf("\n--- Queue Contents ---\n");
  while (current != NULL)
  {
    printf("ID: %d | Name: %s | Price: %.2f | Stock: %d\n",
           current->id, current->name, current->price, current->inventoryCount);
    current = current->next;
  }
  printf("----------------------\n");
}
