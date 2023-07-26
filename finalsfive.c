#include <stdio.h>
#include <string.h>

// Struct to store booking information
struct Booking {
    char status[10];
    char destination[50];
    char time[10];
    int day;
    int month;
    int year;
    char first_name[50];
    char last_name[50];
    char id_passport[20];
    char phone_number[15];
};

// Function to display available destinations
void displayDestinations() {
    printf("Available Destinations:\n");
    printf("1. Mombasa\n");
    printf("2. Kisumu\n");
    printf("3. Eldoret\n");
}

// Function to display available times
void displayTimes() {
    printf("Available Times:\n");
    printf("1. 10am\n");
    printf("2. 2pm\n");
    printf("3. 5pm\n");
}

// Function to calculate and display total cost
void displayTotalCost(int numTickets) {
    int totalCost = numTickets * 100; // Each ticket costs 100 shillings
    printf("Total Cost: %d shillings\n", totalCost);
}

int main() {
    int choice;
    struct Booking booking[100]; // Assuming we can book up to 100 tickets
    int numBookings = 0;
    
    

    while (1) {
        printf("Menu:\n");
        printf("1. Book Ticket\n");
        printf("2. Book Return Ticket\n");
        printf("3. Reserve a Ticket\n");
        printf("4. Exit Program\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                //
                break;

            case 2:
                // Implementation of Case 2 (Booking a return ticket) remains the same, so no changes needed here.
                // ...
                break;

            case 3:
                printf("Reserving a ticket...\n");

                strcpy(booking[numBookings].status, "reserve");

                printf("Please choose a destination:\n");
                displayDestinations();

                int destinationChoice;
                scanf("%d", &destinationChoice);

                switch (destinationChoice) {
                    case 1:
                        strcpy(booking[numBookings].destination, "Mombasa");
                        break;
                    case 2:
                        strcpy(booking[numBookings].destination, "Kisumu");
                        break;
                    case 3:
                        strcpy(booking[numBookings].destination, "Eldoret");
                        break;
                    default:
                        printf("Invalid destination choice.\n");
                        continue;
                }

                printf("Please choose a time:\n");
                displayTimes();

                int timeChoice;
                scanf("%d", &timeChoice);

                switch (timeChoice) {
                    case 1:
                        strcpy(booking[numBookings].time, "10am");
                        break;
                    case 2:
                        strcpy(booking[numBookings].time, "2pm");
                        break;
                    case 3:
                        strcpy(booking[numBookings].time, "5pm");
                        break;
                    default:
                        printf("Invalid time choice.\n");
                        continue;
                }

                printf("Enter the date (day month year): ");
                scanf("%d %d %d", &booking[numBookings].day, &booking[numBookings].month, &booking[numBookings].year);

                printf("Enter your First Name: ");
                scanf(" %[^\n]", booking[numBookings].first_name);

                printf("Enter your Last Name: ");
                scanf(" %[^\n]", booking[numBookings].last_name);

                printf("Enter your ID/Passport number: ");
                scanf(" %[^\n]", booking[numBookings].id_passport);

                printf("Enter your Phone Number: ");
                scanf(" %[^\n]", booking[numBookings].phone_number);

                numBookings++;

                char reserveAgain;
                printf("Do you want to reserve another ticket? (Y/N): ");
                scanf(" %c", &reserveAgain);

                if (reserveAgain == 'N' || reserveAgain == 'n') {
                    printf("Reservations completed.\n");
                    displayTotalCost(numBookings);
                    return 0;
                }

                break;

            case 4:
                printf("Exiting the program.\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}
