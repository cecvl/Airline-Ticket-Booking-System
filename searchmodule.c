#include <stdio.h>
#include <string.h>

// Define the structure for holding customer data
struct Customer {
    int age;
    char passport[10];
    char fname[50];
    char lname[50];
    char phone[15];
    int day;
    int month;
    int year;
    // Add other fields as needed
};

// Function to search for a customer by first name and return the matching struct
struct Customer findCustomerByFirstName(const char* csvFileName, const char* firstName) {
    struct Customer notFoundCustomer; // Create a dummy struct to return if not found
    notFoundCustomer.age = 0;

    FILE* file = fopen(csvFileName, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return notFoundCustomer;
    }

    char buffer[200]; // Assuming the CSV lines are not longer than 200 characters
    while (fgets(buffer, sizeof(buffer), file)) {
        struct Customer currentCustomer;
        sscanf(buffer, "%d,%9[^,],%49[^,],%49[^,],%14[^,],%d,%d,%d",
            &currentCustomer.age,
            currentCustomer.passport,
            currentCustomer.fname,
            currentCustomer.lname,
            currentCustomer.phone,
            &currentCustomer.day,
            &currentCustomer.month,
            &currentCustomer.year
        );

        if (strcmp(currentCustomer.fname, firstName) == 0) {
            fclose(file);
            return currentCustomer;
        }
    }

    fclose(file);
    notFoundCustomer.age = 0; // Set age to 0 in the dummy struct
    return notFoundCustomer; // Return the dummy struct if not found
}

int main() {
    char csvFileName[] = "personal2.csv";

    char searchFirstName[50];
    printf("Enter the first name to search: ");
    scanf("%s", searchFirstName);

    struct Customer foundCustomer = findCustomerByFirstName(csvFileName, searchFirstName);

    if (foundCustomer.age == 0) {
        printf("\nCustomer with first name '%s' not found.\n", searchFirstName);
    } else {
        printf("\n\t\t\t--------Customer found--------\n");
        printf("\n\t\t\tNAME: %s %s\tAGE: %d\n", foundCustomer.fname, foundCustomer.lname, foundCustomer.age);
        printf("\t\t\tPHONE NO: %s\tID/PASSPORT NO: %s\n", foundCustomer.phone, foundCustomer.passport);
        printf("\t\t\tDEPARTURE DATE: %d-%d-%d\n\n", foundCustomer.day, foundCustomer.month, foundCustomer.year);
        printf("\t\t\t\t------------\n");
        // Print other fields as needed
    }

    return 0;
}
