#include "calculation.h"


int getBasePrice(char row) {
    if (row == 'A' || row == 'B' || row == 'a' || row == 'b')
        return 500;
    if (row == 'C' || row == 'D' || row == 'c' || row == 'd')
        return 750;
    if (row == 'E' || row == 'e')
        return 1000;
    return 0;
}

int calculateFinalPrice(int basePrice, char discountType, int isGroupDiscount) {
    double discountPercentage = 0.0;

    if (discountType == 'S' || discountType == 's') {
        discountPercentage += 0.10;
    } else if (discountType == 'C' || discountType == 'c') {
        discountPercentage += 0.20;
    }

    if (isGroupDiscount) {
        discountPercentage += 0.10;
    }

    int finalPrice = basePrice - (basePrice * discountPercentage);
    return finalPrice;
}
