#include "MainSource.h"
bool Course_Init(string& semester_path, date dmy);
int Courses_Display(string semester_path, string faculty);
bool Course_Proc(int option, string semester_path);
int Course_Select(string faculty);
string Get_Course_Path(string course_string, string faculty);
List_course get_ListCourse(string path);
int Course_Find_in_Student(string student_path, string course_name);