#include "m-tree.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    tree banks;
    int numberOfFiles = argc - 1;
    // initialising the data structure
    banks = (tree)malloc(sizeof(root) * (numberOfFiles));
    //for(int i = 0; i < (numberOfFiles - 1); i++)
    init(&banks, numberOfFiles, argv);

    // destroying
    //for(int i = 0; i < (numberOfFiles - 1); i++)
        destroy(&banks, numberOfFiles);
    return 0;
}