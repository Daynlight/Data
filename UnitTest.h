#pragma once
#include "CPP-DATA/Data.h"
#include <iostream>
#include <filesystem>

class UnitTest {
public:
	UnitTest();
	void File_GetSize_SizeReturned(size_t size = 3);
	void File_PushData_DataPushed(std::string data = "Hello World!!!");
	void File_PopData_DataPopped(std::string data = "Hello World!!!");
	void File_ManageData_DataManaged(std::string data_entry = "Hello", std::string data_change = "World");
	void File_SaveAndRead_DataSavedAndRead(std::string data = "Hello World!!!");
	void File_CreateAndRemoveFile_FileCreatedAndRemoved(const std::string& filename);
	void File_IsEmpty_IsEmptyWorks();
	void File_FileIsDifferent_FileIsDifferentWorks(std::string data_entry = "Hello", std::string data_change = "World");

private:
	unsigned int ran = 0;
	unsigned int passed = 0;
};