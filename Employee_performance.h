#ifndef EMPLOYEE_PERFORMANCE_INCLUDED
#define EMPLOYEE_PERFORMANCE_INCLUDED

#include <stdlib.h>
#include "Employee.h"

extern void record_performance(Employee*, int);
extern void give_raise(Employee*, float);
extern void give_bonus(Employee*, float);

#endif