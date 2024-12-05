#include "m-tree.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFFER 256
#define BANKNAME 100
#define NUM_QUARTERS 4

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
        credit->balance = 0;
        //printf("%s ", credit->str);
        rootNode->debit = (transaction *)malloc(sizeof(transaction));
        transaction *debit = rootNode->debit;
        strcpy(debit->str, "DR");
        debit->balance = 0;
        //printf("%s\n", debit->str);

        // mallocing year node
        credit->year = (YEAR *)malloc(sizeof(YEAR));
        strcpy(credit->year->year, "2023"); // year is to be allocated according to the date
        debit->year = (YEAR *)malloc(sizeof(YEAR));
        strcpy(debit->year->year, "2023");  // year is to be allocated according to the date

        // mallocing quarter nodes
        credit->year->qArr[0] = (quarter *)malloc(sizeof(quarter));
        credit->year->qArr[0]->amounts = NULL;
        credit->year->qArr[0]->balance = 0;
        strcpy(credit->year->qArr[0]->quarter, "Quarter 1");
        //printf("%s ", credit->year->quarter1->quarter);
        credit->year->qArr[1] = (quarter *)malloc(sizeof(quarter));
        credit->year->qArr[1]->amounts = NULL;
        credit->year->qArr[1]->balance = 0;
        strcpy(credit->year->qArr[1]->quarter, "Quarter 2");
        //printf("%s ", credit->year->quarter2->quarter);
        credit->year->qArr[2] = (quarter *)malloc(sizeof(quarter));
        credit->year->qArr[2]->amounts = NULL;
        credit->year->qArr[2]->balance = 0;
        strcpy(credit->year->qArr[2]->quarter, "Quarter 3");
        //printf("%s ", credit->year->quarter3->quarter);
        credit->year->qArr[3] = (quarter *)malloc(sizeof(quarter));
        credit->year->qArr[3]->amounts = NULL;
        credit->year->qArr[3]->balance = 0;
        strcpy(credit->year->qArr[3]->quarter, "Quarter 4");
        //printf("%s\n", credit->year->quarter1->quarter);

        debit->year->qArr[0] = (quarter *)malloc(sizeof(quarter));
        debit->year->qArr[0]->amounts = NULL;
        debit->year->qArr[0]->balance = 0;
        strcpy(debit->year->qArr[0]->quarter, "Quarter 1");
        //printf("%s ", debit->year->quarter1->quarter);
        debit->year->qArr[1] = (quarter *)malloc(sizeof(quarter));
        debit->year->qArr[1]->amounts = NULL;
        debit->year->qArr[1]->balance = 0;
        strcpy(debit->year->qArr[1]->quarter, "Quarter 2");
        //printf("%s ", debit->year->quarter2->quarter);
        debit->year->qArr[2] = (quarter *)malloc(sizeof(quarter));
        debit->year->qArr[2]->amounts = NULL;
        debit->year->qArr[2]->balance = 0;
        strcpy(debit->year->qArr[2]->quarter, "Quarter 3");
        //printf("%s ", debit->year->quarter3->quarter);
        debit->year->qArr[3] = (quarter *)malloc(sizeof(quarter));
        debit->year->qArr[3]->amounts = NULL;
        debit->year->qArr[3]->balance = 0;
        strcpy(debit->year->qArr[3]->quarter, "Quarter 4");
        //printf("%s ", debit->year->quarter4->quarter);
    }
    return;
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

        cr_y_q1 = credit_year->qArr[0];
        cr_y_q2 = credit_year->qArr[1];
        cr_y_q3 = credit_year->qArr[2];
        cr_y_q4 = credit_year->qArr[3];
        dr_y_q1 = debit_year->qArr[0];
        dr_y_q2 = debit_year->qArr[1];
        dr_y_q3 = debit_year->qArr[2];
        dr_y_q4 = debit_year->qArr[3];

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

void fill_data_structure(tree *bank, int numberOfFiles) {
    char *fileName = "./bank_statements/collective.csv";
    char line[BUFFER], srn[10];
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
        int qtr = 0, currBank;
        char year[5];

        // Get bank name
        token = strtok(line, ",");
        for (currBank = 0; currBank < numberOfFiles; currBank++) {
            if (strcmp(token, (*bank)[currBank].bankName) == 0) {
                rootNode = &((*bank)[currBank]);
                break;
            }
        }

        if (rootNode == NULL) {
            fprintf(stderr, "Bank name not found: %s\n", token);
            exit(EXIT_FAILURE); // This shouldn't happen if all inputs are valid
        }

        // Print bank name
        //printf("%s,", rootNode->bankName);

        // SRN
        token = strtok(NULL, ",");
        strcpy(srn, token);

        // Extract transaction date
        token = strtok(NULL, ",");
        if (token != NULL) {
            strncpy(year, token + 6, 4);        // Extract year (characters 7 to 10)
            year[4] = '\0';                     // Null-terminate the string

            char month[3];
            strncpy(month, token + 3, 2);       // Extract month (characters 4 and 5)
            month[2] = '\0';                    // Null-terminate the string

            int month_num = atoi(month);        // Convert month to an integer

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
                q = rootNode->credit->year->qArr[0];
            } else if (qtr == 2) {
                //printf("%s,", rootNode->credit->year->quarter2->quarter);
                q = rootNode->credit->year->qArr[1];
            } else if (qtr == 3) {
                //printf("%s,", rootNode->credit->year->quarter3->quarter);
                q = rootNode->credit->year->qArr[2];
            } else {
                //printf("%s,", rootNode->credit->year->quarter4->quarter);
                q = rootNode->credit->year->qArr[3];
            }
        } else if (strcmp(token, "DR") == 0) {
            //printf("%s,%s,", rootNode->debit->str, year);
            if (qtr == 1) {
                //printf("%s,", rootNode->debit->year->quarter1->quarter);
                q = rootNode->debit->year->qArr[0];
            } else if (qtr == 2) {
                //printf("%s,", rootNode->debit->year->quarter2->quarter);
                q = rootNode->debit->year->qArr[1];
            } else if (qtr == 3) {
                //printf("%s,", rootNode->debit->year->quarter3->quarter);
                q = rootNode->debit->year->qArr[2];
            } else {
                //printf("%s,", rootNode->debit->year->quarter4->quarter);
                q = rootNode->debit->year->qArr[3];
            }
        }

        // skip currency
        token = strtok(NULL, ",");

        // amount
        token = strtok(NULL, ",");
        int amt = atoi(token);
        insert(q, amt, srn);
        //printf("%d\n", q->amounts->amount);

        // skip balance
        token = strtok(NULL, ",");
    }

    // storing total credited amount and total debited amount
    for(int i = 0; i < numberOfFiles; i++) {
        tree rootNode = &((*bank)[i]);
        for(int j = 0; j < 4; j++) {
            rootNode->credit->balance += rootNode->credit->year->qArr[j]->balance;
            rootNode->debit->balance += rootNode->debit->year->qArr[j]->balance;
        }
    }

    // closing the file
    fclose(fp);
}

void print_data_structure(tree *bank, int numberOfFiles) {
    printf("\n\n---------------------------------------------------------------------\n\n");
    for(int i = 0; i < numberOfFiles; i++) {
        tree rootNode = &((*bank)[i]);
        printf("%s:\n", rootNode->bankName);

        transaction *credit = rootNode->credit, *debit = rootNode->debit;

        /* CREDIT */
        printf("%s amount of ", credit->str);
        YEAR *yc = credit->year;
        printf("%s\n", yc->year);

        quarter *q1c = yc->qArr[0], *q2c = yc->qArr[1], *q3c = yc->qArr[2], *q4c = yc->qArr[3];
        amount *a1c = q1c->amounts, *a2c = q2c->amounts, *a3c = q3c->amounts, *a4c = q4c->amounts;

        printf("\n%s:\n", q1c->quarter);
        while(a1c) {
            printf("%d ", a1c->amount);
            a1c = a1c->next;
        }
        printf("\n\n%s:\n", q2c->quarter);
        while(a2c) {
            printf("%d ", a2c->amount);
            a2c = a2c->next;
        }
        printf("\n\n%s:\n", q3c->quarter);
        while(a3c) {
            printf("%d ", a3c->amount);
            a3c = a3c->next;
        }
        printf("\n\n%s:\n", q4c->quarter);
        while(a4c) {
            printf("%d ", a4c->amount);
            a4c = a4c->next;
        }
        printf("\n");

        /* DEBIT */
        printf("%s amount of", debit->str);
        YEAR *yd = debit->year;
        printf("%s\n", yd->year);

        quarter *q1d = yd->qArr[0], *q2d = yd->qArr[1], *q3d = yd->qArr[2], *q4d = yd->qArr[3];
        amount *a1d = q1d->amounts, *a2d = q2d->amounts, *a3d = q3d->amounts, *a4d = q4d->amounts;

        printf("\n%s:\n", q1d->quarter);
        while(a1d) {
            printf("%d ", a1d->amount);
            a1d = a1d->next;
        }
        printf("\n\n%s:\n", q2d->quarter);
        while(a2d) {
            printf("%d ", a2d->amount);
            a2d = a2d->next;
        }
        printf("\n\n%s:\n", q3d->quarter);
        while(a3d) {
            printf("%d ", a3d->amount);
            a3d = a3d->next;
        }
        printf("\n\n%s:\n", q4d->quarter);
        while(a4d) {
            printf("%d ", a4d->amount);
            a4d = a4d->next;
        }
        printf("\n\n---------------------------------------------------------------------\n\n");
    }
}

int avg_quarterly_deb(tree *banks, int numberOfFiles, int Quart) {
    int avg_sum = 0;
    int count_txn = 0;

    for (int i = 0; i < numberOfFiles; i++) {
        tree rootnode = &((*banks)[i]);
        amount *a_i = NULL;
        if (Quart == 1) {
            a_i = rootnode->debit->year->qArr[0]->amounts;
        } else if (Quart == 2) {
            a_i = rootnode->debit->year->qArr[1]->amounts;
        } else if (Quart == 3) {
            a_i = rootnode->debit->year->qArr[2]->amounts;
        } else if (Quart == 4) {
            a_i = rootnode->debit->year->qArr[3]->amounts;
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
            a_i = rootnode->credit->year->qArr[0]->amounts;
        } else if (Quart == 2) {
            a_i = rootnode->credit->year->qArr[1]->amounts;
        } else if (Quart == 3) {
            a_i = rootnode->credit->year->qArr[2]->amounts;
        } else if (Quart == 4) {
            a_i = rootnode->credit->year->qArr[3]->amounts;
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
            a_i = rootnode->credit->year->qArr[0]->amounts;
        } else if (Quart == 2) {
            a_i = rootnode->credit->year->qArr[1]->amounts;
        } else if (Quart == 3) {
            a_i = rootnode->credit->year->qArr[2]->amounts;
        } else if (Quart == 4) {
            a_i = rootnode->credit->year->qArr[3]->amounts;
        }

        while (a_i) {
            count_txn++;
            a_i = a_i->next;
        }

        if (Quart == 1) {
            a_i = rootnode->debit->year->qArr[0]->amounts;
        } else if (Quart == 2) {
            a_i = rootnode->debit->year->qArr[1]->amounts;
        } else if (Quart == 3) {
            a_i = rootnode->debit->year->qArr[2]->amounts;
        } else if (Quart == 4) {
            a_i = rootnode->debit->year->qArr[3]->amounts;
        }

        while (a_i) {
            count_txn++;
            a_i = a_i->next;
        }
        
    }

    return count_txn;
}

void generate_txn_count_graph(tree *banks, int numberOfFiles) {
    // Array to store transaction counts for each quarter
    int txn_counts[4] = {0};

    // Calculate transaction counts for each quarter
    for (int q = 1; q <= 4; q++) {
        txn_counts[q - 1] = txn_count_quart(banks, numberOfFiles, q);
    }

    // Open a pipe to Gnuplot
    FILE *gp = _popen("gnuplot -persistent", "w");
    if (!gp) {
        printf("Error: Could not open Gnuplot.\n");
        return;
    }

    // Send Gnuplot commands
    fprintf(gp, "set title 'Transaction Counts Per Quarter'\n");
    fprintf(gp, "set xlabel 'Quarter'\n");
    fprintf(gp, "set ylabel 'Transaction Count'\n");
    fprintf(gp, "set style data histograms\n");
    fprintf(gp, "set style fill solid\n");
    fprintf(gp, "set boxwidth 0.5\n");
    fprintf(gp, "set grid\n");

    // Define the plot with inline data
    fprintf(gp, "plot '-' using 2:xtic(1) title 'Transactions' with histogram\n");

    // Pass the calculated data to Gnuplot
    for (int i = 0; i < 4; i++) {
        fprintf(gp, "Q%d %d\n", i + 1, txn_counts[i]); // e.g., Q1 10
    }
    fprintf(gp, "e\n"); // End of data

    // Close the pipe
    _pclose(gp);
}

// void plot txn

// stores minimum txn cred and deb details
void minTxn(tree *banks, int numberOfFiles) {
    int min_cred = INT_MAX;
    int min_deb = INT_MAX;
    for (int i = 0; i < numberOfFiles; i++) {
        root *rootnode = *banks + i;
        amount *min_cred_ptr = NULL;
        amount *min_deb_ptr = NULL;

        for(int i = 1; i <= 4; i++) {
            min_cred_ptr = rootnode->credit->year->qArr[i - 1]->amounts;
            while (min_cred_ptr) {
                if (min_cred < min_cred_ptr->amount) {
                    min_cred = min_cred_ptr->amount;
                }
                min_cred_ptr = min_cred_ptr->next;
            }
        }

        for(int i = 1; i <= 4; i++) {
            min_deb_ptr = rootnode->credit->year->qArr[i - 1]->amounts;
            while (min_deb_ptr) {
                if (min_deb < min_deb_ptr->amount) {
                    min_deb = min_deb_ptr->amount;
                }
                min_deb_ptr = min_deb_ptr->next;
            }
        }
    
    }

    if (min_cred == INT_MAX) min_cred = 0;
    if (min_deb == INT_MAX) min_deb = 0;

    printf("Minimum amount debited is: %d\n", min_deb);
    printf("Minimum amount credited is: %d\n", min_cred);
}

void maxTxn(tree *banks, int numberOfFiles) {
    int max_cred = 0;
    int max_deb = 0;
    for (int i = 0; i < numberOfFiles; i++) {
        root *rootnode = *banks + i;
        amount *max_cred_ptr = NULL;
        amount *max_deb_ptr = NULL;

        // Check all quarters for credit transactions
        for(int i = 1; i <= 4; i++) {
            max_cred_ptr = rootnode->credit->year->qArr[i - 1]->amounts;
            while (max_cred_ptr) {
                if (max_cred < max_cred_ptr->amount) {
                    max_cred = max_cred_ptr->amount;
                }
                max_cred_ptr = max_cred_ptr->next;
            }
        }

        for(int i = 1; i <= 4; i++) {
            max_deb_ptr = rootnode->credit->year->qArr[i - 1]->amounts;
            while (max_deb_ptr) {
                if (max_cred < max_deb_ptr->amount) {
                    max_cred = max_deb_ptr->amount;
                }
                max_deb_ptr = max_deb_ptr->next;
            }
        }
    }
    printf("Maximum amount debited is: %d\n", max_deb);
    printf("Maximum amount credited is: %d\n", max_cred);
}

void search_transactions(tree *bank, int numberOfFiles, char **fileNames) {
    tree root = (*bank);
    int numBanks = 0, qFrom, qTo;
    char **bankNames, cr_dr[8];

    // taking a frequency array of banks
    int *freqBanks = (int *)malloc(sizeof(int) * numberOfFiles);
    for(int i = 0; i < numberOfFiles; i++)
        freqBanks[i] = 0;

    // asking number of banks from which transactions are to be extracted
    while(numBanks < 1) {
        printf("Enter number of Banks: ");
        scanf(" %d", &numBanks);
        if(numBanks < 1)
            printf("Please enter correct number of banks.\n");
    }

    // asking names of the banks to determine names of banks
    bankNames = (char **)malloc(sizeof(char *) * numBanks);
    for(int i = 0; i < numBanks; i++) {
        bankNames[i] = (char *)malloc(sizeof(char) * BANK_NAME);
        printf("Enter name of the bank %d: ", i + 1);
        scanf("%s", bankNames[i]);
        for(int j = 0; j < strlen(bankNames[i]); j++) {
            bankNames[i][j] = tolower(bankNames[i][j]);
        }
    }

    // checking whether entered bank names are in the data structure or not, and updating the frequency array
    for(int i = 0; i < numBanks; i++) {
        for(int j = 0; j < numberOfFiles; j++) {
            if(strcmp(root[j].bankName, bankNames[i]) == 0) {
                freqBanks[j] = 1;
                break;
            }
        }
    }

    // ask quarter
    printf("Enter FROM quarter: ");
    scanf("%d", &qFrom);
    printf("Enter TO quarter: ");
    scanf("%d", &qTo);

    // ask credit/debit/both
    printf("Credit/debit/both? ");
    scanf("%s", cr_dr);
    cr_dr[1] = '\0';
    cr_dr[0] = tolower(cr_dr[0]);

    // ask amount range
    char range[4];
    int lowAmt = -1, highAmt = -1;
    printf("Is there any amount range? [Y/N] ");
    scanf("%s", range);
    range[1] = '\0';
    range[0] = toupper(range[0]);
    if(range[0] == 'Y') {
        printf("Enter lower amount: ");
        scanf("%d", &lowAmt);
        printf("Enter higher amount: ");
        scanf("%d", &highAmt);
    }

    // printing the header line
    char tmp[BUFFER];
    FILE *temp = fopen(fileNames[1], "r");
    if(temp == NULL) {
        perror("File cannot open");
        exit(EXIT_FAILURE);
    }
    fgets(tmp, BUFFER, temp);
    printf("\n%s\n", tmp);
    fclose(temp);

    // printing required data
    for(int i = 0; i < numberOfFiles; i++) {
        if(freqBanks[i]) {
            tree rootNode = &((*bank)[i]);
            FILE *fp;// = fopen(fileNames[i], "r");
            transaction *cr = rootNode->credit, *dr = rootNode->debit;
            YEAR *yc = cr->year, *yd = dr->year;
            char line[BUFFER], buf[BUFFER], *token;

            // credit
            if(cr_dr[0] == 'c' || cr_dr[0] == 'b') {
                for(int j = qFrom; j <= qTo; j++) {
                    quarter *qc = yc->qArr[j - 1];
                    // print quarter name
                    //printf("%s:\n", qc->quarter);
                    amount *amtc = qc->amounts;
                    while(amtc) {
                        // print required statements from the file
                        if(strcmp(range, "Y") == 0) {
                            if(amtc->amount >= lowAmt && amtc->amount <= highAmt) {
                                fp = fopen(fileNames[i + 1], "r");
                                if(fp == NULL) {
                                    perror("File cannot open");
                                    exit(EXIT_FAILURE);
                                }
                                // skip header
                                fgets(line, BUFFER, fp);
                                // find amount statements
                                while(fgets(line, BUFFER, fp)) {
                                    strcpy(buf, line);
                                    token = strtok(buf, ",");
                                    if(strcmp(token, amtc->srno) == 0) {
                                        printf("%s\n", line);
                                        break;
                                    }
                                }
                                fclose(fp);
                            }
                        } else {
                            fp = fopen(fileNames[i + 1], "r");
                            if(fp == NULL) {
                                perror("File cannot open");
                                exit(EXIT_FAILURE);
                            }
                            // skip header
                            fgets(line, BUFFER, fp);
                            // find amount statements
                            while(fgets(line, BUFFER, fp)) {
                                strcpy(buf, line);
                                token = strtok(buf, ",");
                                if(strcmp(token, amtc->srno) == 0) {
                                    printf("%s\n", line);
                                    break;
                                }
                            }
                            fclose(fp);
                        }
                        //printf("%s. %d\n", amtc->srno, amtc->amount);
                        amtc = amtc->next;
                    }
                }
            }
            // debit
            if(cr_dr[0] == 'd' || cr_dr[0] == 'b') {
                for(int j = qFrom; j <= qTo; j++) {
                    quarter *qd = yd->qArr[j - 1];
                    // print quarter name
                    //printf("%s:\n", qc->quarter);
                    amount *amtd = qd->amounts;
                    while(amtd) {
                        // print required statements from the file
                        if(strcmp(range, "Y") == 0) {
                            if(amtd->amount >= lowAmt && amtd->amount <= highAmt) {
                                fp = fopen(fileNames[i + 1], "r");
                                // skip header
                                fgets(line, BUFFER, fp);
                                // find amount statement
                                while(fgets(line, BUFFER, fp)) {
                                    strcpy(buf, line);
                                    token = strtok(buf, ",");
                                    if(strcmp(token, amtd->srno) == 0) {
                                        printf("%s\n", line);
                                        break;
                                    }
                                }
                                fclose(fp);
                            }
                        } else {
                            fp = fopen(fileNames[i + 1], "r");
                            if(fp == NULL) {
                                perror("File cannot open");
                                exit(EXIT_FAILURE);
                            }
                            // skip header
                            fgets(line, BUFFER, fp);
                            // find amount statements
                            while(fgets(line, BUFFER, fp)) {
                                strcpy(buf, line);
                                token = strtok(buf, ",");
                                if(strcmp(token, amtd->srno) == 0) {
                                    printf("%s\n", line);
                                    break;
                                }
                            }
                            fclose(fp);
                        }
                        //printf("%s. %d\n", amtc->srno, amtc->amount);
                        amtd = amtd->next;
                    }
                }
            }
        }
    }
    // free allocated memory
    free(freqBanks);
    for(int i = 0; i < numBanks; i++)
        free(bankNames[i]);
    free(bankNames);
}