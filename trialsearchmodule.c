#include <stdio.h>
#include <string.h>
/*
typedef struct{
  char inputstr[10];   
}trials;
int main()
{
    trials one,two;
    
    char string = 'f';
    char str;

    
    printf("Enter first letter:\t\n");
    scanf("%s", &one.inputstr);

    printf("Enter second letter:\t\n");
    scanf("%s", &two.inputstr);

    
    return 0;
}
*/

#include <stdio.h>
#include <string.h>

// Define the structure for holding customer data
struct Customer {
    char fname[50];
    char lname[50];
    int age;
    // Add other fields as needed
};

// Function to search for a customer by first name and return the matching struct
struct Customer findCustomerByFirstName(struct Customer* customers, int numCustomers, const char* firstName) {
    struct Customer notFoundCustomer; // Create a dummy struct to return if not found
    strcpy(notFoundCustomer.fname, "Not Found");
    strcpy(notFoundCustomer.lname, "");
    notFoundCustomer.age = 0;

    for (int i = 0; i < numCustomers; i++) {
        if (strcmp(customers[i].fname, firstName) == 0) {
            return customers[i]; // Found a match, return the struct
        }
    }

    return notFoundCustomer; // Return the dummy struct if not found
}

int main() {
    // Sample data: array of struct Customer
    struct Customer customers[] = {
        {"John", "Doe", 25},
        {"Jane", "Smith", 30},
        {"Mike", "Johnson", 22},
        // Add more customer data as needed
    };

    int numCustomers = sizeof(customers) / sizeof(customers[0]);

    char searchFirstName[50];
    printf("Enter the first name to search: ");
    scanf("%s", searchFirstName);

    struct Customer foundCustomer = findCustomerByFirstName(customers, numCustomers, searchFirstName);

    if (strcmp(foundCustomer.fname, "Not Found") == 0) {
        printf("Customer with first name '%s' not found.\n", searchFirstName);
    } else {
        printf("Customer found:\n");
        printf("First Name: %s\n", foundCustomer.fname);
        printf("Last Name: %s\n", foundCustomer.lname);
        printf("Age: %d\n", foundCustomer.age);
        // Print other fields as needed
    }

    return 0;
}