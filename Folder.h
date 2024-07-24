#pragma once
#include "File.h"

#include <string>
#include <vector>
#include <filesystem>
#include <fstream>

namespace Data {
	class Folder {
	public:
		Folder(const std::filesystem::path& path_to_folder);
		// Get Info
		size_t count();
		bool exist();
		bool is_empty();
		std::vector<std::string> files_list();
		bool files_list_is_different();
		// Iterators
		std::vector<std::string>::iterator begin();
		std::vector<std::string>::iterator end();
		// Manage Folder
		void CreateFolder();
		void RemoveFolder();
		void FetchFilesList();
		void UpdateList();
		void Clean();
		// [Feature] Thread Update list
		// Manage Files
		void CreateFile(const std::string& file_name);
		void RemoveFile(const std::string& file_name);
		std::shared_ptr<Data::File> OpenFile(const std::string& file_name);

	private:
		std::vector<std::string> files;
		std::filesystem::path path_to_folder;
	};
};