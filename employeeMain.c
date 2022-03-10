#include<string.h>
#include<stdlib.h>
#include "employee.h"

//compile using "gcc employeeMain.c employeeTable.c employeeOne.c" for method 1 (2 functions)
//gcc employeeMain.c employeeTable.c employeeTwo.c for method 2 (1 function)

int main(void){
    //defined in employeeOne.c
    PtrToEmployee searchEmployeeByNumber(const Employee table[], int sizeTable, long numberToFind);
    PtrToEmployee searchEmployeeByName(const Employee table[], int sizeTable, char * nameToFind);
    PtrToEmployee searchEmployeeByPhone(PtrToConstEmployee ptr, int tableSize, char * targetPhone);
    PtrToEmployee searchEmployeeBySalary(PtrToConstEmployee ptr, int tableSize, double targetSalary);


    //defined in employeeTable.c
    extern Employee EmployeeTable[];
    extern const int EmployeeTableEntries;

    PtrToEmployee matchPtr; //declaration
    matchPtr = searchEmployeeByNumber(EmployeeTable, EmployeeTableEntries, 1045);

    //example not found
    if (matchPtr != NULL)
    {
        printf("Employee ID 1045 is in record %d\n", matchPtr - EmployeeTable); //matchPtr and EmployeeTable are both type Employee; finding the difference between the addresses both are pointing to; each employee is 32 bytes to if the difference is 96 bytes they are 3 employees apart, so the answer is location 3 in the table
    }
    else{
        printf("Employee ID is NOT found in the record\n");
    }

    //example found
    matchPtr = searchEmployeeByName(EmployeeTable, EmployeeTableEntries, "Tony Bobcat");
    if (matchPtr != NULL)
    {
        printf("Employee Tony Bobcat is in record %d\n", matchPtr - EmployeeTable);
    }
    else{
        printf("Employee Tony Bobcat is NOT in record\n");
    }

    //example phone number found
    matchPtr = searchEmployeeByPhone(EmployeeTable, EmployeeTableEntries, "714-555-2749");
    if (matchPtr != NULL)
    {
        printf("Phone number 714-555-2749 is in record %d\n", matchPtr - EmployeeTable);
    }
    else{
        printf("Phone number 714-555-2749 is NOT in record\n");
    }

    //example phone number not found
    matchPtr = searchEmployeeByPhone(EmployeeTable, EmployeeTableEntries, "123-456-7890");
    if (matchPtr != NULL)
    {
        printf("Phone number 123-456-7890 is in record %d\n", matchPtr - EmployeeTable);
    }
    else{
        printf("Phone number 123-456-7890 is NOT in record\n");
    }

    //example salary found
    matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 6.34);
    if (matchPtr != NULL)
    {
        printf("Salary 6.34 is in record %d\n", matchPtr - EmployeeTable); //matchPtr and EmployeeTable are both type Employee; finding the difference between the addresses both are pointing to; each employee is 32 bytes to if the difference is 96 bytes they are 3 employees apart, so the answer is location 3 in the table
    }
    else{
        printf("Salary 6.34 is NOT found in the record\n");
    }

    //example salary not found
    matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 5.67);
    if (matchPtr != NULL)
    {
        printf("Salary 5.67 is in record %d\n", matchPtr - EmployeeTable); //matchPtr and EmployeeTable are both type Employee; finding the difference between the addresses both are pointing to; each employee is 32 bytes to if the difference is 96 bytes they are 3 employees apart, so the answer is location 3 in the table
    }
    else{
        printf("Salary 5.67 is NOT found in the record\n");
    }

    return EXIT_SUCCESS;
}