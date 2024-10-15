#include "m-tree.h"
#include <stdio.h>
#include <stdlib.h>

// creating the data structure
void init(tree *root) {
    // mallocing the root node
    (*root) = (tree)malloc(sizeof(root));

    // mallocing 2 children of root node
    (*root)->left = (transaction *)malloc(sizeof(transaction));
    transaction *credit = (*root)->left;
    (*root)->right = (transaction *)malloc(sizeof(transaction));
    transaction *debit = (*root)->right;

    /*
    // mallocing year and month nodes
    credit->year1 = (year *)malloc(sizeof(year));
    credit->year2 = (year *)malloc(sizeof(year));
    debit->year1 = (year *)malloc(sizeof(year));
    debit->year2 = (year *)malloc(sizeof(year));

    // assigning NULL to every year element
    credit->year1->jan = credit->year1->feb = credit->year1->march = credit->year1->april = credit->year1->may = credit->year1->june = credit->year1->july = credit->year1->aug = credit->year1->sept = credit->year1->oct = credit->year1->nov = credit->year1->dec = NULL;
    credit->year2->jan = credit->year2->feb = credit->year2->march = credit->year2->april = credit->year2->may = credit->year2->june = credit->year2->july = credit->year2->aug = credit->year2->sept = credit->year2->oct = credit->year2->nov = credit->year2->dec = NULL;
    debit->year1->jan = debit->year1->feb = debit->year1->march = debit->year1->april = debit->year1->may = debit->year1->june = debit->year1->july = debit->year1->aug = debit->year1->sept = debit->year1->oct = debit->year1->nov = debit->year1->dec = NULL;
    debit->year2->jan = debit->year2->feb = debit->year2->march = debit->year2->april = debit->year2->may = debit->year2->june = debit->year2->july = debit->year2->aug = debit->year2->sept = debit->year2->oct = debit->year2->nov = debit->year2->dec = NULL;
    */

    // callocing year and month nodes so that each points to null
    credit->year1 = (year *)calloc(1, sizeof(year));
    credit->year2 = (year *)calloc(1, sizeof(year));
    debit->year1 = (year *)calloc(1, sizeof(year));
    debit->year2 = (year *)calloc(1, sizeof(year));
    return;
}
void destroy(tree *root) {
    transaction *left, *right;
}