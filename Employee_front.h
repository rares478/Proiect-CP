#ifndef EMPLOYEE_FRONT_H_INCLUDED
#define EMPLOYEE_FRONT_H_INCLUDED

#include <stdio.h>
#include "Employee.h"

extern void add_employee_front();
extern void show_main();
extern void show_main_employee(Employee*);
extern void check_employee();
extern void show_main_admin();
extern void show_employees_on_vacation();
extern void modify_employee_front(Employee*);
extern void print_info_front(Employee*);

#endif