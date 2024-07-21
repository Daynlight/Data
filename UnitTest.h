#pragma once
#include "CPP-DATA/Data.h"
#include <iostream>

class UnitTest {
public:
	UnitTest();
	void Data_GetSize_SizeReturned(size_t size = 3);
	void Data_PushData_DataPushed(std::string data = "Hello World!!!");
	void Data_PopData_DataPopped(std::string data = "Hello World!!!");
	void Data_ManageData_DataManaged(std::string data_entry = "Hello", std::string data_change = "World");
	void Data_SaveAndRead_DataSavedAndRead(std::string data = "Hello World!!!");

private:
	unsigned int ran = 0;
	unsigned int passed = 0;
};