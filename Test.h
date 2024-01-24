#pragma once
#include "Data.h"
#include <iostream>
#include <filesystem>

class TestArray
{
public:
	void ShowAll();
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

private:
	Data::Array Array = Data::Array("Test", 10);
};


class TestVector
{
public:
	void ShowAll();
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

private:
	Data::Vector Vector = Data::Vector("Test");
};