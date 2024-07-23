#pragma once
#include <string>
#include <fstream>
#include <vector>
#include <functional>

namespace Data {
	class File {
	public:
		File(const std::string& path_to_file = "data.txt", const int size = 0);
		// Get Info
		size_t size();
		std::vector<std::string>::iterator begin();
		std::vector<std::string>::iterator end();
		bool is_empty();
		bool is_different(std::function<std::string(std::string)> un_hash_function = nullptr);
		// Manage Data
		void ChangePathToFile(const std::string& path_to_file);
		void CreateFile();
		void RemoveFile();
		void Push(const std::string& data);
		std::string Pop();
		std::string Pop(const int& index);
		void Remove(const int& index);
		std::string& operator[](const int& index);
		// Save and Read
		void Save(std::function<std::string(std::string)> hash_function = nullptr);
		void Read(std::function<std::string(std::string)> un_hash_function = nullptr);

	private:
		std::vector<std::string> content;
		std::string path_to_file;
	};
}