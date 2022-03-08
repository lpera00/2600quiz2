#include<string.h>
#include<stdlib.h>
#include "employee.h"

Employee EmployeeTable[] = 
{
    {1001l, "Daphne Borromeo", "909-555-2134", 8.78},
    {1011l, "Tammy Franklin", "213-555-1212", 4.50},
    {1140l, "Dorris Perl", "310-555-1215", 7.80},
    {4011l, "Tony Bobcat", "909-555-1235", 6.34},
    {5045l, "Brian Height", "714-555-2749", 8.32}
};//size not predetermined because entries may need to be added/removed frequently
//l at the end of the number makes it interpreted as a long

const int EmployeeTableEntries = sizeof(EmployeeTable)/sizeof(EmployeeTable[0]); //160/32

//each member in struct Employee is 8 bytes
//all members can be accessed by incrementing by equal distance
void main(){
    printf("%d\n", sizeof(EmployeeTable));
    printf("%d\n", sizeof(EmployeeTable[0]));
    printf("%d\n", sizeof(long));
    printf("%d\n", sizeof(char*));  //depends on address space; 8 bytes for 64-bit proccessor, 4 for 32
    printf("%d\n", sizeof(char*));  //compiler pads out entries in a structure smaller than the largest size
    printf("%d\n", sizeof(double));
}