#include <stdio.h>
#include <stdlib.h>
#include "llist.h"

/**
 * Create a new linked list with a NULL head pointer.
 */
struct llist *llist_new(void) {
    struct llist *llist = malloc(sizeof(struct llist)); 
    llist -> head = NULL;
    return llist; 
}    

/**
 * Free all the nodes in the linked list and free the linked list
 * itself.
 */
void llist_free(struct llist *llist) {
    struct node *current = llist->head;
    while (current != NULL) {
        struct node *next = current->next;
        free(current);
        current = next;
    }
    free(llist);
}

/**
 * Remove all the items from a linked list.
 */
void llist_drain(struct llist *llist) {   
    struct node *current = llist->head; 
    while (current != NULL) { 
        struct node *next = current->next;
        free(current); 
        current = next; 
    }
    llist->head = NULL;
}
/**
 * Insert a new value in the linked list.
 */
void llist_insert(struct llist *llist, int value) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->value = value; 
    new_node->next = llist->head;
    llist->head = new_node;
}

/**
 * Print a linked list.
 */
void llist_print(struct llist *llist) {
    if (llist->head == NULL)
        printf("[empty]");
    else
        for (struct node *n = llist->head; n != NULL; n = n->next)
            printf("(%d)%s", n->value, n->next == NULL? "": " -> ");

    putchar('\n');
}