#pragma once
#include <filesystem>
#include <fstream>

//############################################## Data ##############################################//

class Data
{
public:
    std::string* Content;
    std::filesystem::path Path;
    int Size = 0;

public:
    Data(const int FileSize, const std::string FileName, const std::string FilePath = "Data/");
    void Save();
    void Add(const int Slot, const std::string Element);
    bool Exist();
    ~Data();

};
