#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "display.h"
#include "calculation.h"

int main() {

    int TheaterSeats[4][5][10] = {0};
    int totalTickets = 0;
    int totalRevenue = 0;
    char SeatNames[4][5][10][100] = {0};


        printf("==============================================\n");
        printf("             WELCOME TO SAVOY CINEMA \n");
        printf("==============================================\n");

        printf("\n1.View Available movies\n");
        printf("2.Exit\n");

        int chooseOne = 0;
        printf("\nPlease Choose Number : ");
        scanf("%d", &chooseOne);


             if (chooseOne == 1){
        while (1) {
            printf("\n============================\n");
            printf(" * * AVAILABLE MOVIES * *\n");
            printf("============================\n");
            printf(" 1. Spider-Man 4\n");
            printf(" 2. The Batman - Part II\n");
            printf(" 3. Jumanji 3\n");
            printf(" 4. Dharmayuddhaya 2\n");
            printf(" 5. Exit\n");

            int movieNum = 0;
            printf("Please Choose Movie Number : ");
            scanf("%d", &movieNum);

            if (movieNum == 5)
                break;
            if (movieNum < 1 || movieNum > 5) {
                printf("Invalid Choice!\n");
                continue;
            }

            int realmId = movieNum - 1;
            int subMenuRunning = 1;

            while (subMenuRunning) {
               menuMovies();

                int menuChoose = 0;
                printf("Please Choose Number : ");
                scanf("%d", &menuChoose);

                switch (menuChoose) {
                    case 1:
                       showTime();
                      break;
                    case 2:
                       showSeatMap(TheaterSeats[realmId]);
                      break;
                    case 3: {
                        printf("===================================================\n");
                        printf("                  BOOK A SEAT                      \n");
                        printf("===================================================\n");

                        int numTickets = 1;
                        printf("How many tickets do you want to book? ");
                        scanf("%d", &numTickets);

                        int isGroup = (numTickets >= 3) ? 1 : 0;

                        if (isGroup) {
                            printf(" Special Offer: 10%% Group Discount Applied!\n");
                        }

                        for (int t = 0; t < numTickets; t++) {
                            printf("\n--- Ticket %d of %d ---\n", t + 1, numTickets);
                            char row;
                            int coloum;
                            char name[100];
                            char discountType;

                            printf("Please Enter Seat Row (A-E): ");
                            scanf(" %c", &row);


                            if (row >= 'a' && row <= 'e') row -= 32;

                            printf("Please Enter Seat Column (1-10): ");
                            scanf("%d", &coloum);

                            int realrId = row - 'A';
                            int realcId = coloum - 1;

                            if (realrId < 0 || realrId > 4 || realcId < 0 || realcId > 9) {
                                printf("Invalid Seat Position!\n");
                                t--;
                                continue;
                            }

                            if (TheaterSeats[realmId][realrId][realcId] == 1) {
                                printf("This seat is Already Booked. Please Try Another one.\n");
                                t--;
                                continue;
                            }

                            printf("Enter Customer Name: ");
                            scanf(" %[^\n]", name);

                            int basePrice = getBasePrice(row);

                            printf("Enter Discount Type ('S' for Student, 'C' for Senior, 'R' for Regular): ");
                            scanf(" %c", &discountType);

                            int finalPrice = calculateFinalPrice(basePrice, discountType, isGroup);

                            TheaterSeats[realmId][realrId][realcId] = 1;
                            strcpy(SeatNames[realmId][realrId][realcId], name);

                            totalTickets++;
                            totalRevenue += finalPrice;

                            printf("Booking Successful for %s! Ticket Price: Rs. %d\n", name, finalPrice);
                        }
                        break;
                     case 4: {
                        printf("===================================================\n");
                        printf("                CANCEL A BOOKING                 \n");
                        printf("===================================================\n");
                        char row;
                        int colNum;
                        char discountType;
                        char groupChoice;

                        printf("Enter Seat Row to Cancel (A-E): ");
                        scanf(" %c", &row);

                        if (row >= 'a' && row <= 'e') {
                            row = row - 32;
                        }

                        printf("Enter Seat Column to Cancel (1-10): ");
                        scanf("%d", &colNum);

                        int realrId = row - 'A';
                        int realcId = colNum - 1;

                        if (realrId < 0 || realrId > 4 || realcId < 0 || realcId > 9) {
                            printf(" Invalid Row or Column!\n");
                            break;
                        }

                        if (TheaterSeats[realmId][realrId][realcId] == 0) {
                            printf(" Error: This seat is not booked yet!\n");
                        } else {
                            printf("Enter Discount Type used during booking ('S' for Student, 'C' for Senior, 'R' for Regular): ");
                            scanf(" %c", &discountType);

                            printf("Was this a Group Booking? (Y/N): ");
                            scanf(" %c", &groupChoice);

                            int isGroup = (groupChoice == 'Y' || groupChoice == 'y') ? 1 : 0;

                            TheaterSeats[realmId][realrId][realcId] = 0;
                            strcpy(SeatNames[realmId][realrId][realcId], "");

                            int basePrice = getBasePrice(row);
                            int finalPrice = calculateFinalPrice(basePrice, discountType, isGroup);

                            totalTickets--;
                            totalRevenue -= finalPrice;

                            printf("\n Cancellation Successful!\n");
                            printf("Amount Refunded: Rs. %d\n", finalPrice);
                            printf("Remaining Total Booked Tickets: %d\n", totalTickets);
                        }
                        break;
                        case 5: {
                        printf("===================================================\n");
                        printf("               SEARCH A BOOKING                   \n");
                        printf("===================================================\n");
                        printf("1. Search by Seat (e.g., A-3)\n");
                        printf("2. Search by Customer Name\n");
                        int searchType;
                        printf("Choose Search Type: ");
                        scanf("%d", &searchType);

                        if (searchType == 1) {
                            char row;
                            int col;
                            printf("Enter Seat Row (A-E): ");
                            scanf(" %c", &row);

                            if (row >= 'a' && row <= 'e') row -= 32;

                            printf("Enter Seat Column (1-10): ");
                            scanf("%d", &col);

                            int realrId = row - 'A';
                            int realcId = col - 1;

                            if (realrId < 0 || realrId > 4 || realcId < 0 || realcId > 9) {
                                printf("Invalid Seat!\n");
                            } else if (TheaterSeats[realmId][realrId][realcId] == 1) { // 🟢 BUG FIXED HERE
                                printf("Seat %c-%d is BOOKED by: %s\n", row, col, SeatNames[realmId][realrId][realcId]);
                            } else {
                                printf("Seat %c-%d is currently AVAILABLE.\n", row, col);
                            }
                        } else if (searchType == 2) {
                            char searchName[100];
                            printf("Enter Customer Name to Search: ");
                            scanf(" %[^\n]", searchName);

                            int found = 0;
                            for (int r = 0; r < 5; r++) {
                                for (int c = 0; c < 10; c++) {
                                    if (TheaterSeats[realmId][r][c] == 1 && strcasecmp(SeatNames[realmId][r][c], searchName) == 0) {
                                        printf("Booking Found! Name: %s | Seat: %c-%d\n", SeatNames[realmId][r][c], 'A' + r, c + 1);
                                        found = 1;
                                    }
                                }
                            }
                            if (!found) {
                                printf("No booking found under the name '%s'.\n", searchName);
                            }
                        } else {
                            printf("Invalid Search Option!\n");
                        }
                        break;
                      }
                     }
                   }
                 }
               }
           }


        } else {
            printf("\n===================================================\n");
            printf("       THANK YOU FOR VISITING SAVOY CINEMA!        \n");
            printf("===================================================\n\n");
        }

    return 0;
}
