#ifndef STRUCT_H
#define STRUCT_H

// Define some structures
struct _Employee {
  int salary; // Monthly salary in UK pounds sterling
  int starting_year;
  char *name; // Pointer to character string holding name of employee.
              // MUST be dynamically allocated from the heap.
};

typedef struct _Employee Employee; // For convenience

// function prototypes
void printEmployee(Employee *employee);
void outputEmployeeFancy(FILE *stream, Employee *employee);

#endif
