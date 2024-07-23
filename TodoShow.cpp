#include "Show.h"

const inline char* private_key = "MyToDo";

void ToDoShow() {
	// Init
	Data::File to_do_file("to_do.txt");
	bool running = true;
	Data::BaseHash hash = Data::BaseHash(private_key);

	// Check if file exist if not create
	if (to_do_file.is_empty()) to_do_file.CreateFile();

	// Load data from file
	to_do_file.Read(&hash);

	// Main app loop
	while (running) {
		// Clear terminal
		system("cls");

		// Show to do list
		std::cout << "To do: " << std::endl;
		for (int i = 0; i < to_do_file.size(); i++)
			std::cout << i + 1 << ". " << to_do_file[i] << std::endl;

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
			to_do_file.Push(name);
			break;
		case 2: // Done
			std::cout << "Chose id: ";
			std::cin >> id;
			if (id <= to_do_file.size()) to_do_file.Remove(id - 1);
			break;
		case 3: // Remove
			std::cout << "Chose id: ";
			std::cin >> id;
			if (id <= to_do_file.size()) to_do_file.Remove(id - 1);
			break;
		default: // Exit
			running = false;
		};

		// Save changes in file
		to_do_file.Save(&hash);
	};
};