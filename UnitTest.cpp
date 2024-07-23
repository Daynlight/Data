#include "UnitTest.h"

UnitTest::UnitTest() {
	std::cout << "Unit Test Started" << std::endl;

	// Folder
	Folder_CreateFolderAndRemoveFolder_FolderCreatedAndRemoved("Data1");
	Folder_CreateFolderAndRemoveFolder_FolderCreatedAndRemoved("Data2");
	Folder_CreateFolderAndRemoveFolder_FolderCreatedAndRemoved("Data3");
	Folder_CreateFolderAndRemoveFolder_FolderCreatedAndRemoved("Data4");
	
	Folder_CreateAndRemoveFile_FileCreatedAndRemoved("Data1.txt");
	Folder_CreateAndRemoveFile_FileCreatedAndRemoved("Data2.txt");
	Folder_CreateAndRemoveFile_FileCreatedAndRemoved("Data3.txt");
	Folder_CreateAndRemoveFile_FileCreatedAndRemoved("Data4.txt");

	Folder_OpenFile_FileOpened("Data1.txt", "Hello World!!!");
	Folder_OpenFile_FileOpened("Data2.txt", "Witaj Świecie!!!");
	Folder_OpenFile_FileOpened("Data3.txt", "Hallo Welt!!!");
	Folder_OpenFile_FileOpened("Data4.txt", "Bonjour le monde!!!");

	Folder_Exist_ExistReturnProperValue("Data1");
	Folder_Exist_ExistReturnProperValue("Data2");
	Folder_Exist_ExistReturnProperValue("Data3");
	Folder_Exist_ExistReturnProperValue("Data4");

	Folder_IsEmpty_ReturnsProperValue("Data1");
	Folder_IsEmpty_ReturnsProperValue("Data2");
	Folder_IsEmpty_ReturnsProperValue("Data3");
	Folder_IsEmpty_ReturnsProperValue("Data4");

	Folder_GetFilesList_FilesListGot({ "file1.txt", "file2.txt", "file3.txt" });
	Folder_GetFilesList_FilesListGot({ "data1.txt", "data2.txt", "data3.txt" });
	Folder_GetFilesList_FilesListGot({ "hello1.txt", "hello2.txt", "hello3.txt" });
	Folder_GetFilesList_FilesListGot({ "world1.txt", "world2.txt", "world3.txt" });

	Folder_IsDifferent_CheckIfFilesAreDifferent({ "file1.txt", "file2.txt", "file3.txt" }, "file4.txt");
	Folder_IsDifferent_CheckIfFilesAreDifferent({ "data1.txt", "data2.txt", "data3.txt" }, "data4.txt");
	Folder_IsDifferent_CheckIfFilesAreDifferent({ "hello1.txt", "hello2.txt", "hello3.txt" }, "hello4.txt");
	Folder_IsDifferent_CheckIfFilesAreDifferent({ "world1.txt", "world2.txt", "world3.txt" }, "world4.txt");

	Folder_GetFilesCount_FilesCountGot({ "file1.txt", "file2.txt", "file3.txt" });
	Folder_GetFilesCount_FilesCountGot({ "data1.txt", "data2.txt", "data3.txt" , "data4.txt"});
	Folder_GetFilesCount_FilesCountGot({ "hello1.txt", "hello2.txt", "hello3.txt" , "hello4.txt", "hello5.txt"});
	Folder_GetFilesCount_FilesCountGot({ "world1.txt", "world2.txt", "world3.txt" , "world4.txt", "world5.txt", "world6.txt"});

	Folder_CleanFolder_FolderCleaned({ "file1.txt", "file2.txt", "file3.txt" });
	Folder_CleanFolder_FolderCleaned({ "data1.txt", "data2.txt", "data3.txt" });
	Folder_CleanFolder_FolderCleaned({ "hello1.txt", "hello2.txt", "hello3.txt" });
	Folder_CleanFolder_FolderCleaned({ "world1.txt", "world2.txt", "world3.txt" });

	// File
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

	File_PopDataAt_DataPoppedAt();

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
		std::cout << passed << "/" << ran << " All tests passed" << std::endl;
	else
		std::cout << passed << "/" << ran << " Some tests failed" << std::endl;
	
	std::cout << "Type any to continue\n";
	std::cin >> std::ws;
}

void UnitTest::File_GetSize_SizeReturned(size_t size) {
	ran++;
	// Arrange
	Data::File file_class = Data::File("data.txt", size);
	for (size_t i = 0; i < size; i++) {
		file_class.Push("Hello World!!!");
	}
	// Act
	size_t data_size = file_class.size();
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
	if (file_class.size() == 0) {
		// Act p2
		file_class.Push(data);
		std::string data1 = data;
		data = "";
		// Assert p2
		if (file_class.size() == 1 && file_class[file_class.size() - 1] == data1) {
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
	if (popped_data == data && file_class.size() == 0) {
		passed++;
		std::cout << "File_PopData_DataPopped Passed" << std::endl;
	}
	else
		std::cout << "File_PopData_DataPopped Failed" << std::endl;
}

void UnitTest::File_PopDataAt_DataPoppedAt(std::vector<std::string> data, const int id) {
	ran++;
	// Arrange
	Data::File file_class = Data::File("data.txt", 0);
	for (const std::string& d : data)
		file_class.Push(d);
	std::vector<std::string> in_data = data;
	in_data.erase(in_data.begin() + id);
	// Act
	std::string popped_data = file_class.Pop(id);
	// Assert part 1
	if (popped_data == data[id]) {
		bool same = true;
		if (in_data.size() != file_class.size()) same = false;
		for (int i = 0; i < file_class.size(); i++)
			if (file_class[i] != in_data[i]) same = false;
		if (same) {
			passed++;
			std::cout << "File_PopDataAt_DataPoppedAt Passed" << std::endl;
		}
		else
			std::cout << "File_PopDataAt_DataPoppedAt Failed on Compare" << std::endl;
	}
	else
		std::cout << "File_PopDataAt_DataPoppedAt Failed on Return" << std::endl;
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
	if (file_class.size() == 1 && file_class[0] == data) {
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
	bool is_empty = file_class.is_empty();
	// Assert p1
	if (is_empty) {
		// Act p2
		file_class.Push("Hello World!!!");
		file_class.Save();
		is_empty = file_class.is_empty();
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
	bool is_different = file_class.is_different();
	// Assert p1
	if (!is_different) {
		// Act p2
		file_class[0] = data_change;
		is_different = file_class.is_different();
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
}

void UnitTest::Folder_CreateFolderAndRemoveFolder_FolderCreatedAndRemoved(std::filesystem::path path) {
	ran++;
	// Arrange
	Data::Folder folder_class = Data::Folder(path);
	folder_class.RemoveFolder();
	// Act p1
	folder_class.CreateFolder();
	// Assert p1
	if (std::filesystem::exists(path)) {
		// Act p2
		folder_class.RemoveFolder();
		// Assert p2
		if (!std::filesystem::exists(path)) {
			passed++;
			std::cout << "Folder_CreateFolderAndRemoveFolder_FolderCreatedAndRemoved Passed" << std::endl;
		}
		else
			std::cout << "Folder_CreateFolderAndRemoveFolder_FolderCreatedAndRemoved Failed on p2" << std::endl;
	}
	else
		std::cout << "Folder_CreateFolderAndRemoveFolder_FolderCreatedAndRemoved Failed on p1" << std::endl;
};

void UnitTest::Folder_CreateAndRemoveFile_FileCreatedAndRemoved(const std::string& file_name) {
	ran++;
	// Arrange
	Data::Folder folder_class = Data::Folder("data");
	folder_class.CreateFolder();
	folder_class.RemoveFile(file_name);
	// Act p1
	folder_class.CreateFile(file_name);
	// Assert p1
	if (std::filesystem::exists("data/" + file_name)) {
		// Act p2
		folder_class.RemoveFile(file_name);
		// Assert p2
		if (!std::filesystem::exists("data/" + file_name)) {
			passed++;
			std::cout << "Folder_CreateAndRemoveFile_FileCreatedAndRemoved Passed" << std::endl;
		}
		else
			std::cout << "Folder_CreateAndRemoveFile_FileCreatedAndRemoved Failed on p2" << std::endl;
	}
	else
		std::cout << "Folder_CreateAndRemoveFile_FileCreatedAndRemoved Failed on p1" << std::endl;
	// clean up
	folder_class.RemoveFolder();
}

void UnitTest::Folder_OpenFile_FileOpened(const std::string& file_name, const std::string& data) {
	ran++;
	// Arrange
	Data::Folder folder_class = Data::Folder("data");
	folder_class.CreateFolder();
	folder_class.CreateFile(file_name);
	// Act
	std::shared_ptr<Data::File> file_class = folder_class.OpenFile(file_name);
	file_class->Push(data);
	file_class->Save();
	file_class->Pop();
	file_class->Read();
	// Assert
	if (std::filesystem::exists("data/" + file_name) && file_class->size() == 1 && (*file_class)[0] == data) {

		passed++;
		std::cout << "Folder_OpenAndCloseFile_FileOpenedAndClosed Passed" << std::endl;
	}
	else
		std::cout << "Folder_OpenAndCloseFile_FileOpenedAndClosed Failed on p1" << std::endl;
	// clean up
	
	folder_class.RemoveFolder();
}

void UnitTest::Folder_Exist_ExistReturnProperValue(std::filesystem::path path) {
	ran++;
	// Arrange
	Data::Folder folder_class = Data::Folder(path);
	folder_class.RemoveFolder();
	// Act p1
	bool exist = folder_class.Exist();
	// Assert p1
	if (!exist) {
		// Act p2
		folder_class.CreateFolder();
		exist = folder_class.Exist();
		if (exist) {
			passed++;
			std::cout << "Folder_Exist_ExistReturnProperValue Passed" << std::endl;
		}
		else {
			std::cout << "Folder_Exist_ExistReturnProperValue Failed on p2" << std::endl;
		}
	}
	else {
		std::cout << "Folder_Exist_ExistReturnProperValue Failed on p1" << std::endl;
	}
	// clean up
	folder_class.RemoveFolder();
}
void UnitTest::Folder_IsEmpty_ReturnsProperValue(std::filesystem::path path) {
	ran++;
	// Arrange
	Data::Folder folder_class = Data::Folder(path);
	folder_class.RemoveFolder();
	folder_class.CreateFolder();
	// Act p1
	bool is_empty = folder_class.IsEmpty();
	if (is_empty) {
		// Act p2
		folder_class.CreateFile("data.txt");
		is_empty = folder_class.IsEmpty();
		// Assert p2
		if (!is_empty) {
			passed++;
			std::cout << "Folder_IsEmpty_ReturnsProperValue Passed" << std::endl;
		}
		else {
			std::cout << "Folder_IsEmpty_ReturnsProperValue Failed on p2" << std::endl;
		}
	}
	else {
		std::cout << "Folder_IsEmpty_ReturnsProperValue Failed on p1" << std::endl;
	}
	// clean up
	folder_class.RemoveFolder();
}

void UnitTest::Folder_GetFilesList_FilesListGot(std::vector<std::string> inner_files) {
	ran++;
	// Arrange
	Data::Folder folder_class = Data::Folder("data");
	folder_class.RemoveFolder();
	folder_class.CreateFolder();
	sort(inner_files.begin(), inner_files.end());
	for (const std::string& file : inner_files)
		folder_class.CreateFile(file);
	// Act
	folder_class.FetchFilesList();
	std::vector<std::string> files = folder_class.GetFilesList();
	sort(files.begin(), files.end());
	// Assert
	if (files.size() == inner_files.size() && files == inner_files) {
		passed++;
		std::cout << "Folder_GetFilesList_FilesListGot Passed" << std::endl;
	}
	else
		std::cout << "Folder_GetFilesList_FilesListGot Failed" << std::endl;
	// clean up
	folder_class.RemoveFolder();
}
void UnitTest::Folder_IsDifferent_CheckIfFilesAreDifferent(std::vector<std::string> inner_files, const std::string& new_file) {
	ran++;
	// Arrange
	Data::Folder folder_class = Data::Folder("data");
	folder_class.RemoveFolder();
	folder_class.CreateFolder();
	for (const std::string& file : inner_files)
		folder_class.CreateFile(file);
	// Act p1
	folder_class.FetchFilesList();
	bool is_different = folder_class.IsDifferent();
	// Assert p1
	if (!is_different) {
		// Act p2
		folder_class.CreateFile(new_file);
		is_different = folder_class.IsDifferent();
		// Assert p2
		if (is_different) {
			passed++;
			std::cout << "Folder_IsDifferent_CheckIfFilesAreDifferent Passed" << std::endl;
		}
		else
			std::cout << "Folder_IsDifferent_CheckIfFilesAreDifferent Failed on p2" << std::endl;
	}
	else 
		std::cout << "Folder_IsDifferent_CheckIfFilesAreDifferent Failed on p1" << std::endl;
	// clean up
	folder_class.RemoveFolder();
}
void UnitTest::Folder_GetFilesCount_FilesCountGot(std::vector<std::string> inner_files) {
	ran++;
	// Arrange
	Data::Folder folder_class = Data::Folder("data");
	folder_class.RemoveFolder();
	folder_class.CreateFolder();
	for (const std::string& file : inner_files)
		folder_class.CreateFile(file);
	// Act
	folder_class.FetchFilesList();
	size_t files_count = folder_class.GetFilesCount();
	// Assert
	if (files_count == inner_files.size()) {
		passed++;
		std::cout << "Folder_GetFilesCount_FilesCountGot Passed" << std::endl;
	}
	else
		std::cout << "Folder_GetFilesCount_FilesCountGot Failed" << std::endl;
	// clean up
	folder_class.RemoveFolder();
}
void UnitTest::Folder_CleanFolder_FolderCleaned(std::vector<std::string> inner_files) {
	ran++;
	// Arrange
	Data::Folder folder_class = Data::Folder("data");
	folder_class.RemoveFolder();
	folder_class.CreateFolder();
	for (const std::string& file : inner_files)
		folder_class.CreateFile(file);
	// Act
	folder_class.Clean();
	// Aseert
	if (folder_class.IsEmpty()) {
		passed++;
		std::cout << "Folder_CleanFolder_FolderCleaned Passed" << std::endl;
	}
	else
		std::cout << "Folder_CleanFolder_FolderCleaned Failed" << std::endl;
	// clean up
	folder_class.RemoveFolder();
};