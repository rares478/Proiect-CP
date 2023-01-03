#ifndef EMPLOYEE_PAY_INCLUDED
#define EMPLOYEE_PAY_INCLUDED

#include <stdlib.h>
#include "Employee.h"


extern float calculate_salary(Employee*);
extern float calculate_taxes(Employee*);
extern float calculate_bonus(Employee*);
extern void pay_employee(Employee*);
extern void print_pay();

#endif