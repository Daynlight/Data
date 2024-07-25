#include "Show.h"

// globals
const inline char* g_private_key = "MyToDo";

void ToDoShow() {
	// Init
	Data::File c_to_do_file("to_do_show.txt");
	bool running = true;
	Data::BaseHash c_hash = Data::BaseHash(g_private_key);

	// Check if file exist if not create
	if (c_to_do_file.isEmpty()) c_to_do_file.createFile();

	// Load data from file
	c_to_do_file.read(&c_hash);

	// Main app loop
	while (running) {
		// Clear terminal
		system("cls");

		// Show to do list
		std::cout << "To do: " << std::endl;
		for (int index = 0; index < c_to_do_file.size(); index++)
			std::cout << index + 1 << ". " << c_to_do_file[index] << std::endl;

		// Show Menu
		std::cout << "----------------------\n";
		std::cout 
			<< "1. Add\n" 
			<< "2. Done\n" 
			<< "3. Remove\n" 
			<< "4. Exit\n";

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
			c_to_do_file.push(name);
			break;
		case 2: // Done
			std::cout << "Chose id: ";
			std::cin >> id;
			if (id <= c_to_do_file.size()) c_to_do_file.remove(id - 1);
			break;
		case 3: // Remove
			std::cout << "Chose id: ";
			std::cin >> id;
			if (id <= c_to_do_file.size()) c_to_do_file.remove(id - 1);
			break;
		default: // Exit
			running = false;
		};

		// Save changes in file
		c_to_do_file.save(&c_hash);
	};
};