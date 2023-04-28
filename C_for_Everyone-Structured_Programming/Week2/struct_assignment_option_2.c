//Option 2: Natural or Social Science Focus
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef enum department
{
    HR,
    Sales,
    Research,
    Software,
    Executive
} Dept;

typedef struct employee
{
    Dept d;
    int salary;
    unsigned int social_security;
} Employee;

void salary_generator(Employee *e);

//function to print out employee's information
void print_info(Employee e);

int main()
{
    srand(time(0));     //initialize seed for rand()
    Employee e1, e2, e3, e4, e5, e6, e7, e8, e9, e10;   //create 10 employees
    //set each of 10 employee's social security number
    e1.social_security = 123234345;
    e2.social_security = 123000345;
    e3.social_security = 123234000;
    e4.social_security = 123030305;
    e5.social_security = 103030345;
    e6.social_security = 123222333;
    e7.social_security = 123333444;
    e8.social_security = 123444555;
    e9.social_security = 132434305;
    e10.social_security = 123000000;

    //assign department to each employee object
    //and generate random salary
    e1.d = HR;
    salary_generator(&e1);
    e2.d = Sales;
    salary_generator(&e2);
    e3.d = Research;
    salary_generator(&e3);
    e4.d = Software;
    salary_generator(&e4);
    e5.d = Executive;
    salary_generator(&e5);
    e6.d = HR;
    salary_generator(&e6);
    e7.d = Sales;
    salary_generator(&e7);
    e8.d = Research;
    salary_generator(&e8);
    e9.d = Software;
    salary_generator(&e9);
    e10.d = Executive;
    salary_generator(&e10);

    //print employee's information
    print_info(e1);
    print_info(e2);
    print_info(e3);
    print_info(e4);
    print_info(e5);
    print_info(e6);
    print_info(e7);
    print_info(e8);
    print_info(e9);
    print_info(e10);
    return 0;
}

void salary_generator(Employee *e)
{
    switch(e->d)
    {
        case 0:
            e->salary = 10000 + rand() % 1000;
            break;
        case 1:
            e->salary = 12000 + rand() % 1000;
            break;
        case 2:
            e->salary = 14000 + rand() % 1000;
            break;
        case 3:
            e->salary = 16000 + rand() % 1000;
            break;
        case 4:
            e->salary = 18000 + rand() % 1000;
            break;
        default:
            e->salary = 10000;
        }
}

void print_info(Employee e)
{
    printf("Department: %d\n", e.d);
    printf("Salary: %d\n", e.salary);
    printf("Social security number: %d\n\n", e.social_security);
}