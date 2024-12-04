#include "m-tree.h"
#include <stdio.h>
#include <stdlib.h>

void insert(quarter *q, int data) {
    amount *new = createNode(data);
    new->next = q->amounts;
    q->amounts = new;
    return;
}
amount *createNode(int data) {
    amount *new = (amount *)malloc(sizeof(amount));
    new->amount = data;
    new->next = NULL;
    return new;
}