#include<stdio.h>
#include<stddef.h>

typedef struct
{
    long number;
    char *name;
    char *phone;
    double salary;
}Employee, *PtrToEmployee; //struct variable name can just be employee or can be a pointer to the struct called ptrtoemployee
//this is the structure of the table

typedef const Employee *PtrToConstEmployee; //pointer of TYPE employee, so a STRUCT type pointer