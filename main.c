#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct {
    int age;
    char idpassport[10];
    char fname[50];
    char lname[50];
    char phone[15];
    char destination[30];
    char time[10];
    int day;
    int month;
        
} Person;


void printTicket(Person p);
void printReservations(Person p);

void printTicket(Person p)
{
   
    printf("\t\t------------------Ticket Reference-----------------------\n");
    printf("\t\tNAME: \t%s %s\t\tAGE: %d\n", p.fname, p.lname,p.age);
    printf("\t\tID/PASSPORT: %s\tPHONE NUMBER:   %s\n", p.idpassport, p.phone);
    printf("\t\tDESTINATION: %s\tTIME: %s\tDATE: %d/%d/2023\n", p.destination,p.time,p.day, p.month);
    printf("\t\t--------------------------------------------------------\n");
    //printf("\t\t\t Thank you for choosing PepeaKenya\n\n");    
}

void printReservations(Person p)
{
    printf("\t\t------------------Reservation-----------------------\n");
    printf("\t\tNAME: \t%s %s\tAGE: %d\n", p.fname, p.lname,p.age);
    printf("\t\tID/PASSPORT: %s\tPHONE NUMBER:   %s\n", p.idpassport, p.phone);
    printf("\t\tDESTINATION: %s\tTIME: %s\tDATE: %d/%d/2023\n", p.destination,p.time,p.day, p.month);
    printf("\t\t--------------------------------------------------------\n");
}
   

void onewayDestinations() {
    printf("\t\tAvailable Destinations:\n");
    printf("\t\tDestination\tPrice\n");
    printf("\t 1.\tMombasa\t\tKsh. 6900\n");
    printf("\t 2.\tKisumu\t\tKsh. 6900\n");
    printf("\t 3.\tEldoret\t\tKsh. 6900\n");   
}
void twowayDestinations(){
    printf("\t\t\n\nAvailable Destinations:\n");
    printf("\t\tDestination\tPrice\n");
    printf("\t 1.\tMombasa\t\tKsh. 13800\n");
    printf("\t 2.\tKisumu\t\tKsh. 13800\n");
    printf("\t 3.\tEldoret\t\tKsh. 13800\n");    
}
void reserveDestinations(){
    printf("\t\t\nAvailable Destinations:\n");
    printf("\t\tDestination\tPrice\n");
    printf("\t 1.\tMombasa\t\tKsh. 3450\n");
    printf("\t 2.\tKisumu\t\tKsh. 3450\n");
    printf("\t 3.\tEldoret\t\tKsh. 3450\n");
}
void displayTimes() {
    printf("\n\t\tAvailable Times:\n");
    printf("\t1. 10am\t\t2. 2pm\t\t3. 5pm\n");
}

int calculateTotalCost(int ticketCount){
    const int PRICE_PER_TICKET = 6900;
    return ticketCount * PRICE_PER_TICKET;
}
int calculateReserveCost(int ticketCount){
    const int PRICE_PER_RESERVE = 3450;
    return ticketCount * PRICE_PER_RESERVE;
} 


int main()
{
    Person person;    
    Person twowayperson;
    Person resperson;
    int choice;
    int totalCost = 0;
    int ticketCount = 0;
    int twoticketCount = 0;
    int resticketCount = 0;

    while(1){
        printf("\n\t----------WELCOME TO PEPEAKENYA TICKETING SYSTEM---------\n");
        printf("\t\t\t1. Book One-Way Ticket\n");
        printf("\t\t\t2. Book Two-Way Ticket\n");
        printf("\t\t\t3. Make Seat Reservation\n");
        printf("\t\t\t4. Exit\n");
        printf("\tEnter your choice (1,2,3 or 4):\t");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:            
            printf("\t\tNow Booking One-Way Ticket.....\n");

            int destination;
            onewayDestinations();
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
            printf("\t\nEnter DATE of Departure(DD/MM):\n");
            printf("\t\tEnter day:\t");
            scanf("%d", &person.day);
            printf("\t\tEnter month:\t");
            scanf("%d", &person.month);
            printf("\n\tEnter your NAME:\n");
            printf("\t\tFirst Name:\t");
            scanf("%s", person.fname);
            printf("\t\tLast Name:\t");
            scanf("%s", person.lname);
            printf("\n\tEnter AGE:\t");
            scanf("%d", &person.age);
            printf("\n\tEnter ID or Passport Number:\t");
            scanf("%s", person.idpassport);
            printf("\n\tEnter Phone Number:\t");
            scanf("%s", person.phone);
            
            
            FILE *outfile;
            outfile = fopen("mainbooking.csv", "a+");
            if (outfile == NULL)
            {
              printf("Error opening file!\n");
              return 1;
             }

            fprintf(outfile, "%d,%s,%s,%s,%s,%s,%s,%d,%d\n",person.age,
                person.idpassport, person.fname, person.lname,
                person.phone, person.destination, person.time,
                person.day, person.month
             );

            if (ferror(outfile)){
                printf("\n\tBooking Reference NOT generated. Please try again.\n");
                return 1;
            }else{
                printf("\n\tBooking Reference generated.\n\n");
            }
            fclose(outfile);
            printTicket(person);
            ticketCount++;

            char again;
            printf("\n\tDo you want to book another ticket? (y/n)\t");
            scanf("%s", &again);

            if(again == 'N' || again == 'n'){
                printf("\n\t\tThank you for using our ticketing system.\n");
                printf("\n\tHere are your tickets:\n");
                for (int i = 0; i < ticketCount; i++)
                {
                    printTicket(person);
                }
                printf("\n\t\tTotal Cost: Ksh. %d\n", calculateTotalCost(ticketCount));
                return 0;
            }

            break;
        
        case 2:
            printf("\t\tNow Booking Two-Way Ticket.....\n");
            int twowaydestination;
            twowayDestinations();
            printf("\t\tPlease choose your destination: \t");
            scanf("%d", &twowaydestination);

            switch (twowaydestination)
            {
            case 1:
                strcpy(twowayperson.destination, "Mombasa");
                break;
            case 2:
                strcpy(twowayperson.destination, "Kisumu");
                break;
            case 3:
                strcpy(twowayperson.destination, "Eldoret");
                break;
            default:
                printf("Please enter a valid choice\n");
            continue;
            }
            
            int twowaytime;
            displayTimes();
            printf("\t\tPlease choose time:\t");            
            scanf("%d", &twowaytime);

            switch (twowaytime)
            {
            case 1:
                strcpy(twowayperson.time, "10am");
                break;
            case 2:
                strcpy(twowayperson.time, "2pm");
                break;
            case 3:
                strcpy(twowayperson.time, "5pm");
                break;
            default:
                printf("/tPlease enter a valid choice\n");    
                continue;
            }
            printf("\n\tEnter DATE of Departure(DD/MM):\n");
            printf("\t\tEnter day: \t");
            scanf("%d", &twowayperson.day);
            printf("\t\tEnter month: \t");
            scanf("%d", &twowayperson.month);
            printf("\n\tEnter NAME:\n");
            printf("\t\tFirst Name: \t");
            scanf("%s", twowayperson.fname);
            printf("\t\tLast Name: \t");
            scanf("%s", twowayperson.lname);
            printf("\n\tEnter AGE: \t");
            scanf("%d", &twowayperson.age);
            printf("\n\tEnter ID or Passport Number: \t");
            scanf("%s", twowayperson.idpassport);
            printf("\n\tEnter PHONE NUMBER: \t");
            scanf("%s", twowayperson.phone);


            FILE *twowayfile;
            twowayfile = fopen("twowaybooking.csv", "a+");
            if (twowayfile == NULL)
            {
              printf("Error opening file!\n");
              return 1;
             }

            fprintf(twowayfile, "%d,%s,%s,%s,%s,%s,%s,%d,%d\n",twowayperson.age,
                twowayperson.idpassport, twowayperson.fname, twowayperson.lname,
                twowayperson.phone, twowayperson.destination, twowayperson.time,
                twowayperson.day, twowayperson.month
             );

            if (ferror(twowayfile)){
                printf("\tBooking Reference NOT generated. Please try again.\n");
                return 1;
            }else{
                printf("\n\tBooking Successful!\n\n");
            }
            fclose(twowayfile);
            printTicket(twowayperson);
            ticketCount++;

            //loop 2

            char againtwo;
            printf("\n\tDo you want to book another ticket? (y/n)\t");
            scanf("%s", &againtwo);

            if(againtwo == 'N' || againtwo == 'n'){
                printf("\n\t\tThank you for using our ticketing system.\n");
                printf("\n\tHere are your tickets:\n");
                for (int i = 0; i < twoticketCount; i++)
                {
                    printTicket(twowayperson);
                }
                printf("\n\t\tTotal Cost: Ksh. %d\n", calculateTotalCost(twoticketCount));
                return 0;
            }

            break;
        case 3:
            printf("\t\tNow Reserving a Seat.....\n");
            int resdestination;
            reserveDestinations();
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
            printf("\n\tEnter DATE of Departure(DD/MM):\n");
            printf("\t\tEnter day: \t");
            scanf("%d", &resperson.day);
            printf("\t\tEnter month: \t");
            scanf("%d", &resperson.month);
            printf("\n\tEnter NAME:\n");
            printf("\t\tFirst Name: \t");
            scanf("%s", resperson.fname);
            printf("\t\tLast Name: \t");
            scanf("%s", resperson.lname);
            printf("\n\tEnter AGE: \t");
            scanf("%d", &resperson.age);
            printf("\n\tEnter ID or Passport Number: \t");
            scanf("%s", resperson.idpassport);
            printf("\n\tEnter PHONE NUMBER: \t");
            scanf("%s", resperson.phone);


            FILE *rfile;
            rfile = fopen("reservations.csv", "a+");
            if (rfile == NULL)
            {
              printf("Error opening file!\n");
              return 1;
             }
            fprintf(rfile, "%d,%s,%s,%s,%s,%s,%s,%d,%d\n",resperson.age,
                resperson.idpassport, resperson.fname, resperson.lname,
                resperson.phone, resperson.destination, resperson.time,
                resperson.day, resperson.month
             );
             if(ferror(rfile)){
                 printf("\tReservation UNSUCCESSFUL. Please try again.\n"); 
             }else{
                 printf("\n\tReservation Successful!\n\n");
             }
            fclose(rfile);
            printReservations(resperson);
            ticketCount++;
            //loop 3

            char againthree;
            printf("\n\tDo you want to book another ticket? (y/n)\t");
            scanf("%s", &againthree);

            if( againthree== 'N' || againthree == 'n'){
                printf("\n\t\tThank you for using our ticketing system.\n");
                printf("\n\tHere are your reservations:\n");
                for (int i = 0; i < resticketCount; i++)
                {
                    printReservations(resperson);
                }
                printf("\n\n\n\t\tTotal Cost: Ksh. %d\n", calculateReserveCost(resticketCount));
                return 0;
            }

            break; 
        case 4:
            printf("\tThank you for using our ticketing system.");
            ticketCount++;
            
            printf("\n\n\tExiting program:)\n");
            exit(0);    
        default:
            printf("\n\t\tPlease enter a valid choice(1, 2 or 3).\n");
            break;
        }
    }
  

    return 0;
}
