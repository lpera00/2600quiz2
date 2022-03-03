#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
int main(){
    int guesses = 0;
    int gamesWon = 0;
    int gamesLost = 0;
    int maxNum = 10;
menu_display:
    //generate random number to be the answer and initialize input variables
    int userInput = 1;
    time_t t;
    srand((unsigned) time(&t));
    int userAnswer = 1;
    char userAnswerInput[2];
    int answer = (rand() % maxNum) + 1; //will generate a number between 1-maxNum
    //display menu and read input
    printf("Press 1 to play a game\nPress 2 to change the max number\nPress 3 to quit\n");
    printf("user input: ");
    fflush(stdout);
    scanf("%d", &userInput);

//validate user input
if (userInput > 3 || userInput < 1)
{
    printf("invalid input, try again\n");
    goto menu_display;
}

switch (userInput)
{
case 1:
    //run guessing game 
    game_display: 
        printf("guess a number between 1 and %d: ", maxNum);
        fflush(stdout);
        scanf("%s", userAnswerInput);
        userAnswer = atoi(userAnswerInput);
    //validate user input and play game
     if (strcmp(userAnswerInput, "q") == 0) //compares user input to q, 0 means user input is "q"
    {
        printf("quitting game and returning to menu\n");
        gamesLost++;
        goto menu_display;
    }
    else if (userAnswer < 1 || userAnswer > maxNum)
    {
        printf("invalid input, try again\n");
        goto game_display;
    }
    else if (userAnswer == answer)
    {
        printf("you win! returning to menu\n");
        guesses++;
        gamesWon++;
        goto menu_display;
    }
    else if (userAnswer < answer)
    {
        printf("too low, try again\n");
        guesses++;
        goto game_display;
    }
    else if(userAnswer > answer)
    {
        printf("too high, try again\n");
        guesses++;
        goto game_display;
    }
    break;

case 2:
new_max_prompt:
int userMaxNum = 10;
printf("enter a new max value between 2 and 10: ");
scanf("%d", &userMaxNum);
//validate input, update maxNum to user input, send to menu
if (userMaxNum > 10 || userMaxNum < 2)
{
    printf("invalid input, try again\n");
    goto new_max_prompt;
}
else {
    maxNum = userMaxNum;
    printf("new max value is: %d\nreturning to menu\n", userMaxNum);
    goto menu_display;
}

break;

case 3:
    //thank user for playing and display game stats
    printf("thanks for playing! here are your results: \n");
    printf("total guesses: %d\ntotal games won: %d\ntotal games lost: %d\n", guesses, gamesWon, gamesLost);
break;

default:
    break;
}

    return 0;
}
