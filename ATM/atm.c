#include <stdio.h>

void menu();
void checkBalance(int balance);
int deposit(int balance);
int withdraw(int balance);
int changePin(int oldPin);

int main()
{
    int pin = 1234;          
    int enteredPin;
    int balance = 5000;      
    int choice;
    int attempts = 0;

    printf("=================================\n");
    printf("        WELCOME TO ATM\n");
    printf("=================================\n");

    /* PIN verification */
    while (attempts < 3)
    {
        printf("Enter your PIN: ");
        scanf("%d", &enteredPin);

        if (enteredPin == pin)
        {
            printf("\nPIN verified successfully!\n");
            break;
        }
        else
        {
            printf("Incorrect PIN. Try again.\n");
            attempts++;
        }
    }

    if (attempts == 3)
    {
        printf("\nToo many wrong attempts. Card blocked!\n");
        return 0;
    }

    
    do
    {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            checkBalance(balance);
            break;

        case 2:
            balance = deposit(balance);
            break;

        case 3:
            balance = withdraw(balance);
            break;

        case 4:
            pin = changePin(pin);
            break;

        case 5:
            printf("\nThank you for using the ATM.\n");
            break;

        default:
            printf("\nInvalid choice. Please try again.\n");
        }

    } while (choice != 5);

    return 0;
}


void menu()
{
    printf("\n------------ ATM MENU ------------\n");
    printf("1. Check Balance\n");
    printf("2. Deposit Money\n");
    printf("3. Withdraw Money\n");
    printf("4. Change PIN\n");
    printf("5. Exit\n");
    printf("----------------------------------\n");
}


void checkBalance(int balance)
{
    printf("\nYour current balance is: Rs. %d\n", balance);
}


int deposit(int balance)
{
    int amount;
    printf("\nEnter amount to deposit: ");
    scanf("%d", &amount);

    if (amount > 0)
    {
        balance += amount;
        printf("Amount deposited successfully.\n");
        printf("New balance: Rs. %d\n", balance);
    }
    else
    {
        printf("Invalid deposit amount.\n");
    }

    return balance;
}


int withdraw(int balance)
{
    int amount;
    printf("\nEnter amount to withdraw: ");
    scanf("%d", &amount);

    if (amount > balance)
    {
        printf("Insufficient balance.\n");
    }
    else if (amount <= 0)
    {
        printf("Invalid withdrawal amount.\n");
    }
    else
    {
        balance -= amount;
        printf("Please collect your cash.\n");
        printf("Remaining balance: Rs. %d\n", balance);
    }

    return balance;
}


int changePin(int oldPin)
{
    int newPin, confirmPin;

    printf("\nEnter new PIN: ");
    scanf("%d", &newPin);

    printf("Confirm new PIN: ");
    scanf("%d", &confirmPin);

    if (newPin == confirmPin)
    {
        printf("PIN changed successfully.\n");
        return newPin;
    }
    else
    {
        printf("PINs do not match. PIN not changed.\n");
        return oldPin;
    }
}

