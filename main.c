#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {


        printf("==============================================\n");
        printf("             WELCOME TO SAVOY CINEMA \n");
        printf("==============================================\n");

        printf("\n1.View Available movies\n");
        printf("2.Exit\n");

        int chooseOne = 0;
        printf("\nPlease Choose Number : ");
        scanf("%d", &chooseOne);

        if (chooseOne == 1) {

            //

        } else {
            printf("\n===================================================\n");
            printf("       THANK YOU FOR VISITING SAVOY CINEMA!        \n");
            printf("===================================================\n\n");
        }

    return 0;
}
