#define BANK_NAME 16
#define CR_DR 4
#define QUARTER 16

typedef struct amount {
    char srno[10];
    // char bankName[BANK_NAME];
    int amount;
    struct amount *next;
}amount;

typedef struct quarter {
    char quarter[QUARTER];
    long balance;
    amount *amounts;
}quarter;

typedef struct YEAR {
    char year[5];
    quarter *qArr[4];
}YEAR;

typedef struct transaction {
    char str[CR_DR]; // cr/dr
    long balance;
    YEAR *year;
}transaction;

typedef struct root {
    char bankName[BANK_NAME];
    transaction *credit, *debit;
}root;

typedef root* tree;

// file function declarations
void combineFile(int argc, char *argv[]);

// function definitions:
void init(tree *bank, int numberOfFiles, char **bankName);
void fill_data_structure(tree *bank, int numberOfFiles);
void print_data_structure(tree *bank, int numberOfFiles);

// tree balance_bank1();
// tree balance_bank2();
// tree total_credit_bank1();
// tree total_credit_bank2();
// tree total_debit_bank1();
// tree total_debit_bank2();
// void sort(); // on basis of amount/date/month
void destroy(tree *bank, int numberOfFiles);

int avg_quarterly_deb(tree *banks, int numberOfFiles, int Quart);
int avg_quarterly_cred(tree *banks, int numberOfFiles, int Quart);
int txn_count_quart(tree *banks, int numberOfFiles, int Quart);
void generate_txn_count_graph(tree *banks, int numberOfFiles);
void minTxn(tree *banks, int numberOfFiles);
void maxTxn(tree *banks, int numberOfFiles);
void search_transactions(tree *bank, int numberOfFiles, char **fileNames);

// list functions
void insert(quarter *q, int data, char *srn);
amount *createNode(int data, char *s);
