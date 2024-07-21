#include "UnitTest.h"

UnitTest::UnitTest() {
	std::cout << "Unit Test Started" << std::endl;

	File_GetSize_SizeReturned(10);
	File_GetSize_SizeReturned(0);
	File_GetSize_SizeReturned(100);
	File_GetSize_SizeReturned(1000);
	File_GetSize_SizeReturned(10000);
	File_GetSize_SizeReturned(100000);

	File_PushData_DataPushed("Hello World!!!");
	File_PushData_DataPushed("Witaj Świecie!!!");
	File_PushData_DataPushed("Hallo Welt!!!");
	File_PushData_DataPushed("Bonjour le monde!!!");
	File_PushData_DataPushed("Hola Mundo!!!");
	File_PushData_DataPushed("Ciao mondo!!!");

	File_PopData_DataPopped("Hello World!!!");
	File_PopData_DataPopped("Witaj Świecie!!!");
	File_PopData_DataPopped("Hallo Welt!!!");
	File_PopData_DataPopped("Bonjour le monde!!!");
	File_PopData_DataPopped("Hola Mundo!!!");
	File_PopData_DataPopped("Ciao mondo!!!");

	File_ManageData_DataManaged("Hello", "World");
	File_ManageData_DataManaged("Witaj", "Świecie");
	File_ManageData_DataManaged("Hallo", " Welt");
	File_ManageData_DataManaged("Bonjour", " le monde");
	File_ManageData_DataManaged("Hola", "Mundo");
	File_ManageData_DataManaged("Ciao", "Mondo");

	File_SaveAndRead_DataSavedAndRead("Hello World!!!");
	File_SaveAndRead_DataSavedAndRead("Witaj Świecie!!!");
	File_SaveAndRead_DataSavedAndRead("Hallo Welt!!!");
	File_SaveAndRead_DataSavedAndRead("Bonjour le monde!!!");
	File_SaveAndRead_DataSavedAndRead("Hola Mundo!!!");
	File_SaveAndRead_DataSavedAndRead("Ciao mondo!!!");

	File_FileIsDifferent_FileIsDifferentWorks("Hello", "World");
	File_FileIsDifferent_FileIsDifferentWorks("Witaj", "Świecie");
	File_FileIsDifferent_FileIsDifferentWorks("Hallo", " Welt");
	File_FileIsDifferent_FileIsDifferentWorks("Bonjour", " le monde");
	File_FileIsDifferent_FileIsDifferentWorks("Hola", "Mundo");
	File_FileIsDifferent_FileIsDifferentWorks("Ciao", "Mondo");

	File_CreateAndRemoveFile_FileCreatedAndRemoved("data.txt");
	File_CreateAndRemoveFile_FileCreatedAndRemoved("HelloThere.txt");
	File_CreateAndRemoveFile_FileCreatedAndRemoved("World.txt");
	File_CreateAndRemoveFile_FileCreatedAndRemoved("HelloWorld.txt");

	File_IsEmpty_IsEmptyWorks();

	if (ran == passed)
		std::cout << "All tests passed" << std::endl;
	else
		std::cout << "Some tests failed" << std::endl;
}

void UnitTest::File_GetSize_SizeReturned(size_t size) {
	ran++;
	// Arrange
	Data::File file_class = Data::File("data.txt", size);
	for (size_t i = 0; i < size; i++) {
		file_class.Push("Hello World!!!");
	}
	// Act
	size_t data_size = file_class.Size();
	// Assert
	if (data_size == size) {
		passed++;
		std::cout << "File_GetSize_SizeReturned Passed" << std::endl;
	}
	else
		std::cout << "File_GetSize_SizeReturned Failed" << std::endl;
}

void UnitTest::File_PushData_DataPushed(std::string data) {
	ran++;
	// Arrange
	Data::File file_class = Data::File("data.txt", 0);
	// Assert p1
	if (file_class.Size() == 0) {
		// Act p2
		file_class.Push(data);
		// Assert p2
		if (file_class.Size() == 1 && file_class[file_class.Size() - 1] == data) {
			passed++;
			std::cout << "File_PushData_DataPushed Passed" << std::endl;
		}
		else
			std::cout << "File_PushData_DataPushed Failed on p2" << std::endl;
	}
	else
		std::cout << "File_PushData_DataPushed Failed on p1" << std::endl;
};

void UnitTest::File_PopData_DataPopped(std::string data) {
	ran++;
	// Arrange
	Data::File file_class = Data::File("data.txt", 0);
	file_class.Push(data);
	// Act
	std::string popped_data = file_class.Pop();
	// Assert
	if (popped_data == data && file_class.Size() == 0) {
		passed++;
		std::cout << "File_PopData_DataPopped Passed" << std::endl;
	}
	else
		std::cout << "File_PopData_DataPopped Failed" << std::endl;
};

void UnitTest::File_ManageData_DataManaged(std::string data_entry, std::string data_change) {
	ran++;
	// Arrange
	Data::File file_class = Data::File("data.txt", 0);
	file_class.Push(data_entry);
	// Act
	file_class[0] = data_change;
	// Assert
	if (file_class[0] == data_change) {
		passed++;
		std::cout << "File_ManageData_DataManaged Passed" << std::endl;
	}
	else
		std::cout << "File_ManageData_DataManaged Failed" << std::endl;
};

void UnitTest::File_SaveAndRead_DataSavedAndRead(std::string data) {
	ran++;
	// Arrange
	Data::File file_class = Data::File("data.txt", 0);
	file_class.Push(data);
	// Act
	file_class.Save();
	file_class.Pop();
	file_class.Read();
	// Assert
	if (file_class.Size() == 1 && file_class[0] == data) {
		passed++;
		std::cout << "File_SaveAndRead_DataSavedAndRead Passed" << std::endl;
	}
	else
		std::cout << "File_SaveAndRead_DataSavedAndRead Failed" << std::endl;
	// clean up
	file_class.RemoveFile();
}

void UnitTest::File_CreateAndRemoveFile_FileCreatedAndRemoved(const std::string& filename) {
	ran++;
	// Arrange
	Data::File file_class = Data::File(filename, 0);
	// Act p1 
	file_class.CreateFile();
	// Assert p1
	if (std::filesystem::exists(filename)) {
		// Act p2
		file_class.RemoveFile();
		// Assert p2
		if (!std::filesystem::exists(filename)) {
			passed++;
			std::cout << "File_CreateAndRemoveFile_FileCreatedAndRemoved Passed" << std::endl;
		}
		else
			std::cout << "File_CreateAndRemoveFile_FileCreatedAndRemoved Failed p2" << std::endl;
	}
	else
		std::cout << "File_CreateAndRemoveFile_FileCreatedAndRemoved Failed p1" << std::endl;
	// clean up
	file_class.RemoveFile();
};

void UnitTest::File_IsEmpty_IsEmptyWorks() {
	ran++;
	// Arrange
	Data::File file_class = Data::File("data.txt", 0);
	// Act p1
	bool is_empty = file_class.IsEmpty();
	// Assert p1
	if (is_empty) {
		// Act p2
		file_class.Push("Hello World!!!");
		file_class.Save();
		is_empty = file_class.IsEmpty();
		// Assert p2
		if (!is_empty) {
			passed++;
			std::cout << "File_IsEmpty_IsEmptyWorks Passed" << std::endl;
		}
		else {
			std::cout << "File_IsEmpty_IsEmptyWorks Failed on p2" << std::endl;
		}
	}
	else
		std::cout << "File_IsEmpty_IsEmptyWorks Failed on p1" << std::endl;
	// clean up
	file_class.RemoveFile();
}

void UnitTest::File_FileIsDifferent_FileIsDifferentWorks(std::string data_entry, std::string data_change) {
	ran++;
	// Arrange
	Data::File file_class = Data::File("data.txt", 0);
	file_class.Push(data_entry);
	file_class.Save();
	// Act p1
	bool is_different = file_class.IsDifferent();
	// Assert p1
	if (!is_different) {
		// Act p2
		file_class[0] = data_change;
		is_different = file_class.IsDifferent();
		// Assert p2
		if (is_different) {
			passed++;
			std::cout << "File_FileIsDifferent_FileIsDifferentWorks Passed" << std::endl;
		}
		else {
			std::cout << "File_FileIsDifferent_FileIsDifferentWorks Failed on p2" << std::endl;
		}
	}
	else
		std::cout << "File_FileIsDifferent_FileIsDifferentWorks Failed on p1" << std::endl;
};