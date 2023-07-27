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
   //char flightno[] = "JM8655";
    
    printf("\t\t-------------------Ticket Reference---------------------\n");
    printf("\t\tNAME: \t%s %s\tAGE: %d\n", p.fname, p.lname,p.age);
    printf("\t\tID/PASSPORT: %s\tPHONE NUMBER:   %s\n", p.passport, p.phone);
    printf("\t\tDESTINATION: %s\tTIME: %s\tDATE: %d/%d/%d\n", p.destination,p.time,p.day, p.month, p.year);
    printf("\t\t--------------------------------------------------------\n");
    //printf("\t\t\t Thank you for choosing PepeaKenya\n\n");    
}
void displayDestinations() {
    printf("\t\tAvailable Destinations:\n");
    printf("\t1. Mombasa\t2.Kisumu\t3.Eldoret\n");    
}
void displayTimes() {
    printf("\t\tAvailable Times:\n");
    printf("\t1. 10am\t\t2. 2pm\t\t3. 5pm\n");
   }



int main()
{
    Person person;
    Person resperson;
    int choice;
    int totalCost = 0;
    


    while(1){
        printf("\n\t----------WELCOME TO PEPEAKENYA TICKETING SYSTEM---------\n");
        printf("\t\t\t1. Book Ticket\n");
        printf("\t\t\t2. Reserve a Seat\n");
        printf("\t\t\t3. Exit Program\n");
        printf("\tEnter your choice (1,2 or 3):\t");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:            
            printf("\t\tNow Booking a Ticket.....\n");

            int destination;
            displayDestinations();
            printf("\t\tPlease choose your destination:\t");            
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
                printf("Please enter a valid choice.\n");
            continue;
            }
            
            int time;
            displayTimes();
            printf("\t\tPlease choose time:\t");            
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
                printf("Please enter a valid choice.\n");    
                continue;
            }
            printf("\tEnter DATE of Departure(DD/MM/YY):\n");
            printf("\t\tEnter day:\t");
            scanf("%d", &person.day);
            printf("\t\tEnter month:\t");
            scanf("%d", &person.month);
            printf("\t\tEnter year:\t");
            scanf("%d", &person.year);
            printf("\n\tEnter your NAME:\n");
            printf("\t\tFirst Name:\t");
            scanf("%s", person.fname);
            printf("\t\tLast Name:\t");
            scanf("%s", person.lname);
            printf("\n\tEnter AGE:\t");
            scanf("%d", &person.age);
            printf("\n\tEnter ID or Passport Number:\t");
            scanf("%s", person.passport);
            printf("\n\tEnter Phone Number:\t");
            scanf("%s", person.phone);
            
            
            FILE *outfile;
            outfile = fopen("mainbooking.csv", "a+");
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
                printf("\n\tBooking UNSUCCESSFUL. Please try again.\n");
                return 1;
            }else{
                printf("\n\tBooking Successful!\n\n");
            }
            fclose(outfile);
            printTicket(person);


            break;
        case 2:
            printf("\t\tNow Reserving a Seat.....\n");
            int resdestination;
            displayDestinations();
            printf("\t\tPlease choose your destination: \t");
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
            printf("\t\tPlease choose time:\t");            
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
            printf("\n\tEnter DATE of Departure(DD/MM/YY):\n");
            printf("\t\tEnter day: \t");
            scanf("%d", &resperson.day);
            printf("\t\tEnter month: \t");
            scanf("%d", &resperson.month);
            printf("\t\tEnter year: \t");
            scanf("%d", &resperson.year);
            printf("\n\tEnter NAME:\n");
            printf("\t\tFirst Name: \t");
            scanf("%s", resperson.fname);
            printf("\t\tLast Name: \t");
            scanf("%s", resperson.lname);
            printf("\n\tEnter AGE: \t");
            scanf("%d", &resperson.age);
            printf("\n\tEnter ID or Passport Number: \t");
            scanf("%s", resperson.passport);
            printf("\n\tEnter PHONE NUMBER: \t");
            scanf("%s", resperson.phone);


            //totalCost += 100;

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
                printf("\tReservation UNSUCCESSFUL. Please try again.\n");
                return 1;
            }else{
                printf("\n\tReservation Successful!\n\n");
            }
            fclose(reservefile);
            printTicket(resperson);

            break;
        case 3:
            printf("\tThank you for using our ticketing system.");
            printf("\n\n\tExiting program...:) :)\n");
            exit(0);    
        default:
            printf("\n\t\tPlease enter a valid choice(1, 2 or 3).\n");
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
