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
    //print_data_structure(&banks, numberOfFiles);

    printf("\nSummary:\n\n");
    for (int q = 1; q <= 4; q++) {
        printf("Quarter %d:\n", q);
        printf("Transaction Count: %d\n", txn_count_quart(&banks, numberOfFiles, q));
        printf("Average Quarterly Debit: %d\n", avg_quarterly_deb(&banks, numberOfFiles, q));
        printf("Average Quarterly Credit: %d\n", avg_quarterly_cred(&banks, numberOfFiles, q));
    }
    minTxn(&banks, numberOfFiles);
    maxTxn(&banks, numberOfFiles);

    generate_txn_count_graph(&banks, numberOfFiles);

    printf("\n\n-----------------------------------------------\n\n");
    // search
    search_transactions(&banks, numberOfFiles, argv);

    // destroying
    destroy(&banks, numberOfFiles);
    return 0;
}