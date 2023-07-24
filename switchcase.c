#include <stdio.h>
#include <stdlib.h>

// Struct to store user information
struct Ticket {
    char destination[20];
    char time[10];
    int date;
    int month;
    int year;
    char name[50];
    char email[50];
    int phone;
};

// Function to display available destinations and get user choice
int callDestination() {
    int choice;
    printf("Choose a destination:\n");
    printf("1. Kisumu\n");
    printf("2. Mombasa\n");
    printf("3. Eldoret\n");
    printf("Enter your choice (1-3): ");
    scanf("%d", &choice);

    return choice;
}

// Function to display available times and get user choice
void timeSelection() {
    printf("Choose a time:\n");
    printf("1. 10am\n");
    printf("2. 2pm\n");
    printf("3. 5pm\n");
}

// Function to get user details and store them in the struct
void getUserDetails(struct Ticket *ticket) {
    printf("Enter your name: ");
    scanf(" %[^\n]", ticket->name);

    printf("Enter your email: ");
    scanf(" %[^\n]", ticket->email);

    printf("Enter your phone number: ");
    scanf("%d", &ticket->phone);
}

// Function to calculate the cost of all tickets combined
int calculateTotalCost(struct Ticket *tickets, int numTickets) {
    // Assume each ticket costs $100
    int ticketCost = 100;
    return ticketCost * numTickets;
}

int main() {
    struct Ticket ticket1, ticket2;
    int totalTickets = 0;
    int choice, timeChoice;

    do {
        choice = callDestination();

        switch (choice) {
            case 1:
                printf("You chose Kisumu.\n");
                timeSelection();
                scanf("%d", &timeChoice);

                switch (timeChoice) {
                    case 1:
                        printf("You chose 10am.\n");
                        break;
                    case 2:
                        printf("You chose 2pm.\n");
                        break;
                    case 3:
                        printf("You chose 5pm.\n");
                        break;
                    default:
                        printf("Invalid time choice.\n");
                        return 1;
                }
                break;
            case 2:
                printf("You chose Mombasa.\n");
                timeSelection();
                scanf("%d", &timeChoice);

                switch (timeChoice) {
                    case 1:
                        printf("You chose 10am.\n");
                        break;
                    case 2:
                        printf("You chose 2pm.\n");
                        break;
                    case 3:
                        printf("You chose 5pm.\n");
                        break;
                    default:
                        printf("Invalid time choice.\n");
                        return 1;
                }
                break;
            case 3:
                printf("You chose Eldoret.\n");
                timeSelection();
                scanf("%d", &timeChoice);

                switch (timeChoice) {
                    case 1:
                        printf("You chose 10am.\n");
                        break;
                    case 2:
                        printf("You chose 2pm.\n");
                        break;
                    case 3:
                        printf("You chose 5pm.\n");
                        break;
                    default:
                        printf("Invalid time choice.\n");
                        return 1;
                }
                break;
            default:
                printf("Invalid destination choice.\n");
                return 1;
        }

        printf("Enter date/month/year (integer format): ");
        scanf("%d %d %d", &ticket1.date, &ticket1.month, &ticket1.year);

        getUserDetails(&ticket1);
        totalTickets++;

        printf("Do you want to book another ticket? (1: Yes, 0: No): ");
        scanf("%d", &choice);
    } while (choice == 1);

    // Call function to calculate total cost of all tickets
    int totalCost = calculateTotalCost(&ticket1, totalTickets);

    printf("Total cost for %d tickets: $%d\n", totalTickets, totalCost);

    return 0;
}
