#ifndef STRUCT_H
#define STRUCT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <readline/readline.h>


// Define some structures
struct _Employee {
  int salary; // Monthly salary in UK pounds sterling
  int starting_year;
  char *name; // Pointer to character string holding name of employee.
              // MUST be dynamically allocated from the heap.
  char *department;
};

typedef struct _Employee Employee; // For convenience

// function prototypes
void printEmployee(Employee *employee);
void outputEmployeeFancy(FILE *stream, Employee *employee);
Employee* generateEmployee(int salary, int starting_year, char* name, char* department);

#endif
