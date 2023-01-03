#ifndef EMPLOYEE_ATTENDANCE_INCLUDED
#define EMPLOYEE_ATTENDANCE_INCLUDED

#include <stdlib.h>
#include "Employee.h"


extern void clock_in (Employee*);
extern void clock_out(Employee*);
extern int calculate_hours_worked(Employee*);
extern void request_leave(Employee*,Date,Date);
extern void cancel_leave(Employee*);

#endif