#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct {
    int age;
    char passport[10];
    char fname[50];
    char lname[50];
    char phone[15];
    int day;
    int month;
    int year;
    
} Person;

void printTicket(Person p);

void printTicket(Person p)
{
    //Person person ;
    char flightno[] = "JM8655";
    
    printf("\t\t\t----------Ticket Reference----------\n");
    printf("\n\t\t\t\tNAME: %s %s\n", p.fname, p.lname);
    printf("\t\t\t\tID PASSPORT: %s\n", p.passport);
    printf("\t\t\t\tPHONE NUMBER: %s\n", p.phone);
    printf("\t\t\t\t%s\t%d/%d/%d\n\n", flightno, p.day, p.month, p.year);
    printf("\t\t\t------------------------------------\n");
    printf("\t\t\t Thank you for choosing PepeaKenya\n\n");

    
}
int main()
{
    FILE *outfile;
    outfile = fopen("personal2.csv", "a+");
    if (outfile == NULL)
    {
        printf("Error opening file!\n");
        return 1;
    }

    Person person;

    printf("Enter customer details:\n");

    printf("\nAge: ");
    scanf("%d", &person.age);

    printf("\nID or Passport Number: ");
    scanf("%s", person.passport);

    printf("\nFirst name: ");
    scanf("%s", person.fname);

    printf("\nLast name: ");
    scanf("%s", person.lname);    

    printf("\nPhone number: ");
    scanf("%s", person.phone);

    printf("\nEnter your Departure Date(DD/MM/YY):");
    printf("Day: ");
    scanf("%d", &person.day);
    printf("Month (enter number): ");
    scanf("%d", &person.month);
    printf("Year: ");
    scanf("%d", &person.year);


    fprintf(outfile, "%d,%s,%s,%s,%s,%d,%d,%d\n", person.age,
     person.passport, person.fname, person.lname, person.phone,
      person.day, person.month, person.year);

    if (ferror(outfile))
    {
        printf("Error writing file!\n");
        return 1;
    }

    fclose(outfile);
    printf("\nCustomer record written to file!\n\n");

    printTicket(person);

    return 0;
}
