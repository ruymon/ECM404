#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * @description: Wipes the whole queue.
 */
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

/**
 * @description: Checks is the queue is empty.
 * @returns {bool} True if the queue has no nodes.
 */
bool isEmpty(Product *headNode)
{
  return headNode->next == NULL;
}

/**
 * @description: Adds a new element to the end of the queue.
 */
void enqueue(Product *headNode, Product *newNode)
{
  newNode->next = NULL;
  Product *tempNode = headNode;

  while (tempNode->next != NULL)
  {
    tempNode = tempNode->next;
  }

  tempNode->next = newNode;
}

/**
 * @description: Removes the first element from the queue
 */
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

  return firstNode; // return for processing or freeing
}
