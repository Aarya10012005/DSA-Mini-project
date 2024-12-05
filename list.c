#include "m-tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void insert(quarter *q, int data, char *srn) {
    amount *new = createNode(data, srn);
    new->next = q->amounts;
    q->amounts = new;
    q->balance += data;
    return;
}
amount *createNode(int data, char *s) {
    amount *new = (amount *)malloc(sizeof(amount));
    new->amount = data;
    strcpy(new->srno, s);
    new->next = NULL;
    return new;
}