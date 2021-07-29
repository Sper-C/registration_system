#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <direct.h>
#include <filesystem>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;
struct date {
    int day, month, year;
};
struct TimeRange
{
	date begin, end;
};
struct Account {
    string username;
    string password;
};
struct str {
	string info;
	str* next;
};
struct strings {
	str* head;
	str* tail;
};
struct Course {
	string id,name,teacher;
	string day,session;
	int cre,capacity;
};
struct Student {
	int number;
	int id;
	string name, gender, faculty, birthdate;
	int socialID;
	Account user;
};
struct Student_node {
	Student info;
	Student_node*next;
};
struct Class {
	Student_node* head;
	Student_node* tail;
};
