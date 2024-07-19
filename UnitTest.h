#pragma once
#include "CPP-DATA/Data.h"
#include <iostream>
#include <filesystem>
#include <string>

class TestArray {
public:
	TestArray();
	void CheckIfFileIsNotEmptyWorking_IfFileInNotEmptyWorked();

	void CREATEFILE_FILECREATED();
	void REMOVEFILE_FILEREMOVED();
	
	void SAVEFILE_FILESAVED();
	void ReadFile();
	
	void FolderChange();
	
	void ManageData();
	void PrintData();
	void UpdateFilesList();
	void ListFiles();
	void GetSize();
	void HashTest();

private:
	unsigned int ran = 0;
	unsigned int passed = 0;
	Data::Array Array = Data::Array("Test", 10);
};

class TestVector {
public:
	TestVector();
	void Exist();
	void CreateFile();
	void RemoveFile();
	void SaveFile();
	void ReadFile();
	void FolderChange();
	void ManageData();
	void PrintData();
	void UpdateFilesList();
	void ListFiles();
	void GetSize();
	void HashTest();

private:
	unsigned int ran = 0;
	unsigned int passed = 0;
	Data::Vector Vector = Data::Vector("Test");
};