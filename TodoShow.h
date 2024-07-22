#pragma once
#include "CPP-DATA/Data.h"
#include <iostream>

class TodoShow
{
public:
	TodoShow();
	void Loop();
	void Add(const std::string& name);
	void Done(const int id);
	
private:
	Data::File todo_file = Data::File("ToDoShowcase.txt");
	bool running = true;
};

