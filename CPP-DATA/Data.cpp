#include "Data.h"

namespace Data
{
	Data::Data(const std::string& filename, const int size)
		: filename(filename)
	{
		content.reserve(size);
		if (!std::filesystem::exists(path_to_folder)) std::filesystem::create_directory(path_to_folder);
	};

	void Data::Push(std::string data)
	{ content.emplace_back(data); };

	std::string Data::Pop()
	{
		std::string temp = content[content.size() - 1];
		content.pop_back();
		return temp;
	};

	std::string& Data::operator[](int index)
	{ return content[index]; };

	size_t Data::Size()
	{ return content.size(); };

	void Data::ChangeFilename(std::string filename)
	{ this->filename = filename; };

	void Data::Read(std::function<std::string(std::string)> un_hash_function) {
		std::fstream file(path_to_folder.string() + "/" + filename, std::ios::in);
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

	void Data::Save(std::function<std::string(std::string)> hash_function) {

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

		std::fstream file(path_to_folder.string() + "\\" + filename, std::ios::out);
		file << temp;
		file.close();
	};
};
