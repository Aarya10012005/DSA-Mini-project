#include "m-tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER 256
#define BANKNAME 100

void init(tree *bank, int numberOfFiles, char *bankName) {
    root rootNode;
    for(int i = 0; i < numberOfFiles; i++) {
        rootNode = (*bank)[i];
        // mallocing the root node
        // (*bank) = (tree)malloc(sizeof(root));

        // assigning bank name to the root node element
        strcpy(rootNode.bankName, bankName[i + 1]);

        // mallocing 2 children of root node
        rootNode.credit = (transaction *)malloc(sizeof(transaction));
        transaction *credit = rootNode.credit;
        strcpy(credit->str, "Cr");
        rootNode.debit = (transaction *)malloc(sizeof(transaction));
        transaction *debit = rootNode.debit;
        strcpy(debit->str, "Dr");

        /*
        // callocing year and month nodes so that each points to null
        credit->year1 = (year *)calloc(1, sizeof(year));
        credit->year2 = (year *)calloc(1, sizeof(year));
        debit->year1 = (year *)calloc(1, sizeof(year));
        debit->year2 = (year *)calloc(1, sizeof(year));
        */

        // mallocing year node
        credit->year1 = (year *)malloc(sizeof(year));
        strcpy(credit->year1->year, "2023");
        credit->year2 = (year *)malloc(sizeof(year));
        strcpy(credit->year2->year, "2024");
        debit->year1 = (year *)malloc(sizeof(year));
        strcpy(debit->year1->year, "2023");
        debit->year2 = (year *)malloc(sizeof(year));
        strcpy(debit->year2->year, "2024");


        // mallocing quarter nodes
        credit->year1->quarter1 = (quarter *)malloc(sizeof(quarter));
        credit->year1->quarter1->amounts = NULL;
        strcpy(credit->year1->quarter1, "Quarter 1");
        credit->year1->quarter2 = (quarter *)malloc(sizeof(quarter));
        credit->year1->quarter2->amounts = NULL;
        strcpy(credit->year1->quarter2, "Quarter 2");
        credit->year1->quarter3 = (quarter *)malloc(sizeof(quarter));
        credit->year1->quarter3->amounts = NULL;
        strcpy(credit->year1->quarter3, "Quarter 3");
        credit->year1->quarter4 = (quarter *)malloc(sizeof(quarter));
        credit->year1->quarter4->amounts = NULL;
        strcpy(credit->year1->quarter4, "Quarter 4");

        credit->year2->quarter1 = (quarter *)malloc(sizeof(quarter));
        credit->year2->quarter1->amounts = NULL;
        strcpy(credit->year2->quarter1, "Quarter 1");
        credit->year2->quarter2 = (quarter *)malloc(sizeof(quarter));
        credit->year2->quarter2->amounts = NULL;
        strcpy(credit->year2->quarter2, "Quarter 2");
        credit->year2->quarter3 = (quarter *)malloc(sizeof(quarter));
        credit->year2->quarter3->amounts = NULL;
        strcpy(credit->year2->quarter3, "Quarter 3");
        credit->year2->quarter4 = (quarter *)malloc(sizeof(quarter));
        credit->year2->quarter4->amounts = NULL;
        strcpy(credit->year2->quarter4, "Quarter 4");
        
        debit->year1->quarter1 = (quarter *)malloc(sizeof(quarter));
        debit->year1->quarter1->amounts = NULL;
        strcpy(debit->year1->quarter1, "Quarter 1");
        debit->year1->quarter2 = (quarter *)malloc(sizeof(quarter));
        debit->year1->quarter2->amounts = NULL;
        strcpy(debit->year1->quarter2, "Quarter 2");
        debit->year1->quarter3 = (quarter *)malloc(sizeof(quarter));
        debit->year1->quarter3->amounts = NULL;
        strcpy(debit->year1->quarter3, "Quarter 3");
        debit->year1->quarter4 = (quarter *)malloc(sizeof(quarter));
        debit->year1->quarter4->amounts = NULL;
        strcpy(debit->year1->quarter4, "Quarter 4");

        debit->year2->quarter1 = (quarter *)malloc(sizeof(quarter));
        debit->year2->quarter1->amounts = NULL;
        strcpy(debit->year2->quarter1, "Quarter 1");
        debit->year2->quarter2 = (quarter *)malloc(sizeof(quarter));
        debit->year2->quarter2->amounts = NULL;
        strcpy(debit->year2->quarter2, "Quarter 2");
        debit->year2->quarter3 = (quarter *)malloc(sizeof(quarter));
        debit->year2->quarter3->amounts = NULL;
        strcpy(debit->year2->quarter3, "Quarter 3");
        debit->year2->quarter4 = (quarter *)malloc(sizeof(quarter));
        debit->year2->quarter4->amounts = NULL;
        strcpy(debit->year2->quarter4, "Quarter 4");
    }
    return;


    /*
    // mallocing the root node
    (*bank) = (tree)malloc(sizeof(root));

    // mallocing 2 children of root node
    (*root)->left = (transaction *)malloc(sizeof(transaction));
    transaction *credit = (*root)->left;
    (*root)->right = (transaction *)malloc(sizeof(transaction));
    transaction *debit = (*root)->right;
    */
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

    /*
    // callocing year and month nodes so that each points to null
    credit->year1 = (year *)calloc(1, sizeof(year));
    credit->year2 = (year *)calloc(1, sizeof(year));
    debit->year1 = (year *)calloc(1, sizeof(year));
    debit->year2 = (year *)calloc(1, sizeof(year));
    */
}

void destroy(tree *bank, int numberOfFiles) {
    root rootNode;
    transaction *credit, *debit;
    year *credit_year1, *credit_year2, *debit_year1, *debit_year2;
    quarter *cr_y1_q1, *cr_y1_q2, *cr_y1_q3, *cr_y1_q4, *cr_y2_q1, *cr_y2_q2, *cr_y2_q3, *cr_y2_q4, *dr_y1_q1, *dr_y1_q2, *dr_y1_q3, *dr_y1_q4, *dr_y2_q1, *dr_y2_q2, *dr_y2_q3, *dr_y2_q4;
    amount *amounts;
    for(int i = 0; i < numberOfFiles; i++) {
        rootNode = (*bank)[i];
        credit = rootNode.credit;
        debit = rootNode.debit;

        credit_year1 = credit->year1;
        credit_year2 = credit->year2;
        debit_year1 = debit->year1;
        debit_year2 = debit->year2;

        cr_y1_q1 = credit_year1->quarter1;
        cr_y1_q2 = credit_year1->quarter2;
        cr_y1_q3 = credit_year1->quarter3;
        cr_y1_q4 = credit_year1->quarter4;
        cr_y2_q1 = credit_year2->quarter1;
        cr_y2_q2 = credit_year2->quarter2;
        cr_y2_q3 = credit_year2->quarter3;
        cr_y2_q4 = credit_year2->quarter4;
        dr_y1_q1 = debit_year1->quarter1;
        dr_y1_q2 = debit_year1->quarter2;
        dr_y1_q3 = debit_year1->quarter3;
        dr_y1_q4 = debit_year1->quarter4;
        dr_y2_q1 = debit_year2->quarter1;
        dr_y2_q2 = debit_year2->quarter2;
        dr_y2_q3 = debit_year2->quarter3;
        dr_y2_q4 = debit_year2->quarter4;

        // freeing amount nodes
        amounts = cr_y1_q1->amounts;
        while(amounts != NULL) {
            free(amounts);
            amounts = amounts->next;
        }
        amounts = cr_y1_q2->amounts;
        while(amounts != NULL) {
            free(amounts);
            amounts = amounts->next;
        }
        amounts = cr_y1_q3->amounts;
        while(amounts != NULL) {
            free(amounts);
            amounts = amounts->next;
        }
        amounts = cr_y1_q4->amounts;
        while(amounts != NULL) {
            free(amounts);
            amounts = amounts->next;
        }

        amounts = cr_y2_q1->amounts;
        while(amounts != NULL) {
            free(amounts);
            amounts = amounts->next;
        }
        amounts = cr_y2_q2->amounts;
        while(amounts != NULL) {
            free(amounts);
            amounts = amounts->next;
        }
        amounts = cr_y2_q3->amounts;
        while(amounts != NULL) {
            free(amounts);
            amounts = amounts->next;
        }
        amounts = cr_y2_q4->amounts;
        while(amounts != NULL) {
            free(amounts);
            amounts = amounts->next;
        }

        amounts = dr_y1_q1->amounts;
        while(amounts != NULL) {
            free(amounts);
            amounts = amounts->next;
        }
        amounts = dr_y1_q2->amounts;
        while(amounts != NULL) {
            free(amounts);
            amounts = amounts->next;
        }
        amounts = dr_y1_q3->amounts;
        while(amounts != NULL) {
            free(amounts);
            amounts = amounts->next;
        }
        amounts = dr_y1_q4->amounts;
        while(amounts != NULL) {
            free(amounts);
            amounts = amounts->next;
        }

        amounts = dr_y2_q1->amounts;
        while(amounts != NULL) {
            free(amounts);
            amounts = amounts->next;
        }
        amounts = dr_y2_q2->amounts;
        while(amounts != NULL) {
            free(amounts);
            amounts = amounts->next;
        }
        amounts = dr_y2_q3->amounts;
        while(amounts != NULL) {
            free(amounts);
            amounts = amounts->next;
        }
        amounts = dr_y2_q4->amounts;
        while(amounts != NULL) {
            free(amounts);
            amounts = amounts->next;
        }

        // freeing quarter nodes
        if(cr_y1_q1 != NULL)
            free(cr_y1_q1);

        if(cr_y1_q2 != NULL)
            free(cr_y1_q2);

        if(cr_y1_q3 != NULL)
            free(cr_y1_q3);

        if(cr_y1_q4 != NULL)
            free(cr_y1_q4);

        if(cr_y2_q1 != NULL)
            free(cr_y2_q1);

        if(cr_y2_q2 != NULL)
            free(cr_y2_q2);

        if(cr_y2_q3 != NULL)
            free(cr_y2_q3);

        if(cr_y2_q4 != NULL)
            free(cr_y2_q4);

        if(dr_y1_q1 != NULL)
            free(dr_y1_q1);

        if(dr_y1_q2 != NULL)
            free(dr_y1_q2);

        if(dr_y1_q3 != NULL)
            free(dr_y1_q3);

        if(dr_y1_q4 != NULL)
            free(dr_y1_q4);

        if(dr_y2_q1 != NULL)
            free(dr_y2_q1);

        if(dr_y2_q2 != NULL)
            free(dr_y2_q2);

        if(dr_y2_q3 != NULL)
            free(dr_y2_q3);

        if(dr_y2_q4 != NULL)
            free(dr_y2_q4);

        // freeing year nodes
        if(credit_year1 != NULL)
            free(credit_year1);
        if(credit_year2 != NULL)
            free(credit_year2);
        if(debit_year1 != NULL)
            free(debit_year1);
        if(debit_year2 != NULL)
            free(debit_year2);

        // freeing cr/dr (transaction) nodes
        if(credit != NULL)
            free(credit);
        if(debit != NULL)
            free(debit);
        
        // credit = (*bank)[i].credit;
        // credit_year1 = credit->year1;
        // // freeing all quarter nodes
        // for(int j = 0; j < 4; j++) {
        //     quarter = credit_year1->quarter1;
        // }

    }
    // freeing the malloced memory of root nodes
    free((*bank));
    return;
}

void combineFile(int argc, char *argv[]) {
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

