#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#define NAME_MAX_CHAR 10

typedef struct _Product
{
  int id;
  char name[NAME_MAX_CHAR];
  float price;
  int inventoryCount;
  struct _Product *next;
} Product;

// Function prototypes
Product *createProduct(int id, const char *name, float price, int count);
void clear(Product *headNode);
int isEmpty(Product *headNode);
void enqueue(Product *headNode, Product *newNode);
Product *dequeue(Product *headNode);
void printQueue(Product *headNode);

#endif
