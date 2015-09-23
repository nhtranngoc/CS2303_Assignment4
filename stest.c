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
  
  Employee bluejay; // Declare a local variable (a struct).
  bluejay.salary = 10000;
  bluejay.name = strdup("Erik Grantby"); // Make a dynamic copy.
  bluejay.starting_year = 1945;
  
  Employee nam;
  nam.salary = 9999;
  nam.name = strdup("Nam");
  nam.starting_year = 2015;

  // Output the employees to stdout.
  printEmployee(&harry);
  printEmployee(&bluejay);

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
  fclose(outfile); // Close the file

  printf("Ending program stest.\n"); 

  #ifdef DEBUG
  printf("You have crossed the DEBUG zone.\n");
  #endif

  return 0;
}

/** Prints the contents of an Employee struct to standard output.
 * @param employee Pointer to the Employee struct to print
 */
void printEmployee(Employee *employee) {
  outputEmployeeFancy(stdout, employee);
}

/** Prints the contents of an Employee struct to a stream,
 * such as an already-opened file.
 * @param stream A pointer to a FILE struct representing an already-open 
 *     stream, such as stdout, stderr, or a file.
 * @param employee Pointer to the Employee struct to print
 */
void outputEmployeeFancy(FILE *stream, Employee *employee) {
  fprintf(stream, "Employee. Name = %s, Salary = %d, Starting year = %d\n",
	  employee->name, employee->salary, employee->starting_year);
}
