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

#endif
