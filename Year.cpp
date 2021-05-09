#include "Menu.h"
#include "Year.h"
#include "Node Process.h"
#include <direct.h>
#include <filesystem>

//Delete directory
void Delete_Directory(string dir)
{
	dir = "rmdir /s /q " + dir;
	system(dir.c_str());
}
////Create new directory contain classes//
string Create_Directory(string classes)
{
	string dir = ".\\Classes\\" + ParsePath(classes).substr(0, 9) + "\\";
	cout << "\t\t Directory path: " << dir << endl;
	// Creating a directory
	if (_mkdir(dir.c_str()) == -1)
		cerr << "\t\t Error :  " << strerror(errno) << endl;

	else
		cout << "\t\t Directory created" << endl;
	return dir;
}
////Check the existence of file//
//Input: path of file in string type
//Return: True if file is exist and false if not
bool File_Exist(string path)
{
	fstream fileInput(path);
	if (fileInput.fail()) {
		cout << "\t\t File does not exist" << endl;
		return false;
	}
	else {
		cout << "\t\t File exists" << endl;
		return true;
	}
}


////Add year into year list//
//Input: path of store file and path of year file
void Input_Years(string store, string path)
{

	path = Path_ToYear(path);
	fstream f(store, ios::app | ios::out);
	f << path << endl;
	f.close();
}
//Convert from year path to year name
string Path_ToYear(string s)
{
	int pos = s.find_last_of("\\", strlen(s.c_str()));
	return s.substr(pos + 1);
}
//Convert from year number to year file path
string Year_ToPath(int begin, int end)
{
	stringstream ss1, ss2;
	string name1, name2;
	//Transform name into year file path
	ss1 << begin; ss1 >> name1;
	ss2 << end; ss2 >> name2;
	return   ".\\Years\\" + name1 + "-" + name2 + ".csv";
}
////Create new year file with limited time//
//Input: limit of time that can be used to create
//Return: path of year file that have been created
string Create_Year(int time)
{
	int begin, end;
	string years_path;
	FILE* fileInput;

	cout << "\t\t CREATE YEAR SECTION " << endl;
	do {
		
		cout << "\t\t Created school year from: ";
		begin = Valid_Data(time);
		end = begin + 1;

		year_path = Year_ToPath(begin, end);
		
	} while (File_Exist(year_path));

	//Create new file
	fileInput = fopen(year_path.c_str(), "a+");
	fclose(fileInput);
	//Put file into store file
	Input_Years("Years.csv", year_path.c_str());

	cout << "\t\t School year created successfully" << endl;
	cout << "\t\t "; system("pause");
	return year_path;
}

////Class option //
void Class_Orientation(string classes)
{
	bool run = true;
	do {

		 run = Class_Proc_Active(Class_Menu_Disp());
		 system("cls");

	} while (run);
}
////Year orientation
void Year_Orientation(string years, int quanti)
{
	cout << "\t\t Choose year: ";
	int choice = Valid_Data(quanti);

	string classes; int i = 1;
	fstream f(years, ios::in);

	while (!f.eof()) {
		string read;
		f >> read;
		if (i++ == choice)
		{
			classes = ".\\Years\\" + read;
			Classes_Display(classes);
			Class_Orientation(classes);
			break;
		}
	}
	f.close();
}
////Classes displaying//
int Classes_Display(string classes)
{
	if (File_Exist(classes) == false)
	{
		return 0;
	}
	system("cls");
	cout << "\t\t CREATED CLASS: " << endl;
	fstream f(classes, ios::in); int i = 1;

	while (!f.eof())
	{
		string read;
		f >> read;
		if (read != "")
		{
			cout << "\t\t " << i++ << ". " << read.substr(0,6) << endl;
		}
	}
	f.close();
	return 1;
}

////Input Year from node to file after delete//
void ReInput_Year(yrs list)
{
	yr* move = list.head;
	fstream f("Years.csv", ios::in | ios::out);
	while (move->next != nullptr)
	{
		f << move->info << endl;
		move = move->next;
	}
	f.close();
}
////Year_Delete////
void Year_Delete(int quanti)
{
	cout << "\t\t Choose year: ";
	int choice = Valid_Data(quanti);

	int i = 1;
	string years_path = "Years.csv";
	stringstream ss;
	yrs list = Init_List();
	fstream f(years_path, ios::in | ios::out);
	
	while (!f.eof()) {

		//Read year file's name from "Years.csv"
		string year_path, year_name;
		f >> year_name;
		//Add year file's name into list of nodes
		year_path = ".\\Years\\" + year_name;
		yr* node = Create_Node(year_name);
		Add_Last(list, node);

		if (i++ == choice)
		{
			//Just deleted file in directory, not in Years.csv
			remove(year_path.c_str());
			//Delete in file by deleting node(s) in list
			Remove_Info(list, year_name);
			break;
		}
	}
	f.close();
	//Delete old "Years.csv" and create the new one
	remove(years_path.c_str());
	f.open(years_path.c_str(), ios::out);
	f.close();
	//Copy year's name to "Years.csv" from list
	ReInput_Year(years_path, list);

}
////Delete all years//
void Year_Clear(string years) {
	cout << "\t\t All years will be deleted !!!!" << endl;
	cout << "\t\t Are you sure ???" << endl;
	cout << "\t\t Press 0 for accepting, 1 for not:  ";
	int n; cin >> n;
	if (n == 0)
	{
		fstream f(years, ios::in | ios::out);
		int i = 1;

		while (!f.eof()) {

			string year_name,year_path;
			f >> year_name;

			//Delete files
			year_path = ".\\Years\\" + year_name;
			remove(year_path.c_str());

		}
		f.close();
		//Remake a new "Years.csv"
		remove(years.c_str());
		f.open(years.c_str(), ios::out);
		f.close();
	}
}

//Year sorting
void Year_Sort(string years)
{
	int i = 1;
	fstream f(years, ios::in | ios::out);
	stringstream ss;
	yrs list = Init_List();

	while (!f.eof())
	{
		string read;
		f >> read;
		yr* node = Init_Node(read);
		Add_Last(list, node);
	}
	f.close();
	SortAscen_List(list);
	remove(years.c_str());
	f.open(years.c_str(), ios::out);
	f.close();
	ReInput_Year(years, list);
}
////Year displaying//
int Years_Display()
{
	string years = "Years.csv";

	system("cls");
	Year_Sort(years);
	cout << "\t\t CREATED YEARS: " << endl;

	fstream f(years, ios::in);
	int i = 1;
	
	//Reading Years information from "Years.csv"
	cout << "\t\t 0. Back " << endl;
	while (!f.eof()) {
		string read;
		f >> read;
		if (read != "") {
			cout << "\t\t " << i++ << ". " << read << endl;
		}
	}
	f.close();
	return i;
}

////Process year task//
bool Year_Proc_Active(int option,int time)
{
	if (option == 1)
	{
		Create_Year(time);
		system("cls");
		return true;
	}
	else if (option == 2)
	{
		int quanti = Years_Display();
		Year_Orientation("Years.csv", quanti);
		system("cls");
		return true;
	}
	else if (option == 3)
	{
		int quanti = Years_Display();
		Year_Delete(quanti);
		system("cls");
		return true;
	}
	else if (option == 4)
	{
		Year_Clear("Years.csv");
		system("cls");
		return true;
	}
	else
	{
		cout << "\t\t EXIT" << endl;
		system("cls");
		return false;
	}
}