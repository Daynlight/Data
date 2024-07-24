#include "Folder.h"

namespace Data {
	Folder::Folder(const std::filesystem::path& path_to_folder)
		: path_to_folder(path_to_folder) {};

	void Folder::CreateFolder() {
		std::filesystem::create_directory(path_to_folder);
	};

	void Folder::RemoveFolder() {
		std::filesystem::remove_all(path_to_folder);
	};

	std::vector<std::string> Folder::files_list() {
		return files;
	};

	void Folder::FetchFilesList() {
		files.clear();
		for (const std::filesystem::directory_entry& entry : std::filesystem::directory_iterator(path_to_folder))
			files.emplace_back(entry.path().filename().string());
	};

	void Folder::UpdateList() {
		if (files_list_is_different()) FetchFilesList();
	};

	size_t Folder::count() {
		return files.size();
	};

	void Folder::CreateFile(const std::string& file_name) {
		std::fstream file((path_to_folder / file_name).string(), std::ios::out);
		file.close();
	};

	void Folder::RemoveFile(const std::string& file_name) {
		std::remove((path_to_folder / file_name).string().c_str());
	};

	std::shared_ptr<File> Folder::OpenFile(const std::string& file_name) {
		return std::make_shared<File>((path_to_folder / file_name).string());
	};

	void Folder::Clean() {
		RemoveFolder();
		CreateFolder();
	};

	bool Folder::exist() {
		return std::filesystem::exists(path_to_folder);
	};

	bool Folder::is_empty() {
		if (std::filesystem::is_empty(path_to_folder)) return true;
		return false;
	};

	bool Folder::files_list_is_different() {
		std::vector<std::string> temp;

		for (const std::filesystem::directory_entry& entry : std::filesystem::directory_iterator(path_to_folder))
			temp.emplace_back(entry.path().filename().string());
		
		if (temp.size() != files.size()) return true;
		for (int i = 0; i < temp.size(); i++)
			if (temp[i] != files[i]) return true;
		return false;
	};

	std::vector<std::string>::iterator Folder::begin() {
		return files.begin();
	};

	std::vector<std::string>::iterator Folder::end() {
		return files.end();
	};
};