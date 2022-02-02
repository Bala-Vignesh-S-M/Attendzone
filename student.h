#ifndef all_h
#include<bits/stdc++.h>
#define all_h
#endif // all_h
#ifndef student_h
#include"attendances.h"
class Student
{
    int rollno;
    char name[30],pword[20];
public:
    std::vector<Attendances *> attendance;
    Student();
    void create_login();
    int check_login(char []);
    void view_attendence();
    int get_rollno();
};
#define student_h
#endif // student_h
