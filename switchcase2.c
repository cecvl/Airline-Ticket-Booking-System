#include <stdio.h>
#include <string.h>

#define MAX_BOOKINGS 2
#define COST_PER_TICKET 100 // Replace with the actual cost per ticket

// Struct to store user details
struct UserDetails {
    char name[50];
    int age;
    char idOrPassport[20];
    char phoneNumber[15];
};

// Struct to store booking information
struct Booking {
    char destination[20];
    char time[5];
    int departureDay;
    int departureMonth;
    int departureYear;
    struct UserDetails user;
};

// Function to display destinations and get user input
int getDestination() {
    int choice;
    printf("\nDestinations: \n");
    printf("1. Mombasa\n");
    printf("2. Kisumu\n");
    printf("3. Eldoret\n");
    printf("Choose a destination: ");
    scanf("%d", &choice);
    return choice;
}

// Function to display times and get user input
int getTime() {
    int choice;
    printf("\nTimes: \n");
    printf("1. 10am\n");
    printf("2. 2pm\n");
    printf("3. 5pm\n");
    printf("Choose a time: ");
    scanf("%d", &choice);
    return choice;
}

// Function to get user details
void getUserDetails(struct UserDetails *user) {
    printf("\nEnter name: ");
    scanf("%s", user->name);
    printf("Enter age: ");
    scanf("%d", &user->age);
    printf("Enter ID/passport number: ");
    scanf("%s", user->idOrPassport);
    printf("Enter phone number: ");
    scanf("%s", user->phoneNumber);
}

// Function to print ticket details
void printTicket(struct Booking booking) {
    printf("\nTicket Details:\n");
    printf("Name: %s\n", booking.user.name);
    printf("Age: %d\n", booking.user.age);
    printf("ID/Passport: %s\n", booking.user.idOrPassport);
    printf("Phone Number: %s\n", booking.user.phoneNumber);
    printf("Destination: %s\n", booking.destination);
    printf("Time: %s\n", booking.time);
    printf("Departure Date: %d/%d/%d\n", booking.departureDay, booking.departureMonth, booking.departureYear);
}

int main() {
    struct Booking bookings[MAX_BOOKINGS];
    int numBookings = 0;

    printf("Welcome to the Ticket Booking System!\n");

    while (numBookings < MAX_BOOKINGS) {
        printf("\nBooking %d:\n", numBookings + 1);

        int destinationChoice = getDestination();
        if (destinationChoice < 1 || destinationChoice > 3) {
            printf("Invalid input. Try again.\n");
            continue;
        }

        int timeChoice = getTime();
        if (timeChoice < 1 || timeChoice > 3) {
            printf("Invalid input. Try again.\n");
            continue;
        }

        struct Booking newBooking;
        switch (destinationChoice) {
        case 1:
            strcpy(newBooking.destination, "Mombasa");
            break;
        case 2:
            strcpy(newBooking.destination, "Kisumu");
            break;
        case 3:
            strcpy(newBooking.destination, "Eldoret");
            break;
        }

        switch (timeChoice) {
        case 1:
            strcpy(newBooking.time, "10am");
            break;
        case 2:
            strcpy(newBooking.time, "2pm");
            break;
        case 3:
            strcpy(newBooking.time, "5pm");
            break;
        }

        printf("Enter departure date (day month year): ");
        scanf("%d %d %d", &newBooking.departureDay, &newBooking.departureMonth, &newBooking.departureYear);

        getUserDetails(&newBooking.user);

        bookings[numBookings] = newBooking;
        numBookings++;

        char bookAnother;
        printf("Do you want to book another ticket? (y/n): ");
        scanf(" %c", &bookAnother);
        if (bookAnother == 'n' || bookAnother == 'N')
            break;
    }

    // Print tickets and cost if more than two tickets booked
    if (numBookings > 0) {
        int totalCost = numBookings * COST_PER_TICKET;
        printf("\n--- Tickets ---\n");
        for (int i = 0; i < numBookings; i++) {
            printTicket(bookings[i]);
        }
        printf("Total cost: %d\n", totalCost);
    } else {
        printf("No tickets booked.\n");
    }

    printf("Thank you for using the Ticket Booking System!\n");

    return 0;
}
