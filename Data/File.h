#pragma once
// system
#include <string>
#include <fstream>
#include <vector>

#include "Hash.h"

const static std::string SEPERATE = "SEPERATE";

namespace Data {
	class File {
	public:
		File(const std::string& path_to_file = "data.txt", size_t size = 0);
		size_t size();
		bool isEmpty();
		bool isDifferent(i_Hash* hash = nullptr); // [FEATURE] Optimize this function
		// [FEATURE] Thread isDifferentAsync
		void changePathToFile(const std::string& path_to_file);
		void createFile();
		void removeFile();
		void push(const std::string& data);
		std::string pop();
		std::string pop(const size_t& index);
		void remove(const size_t& index);
		void save(i_Hash* hash = nullptr); // [FEATURE] simplify this function, optimize and hash whole file
		// [FEATURE] Thread saveAsync
		void read(i_Hash* hash = nullptr); // [FEATURE] simplify this function, optimize and un hash whole file
		// [FEATURE] Thread readAsync
		std::string& operator[](const size_t& index); // [FEATURE] Add for -> ptr variant
		std::string& operator[](const size_t& index); // [FEATURE] Add for -> ptr variant
		std::vector<std::string>::iterator begin();
		std::vector<std::string>::iterator end();

	private:
		std::vector<std::string> content;
		std::string path_to_file;
	};
};