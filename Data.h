#pragma once
#include <fstream>
#include <filesystem>
#include <vector>

//############################################## Data ##############################################//

namespace Data
{
    //############################################## Array Format ##############################################//
    class Array {
    public:
        std::string* Content;
        std::filesystem::path Path;
        int Size = 0;

    public:
        Array(const std::filesystem::path FilePath = "Data", const int FileSize = 0);
        std::vector<std::filesystem::path> List();
        void Read(const std::string FileName);
        void Save(const std::string FileName);
        void Remove(const std::string FileName);
        bool Exist(const std::string FileName);
        ~Array();
    };

    //############################################## Vector Format ##############################################//

    class Vector {
    public:
        std::vector<std::string> Content;
        std::filesystem::path Path;

    public:
        Vector(const std::filesystem::path FilePath = "Data", const int FileSize = 0);
        std::vector<std::filesystem::path> List();
        void Read(const std::string FileName);
        void Save(const std::string FileName);
        std::string Get(const int Slot);
        void Add(const std::string Element);
        void Change(const int Slot, const std::string Element);
        void Clear();
        void Remove(const std::string FileName);
        bool Exist(const std::string FileName);
    };

};
