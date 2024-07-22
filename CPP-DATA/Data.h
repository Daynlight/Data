#pragma once
#include <string>
#include <filesystem>
#include <fstream>
#include <vector>
#include <functional>
#include <memory>

namespace Data {
	class File {
	public:
		File(const std::string& path_to_file = "data.txt", const int size = 0);
		size_t Size();
		void ChangePathToFile(const std::string& path_to_file);
		void Push(std::string data);
		std::string Pop();
		std::string& operator[](int index);
		void Save(std::function<std::string(std::string)> hash_function = nullptr);
		void Read(std::function<std::string(std::string)> un_hash_function = nullptr);
		bool IsEmpty();
		void CreateFile();
		void RemoveFile();
		bool IsDifferent(std::function<std::string(std::string)> un_hash_function = nullptr);

	private:
		std::vector<std::string> content;
		std::string path_to_file;
	};

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

	private:
		std::vector<std::string> files;
		std::filesystem::path path_to_folder;
	};
};