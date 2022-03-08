#include<string.h>
#include "employee.h"
/*5 functions have been defined below
ptr - points to table to be searched
tableSize - size of table
targetPtr - points to value that will be searched for in table
functionPtr - points to comparison function below and will perform the associated check

setting a function static
functionPtr is the address of the function just use the name
()(the second set of parentheses is the arguments of the function call)
because the search functions are defined in main, both this file and employeeOne will work
without having to change main
static in declaration of a function means the function can ONLY be used in THIS file
void *targetPtr allows any kind of ptr to be passed to this function, and for *targetpointer to be typecast as an int or char pointer later
int (*functionPtr)(const void *, PtrToConstEmployee) passes a function (like compareEmployeeName) and its arguments
*/
static PtrToEmployee searchEmployeeTable(PtrToConstEmployee ptr, int tableSize, const void *targetPtr, int (*functionPtr)(const void *, PtrToConstEmployee))
{
    PtrToConstEmployee endPtr = ptr + tableSize;
    for (; ptr < endPtr; ptr++)
    {
        if ((*functionPtr)(targetPtr, ptr) == 0) //compareEmployeeNumber(&1045, TableRow); this basically compares addresses rather than numbers or strings
        {
            return (PtrToEmployee) ptr;
        }
    }
    return NULL;
    
}

//the functionPtr will point to one of these comparison function to perform a check
static int compareEmployeeNumber(const void *targetPtr, PtrToConstEmployee tableValuePtr){
    return * (long *) targetPtr != tableValuePtr->number; //const void *targetPtr is typecast as long pointer then dereferenced(value is read from the location its pointing to)
}
static int compareEmployeeName(const void *targetPtr, PtrToConstEmployee tableValuePtr){
    return strcmp((char *) targetPtr, tableValuePtr->name); //const void *targetPtr is typecast as char pointer then passed to strcmp 
}

//these are called wrappers. these functions are what will be used in main
PtrToEmployee searchEmployeeByNumber(PtrToConstEmployee ptr, int size, long number){
    return searchEmployeeTable(ptr, size, &number, compareEmployeeNumber);
}
PtrToEmployee searchEmployeeByName(PtrToConstEmployee ptr, int size, char* name){
    return searchEmployeeByName(ptr, size, name, compareEmployeeName); //char *name is already an address so we don't need &
}