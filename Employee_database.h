#ifndef EMPLOYEE_DATABASE_INCLUDED
#define EMPLOYEE_DATABASE_INCLUDED

#include <stdlib.h>
#include "Employee.h"

extern void add_employee(Employee*);
extern void modify_employee(Employee*);
extern void remove_employee(int id);
extern Employee* search_employee_by_name(char*);
extern Employee* search_employee_by_id(int);

#endif // EMPLOYEE_DATABASE_INCLUDED
