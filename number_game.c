/*output instructions 
read input w/ argv
if input = 1:
generate random number between [n-(n-1) to n-1] where n is MAXNUM (initially 10)
place random number in int variable
display instruction to enter number
argv to i (atoi)
    if answer is = random number generated
        display that they won and goto menu display section
        gamesWon++
    else if answer < random number generated
        display that the number is too low and prompt to try again
        read console input again w/ "fflush(stdout);
                                    scanf("%d" &i);"
        guessCounter++
    else if answer > random number generated
        display that the number is too high and prompt to try again
        guessCounter++
    else if input = q
        goto menu display section
        gamesLost++

if input = 2:
display that the max value is 10 and to choose a positive integer between 2-9
check validity of input:
if input < 0 or > 10
    goto ask for new number
else 
    maxnum = input
    goto 1 selected section

if input = 3
    display thanks for playing
    display guessCounter, gamesWon, and gamesLost
    break;

    for save max number branch:
    use a text file to store max number input 
    read this input before beginning game (default will be 10)
    rewrite this input if 2 is selected w/ new input
*/