#include "Employee_database.h"
#include "Employee_attendance.h"
#include "Employee_pay.h"
#include "Employee_performance.h"
#include "Employee.h"
#include <stdio.h>


int main() {
    Employee* e = search_employee_by_id(1);


    give_bonus(e, 25.0);

    return 0;
}