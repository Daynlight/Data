#include "File.h"

namespace Data {
	File::File(const std::string& path_to_file, size_t size)
		: path_to_file(path_to_file) {
		content.reserve(size);
		if (size) for (int i = 0; i < size; i++) 
			content.emplace_back(std::to_string(0));
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
		std::shared_ptr<std::string> temp = std::make_shared<std::string>("");
		if (index < content.size()) return content[index];
		return *temp;
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

	void File::save(IHash* hash) {
		std::string temp = "";

#if DATAHASHBYPARTS
		for (const std::string& el : content)
		{
			if (hash != nullptr) temp += hash->hash_function(std::string(el + DATASEPERATOR));
			else temp += std::string(el + DATASEPERATOR);
		};
#else
		for (const std::string& el : content)
			temp += el + DATASEPERATOR;
		if (hash != nullptr) temp = hash->hash_function(temp);
#endif
		
		std::fstream file(path_to_file, std::ios::out);
		file << temp;
		file.close();
	};

	void File::read(IHash* hash) {
		content.clear();

		std::fstream file(path_to_file, std::ios::in);
		std::string line = "", temp = "";

#if DATAHASHBYPARTS
		while (!file.eof()) {
			std::getline(file, line);
			if (hash != nullptr) temp += hash->un_hash_function(line);
			else temp += line;
		};
#else
		while (!file.eof()) {
			std::getline(file, line);
			temp += line;
		};
		if (hash != nullptr) temp = hash->un_hash_function(temp);
#endif

		line = "";
		for (int index = 0; index < temp.size() - DATASEPERATOR.size() + 1; index++) {
			std::string find_next_sep = temp.substr(index, DATASEPERATOR.size());
			if (find_next_sep == DATASEPERATOR) {
				content.emplace_back(line);
				line = "";
				index += DATASEPERATOR.size() - 1;
			}
			else line += temp[index];
		};

		file.close();
	};

	bool File::isDifferent(IHash* hash) {
		std::fstream file(path_to_file, std::ios::in);
		std::string temp = "", data = "";

		while (!file.eof()) {
			std::getline(file, data);
			temp += data;
		};

		if (hash != nullptr) temp = hash->un_hash_function(temp);

		data = "";
		for (const std::string& el : content)
			data += el + DATASEPERATOR;

		file.close();

		if (data != temp) return true;
		return false;
	};
};