#include <stdio.h>
#include <string.h>
#include <stdlib.h>


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

void printTicket(Person p);

void printTicket(Person p)
{
    //Person person ;
    char flightno[] = "JM8655";
    
    printf("\t\t-------------Ticket Reference----------------\n");
    printf("\n\t\t\tNAME: \t%s %s\tAGE: \n", p.fname, p.lname);
    printf("\t\tID/PASSPORT: \t%s\n", p.passport);
    printf("\t\t\tPHONE NUMBER: \t%s\n", p.phone);
    printf("\t\t\tFLIGHT NO: %s\tDATE:%d/%d/%d\n", flightno, p.day, p.month, p.year);
    printf("\t\t\tDESTINATION: %s\tTIME: %s\n", p.destination,p.time);
    printf("\n\t\t-------------------------------------------\n");
    //printf("\t\t\t Thank you for choosing PepeaKenya\n\n");    
}
void displayDestinations() {
    printf("\t\tAvailable Destinations:\n");
    printf("\t\t\t1. Mombasa\n");
    printf("\t\t\t2. Kisumu\n");
    printf("\t\t\t3. Eldoret\n");
}
void displayTimes() {
    printf("\t\tAvailable Times:\n");
    printf("\t\t\t1. 10am\n");
    printf("\t\t\t2. 2pm\n");
    printf("\t\t\t3. 5pm\n");
}
void bookTicket(int *totalCost) {
    // Update the total cost for booking a ticket (assuming the ticket costs 100 shillings)
    *totalCost += 100;
}

// Function to calculate the total cost of all booked tickets
int calculateTotalCost(int totalCost) {
    return totalCost;
}



int main()
{
    Person person;
    Person resperson;
    int choice;
    int totalCost = 0;
    


    while(1){
        printf("\t\t----WELCOME TO PEPEAKENYA TICKETING SYSTEM----\n");
        printf("\t\t\t1. Book Ticket\n");
        printf("\t\t\t2. Reserve a Seat\n");
        printf("\t\t\t3. Exit Program\n");
        printf("\tEnter your choice (1-3):\t");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:            
            printf("\t\t-----Booking a Ticket-----\n");

            int destination;
            displayDestinations();
            printf("\t\tPlease choose a destination: \n");            
            scanf("%d", &destination);
            
            switch (destination)
            {
            case 1:
                strcpy(person.destination, "Mombasa");
                break;
            case 2:
                strcpy(person.destination, "Kisumu");
                break;
            case 3:
                strcpy(person.destination, "Eldoret");
                break;
            default:
                printf("Please enter a valid choice\n");
            continue;
            }
            
            int time;
            displayTimes();
            printf("\tPlease choose a time: \n");            
            scanf("%d", &time);

            switch (time)
            {
            case 1:
                strcpy(person.time, "10am");
                break;
            case 2:
                strcpy(person.time, "2pm");
                break;
            case 3:
                strcpy(person.time, "5pm");
                break;
            default:
                printf("Please enter a valid choice\n");    
                continue;
            }
            printf("Enter DATE of departure(DD/MM/YY):\n");
            printf("Enter date: \t");
            scanf("%d", &person.day);
            printf("Enter month: \t");
            scanf("%d", &person.month);
            printf("Enter year: \t");
            scanf("%d", &person.year);
            printf("\n---Enter NAME:---");
            printf("\n\tFirst : \t");
            scanf("%s", person.fname);
            printf("\n\tLast Name: \t");
            scanf("%s", person.lname);
            printf("\nEnter AGE: \t");
            scanf("%d", &person.age);
            printf("\nEnter ID or Passport Number: \t");
            scanf("%s", person.passport);
            printf("\nEnter PHONE NUMBER: \t");
            scanf("%s", person.phone);
            
            //totalCost += 100;
            
            
            FILE *outfile;
            outfile = fopen("main.csv", "a+");
            if (outfile == NULL)
            {
              printf("Error opening file!\n");
              return 1;
             }

            fprintf(outfile, "%d,%s,%s,%s,%s,%s,%s,%d,%d,%d\n",
             person.age,person.passport, person.fname, person.lname,
              person.phone, person.destination, person.time,
              person.day, person.month, person.year);

            if (ferror(outfile)){
                printf("Error writing file!\n");
                return 1;
            }else{
                printf("Ticket written to file!\n\n");
            }
            fclose(outfile);
            printTicket(person);
            printf("Totak cost: %d\n", calculateTotalCost(totalCost));
            //bookTicket(&totalCost);


            break;
        case 2:
            printf("\t\t-----Reserving a Seat-----\n");
            int resdestination;
            displayDestinations();
            printf("\t\tPlease choose a destination: \n");
            
            scanf("%d", &resdestination);
            
            switch (resdestination)
            {
            case 1:
                strcpy(resperson.destination, "Mombasa");
                break;
            case 2:
                strcpy(resperson.destination, "Kisumu");
                break;
            case 3:
                strcpy(resperson.destination, "Eldoret");
                break;
            default:
                printf("Please enter a valid choice\n");
            continue;
            }
            
            int restime;
            displayTimes();
            printf("\tPlease choose a time:\n");            
            scanf("%d", &restime);

            switch (restime)
            {
            case 1:
                strcpy(resperson.time, "10am");
                break;
            case 2:
                strcpy(resperson.time, "2pm");
                break;
            case 3:
                strcpy(resperson.time, "5pm");
                break;
            default:
                printf("/tPlease enter a valid choice\n");    
                continue;
            }
            printf("\tEnter DATE of departure(DD/MM/YY):\n");
            printf("\t\tEnter date: \t");
            scanf("%d", &resperson.day);
            printf("\t\tEnter month: \t");
            scanf("%d", &resperson.month);
            printf("\t\tEnter year: \t");
            scanf("%d", &resperson.year);
            printf("\n\tEnter NAME:---");
            printf("\n\t\tFirst : \t");
            scanf("%s", resperson.fname);
            printf("\n\tLast Name: \t");
            scanf("%s", resperson.lname);
            printf("\n\tEnter AGE: \t");
            scanf("%d", &resperson.age);
            printf("\n\tEnter ID or Passport Number: \t");
            scanf("%s", resperson.passport);
            printf("\n\tEnter PHONE NUMBER: \t");
            scanf("%s", resperson.phone);


            totalCost += 100;

            FILE *reservefile;
            reservefile = fopen("mainreserve.csv", "a+");
            if (reservefile == NULL)
            {
              printf("Error opening file!\n");
              return 1;
             }

            fprintf(reservefile, "%d,%s,%s,%s,%s,%s,%s,%d,%d,%d\n",resperson.age,
                resperson.passport, resperson.fname, resperson.lname,
                resperson.phone, resperson.destination, resperson.time,
                resperson.day, resperson.month, resperson.year
             );

            if (ferror(reservefile)){
                printf("Error writing file!\n");
                return 1;
            }else{
                printf("\nReservation successful!\n\n");
            }
            fclose(reservefile);
            printTicket(resperson);

            break;
        case 3:
            printf("Exiting program...\n");
            exit(0);    
        default:
            printf("Please enter a valid choice\n");
            break;
        }
    }
    /*
    printf("Enter customer details:\n");
    
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
    */
    //fclose(outfile);   
    //printf("\nCustomer record written to file!\n\n");

    //printTicket(person);
    return 0;
}
