#pragma once
#include <fstream>
#include <filesystem>
#include <vector>
#include <functional>

namespace Data
{
	static std::filesystem::path path_to_folder = std::filesystem::current_path();

	class Data {
	public:
		Data(const std::string& filename = "data.txt", const int size = 0);
		size_t Size();
		void ChangeFilename(std::string filename);
		void Push(std::string data);
		std::string Pop();
		std::string& operator[](int index);
		void Save(std::function<std::string(std::string)> hash_function = nullptr);
		void Read(std::function<std::string(std::string)> un_hash_function = nullptr);

	private:
		std::vector<std::string> content;
		std::string filename;
	};
};