#include "m-tree.h"
#include <stdio.h>
#include <stdlib.h>

#define TERMINATE 3

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
    int *maxCredDeb, *minCredDeb;
    int operation = 1;

    // initialisation of banks
    //banks = (tree)malloc(sizeof(root) * numberOfFiles);
    init(&banks, numberOfFiles, argv);

    // combining files
    combineFile(argc, argv);

    // filling the data structure
    fill_data_structure(&banks, numberOfFiles);

    while(operation != TERMINATE) {
        printf("\n\n---------------------------------------------------------------------\n\n");
        printf("1. Summary\n2. Search\n3. Terminate\n\nEnter operation: ");
        scanf(" %d", &operation);
        switch (operation) {
            case 1:
                printf("\nSummary:\n\n");
                for (int q = 1; q <= 4; q++) {
                    printf("Quarter %d:\n", q);
                    printf("Transaction Count: %d\n", txn_count_quart(&banks, numberOfFiles, q));
                    printf("Average Quarterly Debit: %d\n", avg_quarterly_deb(&banks, numberOfFiles, q));
                    printf("Average Quarterly Credit: %d\n", avg_quarterly_cred(&banks, numberOfFiles, q));
                }

                minCredDeb = minTxn(&banks, numberOfFiles, argv);
                maxCredDeb = maxTxn(&banks, numberOfFiles, argv);

                generate_txn_count_graph(&banks, numberOfFiles);

                free(minCredDeb);
                free(maxCredDeb);
                break;

            case 2:
                // search
                search_transactions(&banks, numberOfFiles, argv);
                break;
            
            default:
                break;
        }
    }

    // printing the data structure
    //print_data_structure(&banks, numberOfFiles);

    // destroying
    destroy(&banks, numberOfFiles);

    // delete collective
    return 0;
}