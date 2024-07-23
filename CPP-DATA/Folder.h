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
		void CreateFolder();
		void RemoveFolder();
		void CreateFile(const std::string& file_name);
		void RemoveFile(const std::string& file_name);
		std::shared_ptr<Data::File> OpenFile(const std::string& file_name);
		void Clean();
		bool Exist();
		bool IsEmpty();
		void FetchFilesList();
		size_t GetFilesCount();
		std::vector<std::string> GetFilesList();
		bool IsDifferent();
		std::vector<std::string>::iterator begin();
		std::vector<std::string>::iterator end();

	private:
		std::vector<std::string> files;
		std::filesystem::path path_to_folder;
	};
};