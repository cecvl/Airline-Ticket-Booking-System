#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to store booking information
typedef struct{
    char status[10];
    char destination[50];
    char time[10];
    int day;
    int month;
    int year;
    char first_name[50];
    char last_name[50];
    int age;
    char id_passport[20];
    char phone_number[15];
}Booking;

/*struct bookings {
    
    char status[10];
    char destination[50];
    char time[10];
    int day;
    int month;
    int year;
    char first_name[30];
    char last_name[30];
    int age;
    char id_passport[20];
    char phone_number[15];
};*/

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
    Booking booking[100]; // Assuming we can book up to 100 tickets
    //bookings booking[100]; 
    int numBookings = 0;//int revBookings = 0;
    int totalCost = 0;


    while (1) {
        printf("Menu:\n");
        printf("1. Book Ticket\n");
        //printf("2. Book Return Ticket\n");
        printf("2. booking a Seat\n");
        printf("3. Exit Program\n");
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

                printf("Enter your first name: ");
                scanf(" %[^\n]", booking[numBookings].first_name);

                printf("Enter your first name: ");
                scanf(" %[^\n]", booking[numBookings].last_name);

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
                        printf("Name: %s\n", booking[i].first_name);
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
                printf("Reserving a ticket...\n");
                strcpy(booking[numBookings].status, "reserving");
                if(strcpy(booking[numBookings].status, "reserving") == 0)
                {  
                    printf("Error reserving ticket.\n");
                    return 1;
                }else{
                    printf("NOW IN RESERVING.......\n");
                }

                printf("Please choose a destination:\n");
                displayDestinations();

                int resdestinationChoice;
                scanf("%d", &resdestinationChoice);

                switch (resdestinationChoice) {
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

                int restimeChoice;
                scanf("%d", &restimeChoice);

                switch (restimeChoice) {
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

                printf("Enter DEPARTURE date (DD/MM/YY): ");
                scanf("%d %d %d", &booking[numBookings].day, &booking[numBookings].month, &booking[numBookings].year);

                printf("Enter your first name: ");
                scanf("%s", booking[numBookings].first_name);

                printf("Enter your last name: ");
                scanf("%s", booking[numBookings].last_name);

                printf("Enter your age: ");
                scanf("%d", &booking[numBookings].age);

                printf("Enter your ID/Passport number: ");
                scanf("%s", booking[numBookings].id_passport);

                printf("Enter your phone number: ");
                scanf("%s", booking[numBookings].phone_number);

                //strcpy(booking[numBookings].status, "reserving");

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
                        printf("Name: %s\n", booking[i].first_name);
                        printf("Age: %d\n", booking[i].age);
                        printf("ID/Passport: %s\n", booking[i].id_passport);
                        printf("Phone number: %s\n", booking[i].phone_number);
                        printf("\n");
                    }
                    printf("Total Cost: %d shillings\n", totalCost);

                    FILE *bookingfile;
                    bookingfile = fopen("booking.csv", "w");

                    if (bookingfile == NULL) {
                        printf("Error opening file.\n");
                        return 1;
                    }else{
                        printf("File opened successfully.\n");
                    }
                    
                    Booking booking[100]; //numBookings

                    fprintf(bookingfile, "%s,%s,%s,%d/%d/%d,%s,%s,%d,%s,%s\n",
                     booking[numBookings].status, booking[numBookings].destination, 
                     booking[numBookings].time, booking[numBookings].day,
                      booking[numBookings].month, booking[numBookings].year,
                       booking[numBookings].first_name, booking[numBookings].last_name,
                        booking[numBookings].age, booking[numBookings].id_passport, booking[numBookings].phone_number);
                    
                    if(ferror(bookingfile))
                    {
                        printf("Error writing file.\n");
                        return 1;
                    }else{
                        printf("File written successfully.\n");
                    };

                    fclose(bookingfile);
                                
                    
                    
                    return 0;
                }
                break;

            case 3:
                printf("Exiting the program.\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}

