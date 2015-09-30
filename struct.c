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

Employee* promptEmployee(){
	int state=0;
	char* input;

	char name[32];
	char department[50];
	int salary;
	int year;

	while(1){
		switch(state){
			case 0:
				input = readline("Please enter employee's name: ");
				if (sscanf(input, "%s", name))
					state = 1;
				else
					state = -1;
				break;

			case 1:
				free(input);
				input = readline("Please enter employee's starting year: ");
				if (sscanf(input, "%i", year)) 
					state = 2;
				else
					state = -1;
				break;

			case 2:
				free(input);
				input = readline("Please enter employee's department: ");
				if (sscanf(input, "%s", department)) 
					state = 3;
				else
					state = -1;
				break;
			case 3: 
				free(input);
				input = readline("Please enter employee's salary: ");
				if (sscanf(input, "%d", salary)) 
					break;
				else
					state = -1;
				break;
			case -1:
				printf("Sorry, please try again.\n");
				free(input);
				state = 0;
				break;
		}
	}
	return generateEmployee(salary, year, name, department);
}

void printEmployeeToFile(FILE *output, Employee *employee){
    fprintf(output, "%s %d %d %s\n",
            employee->name, employee->starting_year, employee->salary, employee->department);
}

void freeEmployee(Employee* employee){
	free(employee->name);
	free(employee->starting_year);
	free(employee->salary);
	free(employee->department);
	free(employee);
}