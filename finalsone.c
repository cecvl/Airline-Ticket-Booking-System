#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to store booking information
struct Booking {
    char status[10];
    char destination[50];
    char time[10];
    int day;
    int month;
    int year;
    char name[50];
    int age;
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

int main() {
    int choice;
    char again;
    struct Booking booking[100]; // Assuming we can book up to 100 tickets
    int numBookings = 0;
    int totalCost = 0;

    while (1) {
        printf("Menu:\n");
        printf("1. Book Ticket\n");
        printf("2. Book Return Ticket\n");
        printf("3. Reserve a Seat\n");
        printf("4. Exit Program\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Booking a ticket...\n");
                strcpy(booking[numBookings].status, "booking");

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

                printf("Enter your name: ");
                scanf(" %[^\n]", booking[numBookings].name);

                printf("Enter your age: ");
                scanf("%d", &booking[numBookings].age);

                printf("Enter your ID/Passport number: ");
                scanf(" %[^\n]", booking[numBookings].id_passport);

                printf("Enter your phone number: ");
                scanf(" %[^\n]", booking[numBookings].phone_number);

                printf("Booking successful!\n");

                totalCost += 100; // Each ticket costs 100 shillings
                numBookings++;

                printf("Do you want to book another ticket? (Y/N): ");
                scanf(" %c", &again);

                if (again == 'N' || again == 'n') {
                    printf("Thank you for using the ticket booking system.\n");
                    printf("Here are your tickets:\n");
                    for (int i = 0; i < numBookings; i++) {
                        printf("Ticket %d:\n", i + 1);
                        printf("Status: %s\n", booking[i].status);
                        printf("Destination: %s\n", booking[i].destination);
                        printf("Time: %s\n", booking[i].time);
                        printf("Date: %d/%d/%d\n", booking[i].day, booking[i].month, booking[i].year);
                        printf("Name: %s\n", booking[i].name);
                        printf("Age: %d\n", booking[i].age);
                        printf("ID/Passport: %s\n", booking[i].id_passport);
                        printf("Phone number: %s\n", booking[i].phone_number);
                        printf("\n");
                    }
                    printf("Total Cost: %d shillings\n", totalCost);
                    return 0;
                }

                break;

            case 2:
                // Implement the logic for booking a return ticket (not covered in this example)
                printf("Booking a return ticket...\n");
                break;

            case 3:
                // Implement the logic for reserving a seat (not covered in this example)
                printf("Reserving a seat...\n");
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
