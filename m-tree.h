#define BANK_NAME 16
#define CR_DR 4

typedef struct amount {
    int srno;
    char bankName[BANK_NAME];
    int amount;
    struct amount *next;
}amount;

typedef struct year {
    amount *jan, *feb, *march, *april, *may, *june, *july, *aug, *sept, *oct, *nov, *dec;
}year;

typedef struct transaction {
    char str[CR_DR]; // cr/dr
    year *year1, *year2;
}transaction;

typedef struct root {
    char bankName[BANK_NAME];
    transaction *left, *right;
}root;

typedef root* tree;

// function definitions:
void init(tree *root);
tree balance_bank1();
tree balance_bank2();
tree total_credit_bank1();
tree total_credit_bank2();
tree total_debit_bank1();
tree total_debit_bank2();
void sort(); // on basis of amount/date/month
void destroy(tree *root);
void combineFile(int argc, char *argv[]);