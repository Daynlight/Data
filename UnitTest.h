#pragma once
#include "CPP-DATA/Data.h"
#include <iostream>
#include <filesystem>

class UnitTest {
public:
	UnitTest();

	void Folder_CreateFolderAndRemoveFolder_FolderCreatedAndRemoved(std::filesystem::path path = "data");
	void Folder_CreateAndRemoveFile_FileCreatedAndRemoved(const std::string& file_name);
	void Folder_OpenAndCloseFile_FileOpenedAndClosed(const std::string& file_name, const std::string& data);
	void Folder_Exist_ExistReturnProperValue(std::filesystem::path path = "data");
	void Folder_IsEmpty_ReturnsProperValue(std::filesystem::path path = "data");
	void Folder_GetFilesList_FilesListGot(std::vector<std::string> inner_files = { "file1.txt", "file2.txt", "file3.txt" });
	void Folder_IsDifferent_CheckIfFilesAreDifferent(std::vector<std::string> inner_files = { "file1.txt", "file2.txt", "file3.txt" }, const std::string& new_file = "file4.txt");
	void Folder_GetFilesCount_FilesCountGot(std::vector<std::string> inner_files = { "file1.txt", "file2.txt", "file3.txt" });
	void Folder_CleanFolder_FolderCleaned(std::vector<std::string> inner_files = { "file1.txt", "file2.txt", "file3.txt" });

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