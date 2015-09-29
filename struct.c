#include "struct.h"

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
