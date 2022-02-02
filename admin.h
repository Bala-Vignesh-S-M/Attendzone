#ifndef all_h
#include<bits/stdc++.h>
#define all_h
#endif // all_h
#include"staff.h"
#include"student.h"
#ifndef admin_h
class Admin
{
    int employee_number;
    char pword[20];
    std::vector<staff *> teachers;
    std::vector<Student *> students;
public:
    void create_login();
    int check_login(char []);
    void student_login_operations(int op);
    void staff_login_operations(int op);
    void staff_student_operations();
};
#endif // admin_h
