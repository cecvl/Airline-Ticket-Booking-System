#include <stdio.h>
#include <string.h>

#define MAX_CUSTOMERS 100 // Define the maximum number of customers to be found

struct Customer {
    int age;
    char idpassport[10];
    char fname[50];
    char lname[50];
    char phone[15];
    char destination[30];
    char time[10];
    int day;
    int month;
};

// Function to initialize the customer structure with default values
void initializeCustomer(struct Customer* customer) {
    customer->age = 0;
    strcpy(customer->idpassport, "");
    strcpy(customer->fname, "");
    strcpy(customer->lname, "");
    strcpy(customer->phone, "");
    strcpy(customer->destination, "");
    strcpy(customer->time, "");
    customer->day = 0;
    customer->month = 0;
}

void displayBanner(){
    printf("\n\n\t\tPepeaKenya Management system.\n");
}

// Function to search for customers by first name and passport number
int findCustomersByFirstNameAndPassport(const char* csvFileName, const char* firstName, const char* passportNumber, struct Customer* matchingCustomers) {
    int numMatches = 0;

    FILE* file = fopen(csvFileName, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return numMatches;
    }

    char buffer[200]; 
    while (fgets(buffer, sizeof(buffer), file)) {
        struct Customer currentCustomer;
        initializeCustomer(&currentCustomer);

        sscanf(buffer, "%d,%9[^,],%49[^,],%49[^,],%14[^,],%29[^,],%9[^,],%d,%d",
            &currentCustomer.age,
            currentCustomer.idpassport,
            currentCustomer.fname,
            currentCustomer.lname,
            currentCustomer.phone,
            currentCustomer.destination,
            currentCustomer.time,
            &currentCustomer.day,
            &currentCustomer.month
            );

        if (strcmp(currentCustomer.fname, firstName) == 0 && strcmp(currentCustomer.idpassport, passportNumber) == 0) {
            matchingCustomers[numMatches++] = currentCustomer;
        }
    }

    fclose(file);
    return numMatches;
}

int countTotalReservations(const char* csvFileName) {
    int totalReservations = 0;

    FILE* file = fopen(csvFileName, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return totalReservations;
    }

    char buffer[200];
    while (fgets(buffer, sizeof(buffer), file)) {
        totalReservations++;
    }

    fclose(file);
    return totalReservations - 1;
}



int main() {
    char csvFileName[] = "reservations.csv";
    char searchFirstName[50];
    char searchPassport[10];

    printf("\n\t----------PEPEAKENYA FLIGHT MANAGEMENT---------\n\n");
    printf("\tEnter the FIRST NAME to search: ");    
    scanf("%s", searchFirstName);

    printf("\tEnter  ID/Passport Number to search: ");
    scanf("%s", searchPassport);

    struct Customer matchingCustomers[MAX_CUSTOMERS];
    for (int i = 0; i < MAX_CUSTOMERS; i++) {
        initializeCustomer(&matchingCustomers[i]);
    }

    int numMatches = findCustomersByFirstNameAndPassport(csvFileName, searchFirstName, searchPassport, matchingCustomers);

    if (numMatches == 0) {
        printf("\nReservation : first name '%s' and passport number '%s' not found.\n", searchFirstName, searchPassport);
    } else {
        printf("\n\t\t------------Reservations Found(%d)------------\n", numMatches);
        for (int i = 0; i < numMatches; i++) {
            struct Customer foundCustomer = matchingCustomers[i];
            printf("\t\tNAME: %s %s\t\tAGE: %d\n", foundCustomer.fname, foundCustomer.lname, foundCustomer.age);
            printf("\t\tID/PASSPORT NO: %s\n", foundCustomer.idpassport);
            printf("\t\tDEPARTURE DATE: %d/%d/2023\n", foundCustomer.day, foundCustomer.month);
            printf("\t\t-----------------------------------------\n");
        }

        int choice;
        printf("\n\t\t-------Actions Available-------\n");
        //printf("\t\t1. Total Number of reservations\n");
        printf("\t\t1. Delete reservation\n");
        printf("\t\t2. Exit\n");
        printf("\n\t\tSelect an action(1 or 2):\t");
        scanf("%d", &choice);

        switch (choice) {
        /*
        case 1:
            int totalReservations = countTotalReservations(csvFileName);
            printf("\nTotal number of reservations: %d\n", totalReservations);
            break;
            */
        case 1:
            // Delete the customer from the CSV file
            FILE* tempFile = fopen("temp.csv", "w");
            if (tempFile == NULL) {
                printf("Error creating temporary file.\n");
                return 1;
            }

            FILE* file = fopen(csvFileName, "r");
            if (file == NULL) {
                printf("Error opening file.\n");
                fclose(tempFile);
                return 1;
            }

            char buffer[200];
            while (fgets(buffer, sizeof(buffer), file)) {
                struct Customer currentCustomer;
                initializeCustomer(&currentCustomer);
                sscanf(buffer, "%d,%9[^,],%49[^,],%49[^,],%14[^,],%29[^,],%9[^,],%d,%d",
                    &currentCustomer.age,
                    currentCustomer.idpassport,
                    currentCustomer.fname,
                    currentCustomer.lname,
                    currentCustomer.phone,
                    currentCustomer.destination,
                    currentCustomer.time,
                    &currentCustomer.day,
                    &currentCustomer.month
                );

                if (strcmp(currentCustomer.fname, searchFirstName) != 0 || strcmp(currentCustomer.idpassport, searchPassport) != 0) {
                    // Write the customer details to the temporary file (excluding the one to be deleted)
                    fprintf(tempFile, "%d,%s,%s,%s,%s,%s,%s,%d,%d\n",
                        currentCustomer.age,
                        currentCustomer.idpassport,
                        currentCustomer.fname,
                        currentCustomer.lname,
                        currentCustomer.phone,
                        currentCustomer.destination,
                        currentCustomer.time,
                        currentCustomer.day,
                        currentCustomer.month
                    );
                }
            }

            fclose(file);
            fclose(tempFile);

            // Remove the original file and rename the temporary file to the original file name
            remove(csvFileName);
            rename("temp.csv", csvFileName);

            printf("\n\tReservation with first name '%s' and passport number '%s' has been deleted.\n", searchFirstName, searchPassport);
            printf("\n\tNumber of reservations remaining: %d\n", countTotalReservations(csvFileName));
            displayBanner();
            break;
            
        case 2:
            //printf("\n\nPepeaKenya Management system.\n");
            displayBanner();
            break;         

        default:
            printf("Invalid choice. No action taken.\n");
        }
    }

    return 0;
}
