#pragma once

#include <string>
#include <iostream>
#include <conio.h>

#define ENTER_BUTT 13
#define CHAR_TO_NUM(num) (num - 49) 

using namespace std;

class MenuByList
{
	int size;
	string* list;

public: 
	MenuByList(initializer_list<string> list);
	~MenuByList();

	int getChoice(const string mName);

	static void enterPause();
};

