#include "UnitTest.h"

UnitTest::UnitTest()
{
	std::cout << "Unit Test Started" << std::endl;

	Data_GetSize_SizeReturned(10);
	Data_GetSize_SizeReturned(0);
	Data_GetSize_SizeReturned(100);
	Data_GetSize_SizeReturned(1000);
	Data_GetSize_SizeReturned(10000);
	Data_GetSize_SizeReturned(100000);

	Data_PushData_DataPushed("Hello World!!!");
	Data_PushData_DataPushed("Witaj Świecie!!!");
	Data_PushData_DataPushed("Hallo Welt!!!");
	Data_PushData_DataPushed("Bonjour le monde!!!");
	Data_PushData_DataPushed("Hola Mundo!!!");
	Data_PushData_DataPushed("Ciao mondo!!!");
	Data_PushData_DataPushed("Привет, мир!!!");
	Data_PushData_DataPushed("こんにちは世界!!!");
	Data_PushData_DataPushed("你好，世界！！！");
	Data_PushData_DataPushed("안녕하세요 세계!!!");

	Data_PopData_DataPopped("Hello World!!!");
	Data_PopData_DataPopped("Witaj Świecie!!!");
	Data_PopData_DataPopped("Hallo Welt!!!");
	Data_PopData_DataPopped("Bonjour le monde!!!");
	Data_PopData_DataPopped("Hola Mundo!!!");
	Data_PopData_DataPopped("Ciao mondo!!!");
	Data_PopData_DataPopped("Привет, мир!!!");
	Data_PopData_DataPopped("こんにちは世界!!!");
	Data_PopData_DataPopped("你好，世界！！！");
	Data_PopData_DataPopped("안녕하세요 세계!!!");

	Data_ManageData_DataManaged("Hello", "World");
	Data_ManageData_DataManaged("Witaj", "Świecie");
	Data_ManageData_DataManaged("Hallo", " Welt");
	Data_ManageData_DataManaged("Bonjour", " le monde");
	Data_ManageData_DataManaged("Hola", "Mundo");
	Data_ManageData_DataManaged("Ciao", "Mondo");
	Data_ManageData_DataManaged("Привет", "мир");
	Data_ManageData_DataManaged("こんにちは", "世界");
	Data_ManageData_DataManaged("你好", "世界");
	Data_ManageData_DataManaged("안녕하세요", "세계");

	Data_SaveAndRead_DataSavedAndRead("Hello World!!!");
	Data_SaveAndRead_DataSavedAndRead("Witaj Świecie!!!");
	Data_SaveAndRead_DataSavedAndRead("Hallo Welt!!!");
	Data_SaveAndRead_DataSavedAndRead("Bonjour le monde!!!");
	Data_SaveAndRead_DataSavedAndRead("Hola Mundo!!!");
	Data_SaveAndRead_DataSavedAndRead("Ciao mondo!!!");
	Data_SaveAndRead_DataSavedAndRead("Привет, мир!!!");
	Data_SaveAndRead_DataSavedAndRead("こんにちは世界!!!");
	Data_SaveAndRead_DataSavedAndRead("你好，世界！！！");
	Data_SaveAndRead_DataSavedAndRead("안녕하세요 세계!!!");

	if (ran == passed)
		std::cout << "All tests passed" << std::endl;
	else
		std::cout << "Some tests failed" << std::endl;
}

void UnitTest::Data_GetSize_SizeReturned(size_t size) {
	ran++;
	// Arrange
	Data::Data data_class = Data::Data("data.txt", size);
	for (size_t i = 0; i < size; i++) {
		data_class.Push("Hello World!!!");
	}
	// Act
	size_t data_size = data_class.Size();
	// Assert
	if (data_size == size) {
		passed++;
		std::cout << "Data_GetSize_SizeReturned Passed" << std::endl;
	}
	else
		std::cout << "Data_GetSize_SizeReturned Failed" << std::endl;
}

void UnitTest::Data_PushData_DataPushed(std::string data) {
	ran++;
	// Arrange
	Data::Data data_class = Data::Data("data.txt", 0);
	if (data_class.Size() == 0) {
		// Act
		data_class.Push(data);
		// Assert
		if (data_class.Size() == 1 && data_class[data_class.Size() - 1] == data) {
			passed++;
			std::cout << "Data_PushData_DataPushed Passed" << std::endl;
		}
		else
			std::cout << "Data_PushData_DataPushed Failed" << std::endl;
	}
}

void UnitTest::Data_PopData_DataPopped(std::string data)
{
	ran++;
	// Arrange
	Data::Data data_class = Data::Data("data.txt", 0);
	data_class.Push(data);
	// Act
	std::string popped_data = data_class.Pop();
	// Assert
	if (popped_data == data && data_class.Size() == 0) {
		passed++;
		std::cout << "Data_PopData_DataPopped Passed" << std::endl;
	}
	else
		std::cout << "Data_PopData_DataPopped Failed" << std::endl;
}

void UnitTest::Data_ManageData_DataManaged(std::string data_entry, std::string data_change)
{
	ran++;
	// Arrange
	Data::Data data_class = Data::Data("data.txt", 0);
	data_class.Push(data_entry);
	// Act
	data_class[0] = data_change;
	// Assert
	if (data_class[0] == data_change) {
		passed++;
		std::cout << "Data_ManageData_DataManaged Passed" << std::endl;
	}
	else
		std::cout << "Data_ManageData_DataManaged Failed" << std::endl;
}

void UnitTest::Data_SaveAndRead_DataSavedAndRead(std::string data) {
	ran++;
	// Arrange
	Data::Data data_class = Data::Data("data.txt", 0);
	data_class.Push(data);
	// Act
	data_class.Save();
	data_class.Pop();
	data_class.Read();
	// Assert
	if (data_class.Size() == 1 && data_class[0] == data) {
		passed++;
		std::cout << "Data_SaveAndRead_DataSavedAndRead Passed" << std::endl;
	}
	else
		std::cout << "Data_SaveAndRead_DataSavedAndRead Failed" << std::endl;
}
