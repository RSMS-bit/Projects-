#include <stdio.h>

int main() {
    float balance = 1000.0;
    int choice;
    float amount;

    while (1) {
        printf("\n--- ATM Simulator ---\n");
        printf("1. Check Balance\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Current Balance: R%.2f\n", balance);
        }

        else if (choice == 2) {
            printf("Enter amount to deposit: ");
            scanf("%f", &amount);
            balance += amount;
            printf("Deposit successful! New Balance: R%.2f\n", balance);
        }

        else if (choice == 3) {
            printf("Enter amount to withdraw: ");
            scanf("%f", &amount);

            if (amount > balance) {
                printf("Insufficient funds!\n");
            } else {
                balance -= amount;
                printf("Withdrawal successful! New Balance: R%.2f\n", balance);
            }
        }

        else if (choice == 4) break;
        else printf("Invalid choice!\n");
    }

    return 0;
}
