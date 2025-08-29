#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main()
{
    // Create a dummy head node
    Product head;
    head.next = NULL;

    printf("Queue Demo:\n");

    // Enqueue some products
    enqueue(&head, createProduct(1, "Apple", 0.99, 50));
    enqueue(&head, createProduct(2, "Banana", 1.20, 30));
    enqueue(&head, createProduct(3, "Milk", 2.50, 10));

    // Print queue
    printQueue(&head);

    // Dequeue one product
    Product *p = dequeue(&head);
    if (p)
    {
        printf("\nDequeued: %s (ID %d)\n", p->name, p->id);
        free(p); // free after using
    }

    // Print again
    printQueue(&head);

    // Clear queue
    clear(&head);
    printQueue(&head);

    return 0;
}
