#include <stdio.h>
#include <string.h>
#include "display.h"


void menuMovies() {
printf("\n--- Movie Options ---\n");
printf("1. View Show Times\n");
printf("2. View Seat Map\n");
printf("3. Book A Seat\n");
printf("4. Booking cancel\n");
printf("5. Search booking\n");
printf("6. View Revenue Report\n");
printf("7. Go Back to Main Menu\n");
printf("------------------------\n");
  }

void showTime() {
printf("\n========================\n");
printf(" Available Times \n");
printf("========================\n");
printf("1. 10.00 - 12.30\n");
printf("2. 01.00 - 03.30\n");
printf("------------------------\n");
 }

void showSeatMap(int seats[5][10]) {
printf("\n=====================================\n");
printf("              SEAT MAP \n");
printf("=====================================\n");
printf("\n  1 2 3 4 5 6 7 8 9 10\n");
   char row = 'A';
    for (int i = 0;i < 5; i++){
            printf("%c ", row + i);
    for (int j = 0; j < 10; j++) {
         if (seats[i][j] == 0){
              printf(". ");
    }else{
         printf("X ");
        }
    }
     if (i < 2) printf(" [Regular]");
     else if (i < 4) printf(" [Premium]");
     else printf(" [VIP]");
     printf("\n");
   } printf("-------------------------------------\n");
     printf(" Note: [.] = Available, [X] = Booked\n");
    }
