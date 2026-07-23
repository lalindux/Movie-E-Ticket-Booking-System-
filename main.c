#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "display.h"
int main() {

    int TheaterSeats[4][5][10] = {0};


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
