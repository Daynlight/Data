#include "File.h"

namespace Data {
	File::File(const std::string& path_to_file, size_t size)
		: path_to_file(path_to_file) {
		content.reserve(size);
	};

	void File::push(const std::string& data) {
		content.emplace_back(data);
	};

	std::string File::pop() {
		std::string temp = content[content.size() - 1];
		content.pop_back();
		return temp;
	};

	std::string File::pop(const size_t& index) {
		std::string temp = content[index];
		content.erase(content.begin() + index);
		return temp;
	};

	void File::remove(const size_t& index) {
		content.erase(content.begin() + index);
	};

	std::string& File::operator[](const size_t& index) {
		return content[index];
	};

	size_t File::size() {
		return content.size();
	};

	void File::changePathToFile(const std::string& path_to_file) {
		this->path_to_file = path_to_file;
	};

	bool File::isEmpty() {
		std::fstream file(path_to_file, std::ios::in);
		if (file.peek() == std::ifstream::traits_type::eof()) return true;
		return false;
	};

	void File::createFile() {
		std::fstream file(path_to_file, std::ios::out);
		file.close();
	};

	void File::removeFile() {
		std::remove(path_to_file.c_str());
	};

	std::vector<std::string>::iterator File::begin() {
		return content.begin();
	};

	std::vector<std::string>::iterator File::end() {
		return content.end();
	};

	void File::save(i_Hash* hash) {
		std::string line = "", temp = "";

		for (int count_content = 0; count_content < content.size(); count_content++) {
			for (const uint8_t& data : content[count_content]) {
				if (data < 100) line += "0";
				if (data < 10) line += "0";
				line += std::to_string(data);
			};

			if (hash && content[count_content] != "") line = hash->hash_function(line);

			temp += line;
			line = "";

			if (count_content < content.size() - 1) temp += "\n";
		};
		temp += "\0";

		std::fstream file(path_to_file, std::ios::out);
		file << temp;
		file.close();
	};

	void File::read(i_Hash* hash) {
		content.clear();

		std::fstream file(path_to_file, std::ios::in);
		std::string line = "", temp = "";

		while (!file.eof()) {
			temp = "";
			std::getline(file, line);

			if (line != "") {
				if (hash) line = hash->un_hash_function(line);
				for (size_t count_char = 0; count_char < line.size(); count_char = count_char + 3) {
					uint8_t line_char = 0;
					try {
						line_char = std::stoul(line.substr(count_char, 3));
					}
					catch (std::exception e) {
						line_char = 0;
					};
					temp += line_char;
				};
				content.emplace_back(temp);
			};
		};
		file.close();
	};

	bool File::isDifferent(i_Hash* hash) {
		std::fstream file(path_to_file, std::ios::in);
		std::string line = "", temp = "";
		size_t count = 0;

		while (!file.eof()) {
			temp = "";
			std::getline(file, line);

			if (line != "") {
				if (hash) line = hash->un_hash_function(line);
				for (size_t count_char = 0; count_char < line.size(); count_char = count_char + 3) {
					uint8_t line_char = 0;
					try {
						line_char = std::stoul(line.substr(count_char, 3));
					}
					catch (std::exception e) {
						line_char = 0;
					};
					temp += line_char;
				};

				if (count >= content.size()) return true;
				if (content[count] != temp) return true;

				count++;
			};
		};
		file.close();
		return false;
	};
};