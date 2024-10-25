#include "Show.h"

const static inline std::string PASSWORD = "Hello";
const static inline std::string HASHKEY = "abacs";
const static inline std::string DEFFOLDER = "showdata";
const static inline std::string DEFFILE = "to_do_show.txt";

void ToDoShow() {
	bool running = true;
	std::string password = "";
	
	std::cout << "Password: ";
	std::cin >> password;

	if (password == PASSWORD) {
		Data::Folder folder(DEFFOLDER);
		Data::BaseHash hash(HASHKEY.c_str());
		if (!folder.exist()) folder.createFolder();

		bool file_exist = false;
		folder.fetchFilesList();
		for (std::string& el : folder)
			if (el == DEFFILE) file_exist = true;
		if (!file_exist) folder.createFile(DEFFILE);

		std::shared_ptr<Data::File> file(folder.openFile(DEFFILE));
		
		if (file->isEmpty()) {
			file->push("Welcome");
			file->save(&hash);
		};

		while (running) {
			system("cls");
			file->read(&hash);
			uint8_t action = 0;
			std::string data = "";

			for (uint8_t index = 0; index < file->size(); index++)
				std::cout << index + 1 << ". " << (*file)[index] << "\n";
				
			std::cout << "Chose Action: \n";
			std::cout << "1. Add\n";
			std::cout << "2. Remove\n";
			std::cout << "3. Exit\n";
			std::cout << "> ";
			std::cin >> action;

			switch (action) {
			case '1':
				std::cout << "> ";
				std::cin >> data;
				file->push(data);
				break;
			case '2':
				std::cout << "> ";
				std::cin >> action;
				std::cout << file->pop(action) << " removed";
				break;
			default:
				running = false;
				break;
			}

			file->save(&hash);
		};
	};
};