#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include "Menu.h"
#include <sstream>
#include <fstream>

struct yr {
	string path;
	yr* next;
};

bool File_Exist(string path);
//Create year section
void Input_Year(string store, string path);
string Create_Year(int time);
//Path Parsing
string ParsePath(string s);


