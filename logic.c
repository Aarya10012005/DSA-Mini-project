#include "m-tree.h"
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define BUFFER 256
#define BANKNAME 100

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

void combineFile(int argc, char *argv[]){
		/* Allocate memory for file pointers and other variables */
	FILE **fp = NULL, *newFile;
	char line[BUFFER], *token, bank[BANKNAME];
	
	fp = (FILE **)calloc(argc - 1, sizeof(FILE *));
	
	/* Opening the bank statements in read mode */
	for(int i = 0; i < (argc - 1); i++){
		fp[i] = fopen(argv[i + 1], "r");
		if(fp[i] == NULL){
			printf("Error while opening the file!");
			exit(1);
		}
	}

	/* Opening new file to store all the combined bank statements */
	newFile = fopen("./bank_statements/collective.csv", "a");
	if(newFile == NULL){
		printf("Error while creating a new file");
		exit(1);
	}

	/* Writing the header row (from the first file) to the new file */
	fgets(line, BUFFER, fp[0]);         /* Get the header row of the first file */
	fputs("Bank Name,", newFile);       /* Add an extra column for bank name */
	fputs(line, newFile);               /* Write the header to the new file */

	/* Process each bank file */
	for(int i = 1; i <= argc - 1; i++){
		strcpy(bank, argv[i]);
		token = strtok(bank, "/");  /* Extract bank name from the filename */
		token = strtok(NULL, ".");

		/* For the first file, the header has already been processed, so no need to skip the header */
		if(i > 1){
			fgets(line, BUFFER, fp[i - 1]);  /* Skip the header line for subsequent files */ 
		}
		
		/* Read and write the transactions */
		while(fgets(line, BUFFER, fp[i - 1]) != NULL){
			/* Write the bank name and transaction data */
			fputs(token, newFile);
			fputs(",", newFile);
			fputs(line, newFile);
		}
	}

	/* Close all the files */
	for(int i = 0; i < argc - 1; i++){
		fclose(fp[i]);
	}
	fclose(newFile);

	/* Free allocated memory */
	free(fp);
	return;
}