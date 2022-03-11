#include<stdio.h>
#include<stddef.h>
#include<stdlib.h>
#include<time.h>

typedef struct
{
    int loShuTable[3][3];
} LoShuTable;

int checkTable(LoShuTable loShu);
int generateRandomNumbers(LoShuTable loShu);
int checkDiagonals(LoShuTable losShu);
int checkRow(LoShuTable losShu, int rowToCheck);
int checkCol(LoShuTable losShu, int colToCheck);
LoShuTable populateArray(LoShuTable loShu);

int main() {
    LoShuTable loShu = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    int solved = 0; //0 = not solved, 1 = solved
    int squaresGenerated = 0;
    const int MAXSQUARES = 10000;
    do
    {
        squaresGenerated++;
        loShu = populateArray(loShu);
        solved = checkTable(loShu);
        if (squaresGenerated > MAXSQUARES)
        {
            break;
        }
    } while (solved == 0);
    if (squaresGenerated > MAXSQUARES)
    {
        printf("Could not generate a Lo Shu Magic Square in %d square generations, restart program to try again\n", MAXSQUARES); //keeps program from using 100% CPU and running forever
    }
    else
    {
        printf("Number of squares generated before success: %d\n", squaresGenerated);
        for (int i = 0; i < 3; i++)
        {
            printf("[ ");
            for (int j = 0; j < 3; j++)
            {
                printf("%d ", loShu.loShuTable[i][j]);
            }
            printf("]\n");
        }
    }
    return 0;
}

int checkTable(LoShuTable loShu) {
    int neSwSum = 0; //diagonal North East/South West " / "
    int nwSeSum = 0; //diagonal North West/South East " \ "
    int col1Sum = 0;
    int col2Sum = 0;
    int col3Sum = 0;
    int row1Sum = 0;
    int row2Sum = 0;
    int row3Sum = 0;
    int rowCheck = 0;
    int colCheck = 0;
    int diagonalCheck = 0;
    neSwSum = loShu.loShuTable[2][0] + loShu.loShuTable[1][1] + loShu.loShuTable[0][2];
    nwSeSum = loShu.loShuTable[0][0] + loShu.loShuTable[1][1] + loShu.loShuTable[2][2];
    col1Sum = loShu.loShuTable[0][0] + loShu.loShuTable[1][0] + loShu.loShuTable[2][0];
    col2Sum = loShu.loShuTable[0][1] + loShu.loShuTable[1][1] + loShu.loShuTable[2][1];
    col3Sum = loShu.loShuTable[0][2] + loShu.loShuTable[1][2] + loShu.loShuTable[2][2];
    row1Sum = loShu.loShuTable[0][0] + loShu.loShuTable[0][1] + loShu.loShuTable[0][2];
    row2Sum = loShu.loShuTable[1][0] + loShu.loShuTable[1][1] + loShu.loShuTable[1][2];
    row3Sum = loShu.loShuTable[2][0] + loShu.loShuTable[2][1] + loShu.loShuTable[2][2];
    if (row1Sum == row2Sum && row2Sum == row3Sum)
    {
        rowCheck = 1; //1 = sums are the same
    }
    if (col1Sum == col2Sum && col2Sum == col3Sum)
    {
        colCheck = 1;
    }
    if (neSwSum == nwSeSum)
    {
        diagonalCheck = 1;
    }
    if (rowCheck == colCheck && colCheck == diagonalCheck)
    {
        if (rowCheck == 1)
        {
            return 1;
        }
        else {
            return 0;
        }
    }
    else {
        return 0;
    }
}
int checkDiagonals(LoShuTable loShu) {
    int neswSum = 0;
    int nwseSum = 0;
    neswSum = loShu.loShuTable[2][0] + loShu.loShuTable[1][1] + loShu.loShuTable[0][2];
    nwseSum = loShu.loShuTable[0][0] + loShu.loShuTable[1][1] + loShu.loShuTable[2][2];
    if (neswSum == nwseSum)
    {
        return 1;
    }
    else {
        return 0;
    }
}

int checkRow(LoShuTable losShu, int rowToCheck) {
    int rowSum1 = 0;
    int rowSum2 = 0;
    rowSum1 = losShu.loShuTable[rowToCheck - 1][0] + losShu.loShuTable[rowToCheck - 1][1] + losShu.loShuTable[rowToCheck - 1][2];
    rowSum2 = losShu.loShuTable[rowToCheck][0] + losShu.loShuTable[rowToCheck][1] + losShu.loShuTable[rowToCheck][2];
    if (rowSum1 == rowSum2)
    {
        return 1;
    }
    else {
        return 0;
    }
}

int checkCol(LoShuTable losShu, int colToCheck) {
    int colSum1 = 0;
    int colSum2 = 0;
    colSum1 = losShu.loShuTable[0][colToCheck - 1] + losShu.loShuTable[1][colToCheck - 1] + losShu.loShuTable[2][colToCheck - 1];
    colSum2 = losShu.loShuTable[0][colToCheck] + losShu.loShuTable[1][colToCheck] + losShu.loShuTable[2][colToCheck];
    if (colSum1 == colSum2)
    {
        return 1;
    }
    else {
        return 0;
    }
}

int generateRandomNumbers(LoShuTable loShu) {
    int randNum = 0;
    int inArray = 0; //1 = # is in array, 0 = # is not in array
    time_t t;
    srand((unsigned)time(&t));
    do
    {
        inArray = 0;
        randNum = (rand() % 9) + 1; //generates random number between 1-9
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (loShu.loShuTable[i][j] == randNum)
                {
                    inArray = 1;
                }
            }
        }
    } while (inArray == 1); //if generated # is in array, generate another
    return randNum;
}

LoShuTable populateArray(LoShuTable loShu) {

    const int MAXITER = 100;
    int iterations = 0;
    //-------------------------genereate table by finding diagonals and keeping those with the same sum--------------------------------------
    iterations = 0;
    //initializes array to all be 0
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            loShu.loShuTable[i][j] = 0;
        }

    }
    //generate diagonals
    do
    {
        //initializes diagonals be 0
        loShu.loShuTable[2][0] = 0;
        loShu.loShuTable[1][1] = 0;
        loShu.loShuTable[0][2] = 0;
        loShu.loShuTable[0][0] = 0;
        loShu.loShuTable[2][2] = 0;
        //generates random numbers on diagonals of table         
        loShu.loShuTable[2][0] = generateRandomNumbers(loShu);
        loShu.loShuTable[1][1] = generateRandomNumbers(loShu);
        loShu.loShuTable[0][2] = generateRandomNumbers(loShu);
        loShu.loShuTable[0][0] = generateRandomNumbers(loShu);
        loShu.loShuTable[2][2] = generateRandomNumbers(loShu);
        if (checkDiagonals(loShu) == 1)
        {
            break;
        }
        else {
            iterations++;
        }
    } while (iterations < MAXITER);
    //if solved diagonals are found, try to find the rest of the numbers correctly
    if (checkDiagonals(loShu) == 1)
    {
        iterations = 0;
        do {
            //initializes these numbers to be 0
            loShu.loShuTable[0][1] = 0;
            loShu.loShuTable[1][0] = 0;
            loShu.loShuTable[1][2] = 0;
            loShu.loShuTable[2][1] = 0;
            //generates the rest of the numbers randomly then checks if the table is correct; if it's not, regenerate these numbers
            loShu.loShuTable[0][1] = generateRandomNumbers(loShu);
            loShu.loShuTable[1][0] = generateRandomNumbers(loShu);
            loShu.loShuTable[1][2] = generateRandomNumbers(loShu);
            loShu.loShuTable[2][1] = generateRandomNumbers(loShu);
            if (checkTable(loShu) == 1)
            {
                return loShu;
            }
            else
            {
                iterations++;
            }
        } while (iterations < MAXITER);
    }

    //-----------------------generate table row by row, keeping rows with the same sum-------------------------------------------
    int row2Tries = 0;
    int row3Tries = 0;
    int totalTries = 0;
    do
    {
        //initializes array to all be 0; counter for permutations of rows 2 and 3 are also reset to 0, since this should be a new attempt every loop until max
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                loShu.loShuTable[i][j] = 0;
            }
        }
        row2Tries = 0;
        row3Tries = 0;

        //populate first row
        for (int j = 0; j < 3; j++)
        {
            loShu.loShuTable[0][j] = generateRandomNumbers(loShu);
        }
        do
        {
            //re-clears row so the check in generateRandomNumbers doesn't count the numbers from the previous try
            loShu.loShuTable[1][0] = 0;
            loShu.loShuTable[1][1] = 0;
            loShu.loShuTable[1][2] = 0;

            //populate second row
            for (int j = 0; j < 3; j++)
            {
                loShu.loShuTable[1][j] = generateRandomNumbers(loShu);
            }
            if (row2Tries <= 200) //all possible combinations of numbers have been checked for this row
            {
                row2Tries++;
            }
            else {
                totalTries += row2Tries;
                break;
            }
        } while (checkRow(loShu, 1) == 0); //check if sum of 2nd row = sum of 1st row; if not, regenerate

        do
        {

            //re-clears row so the check in generateRandomNumbers doesn't count the numbers from the previous try
            loShu.loShuTable[2][0] = 0;
            loShu.loShuTable[2][1] = 0;
            loShu.loShuTable[2][2] = 0;
            //populate third row
            for (int j = 0; j < 3; j++)
            {
                loShu.loShuTable[2][j] = generateRandomNumbers(loShu);
            }
            if (row3Tries <= 20) //all possible combinations of numbers have been checked for this row
            {
                row3Tries++;
            }
            else {
                totalTries += row3Tries;
                break;
            }
        } while (checkRow(loShu, 2) == 0); //check if sum of 3nd row = sum of 2nd row; if not, regenerate

        if (checkRow(loShu, 2) == 1 && checkRow(loShu, 1) == 1)
        {
            if (checkTable(loShu) == 1)
            {
                return loShu;
            }
        }
    } while (totalTries <= MAXITER);

    //-----------------------generate table col by col, keeping rows with the same sum-------------------------------------------
    int col2Tries = 0;
    int col3Tries = 0;
    totalTries = 0;
    do
    {
        //initializes array to all be 0;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                loShu.loShuTable[i][j] = 0;
            }
        }
        col2Tries = 0;
        col3Tries = 0;

        //populate first col
        for (int i = 0; i < 3; i++)
        {
            loShu.loShuTable[i][0] = generateRandomNumbers(loShu);
        }
        do
        {
            //re-clears row so the check in generateRandomNumbers doesn't count the numbers from the previous try
            loShu.loShuTable[0][1] = 0;
            loShu.loShuTable[1][1] = 0;
            loShu.loShuTable[2][1] = 0;

            //populate second row
            for (int i = 0; i < 3; i++)
            {
                loShu.loShuTable[i][1] = generateRandomNumbers(loShu);
            }
            if (col2Tries <= 200) //all possible combinations of numbers have been checked for this row
            {
                col2Tries++;
            }
            else {
                totalTries += col2Tries;
                break;
            }
        } while (checkCol(loShu, 1) == 0); //check if sum of 2nd row = sum of 1st row; if not, regenerate

        do
        {

            //re-clears row so the check in generateRandomNumbers doesn't count the numbers from the previous try
            loShu.loShuTable[0][2] = 0;
            loShu.loShuTable[1][2] = 0;
            loShu.loShuTable[2][2] = 0;
            //populate third row
            for (int i = 0; i < 3; i++)
            {
                loShu.loShuTable[i][2] = generateRandomNumbers(loShu);
            }
            if (col3Tries <= 20) //all possible combinations of numbers have been checked for this row
            {
                col3Tries++;
            }
            else {
                totalTries += col3Tries;
                break;
            }
        } while (checkCol(loShu, 2) == 0); //check if sum of 3nd row = sum of 2nd row; if not, regenerate

        if (checkCol(loShu, 2) == 1 && checkCol(loShu, 1) == 1)
        {
            if (checkTable(loShu) == 1)
            {
                return loShu;
            }
        }
    } while (totalTries <= MAXITER);

    //--------------------------------------generate entire array at once---------------------------------------------------
    iterations = 0;
    do
    {
        //initializes array to all be 0
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                loShu.loShuTable[i][j] = 0;
            }

        }
        //populate entire array with random numbers
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                loShu.loShuTable[i][j] = generateRandomNumbers(loShu);
            }
        }
        if (checkTable(loShu) == 1)
        {
            return loShu;
        }
        else {
            iterations++;
        }
    } while (iterations < MAXITER);

    return loShu;
}