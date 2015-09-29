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
  fprintf(stream, "Employee. Name = %s, Salary = %d, Starting year = %d, Department = %s\n",
	  employee->name, employee->salary, employee->starting_year, employee->department);
}


/**
 * @brief Create an employee.
 * @param salary Salary.
 * @param starting_year Starting year. 
 * @param name Name.
 * @param department Department.
 * @return Generated employee.
 */
Employee* generateEmployee(int salary, int starting_year, char* name, char* department){
    Employee * emp = (Employee*)malloc(sizeof(Employee));
    emp->salary = salary;
    emp->starting_year = starting_year;
    emp->name = strdup(name);
    emp->department = strdup(department);
    return emp;
}