// struct node { 
//     int data;
//     struct node *next;
// };

// p = head; 
// free(p);
// head = p -> next; 
// cannot access p after freeing it

// next = head->next;
// free(head);
// head = next;
// avoids accessing freed memory

/* Challenge 5.4: Linked List */

#include <stdio.h>
#include "llist.h"

int main(void)
{
    struct llist *llist = llist_new();

    for (int i = 10; i <= 40; i += 10) {
        llist_insert(llist, i);
        llist_print(llist);
    }

    llist_drain(llist);
    llist_print(llist);
    llist_free(llist);
}