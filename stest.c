#include <stdio.h>
#include <string.h>
#include <errno.h>
#include "struct.h"

int main() {
  printf("Starting program stest.\n"); 

  // Anybody recognize these names?
  Employee harry; // Declare a local variable (a struct).
  harry.salary = 5000;
  harry.name = strdup("Harry Palmer"); // Make a dynamic copy.
  harry.starting_year = 1960;
  harry.department = strdup("Homicide");
  
  Employee bluejay; // Declare a local variable (a struct).
  bluejay.salary = 10000;
  bluejay.name = strdup("Erik Grantby"); // Make a dynamic copy.
  bluejay.starting_year = 1945;
  bluejay.department = strdup("Pesticide");
  
  Employee nam;
  nam.salary = 9999;
  nam.name = strdup("Nam");
  nam.starting_year = 2015;
  nam.department = strdup("Logistics");

  Employee* bozhena = generateEmployee(15,1505,"Bozhena","IT");
  Employee* quilek = generateEmployee(7852,2503,"Quilek","HR");

  // Output the employees to stdout.
  printEmployee(&harry);
  printEmployee(&bluejay);
  printEmployee(&nam);
  printEmployee(bozhena);
  printEmployee(quilek);


  // Output the employees to a file.
  printf("About to write to file.\n");
  FILE *outfile = fopen("stest.txt", "w"); // Open or create file for writing
  if (outfile == NULL){
    fprintf(stderr, "Looks like you don't have permisson for that, pal.\n");
    fprintf(stderr, "In program stest.c, error number %d: ", errno);
    printf("%s\n", strerror(errno));
    return -1;
  }
  outputEmployeeFancy(outfile, &harry);
  outputEmployeeFancy(outfile, &bluejay);
  outputEmployeeFancy(outfile, &nam);
  outputEmployeeFancy(outfile, bozhena);
  outputEmployeeFancy(outfile, quilek);
  fclose(outfile); // Close the file

  printf("Ending program stest.\n"); 

  #ifdef DEBUG
  printf("You have crossed the DEBUG zone.\n");
  #endif

  return 0;
}

