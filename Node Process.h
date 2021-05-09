#pragma once
#include "Year.h"
#include "Menu.h"


struct List {
	yr* head;
	yr* tail;
};

List Init_List();
yr* Init_Node(string path);
void Add_Last(List& list, yr* node);
bool Output_List(List l);
void Remove_Info(List& list, string path);
void SortAscen_List(List& list);
