#include "Show.h"

void TodoShow()
{
	// Init
	Data::File todo_file("todo.txt");
	bool running = true;

	// Check if file exist if not create
	if (todo_file.IsEmpty()) todo_file.CreateFile();

	// Load data from file
	todo_file.Read();

	// Main app loop
	while (running) {
		// Clear terminal
		system("cls");

		// Show todo list
		std::cout << "Todo: " << std::endl;
		for (int i = 0; i < todo_file.Size(); i++)
			std::cout << i + 1 << ". " << todo_file[i] << std::endl;

		// Show Menu
		std::cout << "----------------------\n";
		std::cout << "1. Add\n" << "2. Done\n" << "3. Remove\n" << "4. Exit\n";

		// Get user action
		int action = 0;
		std::cout << "Chose Action: ";
		std::cin >> action;

		// Run user action
		std::string name = "";
		int id = 0;
		switch (action)
		{
		case 1: // Add
			std::cout << "Title: ";
			std::getline(std::cin >> std::ws, name);
			todo_file.Push(name);
			break;
		case 2: // Done
			std::cout << "Chose id: ";
			std::cin >> id;
			if (id <= todo_file.Size()) todo_file.Pop(id - 1);
			break;
		case 3: // Remove
			std::cout << "Chose id: ";
			std::cin >> id;
			if (id <= todo_file.Size()) todo_file.Pop(id - 1);
			break;
		default: // Exit
			running = false;
		};

		// Save changes in file
		todo_file.Save();
	};
};