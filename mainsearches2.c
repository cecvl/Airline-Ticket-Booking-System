#include <stdio.h>
#include <string.h>

#define MAX_CHARACTERS 100 /* You can adjust the MAX_CHARACTERS constant 
if your lines are longer than 100 characters in the CSV file
*/

typedef struct {
    int age;
    char passport[10];
    char fname[50];
    char lname[50];
    char phone[15];
    char destination[30];
    char time[10];
    int day;
    int month;
    int year;
} Person;

void printPerson(const Person* person) {
    printf("Name: %s %s\n", person->fname, person->lname);
    printf("Age: %d\n", person->age);
    printf("Passport: %s\n", person->passport);
    printf("Phone: %s\n", person->phone);
    printf("Destination: %s\n", person->destination);
    printf("Time: %s\n", person->time);
    printf("Date: %d/%d/%d\n", person->day, person->month, person->year);
    printf("--------------------------------------------\n");
}

int main() {
    FILE *csvFile;
    csvFile = fopen("mainreserve.csv", "r");
    if (csvFile == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    char searchFirstName[MAX_CHARACTERS];
    printf("Enter the first name to search for: ");
    scanf("%s", searchFirstName);

    char line[MAX_CHARACTERS];
    Person person;
    int matchCount = 0; // Counter variable for matches found

    while (fgets(line, MAX_CHARACTERS, csvFile) != NULL) {
        sscanf(line, "%d,%9[^,],%49[^,],%49[^,],%14[^,],%29[^,],%9[^,],%d,%d,%d",
               &person.age, person.passport, person.fname, person.lname,
               person.phone, person.destination, person.time,
               &person.day, &person.month, &person.year);

        if (strcmp(searchFirstName, person.fname) == 0) {
            printPerson(&person);
            matchCount++; // Increment the match counter
        }
    }

    if (matchCount == 0) {
        printf("No matches found for the first name: %s\n", searchFirstName);
    } else {
        printf("Total matches found: %d\n", matchCount);
    }

    fclose(csvFile);
    return 0;
}
