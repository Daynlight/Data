#pragma once
#include <filesystem>
#include <fstream>
#include <string>
#include <vector>
#include "File.h"

namespace Data {
	class Folder {
	public:
		Folder(const std::filesystem::path& path_to_folder = DEFAULTPATHTOFOLDER);
		size_t count();
		bool exist();
		bool isEmpty();
		std::vector<std::string> filesList();
		bool filesListIsDifferent(); // [FEATURE] Optimize this function
		// [FEATURE] filesListIsDifferentAsync
		void createFolder();
		void removeFolder();
		void createFile(const std::string& file_name);
		void removeFile(const std::string& file_name);
		void fetchFilesList(); // [FEATURE] Optimize this function
		// [FEATURE] fetchFilesListAsync
		void updateList();
		bool fileExist(const std::string& file_name);
		std::shared_ptr<Data::File> openFile(const std::string& file_name);
		void clean();
		std::vector<std::string>::iterator begin();
		std::vector<std::string>::iterator end();

	private:
		std::vector<std::string> files;
		std::filesystem::path path_to_folder;
	};
};