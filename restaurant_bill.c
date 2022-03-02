#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
int main(int argc, char *argv[]){

    //save tax and tip as integers
    float tax = atof(argv[1]); //atoi converts argv input to a float number
    float tip = atof(argv[2]);

    //validate inputs
    if (argc != 3)
    {
        printf("invalid inputs; input tax and tip as percentages\n");
        printf("Tax supplied: %f tip supplied: %f\n", tax, tip);
        printf("arguments = %d\n", argc);
    }
    else if (tax < 0 || tip < 0)
    {
        printf("invalid inputs; tax must be entered as a percentage\n");
        printf("Tax supplied is %f\n", tax);
        printf("Tip supplied is %f\n", tip);
    }

    //generate random number to assign a meal price
    char meal[9] = "";
    float mealPrice = 0;
    int randNum = 0;
    time_t t;
    srand((unsigned) time(&t));
    randNum = rand() % 4;
    switch (randNum)
    {
    case 0:
        strcpy(meal, "salad");
        mealPrice = 9.95;
        break;
    case 1:
        strcpy(meal, "soup");
        mealPrice = 4.55;
        break;
    case 2:
        strcpy(meal, "sandwich");
        mealPrice = 13.25;
        break;
    case 3:
        strcpy(meal, "pizza");
        mealPrice = 22.35;
        break;
    default:
        break;
    }

    //calculate tax, tip, total, and display w/ meal and mealprice
    float total = 0;
    float newTip = 0;
    float newTax = 0;
    newTip = (tip/100) * mealPrice;
    newTax = (tax/100) * mealPrice;
    total = mealPrice + newTip + newTax;
    printf("meal: %s\nmeal price: $%f\ntax input (percent): %f\ntip input (percent): %f\ntax calculated: $%f\ntip calculated: $%f\ntotal: $%f\n", meal, mealPrice, tax, tip, newTax, newTip, total);
    
    return 0;
}