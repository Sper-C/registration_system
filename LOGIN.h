#include"Menu.h"
#include<conio.h>
using namespace std;
struct date{
    int d,m,y;
};
// check day
bool check_leap_year(int y);
int day_in_month(int m, int y);
bool check_dmy(date dmy);
void enter_dmy(date& dmy);
// check option
int Valid_Data(int limit);
// password proccess
int enterpass();
void showpass(string& pass);
void hidepass(string& pass);
bool enterpass_proc(int option, string& psw);
bool enter_acc(string& usr, string& psw);
// count line in file csv
int count_acc_in_csv(string name);
// create account
string account(string usr, string psw);
// check account

//Login as ad
bool check_acc_ad(string usr, string psw);
bool login_as_admin(string& user, string& pass,date& dmy);
//Login as stu
bool check_acc_student(string usr, string psw);
bool login_as_student(string& user, string& pass,date& dmy);

