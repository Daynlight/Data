#include "Data.h"

//############################################## Data ##############################################//

namespace Data
{
    Array::Array(const std::filesystem::path FilePath, const int FileSize)
    {
        //Set Size
        Size = FileSize;
        Content = new std::string[Size];

        //Create File Paths
        Path = std::filesystem::current_path() / FilePath / "";

        //Create Dir IF Not Exist
        if (!std::filesystem::exists(Path)) std::filesystem::create_directory(Path);

    }

    std::vector<std::filesystem::path> Array::List(){
        std::vector<std::filesystem::path> Temp;
        for (const auto& entry : std::filesystem::directory_iterator(Path)) Temp.push_back(entry.path());
        return Temp;
    }

    void Array::Read(const std::string FileName){
        //Create File IF Not Exist
        if (!std::filesystem::exists(Path / FileName)) {
            std::fstream Create(Path / FileName, std::ios::out);
            Create.close();
        }

        //Read File
        std::fstream FileData(Path / FileName, std::ios::in);
        std::string Line;
        for (int Count = 0; Count < Size; Count++) {
            std::getline(FileData, Line);
            Content[Count] = Line;
        }
        FileData.close();

    }

    void Array::Save(const std::string FileName) {
        //Create File IF Not Exist
        if (!std::filesystem::exists(Path / FileName)) {
            std::fstream Create(Path / FileName, std::ios::out);
            Create.close();
        }

        //Create Temp String
        std::string Temp;
        for (int Count = 0; Count < Size; Count++) {
            Temp += Content[Count] + "\n";
        }
        Temp += "\0";

        //Save Data
        std::fstream FileData(Path / FileName, std::ios::out);
        FileData << Temp;
        FileData.close();

    }

    void Array::Remove(const std::string FileName){
        std::filesystem::remove(Path / FileName);
    }

    bool Array::Exist(const std::string FileName) {
        std::fstream FileData(Path / FileName, std::ios::in);
        std::string Check;
        FileData >> Check;
        FileData.close();
        if (Check == "") return false;
        return true;

    }

    Array::~Array() {
        delete[] Content;
    }

    //############################################## Vector ##############################################//

    Vector::Vector(const std::filesystem::path FilePath, const int FileSize)
    {
        //Set Size
        Content.reserve(FileSize);

        //Create File Paths
        Path = std::filesystem::current_path() / FilePath / "";

        //Create Dir IF Not Exist
        if (!std::filesystem::exists(Path)) std::filesystem::create_directory(Path);

    }

    std::vector<std::filesystem::path> Vector::List(){
        std::vector<std::filesystem::path> Temp;
        for (const auto& entry : std::filesystem::directory_iterator(Path)) Temp.push_back(entry.path());
        return Temp;
    }

    void Vector::Read(const std::string FileName){
        //Create File IF Not Exist
        if (!std::filesystem::exists(Path / FileName)) {
            std::fstream Create(Path / FileName, std::ios::out);
            Create.close();
        }

        //Read File
        std::fstream FileData(Path / FileName, std::ios::in);
        std::string Line;
        while (!FileData.eof()) {
            std::getline(FileData, Line);
            Content.emplace_back(Line);
        }
        FileData.close();

    }

    void Vector::Save(const std::string FileName) {
        //Create File IF Not Exist
        if (!std::filesystem::exists(Path / FileName)) {
            std::fstream Create(Path / FileName, std::ios::out);
            Create.close();
        }

        //Create Temp String
        std::string Temp;
        for (int Count = 0; Count < Content.size(); Count++) {
            Temp += Content[Count] + "\n";
        }
        Temp += "\0";

        //Save Data
        std::fstream FileData(Path / FileName, std::ios::out);
        FileData << Temp;
        FileData.close();

    }

    std::string Vector::Get(const int Slot){
        if(Slot >= (Content.size() - 1)) return "";
        return Content[Slot];
    }

    void Vector::Add(const std::string Element){
        Content.emplace_back(Element);
    }

    void Vector::Change(const int Slot, const std::string Element){ //Need be Seted
        Content[Slot] = Element;
    }

    void Vector::Clear(){
        Content.clear();
    }

    void Vector::Remove(const std::string FileName){
         std::filesystem::remove(Path / FileName);
    }

    bool Vector::Exist(const std::string FileName) {
        std::fstream FileData(Path / FileName, std::ios::in);
        std::string Check;
        FileData >> Check;
        FileData.close();
        if (Check == "") return false;
        return true;

    };
};
