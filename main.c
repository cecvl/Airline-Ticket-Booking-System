#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_BOOKINGS 100


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
    char returntime[10];
    int returnday;
    int returnmonth; //to be used to store return dates
        
} Person;


void printTicket(Person p);
void printReservations(Person p);

void printTicket(Person p)
{
    
    printf("\t\t--------------------------------------------------------\n");
    printf("\t\tNAME: \t%s %s\t\tAGE: %d\n", p.fname, p.lname,p.age);
    printf("\t\tID/PASSPORT: %s\tPHONE NUMBER:   %s\n", p.idpassport, p.phone);
    printf("\t\tDESTINATION: %s\tTIME: %s\tDATE: %d/%d/2023\n", p.destination,p.time,p.day, p.month);
    printf("\t\t--------------------------------------------------------\n");
       
}

void printTwoWayTicket(Person p)
{
    printf("\t\tNAME: \t%s %s\t\tAGE: %d\n", p.fname, p.lname,p.age);
    printf("\t\tID/PASSPORT: %s\tPHONE NUMBER:   %s\n", p.idpassport, p.phone);
    printf("\t\tFROM:\tNAIROBI\t\tTO:\t%s\n", p.destination);
    printf("\t\tTIME:\t%s\t\tDATE:\t%d/%d/2023\n",p.time,p.day, p.month);
    printf("\t\t--------------------------------------------------------");
    printf("\n\t\t\t\t-----\t----RETURN DETAILS-----\t----\n");
    printf("\n\t\tFROM: %s\t\tTO: NAIROBI\n", p.destination);
    printf("\t\tRETURN TIME: %s\tRETURN DATE: %d/%d/2023\n", p.returntime, p.returnday, p.returnmonth);
    printf("\t\t--------------------------------------------------------\n");
       
}

void printReservations(Person p)
{
    
    printf("\t\tNAME: \t%s %s\tAGE: %d\n", p.fname, p.lname,p.age);
    printf("\t\tID/PASSPORT: %s\tPHONE NUMBER:   %s\n", p.idpassport, p.phone);
    printf("\t\tDESTINATION: %s\tTIME: %s  DATE: %d/%d/2023\n", p.destination,p.time,p.day, p.month);
    printf("\t\t------------------------------------------------------\n");
}
   

void onewayDestinations() {
    printf("\n\t\tAvailable Destinations:\n");
    printf("\t\tDestination\tPrice\n");
    printf("\t 1.\tMombasa\t\tKsh. 6900\n");
    printf("\t 2.\tKisumu\t\tKsh. 6900\n");
    printf("\t 3.\tEldoret\t\tKsh. 6900\n");   
}

/* #TWO WAY TRIP means a return trip between two points
 (same day or at a later date)*/
void twowayDestinations(){
    printf("\n\n\t\tAvailable Destinations:\n");
    printf("\t\tDestination\tPrice\n");
    printf("\t 1.\tMombasa\t\tKsh. 13800\n");
    printf("\t 2.\tKisumu\t\tKsh. 13800\n");
    printf("\t 3.\tEldoret\t\tKsh. 13800\n");    
}
void reserveDestinations(){
    printf("\n\t\tAvailable Destinations:\n");
    printf("\t\tDestination\tPrice\n");
    printf("\t 1.\tMombasa\t\tKsh. 3450\n");
    printf("\t 2.\tKisumu\t\tKsh. 3450\n");
    printf("\t 3.\tEldoret\t\tKsh. 3450\n");
}
void displayTimes() {
    printf("\n\t\tAvailable Times:\n");
    printf("\t1. 10am\t\t2. 2pm\t\t3. 5pm\n");
}
void displayreturnTimes() {
    printf("\n\t\tAvailable Times for the RETURN Trip:\n");
    printf("\t1. 10am\t\t2. 2pm\t\t3. 5pm\n");
}
void displayBorderLine(){
    printf("\n\t\t------------------------------------------------------\n");
    printf("\t\tThank you for using PepeaKenya Ticketing system.\n");
    printf("\t\t------------------------------------------------------\n");
}

//calculate one-way ticket costs
int calculateOneWayCost(int ticketCount){
    const int PRICE_PER_ONE_WAY = 6900;
    return ticketCount * PRICE_PER_ONE_WAY;
}
//calculate two-way ticket costs
int calculateTwoWayCost(int twoticketCount){ 
    const int PRICE_PER_TWO_WAY = 13800;
    return twoticketCount * PRICE_PER_TWO_WAY;
}
//calculate reservation costs
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

    Person onewayBookings[MAX_BOOKINGS];
    Person twowayBookings[MAX_BOOKINGS];
    Person reserveBookings[MAX_BOOKINGS];

    while(1){
        printf("\n\t----------WELCOME TO PEPEAKENYA TICKETING SYSTEM---------\n");
        printf("\t\t\t1. One-Way Ticket\n");
        printf("\t\t\t2. Two-Way Ticket(Return Ticket)\n");
        printf("\t\t\t3. Seat Reservation\n");
        printf("\t\t\t4. Exit\n");
        printf("\tEnter your choice (1,2,3 or 4):\t");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:            
            printf("\n\t\tNow Booking One-Way Ticket.....\n");

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
            printf("\n\tEnter DATE of Departure(DD/MM):\n");
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
                printf("\n\tOne-Way Booking Reference NOT generated. Please try again.\n");
                return 1;
            }else{
                printf("\n\tOne-Way Booking Reference generated.\n\n");
            }
            fclose(outfile);
            printTicket(person);
            // Add this line before storing the booking
            //onewayBookings[ticketCount] = person;

            ticketCount++;

            char again;
            printf("\n\tDo you want to book another one-way ticket? (y/n)\t");
            scanf("%s", &again);

            if(again == 'N' || again == 'n'){
                //printf("\n\tHere are your tickets:\n");
                for (int i = 0; i < ticketCount; i++)
                {
                    printf("\n\t\t-------------------ONE-WAY TICKET (%d)-------------------\n", i+1);
                    printTicket(person);
                }
                printf("\n\t\tTotal Cost of ONE-WAY TICKETS(%d): Ksh. %d\n",ticketCount, calculateOneWayCost(ticketCount));
                displayBorderLine();
                return 0;
            }

            break;
        
        case 2:
            printf("\n\t\tNow Booking Two-Way Ticket.....\n");
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
            printf("\n\t--------------------------------------------------------\n");
            printf("\n\tPlease let's finalise with the details for return trip.\n");
            
            int twowayreturntime;
            displayreturnTimes();
            printf("\t\tPlease choose RETURN time:\t");            
            scanf("%d", &twowayreturntime);

            switch (twowayreturntime)
            {
                case 1:
                    strcpy(twowayperson.returntime, "10am");
                    break;
                case 2:
                    strcpy(twowayperson.returntime, "2pm");
                    break;
                case 3:
                    strcpy(twowayperson.returntime, "5pm");
                    break;
            }

            printf("\n\tEnter DATE of Return(DD/MM):\n");
            printf("\t\tEnter day of RETURN: \t");
            scanf("%d", &twowayperson.returnday);
            printf("\t\tEnter month of RETURN: \t");
            scanf("%d", &twowayperson.returnmonth);


            FILE *twowayfile;
            twowayfile = fopen("twowaybooking.csv", "a+");
            if (twowayfile == NULL)
            {
              printf("Error opening file!\n");
              return 1;
             }

            fprintf(twowayfile, "%d,%s,%s,%s,%s,%s,%s,%d,%d,%s,%d,%d\n",twowayperson.age,
                twowayperson.idpassport, twowayperson.fname, twowayperson.lname,
                twowayperson.phone, twowayperson.destination, twowayperson.time,
                twowayperson.day, twowayperson.month, twowayperson.returntime,
                twowayperson.returnday, twowayperson.returnmonth
             );

            if (ferror(twowayfile)){
                printf("\tTwo-Way Booking Reference NOT generated. Please try again.\n");
                return 1;
            }else{
                printf("\n\tTwo-Way Booking reference generated.\n\n");
            }
            fclose(twowayfile);
            printTicket(twowayperson);
            twowayBookings[twoticketCount] = twowayperson;
            twoticketCount++;

            //loop 2

            char againtwo;
            printf("\n\tDo you want to book another two-way ticket? (y/n)\t");
            scanf("%s", &againtwo);

            if(againtwo == 'N' || againtwo == 'n'){
                //printf("\n\tHere are your tickets:\n");
                for (int i = 0; i < twoticketCount; i++) //int j?
                {
                    printf("\n\t\t-------------------TWO-WAY TICKET %d--------------------\n", i+1);
                    printTwoWayTicket(twowayBookings[i]);
                }
                printf("\n\t\tTotal Cost of TWO-WAY TICKETS(%d): Ksh. %d\n",twoticketCount, calculateTwoWayCost(twoticketCount));
                displayBorderLine();
                return 0;
            }

            break;
        case 3:
            printf("\n\t\tNow Reserving a Seat.....\n");
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
            reserveBookings[resticketCount] = resperson;
            resticketCount++;
            //loop 3

            char againthree;
            printf("\n\tDo you want to make another reservation? (y/n)\t");
            scanf("%s", &againthree);

            if( againthree== 'N' || againthree == 'n'){
                //printf("\n\tHere are your reservations:\n");
                for (int i = 0; i < resticketCount; i++) //int i?
                {
                    printf("\n\t\t--------------------RESERVATION %d---------------------\n", i+1);
                    printReservations(reserveBookings[i]); //changed line for trials
                }
                printf("\n\t\tTotal Cost of RESERVATIONS(%d): Ksh. %d\n",resticketCount, calculateReserveCost(resticketCount));
                displayBorderLine();
                return 0;
            }

            break; 
        case 4:
            printf("\n\tYou're welcome to using PepeaKenya Ticketing system again.");            
            printf("\n\n\tExiting program.....\n");
            exit(0);    
        default:
            printf("\n\t\tPlease enter a valid choice(1, 2 or 3).\n");
            break;
        }
    }
    return 0;
}
