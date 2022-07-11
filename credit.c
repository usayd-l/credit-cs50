
#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int count = 0;
    long card; //declaring a variable long for card
    do
    {
        card = get_long("Card no: "); //Getting card number
    }
    while (card < 0); //card must not be less than 0
    long check = card;

    int card1, card2, card3, card4, card5, card6, card7, card8;
    card1 = (((card % 100)/10)*2);                              //(Multiply from second to the last by 2) then keep going
    card2 = (((card % 10000)/1000)*2);                          //(same)
    card3 = (((card % 1000000)/100000)*2);                      //(same)
    card4 = (((card % 100000000)/10000000)*2);
    card5 = (((card % 10000000000)/1000000000)*2);
    card6 = (((card % 1000000000000)/100000000000)*2);
    card7 = (((card % 100000000000000)/10000000000000)*2);
    card8 = (((card % 10000000000000000)/1000000000000000)*2);


    card1 = (card1 % 100/10) + (card1 % 10);
    card2 = (card2 % 100/10) + (card2 % 10);
    card3 = (card3 % 100/10) + (card3 % 10);
    card4 = (card4 % 100/10) + (card4 % 10);
    card5 = (card5 % 100/10) + (card5 % 10);
    card6 = (card6 % 100/10) + (card6 % 10);
    card7 = (card7 % 100/10) + (card7 % 10);
    card8 = (card8 % 100/10) + (card8 % 10);

    int card_no = card1 + card2 + card3 + card4 + card5 + card6 + card7 + card8;

    int non_mult =  (card % 10) + ((card % 1000)/100) + ((card % 100000)/10000) + ((card % 10000000)/1000000) +
    ((card % 1000000000)/100000000) + ((card % 100000000000)/10000000000) + ((card % 10000000000000)/1000000000000) +
    ((card % 1000000000000000)/100000000000000); //adding non multiplied numbers

    int check_sum = card_no + non_mult;   //CHECK SUM CALCULATION for validating input
    if ((check_sum % 10) != 0)   //if check sum doesn't give remainder of "0", print invalid, then terminate
    {
        printf("INVALID\n");
        return 0;
    }
    while (check > 0)    //check is same as card ///check code line 13, i.e, while card is greater than 0
    {
        check = check / 10;  //count the number of digits in card
        count++;   //count untill end
    }
    if (count != 15 && count != 13 && count != 16) //to confirm card length must be equal to 15, 13 or 16
    {
        printf("INVALID\n");
        return 1;
    }
    long MC = card / 100000000000000;     //to give the first two number of card in order to validate MASTER_CARD
    long AMEX = card / 10000000000000;    //to give the first two number of card in order to validate AMERICAN EXPRESS
    long Visa = card / 1000000000000000;  //to give the first number of card in order to validate VISA_CARD
    if (count == 15)
    {
        if (AMEX != 34 && AMEX != 37)  //to check if American Express first two digit is 34 or 37
        {
            printf("INVALID\n");
            return 1;
        }
        else
        {
            printf("AMEX\n");
            return 0;
        }
    }

    if (count == 16)
    {
        if (MC == 51 || MC == 52 || MC == 53 || MC == 54 || MC == 55)  //to check if Master card first two digit is 51, 52, 53, 54, 55.
        {
            printf("MASTERCARD\n");
            return 0;
        }
        else if (Visa == 4)  //first validation for visa card(16).....to check if visa_card first digit is 4
        {
            printf("VISA\n");
            return 0;
        }
        else if (MC != 51 && MC != 52 && MC != 53 && MC != 54 && MC != 55 && Visa == 4)
        {
            printf("INVALID\n");
            return 1;
        }
    }

    if (count == 13 && Visa == 4)  //second validation for visa card(13).....to check for validation
    {
        printf("VISA\n");
        return 0;
    }
    else if (count != 13 && Visa != 4)
    {
        printf("INVALID\n");
        return 1;
    }
}


