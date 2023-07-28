#include <stdio.h>
#include <string.h>

#define MAX_CUSTOMERS 100 // Define the maximum number of customers to be found

// Define the structure for holding customer data
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

// Function to search for customers by first name and passport number
int findCustomersByFirstNameAndPassport(const char* csvFileName, const char* firstName, const char* passportNumber, struct Customer* matchingCustomers) {
    int numMatches = 0;

    FILE* file = fopen(csvFileName, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return numMatches;
    }

    char buffer[200]; // Assuming the CSV lines are not longer than 200 characters
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

int main() {
    char csvFileName[] = "twowaybooking.csv";
    char searchFirstName[50];
    char searchPassport[10];

    printf("SEARCH FOR CUSTOMER BY FIRST NAME AND PASSPORT NUMBER\n\n");
    printf("Enter the first name to search: ");    
    scanf("%s", searchFirstName);

    printf("Enter  ID/Passport number to search: ");
    scanf("%s", searchPassport);

    struct Customer matchingCustomers[MAX_CUSTOMERS];
    for (int i = 0; i < MAX_CUSTOMERS; i++) {
        initializeCustomer(&matchingCustomers[i]);
    }

    int numMatches = findCustomersByFirstNameAndPassport(csvFileName, searchFirstName, searchPassport, matchingCustomers);

    if (numMatches == 0) {
        printf("\nCustomer with first name '%s' and passport number '%s' not found.\n", searchFirstName, searchPassport);
    } else {
        printf("\n\t\t\t---------------Customer Found---------------\n");
        for (int i = 0; i < numMatches; i++) {
            struct Customer foundCustomer = matchingCustomers[i];
            printf("\t\t\tNAME: %s %s\t\tAGE: %d\n", foundCustomer.fname, foundCustomer.lname, foundCustomer.age);
            printf("\t\t\tID/PASSPORT NO: %s\n", foundCustomer.idpassport);
            printf("\t\t\tDEPARTURE DATE: %d/%d/2023\n\n", foundCustomer.day, foundCustomer.month);
            printf("\t\t\t--------------------------------------------\n");
            // Print other fields as needed
        }
    }

    return 0;
}
