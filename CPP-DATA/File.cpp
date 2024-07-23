#include "File.h"

namespace Data {
	File::File(const std::string& path_to_file, const int size)
		: path_to_file(path_to_file) {
		content.reserve(size);
	};

	void File::Push(const std::string& data) {
		content.emplace_back(data);
	};

	std::string File::Pop() {
		std::string temp = content[content.size() - 1];
		content.pop_back();
		return temp;
	};

	std::string File::Pop(const int& index) {
		std::string temp = content[index];
		content.erase(content.begin() + index);
		return temp;
	};

	void File::Remove(const int& index) {
		content.erase(content.begin() + index);
	};

	std::string& File::operator[](const int& index) {
		return content[index];
	};

	size_t File::size() {
		return content.size();
	};

	void File::ChangePathToFile(const std::string& path_to_file) {
		this->path_to_file = path_to_file;
	};

	void File::Read(std::function<std::string(std::string)> un_hash_function) {
		content.clear();

		std::fstream file(path_to_file, std::ios::in);
		std::string line = "", temp = "";

		while (!file.eof()) {
			temp = "";
			std::getline(file, line);

			if (line != "") {
				if (un_hash_function) line = un_hash_function(line);
				for (size_t j = 0; j < line.size(); j = j + 3) {
					uint8_t line_char = std::stoul(line.substr(j, 3));
					temp += line_char;
				};
				content.emplace_back(temp);
			};
		};
		file.close();
	};

	bool File::is_empty() {
		std::fstream file(path_to_file, std::ios::in);
		if (file.peek() == std::ifstream::traits_type::eof()) return true;
		return false;
	};

	void File::CreateFile() {
		std::fstream file(path_to_file, std::ios::out);
		file.close();
	};

	void File::RemoveFile() {
		std::remove(path_to_file.c_str());
	};

	bool File::is_different(std::function<std::string(std::string)> un_hash_function) {
		std::fstream file(path_to_file, std::ios::in);
		std::string line = "", temp = "";
		size_t count = 0;

		while (!file.eof()) {
			temp = "";
			std::getline(file, line);

			if (line != "") {
				if (un_hash_function) line = un_hash_function(line);
				for (size_t j = 0; j < line.size(); j = j + 3) {
					uint8_t line_char = std::stoul(line.substr(j, 3));
					temp += line_char;
				};

				if (count >= content.size()) return true;
				if (content[count] != temp) return true;

				count++;
			};
		};
		file.close();
		return false;
	}

	std::vector<std::string>::iterator File::begin() {
		return content.begin();
	};

	std::vector<std::string>::iterator File::end() {
		return content.end();
	};

	void File::Save(std::function<std::string(std::string)> hash_function) {
		std::string line = "", temp = "";

		for (int count_content = 0; count_content < content.size(); count_content++) {
			for (const uint8_t& data : content[count_content]) {
				if (data < 100) line += "0";
				if (data < 10) line += "0";
				line += std::to_string(data);
			};

			if (hash_function && content[count_content] != "") line = hash_function(line);

			temp += line;
			line = "";

			if (count_content < content.size() - 1) temp += "\n";
		};
		temp += "\0";

		std::fstream file(path_to_file, std::ios::out);
		file << temp;
		file.close();
	};
}