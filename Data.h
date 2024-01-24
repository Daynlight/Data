#pragma once
#include <fstream>
#include <filesystem>
#include <vector>

namespace Data
{
    class Array {
    public:
        Array(const std::filesystem::path Path = "Data", const int Szie = 0);
        ~Array();
        void UpdateList();
        void Read(const std::string& FileName);
        void Save(const std::string& FileName);
        void Create(const std::string& FileName);
        void Remove(const std::string& FileName);
        bool Exist(const std::string& FileName);

        std::string* Content;
        std::filesystem::path Path;
        std::vector<std::filesystem::path> FileList;
        int Size = 0;     
    };

    class Vector {
    public:
        Vector(const std::filesystem::path FilePath = "Data", const int FileSize = 0);
        void UpdateList();
        void Read(const std::string& FileName);
        void Save(const std::string& FileName);
        void Create(const std::string& FileName);
        void Remove(const std::string& FileName);
        bool Exist(const std::string& FileName);

        std::vector<std::string> Content;
        std::filesystem::path Path;
        std::vector<std::filesystem::path> FileList;
    };
};