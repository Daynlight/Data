#include "Data.h"

namespace Data
{
	Data::Data(const std::string path_to_file) {
		this->path_to_file = path_to_file;
	};

	void Data::CreateFile() {
		std::fstream file(path_to_file, std::ios::out);
		file.close();
	};

	void Data::RemoveFile() {
		std::remove(path_to_file.c_str());
	};

	File::File(const std::string& path_to_file, const int size)
		: Data(path_to_file), path_to_file(path_to_file)
	{
		content.reserve(size);
	};

	void File::Push(std::string data)
	{ content.emplace_back(data); };

	std::string File::Pop()
	{
		std::string temp = content[content.size() - 1];
		content.pop_back();
		return temp;
	};

	std::string& File::operator[](int index)
	{ return content[index]; };

	size_t File::Size()
	{ return content.size(); };

	void File::ChangePathToFile(const std::string& path_to_file)
	{ this->path_to_file = path_to_file; };

	void File::Read(std::function<std::string(std::string)> un_hash_function) {
		std::fstream file(path_to_file, std::ios::in);
		std::string line = "";
		std::string temp = "";
		while (!file.eof()) {
			temp = "";
			std::getline(file, line);
			if (line != "")
			{
				if (un_hash_function) line = un_hash_function(line);
				for (size_t j = 0; j < line.size(); j = j + 3)
				{
					uint8_t num = std::stoul(line.substr(j, 3));
					temp += num;
				}
				content.emplace_back(temp);
			}
		}
		file.close();
	};

	bool File::IsEmpty(){
		std::fstream file(path_to_file, std::ios::in);
		if (file.peek() == std::ifstream::traits_type::eof()) 
			return true;
		return false;
	};

	bool File::IsDifferent(std::function<std::string(std::string)> un_hash_function) {
		std::fstream file(path_to_file, std::ios::in);
		std::string line = "";
		std::string temp = "";

		size_t count = 0;

		while (!file.eof()) {
			temp = "";
			std::getline(file, line);
			if (line != "")
			{
				if (un_hash_function) line = un_hash_function(line);
				for (size_t j = 0; j < line.size(); j = j + 3)
				{
					uint8_t num = std::stoul(line.substr(j, 3));
					temp += num;
				}
				if (count >= content.size()) return true;
				if (content[count] != temp) return true;

				count++;
			}
		}
		file.close();
		return false;
	};

	void File::Save(std::function<std::string(std::string)> hash_function) {

		std::string temp = "";
		std::string line = "";
		for (int count = 0; count < content.size(); count++) {
			for (size_t j = 0; j < content[count].size(); j++)
			{
				uint8_t data = content[count][j];
				if (data < 100) line += "0";
				if (data < 10) line += "0";
				line += std::to_string(data);
			}
			if (hash_function && content[count] != "") line = hash_function(line);
			temp += line;
			if (count < content.size() - 1) temp += "\n";
		}
		temp += "\0";

		std::fstream file(path_to_file, std::ios::out);
		file << temp;
		file.close();
	};
};