#ifndef all_h
#include<bits/stdc++.h>
#define all_h
#endif // all_h
#ifndef attendances_h
class Attendances
{
    int total_hours,present_hours;
    char name_of_teacher[30];
    int beg_day,beg_month,beg_year;
    int end_day,end_month,end_year;
public:
    Attendances();
    Attendances(Attendances &a);
    char *name_teacher();
    void set_name(char []);
    void set_attendance();
    void view_attendance();
};
#define attendances_h
#endif // attendances_h
