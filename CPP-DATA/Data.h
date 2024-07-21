#pragma once
#include <string>
#include <filesystem>
#include <fstream>
#include <vector>
#include <functional>

namespace Data
{
	class Data {
	public:
		Data(const std::string path_to_file);
		virtual void CreateFile();
		virtual void RemoveFile();

	private:
		std::string path_to_file;
	};

	class File : public Data {
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
		bool IsDifferent(std::function<std::string(std::string)> un_hash_function = nullptr);

	private:
		std::vector<std::string> content;
		std::string path_to_file;
	};

	class Folder {

	};
};