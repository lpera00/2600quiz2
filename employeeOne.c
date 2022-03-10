#include<string.h>
#include "employee.h"

PtrToEmployee searchEmployeeByNumber(PtrToConstEmployee ptr, int tableSize, long targetNumber){
    const PtrToConstEmployee endPtr = ptr + tableSize;
    //ptrtoconstemployee ptr is POINTING to the area of memory where the table we want to seach through is located
    //ptr is where the table starts and ptr + tablesize is where it ends

    for (; ptr < endPtr; ptr++) //search until end of table; ; at the beginning means there's nothing to initialize
    {
        if (ptr->number == targetNumber) //check if the number(data) ptr is pointing to equals the target number
        {
            return(PtrToEmployee) ptr; //return location of the number to callee; typecasted as ptrtoemployee because we don't want it to be const
            //each employee is 32bytes, to pointer++ increases pointer address(row) value by 32bytes
        }
    }
    return NULL; //this will only happen if no employee number matches
}

//basically the same as above but comparing strings instead of numbers
PtrToEmployee searchEmployeeByName(PtrToConstEmployee ptr, int tableSize, char * targetName){
    const PtrToConstEmployee endPtr = ptr + tableSize;

    for (; ptr < endPtr; ptr++)
    {
        if (strcmp(ptr->name,targetName) == 0) //check if the name(data) ptr is pointing to matches the target name
        {
            return(PtrToEmployee) ptr; 
        }
    }
    return NULL;
}

PtrToEmployee searchEmployeeByPhone(PtrToConstEmployee ptr, int tableSize, char * targetPhone){
    const PtrToConstEmployee endPtr = ptr + tableSize;

    for (; ptr < endPtr; ptr++)
    {
        if (strcmp(ptr->phone,targetPhone) == 0) //check if the phone number data the ptr is pointing to matches the target phone number
        {
            return(PtrToEmployee) ptr; 
        }
    }
    return NULL;
}

PtrToEmployee searchEmployeeBySalary(PtrToConstEmployee ptr, int tableSize, double targetSalary){
    const PtrToConstEmployee endPtr = ptr + tableSize;

    for (; ptr < endPtr; ptr++)
    {
        if (ptr->salary == targetSalary) //check if the salary data the ptr is pointing to matches the target salary
        {
            return(PtrToEmployee) ptr;
        }
    }
    return NULL;
}