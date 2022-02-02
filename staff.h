#ifndef all_h
#include<bits/stdc++.h>
#define all_h
#endif // all_h
#include"student.h"
#ifndef staff_h
class staff
{
    int employee_no;
    char name[30],department[30],pword[20];
    std::vector<Student *> students;
public:
    staff();
    void create_login();
    int check_login(char []);
    void student_operations();
    void add_student(Student *stu);
    int get_emp_no();
};
#define staff_h
#endif // staff_h
