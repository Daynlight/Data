#include "TodoShow.h"

TodoShow::TodoShow()
{
	if (todo_file.IsEmpty()) todo_file.CreateFile();
	while (running)
	{
		Loop();
	};
}

void TodoShow::Loop()
{
	todo_file.Read();

	system("cls");
	
	std::cout << "ToDo: " << std::endl;
	
	for (int i = 0; i < todo_file.Size(); i++)
		std::cout << i+1 << ". " << todo_file[i] << std::endl;
	std::cout << "----------------------\n";
	std::cout << "1. Add\n" << "2. Done\n" << "3. Remove\n" << "4. Exit\n";
	int action = 0;
	std::cout << "Chose Action: ";
	std::cin >> action;
	
	if (action == 1) {
		std::string name = "";
		std::cout << "Title: ";
		std::getline(std::cin >> std::ws, name);
		Add(name);
	}
	else if (action == 2) {
		int id = 0;
		std::cout << "Chose id: ";
		std::cin >> id;
		if (id <= todo_file.Size()) Done(id - 1);
	}
	else if (action == 3) {
		int id = 0;
		std::cout << "Chose id: ";
		std::cin >> id;
		if(id <= todo_file.Size()) Done(id - 1);
	}
	else running = false;

	todo_file.Save();
}

void TodoShow::Add(const std::string& name)
{
	todo_file.Push(name);
}

void TodoShow::Done(const int id)
{
	todo_file.Pop(id);
}
