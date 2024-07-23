#pragma once
#include "Hash.h"

#include <string>
#include <fstream>
#include <vector>

namespace Data {
	class File {
	public:
		File(const std::string& path_to_file = "data.txt", size_t size = 0);
		// Get Info
		size_t size();
		bool is_empty();
		bool is_different(Hash* hash = nullptr);
		// Iterators
		std::vector<std::string>::iterator begin();
		std::vector<std::string>::iterator end();
		// Manage Data
		void ChangePathToFile(const std::string& path_to_file);
		void CreateFile();
		void RemoveFile();
		void Push(const std::string& data);
		std::string Pop();
		std::string Pop(const size_t& index);
		void Remove(const size_t& index);
		std::string& operator[](const size_t& index);
		// Save and Read
		void Save(Hash* hash = nullptr);
		void Read(Hash* hash = nullptr);

	private:
		std::vector<std::string> content;
		std::string path_to_file;
	};
}