#include <stddef.h>
#include <stdio.h>

static float accounts [3][50];

void openAccount (float amount)
{
    if (amount<0)
    {
        printf("Can't deposit negative value");
        return;
    }
    for (int i = 0; i < 50; i++)
    {
        if (accounts[0][i] == 0)
        {
            accounts[0][i] = 1;
            accounts[1][i] = amount;
            printf("New account number is: %d\n", i+901);
            return;
        }
    }
    printf("All the accounts are taken\n");
    return;
}

void checkMoney (int account_number)
{
    account_number = account_number - 1 - 900;
    if(account_number < 0 || account_number >49)
    {
        printf("The account does not exist");
        return;
    }
    if (accounts[0][account_number] == 1)
    {
        printf("The balance of account number %d is: %.2f\n", account_number + 901 ,accounts[1][account_number]);
    }
    else
    {
        printf("This account is closed\n");
    }
}

void addMoney (int account_number, double amount)
{
    account_number = account_number - 1 - 900;
    if(account_number < 0 || account_number >49)
    {
        printf("The account does not exist");
        return;
    }
    if (accounts[0][account_number] == 0)
    {
        printf("The account is closed\n");
    }
    else
    {
        accounts[1][account_number] += amount;
        checkMoney(account_number);
    }
}

void getMoney (int account_number, float amount)
{
    account_number = account_number - 1 - 900;
    if(account_number < 0 || account_number >49)
    {
        printf("The account does not exist");
        return;
    }
    if (accounts[0][account_number] == 1)
    {
        if (accounts[1][account_number] >= amount)
        {
            printf("The balance is: %.2f", accounts[1][account_number]);
            accounts[1][account_number] = accounts[1][account_number] - amount;
            printf("The new balance is: %.2f", accounts[1][account_number]);
        }
        else
        {
            printf("Cannot withdraw more than the balance\n");
        }
    }
    else
    {
        printf("The account is closed\n");
    }
    printf("\n");
}

void closeAccount (int account_number)
{
    account_number = account_number - 1 - 900;
    if(account_number < 0 || account_number >49)
    {
        printf("The account does not exist");
        return;
    }
    if (accounts[0][account_number] == 1)
    {
        accounts[0][account_number] = 0;
        //printf("The account was closed\n");
    }
    else
    {
        printf("The account is already close\n");
    }
}

void addInterest (double interest_rate)
{
    for (int i = 0; i < 50; i++)
    {
        if (accounts[0][i] == 1)
        {
            if (accounts[2][i] + interest_rate > 100)
            {
                accounts[2][i] = 100;
            }
            else if (accounts[2][i] + interest_rate < 0)
            {
                accounts[2][i] = 0;
            }
            else
            {
                accounts[2][i] += interest_rate;
            }
        }
    }
}

void printAccounts ()
{
    for (int i = 0; i < 50; i++)
    {
        if (accounts[0][i] == 1)
        {
            printf("The balance of account number %d is: %.2f\n", (900 + 1 + i) ,accounts[1][i]);
        }
    }
}

void closeAccounts()
{
    for (int i = 0; i < 50; i++)
    {
        if (accounts[0][i] == 1)
        {
            closeAccount(i + 900 + 1);
        }
    }
}