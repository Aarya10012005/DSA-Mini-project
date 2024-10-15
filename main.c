#include "m-tree.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // tree root;
    // init(&root);
    // destroy(&root);

    int numberOfFiles = argc - 1;
    // initialising the data structure
    tree *root1 = (tree *)malloc(sizeof(tree) * (numberOfFiles));
    for(int i = 0; i < (numberOfFiles - 1); i++)
        init(&root1[i]);

    // destroying
    for(int i = 0; i < (numberOfFiles - 1); i++)
        destroy(&root1[i]);
    return 0;
}