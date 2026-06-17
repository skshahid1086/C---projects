#include<stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct bank
{
    int acc;
    char name[50];
    float balance;
}Bank;

Bank banks[500];
int accCount = 0;

void menu(){
    printf("\n");
    printf("1. Create Account\n");
    printf("2. Deposit Money\n");
    printf("3. Withdraw Money\n");
    printf("4. List All Acounts\n");
    printf("0. Exit\n");
}

void saveAccounts() {
    FILE *fp = fopen("accounts.dat", "wb");

    if(fp == NULL){
        printf("Error opening file\n");
        return;
    }

    fwrite(&accCount, sizeof(int), 1, fp);

    fwrite(banks, sizeof(Bank), accCount, fp);

    fclose(fp);
}

void loadAccounts() {
    FILE *fp = fopen("accounts.dat", "rb");

    if(fp == NULL){
        return;
    }

    fread(&accCount, sizeof(int), 1, fp);

    fread(banks, sizeof(Bank), accCount, fp);

    fclose(fp);
}

void createAcc(){ 
    if(accCount>=500){
        printf("Database Full\n");
        return;
    } 

    int unique;

    int random_5_digit = (rand() % (99999 - 10000 + 1)) + 10000;

    do
    {
        unique=1;
        random_5_digit = (rand() % (99999 - 10000 + 1)) + 10000;
        int newAcc = (1100 * 1000000) + random_5_digit;

        for(int i=0;i<accCount;i++){
            if(banks[i].acc == newAcc){
                unique = 0;
                break;
            }
        }

    } while (!unique);
    banks[accCount].acc = (1100*1000000) + random_5_digit;

    printf("Enter Account Holder Name: ");
    scanf(" %[^\n]",banks[accCount].name);

    float openBal;
    printf("Enter opening balance: ");
    scanf("%f",&openBal);
    if(openBal<=0){
        printf("Invalid input!\n");
        return;
    }else{
        banks[accCount].balance = openBal;
    }

    printf("Account created successfully!\n\n");
    printf("Your account details are:\n\n");
    printf("Account number: %d\n",banks[accCount].acc);
    printf("Name: %s\n",banks[accCount].name);
    printf("Branch: Demo Branch\n");
    printf("IFSC: 11000\n");
    printf("Account Balance: %.2f\n",banks[accCount].balance);

    accCount++;

    saveAccounts();
}

void deposit(){
    int accNo;
    float amount;
    printf("Enter account number: ");
    scanf("%d",&accNo);

    int found = 0;

    for(int i=0;i<accCount;i++){
        if(accNo==banks[i].acc){
            printf("Enter amount you want to deposit: ");
            scanf("%f",&amount);
            if(amount<=0){
                printf("Invalid amount!\n");
                return;
            }else{
                banks[i].balance+=amount;

                printf("Amount deposited successfully\n");
                printf("Your updated balance is: %.2f\n", banks[i].balance);
                found=1;
                saveAccounts();
                break;
            }
        }
    }

    if(!found) printf("Account not found\n");

}

void withdraw(){
    int accNo;
    float amount;
    printf("Enter account number: ");
    scanf("%d",&accNo);

    int found = 0;

    for(int i=0;i<accCount;i++){

        if(accNo==banks[i].acc){
            printf("Enter amount you want to withdraw: ");
            scanf("%f",&amount);

            if(amount>banks[i].balance){
                printf("Insufficient Balance!\n");
                return;
            }else if(amount<=0){
                printf("Inavlid Input!\n");
                return;
            }else{
                banks[i].balance-=amount;

                printf("Amount withdrawn successfully\n");
                printf("Your updated balance is: %.2f\n", banks[i].balance);
                found=1;
                saveAccounts();
                break;
            }
        }
    }

    if(!found) printf("Account not found\n");

    
}

void display(){
    const int ADMIN_PASS = 1234;
    int passInput;

    printf("For Bank's Staff Only\n");
    printf("Enter admin password: ");
    scanf("%d",&passInput);

    if(ADMIN_PASS==passInput){
        for(int i=0;i<accCount;i++){
            printf("\n");
            printf("Account number: %d\n",banks[i].acc);
            printf("Name: %s\n",banks[i].name);
            printf("Branch: Demo Branch\n");
            printf("IFSC: 11000\n");
            printf("Account Balance: %.2f\n",banks[i].balance);
        }
    }else printf("Wrong password\n");
}

int main(){
    srand(time(NULL));

    loadAccounts();
    
    int running = 1;

    while(running){
        int operation;
        menu();
        printf("Choose operation: ");
        scanf("%d",&operation);

        switch (operation)
        {
        case 1:
            createAcc();
            break;
        case 2:
            deposit();
            break;
        case 3:
            withdraw();
            break;
        case 4:
            display();
            break;
        case 0:
            running=0;
            break;
        default:
        printf("Invlid Input\n");
            break;
        }
    }
    return 0;
}