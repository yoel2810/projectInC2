#include <stdio.h>
#include "myBank.h"

int main ()
{
    char x = 0;
        float amount = -1;
        int account_number = 0;
        float interest_rate = 0;
    while (1)
    {
        
        printf("Please choose a transaction type:\n O-Open Account\n B-Balance Inquiry\n D-Deposit\n W-Withdrawal\n C-Close Account\n I-Interest\n P-Print\n E-Exit\n");
        scanf("%c", &x);
        //printf("x = %c", x);
        if (x=='O')
        {
            printf("Please enter amount for deposit: ");
            int res = scanf("%f", &amount);
            if (res == 1)
            {
            openAccount(amount);
            }
            else
            {
                printf("Failed to read the amount\n");
                printf("\n");
                continue;
            }
        }
        else if (x=='B')
        {
            printf("Please enter account number: ");
            int res = scanf("%d",&account_number);
            if(account_number < 901 || account_number >950)
    {
        printf("The account does not exist\n");
        printf("\n");
        continue;
    }
            if (res == 1)
            {
            checkMoney(account_number);
            }
            else
            {
                printf("Failed to read the account number\n");
                printf("\n");
                continue;
            }
        }
        else if (x=='D')
        {
            printf("Please enter account number: ");
            int res = scanf("%d",&account_number);
            if(account_number < 901 || account_number >950)
    {
        printf("The account does not exist\n");
        printf("\n");
        continue;
    }
            if (res != 1)
            {
                printf("Failed to read the account number\n");
                printf("\n");
                continue;
            }
            printf("Please enter amount for deposit: ");
            int res2 = scanf("%f", &amount);
            if (res2 == 1)
            {
            addMoney(account_number, amount);
            }
            else
            {
                printf("Failed to read the amount\n");
                printf("\n");
                continue;
            }
        }
        else if (x=='W')
        {
            printf("Please enter account number: ");
            int res = scanf("%d",&account_number);
            if(account_number < 901 || account_number >950)
    {
        printf("The account does not exist\n");
        printf("\n");
        continue;
    }
            if(res!=1)
            {
                printf("Failed to read the account number\n");
                printf("\n");
                continue;
            }
            printf("Please enter the amount to withdraw: ");
            int res2 = scanf("%f", &amount);
            if (res2 == 1)
            {
            getMoney(account_number, amount);
            }
            else
            {
                printf("Failed to read the amount\n");
                printf("\n");
                continue;
            }
        }
        else if (x=='C')
        {
            printf("Please enter account number: ");
            int res = scanf("%d",&account_number);
            if(account_number < 901 || account_number >950)
    {
        printf("The account does not exist\n");
        printf("\n");
        continue;
    }
            if (res == 1)
            {
            closeAccount(account_number);
            }
            else
            {
                printf("Failed to read the amount\n");
                printf("\n");
                continue;
            }
        }
        else if (x=='I')
        {
            printf("Please enter interest rate: ");
            int res = scanf("%f", &interest_rate);
            if (res == 1)
            {
            addInterest(interest_rate);
            }
            else
            {
                printf("Failed to read the interest rate\n");
                printf("\n");
                continue;
            }
        }
        else if (x=='P')
        {
            printAccounts();
        }
        else if (x=='E')
        {
            closeAccounts();
            break;
        }
        else
        {
            printf("Invalid transaction type\n");
        }
        while(getchar()!='\n');
        amount = -1;
        x = 0;
        account_number = 0;
        printf("\n");
    }
}