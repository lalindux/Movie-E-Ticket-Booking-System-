#ifndef CALCULATION_H_INCLUDED
#define CALCULATION_H_INCLUDED

int getBasePrice(char row);
int calculateFinalPrice(int basePrice, char discountType, int isGroupDiscount);

#endif // CALCULATION_H_INCLUDED
