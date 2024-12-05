#include "m-tree.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFFER 256
#define BANKNAME 100

void init(tree *bank, int numberOfFiles, char **bankName) {
    (*bank) = (tree)malloc(sizeof(root) * numberOfFiles);
    if((*bank) == NULL) {
        printf("Memory allocation for banks failed.\n");
        exit(EXIT_FAILURE);
    }

    tree rootNode;
    for(int i = 0; i < numberOfFiles; i++) {
        char tmp[BANKNAME];
        strcpy(tmp, bankName[i + 1]);
        rootNode = &((*bank)[i]);
        // assigning bank name to the root node element
        char *token = strtok(tmp, "/");
        token = strtok(NULL, "/");
        token = strtok(NULL, ".");
        strcpy(rootNode->bankName, token);
        //printf("%s\n", rootNode->bankName);

        // mallocing 2 children of root node
        rootNode->credit = (transaction *)malloc(sizeof(transaction));
        transaction *credit = rootNode->credit;
        strcpy(credit->str, "CR");
        //printf("%s ", credit->str);
        rootNode->debit = (transaction *)malloc(sizeof(transaction));
        transaction *debit = rootNode->debit;
        strcpy(debit->str, "DR");
        //printf("%s\n", debit->str);

        // mallocing year node
        credit->year = (YEAR *)malloc(sizeof(YEAR));
        strcpy(credit->year->year, "2023"); // year is to be allocated according to the date
        debit->year = (YEAR *)malloc(sizeof(YEAR));
        strcpy(debit->year->year, "2023");  // year is to be allocated according to the date

        // mallocing quarter nodes
        credit->year->quarter1 = (quarter *)malloc(sizeof(quarter));
        credit->year->quarter1->amounts = NULL;
        strcpy(credit->year->quarter1->quarter, "Quarter 1");
        //printf("%s ", credit->year->quarter1->quarter);
        credit->year->quarter2 = (quarter *)malloc(sizeof(quarter));
        credit->year->quarter2->amounts = NULL;
        strcpy(credit->year->quarter2->quarter, "Quarter 2");
        //printf("%s ", credit->year->quarter2->quarter);
        credit->year->quarter3 = (quarter *)malloc(sizeof(quarter));
        credit->year->quarter3->amounts = NULL;
        strcpy(credit->year->quarter3->quarter, "Quarter 3");
        //printf("%s ", credit->year->quarter3->quarter);
        credit->year->quarter4 = (quarter *)malloc(sizeof(quarter));
        credit->year->quarter4->amounts = NULL;
        strcpy(credit->year->quarter4->quarter, "Quarter 4");
        //printf("%s\n", credit->year->quarter1->quarter);

        debit->year->quarter1 = (quarter *)malloc(sizeof(quarter));
        debit->year->quarter1->amounts = NULL;
        strcpy(debit->year->quarter1->quarter, "Quarter 1");
        //printf("%s ", debit->year->quarter1->quarter);
        debit->year->quarter2 = (quarter *)malloc(sizeof(quarter));
        debit->year->quarter2->amounts = NULL;
        strcpy(debit->year->quarter2->quarter, "Quarter 2");
        //printf("%s ", debit->year->quarter2->quarter);
        debit->year->quarter3 = (quarter *)malloc(sizeof(quarter));
        debit->year->quarter3->amounts = NULL;
        strcpy(debit->year->quarter3->quarter, "Quarter 3");
        //printf("%s ", debit->year->quarter3->quarter);
        debit->year->quarter4 = (quarter *)malloc(sizeof(quarter));
        debit->year->quarter4->amounts = NULL;
        strcpy(debit->year->quarter4->quarter, "Quarter 4");
        //printf("%s ", debit->year->quarter4->quarter);
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
    tree rootNode;
    transaction *credit, *debit;
    YEAR *credit_year, *debit_year;
    quarter *cr_y_q1, *cr_y_q2, *cr_y_q3, *cr_y_q4, *dr_y_q1, *dr_y_q2, *dr_y_q3, *dr_y_q4;
    amount *amounts, *prevAmt;
    for(int i = 0; i < numberOfFiles; i++) {
        rootNode = &((*bank)[i]);

        credit = rootNode->credit;
        debit = rootNode->debit;

        credit_year = credit->year;
        debit_year = debit->year;

        cr_y_q1 = credit_year->quarter1;
        cr_y_q2 = credit_year->quarter2;
        cr_y_q3 = credit_year->quarter3;
        cr_y_q4 = credit_year->quarter4;
        dr_y_q1 = debit_year->quarter1;
        dr_y_q2 = debit_year->quarter2;
        dr_y_q3 = debit_year->quarter3;
        dr_y_q4 = debit_year->quarter4;

        // freeing amount nodes
        amounts = cr_y_q1->amounts;
        while(amounts) {
            prevAmt = amounts;
            amounts = amounts->next;
            free(prevAmt);
        }
        amounts = cr_y_q2->amounts;
        while(amounts) {
            prevAmt = amounts;
            amounts = amounts->next;
            free(prevAmt);
        }
        amounts = cr_y_q3->amounts;
        while(amounts) {
            prevAmt = amounts;
            amounts = amounts->next;
            free(prevAmt);
        }
        amounts = cr_y_q4->amounts;
        while(amounts) {
            prevAmt = amounts;
            amounts = amounts->next;
            free(prevAmt);
        }

        amounts = dr_y_q1->amounts;
        while(amounts) {
            prevAmt = amounts;
            amounts = amounts->next;
            free(prevAmt);
        }
        amounts = dr_y_q2->amounts;
        while(amounts) {
            prevAmt = amounts;
            amounts = amounts->next;
            free(prevAmt);
        }
        amounts = dr_y_q3->amounts;
        while(amounts) {
            prevAmt = amounts;
            amounts = amounts->next;
            free(prevAmt);
        }
        amounts = dr_y_q4->amounts;
        while(amounts) {
            prevAmt = amounts;
            amounts = amounts->next;
            free(prevAmt);
        }

        // freeing quarter nodes
        //if(cr_y_q1)
            free(cr_y_q1);
        //if(cr_y_q2)
            free(cr_y_q2);
        //if(cr_y_q3)
            free(cr_y_q3);
        //if(cr_y_q4)
            free(cr_y_q4);

        //if(dr_y_q1)
            free(dr_y_q1);
        //if(dr_y_q2)
            free(dr_y_q2);
        //if(dr_y_q3)
            free(dr_y_q3);
        //if(dr_y_q4)
            free(dr_y_q4);

        // freeing year nodes
        //if(credit_year)
            free(credit_year);
        //if(debit_year)
            free(debit_year);

        // freeing cr/dr (transaction) nodes
        //if(credit)
            free(credit);
        //if(debit)
            free(debit);
    }
    // freeing the malloced memory of root nodes
    free((*bank));
    (*bank) = NULL;
    return;
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
			//printf("Error while opening the file!");
			perror("Error opening file");
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
		token = strtok(NULL, "/");
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

// void print_statement(tree *bank, int numberOfFiles) {
//     char *fileName = "./bank_statements/collective.csv";
//     char line[BUFFER];
//     char *token;

//     FILE *fp = fopen(fileName, "r");
//     if(fp == NULL) {
//         printf("Cannot open the collective file.\n");
//         exit(EXIT_FAILURE);
//     }

//     // skip the header file
//     fgets(line, BUFFER, fp);

//     while(fgets(line, BUFFER, fp) != NULL) {
//         tree rootNode = NULL;
//         int quarter;

//         //fgets(line, BUFFER, fp);

//         // bank name
//         token = strtok(line, ",");
//         for(int i = 0; i < numberOfFiles; i++) {
//             if(strcmp(token, (*bank)[i].bankName) == 0) {
//                 rootNode = &((*bank)[i]);
//             }
//         }
//         // print bank name
//         printf("%s,", rootNode->bankName);

//         // skip srn, txn date, value date, description
//         token = strtok(NULL, ",");
//         token = strtok(NULL, ",");
//         char *quarterToken = strtok(token, "-");
//         quarterToken = strtok(NULL, "-");
//         if(strcmp(quarterToken, "01") == 0 || strcmp(quarterToken, "02") == 0 || strcmp(quarterToken, "03") == 0) {
//             quarter = 1;
//         } else if(strcmp(quarterToken, "04") == 0 || strcmp(quarterToken, "05") == 0 || strcmp(quarterToken, "06") == 0) {
//             quarter = 2;
//         } else if(strcmp(quarterToken, "07") == 0 || strcmp(quarterToken, "08") == 0 || strcmp(quarterToken, "09") == 0) {
//             quarter = 3;
//         } else {
//             quarter = 4;
//         }
//         token = strtok(NULL, ",");
//         token = strtok(NULL, ",");

//         // cr/dr
//         token = strtok(NULL, ",");
//         // for(int i = 0; i < 2; i++)
//         //     toupper(token[i]);
//         if(strcmp(token, "CR") == 0) {
//             token = strtok(NULL, ",");
//             token = strtok(NULL, ",");
//             printf("%s,%s,", rootNode->credit->str, rootNode->credit->year->year);
//             if(quarter == 1) {
//                 printf("%s,AMOUNT\n", rootNode->credit->year->quarter1->quarter);
//             } else if(quarter == 2) {
//                 printf("%s,AMOUNT\n", rootNode->credit->year->quarter2->quarter);
//             } else if(quarter == 3) {
//                 printf("%s,AMOUNT\n", rootNode->credit->year->quarter3->quarter);
//             } else {
//                 printf("%s,AMOUNT\n", rootNode->credit->year->quarter4->quarter);
//             }
//             /* token has the amount, insert it in credit amounts linked list */
//         } else {
//             token = strtok(NULL, ",");
//             token = strtok(NULL, ",");
//             printf("%s,%s,", rootNode->debit->str, rootNode->debit->year->year);
//             if(quarter == 1) {
//                 printf("%s,AMOUNT\n", rootNode->debit->year->quarter1->quarter);
//             } else if(quarter == 2) {
//                 printf("%s,AMOUNT\n", rootNode->debit->year->quarter2->quarter);
//             } else if(quarter == 3) {
//                 printf("%s,AMOUNT\n", rootNode->debit->year->quarter3->quarter);
//             } else {
//                 printf("%s,AMOUNT\n", rootNode->debit->year->quarter4->quarter);
//             }
//             /* token has the amount, insert it in credit amounts linked list */
//         }
//         token = strtok(NULL, "\n");
//     }
//     printf("\n");
//     fclose(fp);
// }

void fill_data_structure(tree *bank, int numberOfFiles) {
    char *fileName = "./bank_statements/collective.csv";
    char line[BUFFER];
    char *token;

    FILE *fp = fopen(fileName, "r");
    if (fp == NULL) {
        fprintf(stderr, "Cannot open the collective file: %s\n", fileName);
        exit(EXIT_FAILURE);
    }

    // Skip the header line
    fgets(line, BUFFER, fp);

    while (fgets(line, BUFFER, fp) != NULL) {
        tree rootNode = NULL;
        int qtr = 0;
        char year[5]; // Store year as a string (4 chars + null terminator)

        // Get bank name
        token = strtok(line, ",");
        for (int i = 0; i < numberOfFiles; i++) {
            if (strcmp(token, (*bank)[i].bankName) == 0) {
                rootNode = &((*bank)[i]);
                break;
            }
        }

        if (rootNode == NULL) {
            fprintf(stderr, "Bank name not found: %s\n", token);
            exit(EXIT_FAILURE); // This shouldn't happen if all inputs are valid
        }

        // Print bank name
        //printf("%s,", rootNode->bankName);

        // Skip SRN
        token = strtok(NULL, ",");

        // Extract transaction date
        token = strtok(NULL, ","); // txn_date
        if (token != NULL) {
            strncpy(year, token + 6, 4); // Extract year (characters 7 to 10)
            year[4] = '\0';             // Null-terminate the string

            char month[3];
            strncpy(month, token + 3, 2); // Extract month (characters 4 and 5)
            month[2] = '\0';              // Null-terminate the string

            int month_num = atoi(month); // Convert month to an integer

            // Determine quarter based on month
            if (month_num >= 1 && month_num <= 3) {
                qtr = 1;
            } else if (month_num >= 4 && month_num <= 6) {
                qtr = 2;
            } else if (month_num >= 7 && month_num <= 9) {
                qtr = 3;
            } else if (month_num >= 10 && month_num <= 12) {
                qtr = 4;
            }
        }

        // Skip value date and description
        token = strtok(NULL, ",");
        token = strtok(NULL, ",");

        quarter *q = NULL;
        // Determine credit or debit
        token = strtok(NULL, ","); // CR/DR
        if (strcmp(token, "CR") == 0) {
            //printf("%s,%s,", rootNode->credit->str, year);
            if (qtr == 1) {
                //printf("%s,", rootNode->credit->year->quarter1->quarter);
                q = rootNode->credit->year->quarter1;
            } else if (qtr == 2) {
                //printf("%s,", rootNode->credit->year->quarter2->quarter);
                q = rootNode->credit->year->quarter2;
            } else if (qtr == 3) {
                //printf("%s,", rootNode->credit->year->quarter3->quarter);
                q = rootNode->credit->year->quarter3;
            } else {
                //printf("%s,", rootNode->credit->year->quarter4->quarter);
                q = rootNode->credit->year->quarter4;
            }
        } else if (strcmp(token, "DR") == 0) {
            //printf("%s,%s,", rootNode->debit->str, year);
            if (qtr == 1) {
                //printf("%s,", rootNode->debit->year->quarter1->quarter);
                q = rootNode->debit->year->quarter1;
            } else if (qtr == 2) {
                //printf("%s,", rootNode->debit->year->quarter2->quarter);
                q = rootNode->debit->year->quarter2;
            } else if (qtr == 3) {
                //printf("%s,", rootNode->debit->year->quarter3->quarter);
                q = rootNode->debit->year->quarter3;
            } else {
                //printf("%s,", rootNode->debit->year->quarter4->quarter);
                q = rootNode->debit->year->quarter4;
            }
        }

        // skip currency
        token = strtok(NULL, ",");

        // amount
        token = strtok(NULL, ",");
        int amt = atoi(token);
        insert(q, amt);
        //printf("%d\n", q->amounts->amount);

        // skip balance
        token = strtok(NULL, ",");
    }

    fclose(fp);
}

// void fill_data_structure(tree *bank, int numberOfFiles) {
//     char *fileName = "./bank_statements/collective.csv";
//     char line[BUFFER];
//     char *token;

//     FILE *fp = fopen(fileName, "r");
//     if (fp == NULL) {
//         fprintf(stderr, "Cannot open the collective file: %s\n", fileName);
//         exit(EXIT_FAILURE);
//     }

//     // Skip the header line
//     fgets(line, BUFFER, fp);

//     while (fgets(line, BUFFER, fp) != NULL) {
//         tree rootNode = NULL;
//         int qtr = 0;
//         char year[5];

//         // Get bank name
//         token = strtok(line, ",");
//         if (token == NULL) continue; // Skip malformed lines

//         for (int i = 0; i < numberOfFiles; i++) {
//             if (strcmp(token, (*bank)[i].bankName) == 0) {
//                 rootNode = &((*bank)[i]);
//                 break;
//             }
//         }

//         if (rootNode == NULL) {
//             fprintf(stderr, "Bank name not found: %s\n", token);
//             continue;
//         }

//         // Extract transaction date
//         token = strtok(NULL, ","); // txn_date
//         if (token != NULL && strlen(token) >= 10) {
//             strncpy(year, token + 6, 4); // Extract year
//             year[4] = '\0';
//             char month[3];
//             strncpy(month, token + 3, 2); // Extract month
//             month[2] = '\0';
//             int month_num = atoi(month);
//             if (month_num >= 1 && month_num <= 3) qtr = 1;
//             else if (month_num >= 4 && month_num <= 6) qtr = 2;
//             else if (month_num >= 7 && month_num <= 9) qtr = 3;
//             else qtr = 4;
//         }

//         // Skip value date and description
//         token = strtok(NULL, ",");
//         token = strtok(NULL, ",");

//         // Determine credit or debit
//         quarter *q = NULL;
//         token = strtok(NULL, ",");
//         if (strcmp(token, "CR") == 0) q = (qtr == 1) ? rootNode->credit->year->quarter1 : 
//                                 (qtr == 2) ? rootNode->credit->year->quarter2 : 
//                                 (qtr == 3) ? rootNode->credit->year->quarter3 : rootNode->credit->year->quarter4;
//         else if (strcmp(token, "DR") == 0) q = (qtr == 1) ? rootNode->debit->year->quarter1 : 
//                                    (qtr == 2) ? rootNode->debit->year->quarter2 : 
//                                    (qtr == 3) ? rootNode->debit->year->quarter3 : rootNode->debit->year->quarter4;

//         if (q == NULL) {
//             fprintf(stderr, "Quarter pointer is NULL.\n");
//             continue;
//         }

//         // Process amount
//         token = strtok(NULL, ",");
//         int amt = atoi(token);
//         insert(q, amt);
//     }

//     fclose(fp);
// }


void print_data_structure(tree *bank, int numberOfFiles) {
    for(int i = 0; i < numberOfFiles; i++) {
        tree rootNode = &((*bank)[i]);
        printf("%s,", rootNode->bankName);

        transaction *credit = rootNode->credit, *debit = rootNode->debit;

        /* CREDIT */
        printf("%s,", credit->str);
        YEAR *yc = credit->year;
        printf("%s\n", yc->year);

        quarter *q1c = yc->quarter1, *q2c = yc->quarter2, *q3c = yc->quarter3, *q4c = yc->quarter4;
        amount *a1c = q1c->amounts, *a2c = q2c->amounts, *a3c = q3c->amounts, *a4c = q4c->amounts;

        printf("%s:\n", q1c->quarter);
        while(a1c) {
            printf("%d ", a1c->amount);
            a1c = a1c->next;
        }
        printf("\n%s:\n", q2c->quarter);
        while(a2c) {
            printf("%d ", a2c->amount);
            a2c = a2c->next;
        }
        printf("\n%s:\n", q3c->quarter);
        while(a3c) {
            printf("%d ", a3c->amount);
            a3c = a3c->next;
        }
        printf("\n%s:\n", q4c->quarter);
        while(a4c) {
            printf("%d ", a4c->amount);
            a4c = a4c->next;
        }
        printf("\n");

        /* DEBIT */
        printf("%s,", debit->str);
        YEAR *yd = debit->year;
        printf("%s\n", yd->year);

        quarter *q1d = yd->quarter1, *q2d = yd->quarter2, *q3d = yd->quarter3, *q4d = yd->quarter4;
        amount *a1d = q1d->amounts, *a2d = q2d->amounts, *a3d = q3d->amounts, *a4d = q4d->amounts;

        printf("%s:\n", q1d->quarter);
        while(a1d) {
            printf("%d ", a1d->amount);
            a1d = a1d->next;
        }
        printf("\n%s:\n", q2d->quarter);
        while(a2d) {
            printf("%d ", a2d->amount);
            a2d = a2d->next;
        }
        printf("\n%s:\n", q3d->quarter);
        while(a3d) {
            printf("%d ", a3d->amount);
            a3d = a3d->next;
        }
        printf("\n%s:\n", q4d->quarter);
        while(a4d) {
            printf("%d ", a4d->amount);
            a4d = a4d->next;
        }
        printf("\n");
    }
}

// passing the rootest node, argc, and the quarter
int avg_quarterly_deb(tree *banks, int numberOfFiles, int Quart) {
    int avg_sum = 0;
    int count_txn = 0;

    for (int i = 0; i < numberOfFiles; i++) {
        tree rootnode = &((*banks)[i]);
        amount *a_i = NULL;
        if (Quart == 1) {
            a_i = rootnode->debit->year->quarter1->amounts;
        } else if (Quart == 2) {
            a_i = rootnode->debit->year->quarter2->amounts;
        } else if (Quart == 3) {
            a_i = rootnode->debit->year->quarter3->amounts;
        } else if (Quart == 4) {
            a_i = rootnode->debit->year->quarter4->amounts;
        }

        while (a_i) {
            count_txn++;
            avg_sum += a_i->amount;
            a_i = a_i->next;
        }
    }

    if (count_txn == 0) {
        return 0; // Avoid division by zero
    }

    int avg_deb = avg_sum / count_txn;
    return avg_deb;
}

int avg_quarterly_cred(tree *banks, int numberOfFiles, int Quart) {
    int avg_sum = 0;
    int count_txn = 0;

    for (int i = 0; i < numberOfFiles; i++) {
        tree rootnode = &((*banks)[i]);
        amount *a_i = NULL;
        if (Quart == 1) {
            a_i = rootnode->credit->year->quarter1->amounts;
        } else if (Quart == 2) {
            a_i = rootnode->credit->year->quarter2->amounts;
        } else if (Quart == 3) {
            a_i = rootnode->credit->year->quarter3->amounts;
        } else if (Quart == 4) {
            a_i = rootnode->credit->year->quarter4->amounts;
        }

        while (a_i) {
            count_txn++;
            avg_sum += a_i->amount;
            a_i = a_i->next;
        }
    }

    if (count_txn == 0) {
        return 0; // Avoid division by zero
    }

    int avg_cred = avg_sum / count_txn;
    return avg_cred;
}

int txn_count_quart(tree *banks, int numberOfFiles, int Quart) {
    int count_txn = 0;
    for (int i = 0; i < numberOfFiles; i++) {
        tree rootnode = &((*banks)[i]);

        amount *a_i = NULL;
        if (Quart == 1) {
            a_i = rootnode->credit->year->quarter1->amounts;
        } else if (Quart == 2) {
            a_i = rootnode->credit->year->quarter2->amounts;
        } else if (Quart == 3) {
            a_i = rootnode->credit->year->quarter3->amounts;
        } else if (Quart == 4) {
            a_i = rootnode->credit->year->quarter4->amounts;
        }

        while (a_i) {
            count_txn++;
            a_i = a_i->next;
        }

        if (Quart == 1) {
            a_i = rootnode->debit->year->quarter1->amounts;
        } else if (Quart == 2) {
            a_i = rootnode->debit->year->quarter2->amounts;
        } else if (Quart == 3) {
            a_i = rootnode->debit->year->quarter3->amounts;
        } else if (Quart == 4) {
            a_i = rootnode->debit->year->quarter4->amounts;
        }

        while (a_i) {
            count_txn++;
            a_i = a_i->next;
        }
    }

    return count_txn;
}

// stores minimum txn cred and deb details
// char  **minTxn(tree *banks, int argc){
//     //minimum amount debited  : xxxx 
//     //minimum amount credited : xxxx
//     int min_cred = INT_MAX;
//     int bankCount = argc - 1;
//     for(int i = 0; i < bankCount; i++){

//     }


// }

// //stores maximum txn cred and deb details
// char  **maxTxn(){
//     //Bank Name,Srl,Txn Date,Value Date,Description,CR/DR,CCY,Amount (INR),Balance (INR)
//     char max_deb[BUFFER];
//     char max_cred[BUFFER];

//     char maxCrBank[BANK_NAME];
//     char maxDrBank[BANK_NAME];


// }



