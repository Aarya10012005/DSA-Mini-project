#include "m-tree.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // printf("Number of arguments: %d\n", argc);
    // for (int i = 0; i < argc; i++) {
    //     printf("Argument %d: %s\n", i, argv[i]);
    // }

    if(argc < 2) {
        printf("Please give bank statements.\n");
        return 1;
    }

    tree banks;
    int numberOfFiles = argc - 1;

    // initialisation of banks
    //banks = (tree)malloc(sizeof(root) * numberOfFiles);
    init(&banks, numberOfFiles, argv);

    // combining files
    combineFile(argc, argv);

    // filling the data structure
    fill_data_structure(&banks, numberOfFiles);

    // printing the data structure
    print_data_structure(&banks, numberOfFiles);

    // destroying
    destroy(&banks, numberOfFiles);
    return 0;
}