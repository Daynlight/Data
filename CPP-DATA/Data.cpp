#include "Data.h"

namespace Data {
	File::File(const std::string& path_to_file, const int size)
		: path_to_file(path_to_file)
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

	void File::CreateFile() {
		std::fstream file(path_to_file, std::ios::out);
		file.close();
	};

	void File::RemoveFile() {
		std::remove(path_to_file.c_str());
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



	Folder::Folder(const std::filesystem::path& path_to_folder)
		: path_to_folder(path_to_folder) {}
	
	void Folder::CreateFolder() {
		std::filesystem::create_directory(path_to_folder);
	};

	void Folder::RemoveFolder() {
		std::filesystem::remove_all(path_to_folder);
	}

	std::vector<std::string> Folder::GetFilesList() {
		return files;
	};

	void Folder::FetchFilesList() {
		files.clear();
		for (const auto& entry : std::filesystem::directory_iterator(path_to_folder))
			files.emplace_back(entry.path().filename().string());
	}

	size_t Folder::GetFilesCount() {
		return files.size();
	};

	void Folder::CreateFile(const std::string& file_name) {
		std::fstream file((path_to_folder / file_name).string(), std::ios::out);
		file.close();
	};

	void Folder::RemoveFile(const std::string& file_name) {
		std::remove((path_to_folder / file_name).string().c_str());
	};

	std::shared_ptr<Data::File> Folder::OpenFile(const std::string& file_name)
	{ return std::make_shared<File>((path_to_folder / file_name).string()); };

	void Folder::Clean(){
		RemoveFolder();
		CreateFolder();
	};

	bool Folder::Exist() 
	{ return std::filesystem::exists(path_to_folder); }
	
	bool Folder::IsEmpty() {
		if (std::filesystem::is_empty(path_to_folder)) return true;
		return false;
	};

	bool Folder::IsDifferent() {
		std::vector<std::string> temp;
		for (const auto& entry : std::filesystem::directory_iterator(path_to_folder))
			temp.emplace_back(entry.path().filename().string());
		if (temp.size() != files.size()) return true;
		for (int i = 0; i < temp.size(); i++)
			if (temp[i] != files[i]) return true;
		return false;
	};
};