#include "Data.h"

namespace Data
{
    //############################################## Array ##############################################//

    Array::Array(const std::filesystem::path Path, const int Size)
        :Path(std::filesystem::current_path() / Path / ""), Size(Size), Content(new std::string[Size])
    {
        if (!std::filesystem::exists(Path)) std::filesystem::create_directory(Path);
        UpdateList();
    }

    Array::~Array() { delete[] Content; }

    void Array::UpdateList() { 
        FileList.clear();
        for (const std::filesystem::directory_entry& element : std::filesystem::directory_iterator(Path)) 
            FileList.push_back(element.path());
    };

    void Array::Read(const std::string& FileName) {
        Create(FileName);

        std::fstream FileData(Path / FileName, std::ios::in);
        std::string Line;
        for (int Count = 0; Count < Size; Count++) {
            std::getline(FileData, Line);
            Content[Count] = Line;
        }
        FileData.close();
    };

    void Array::Save(const std::string& FileName) {
        Create(FileName);

        std::string Temp;
        for (int Count = 0; Count < Size; Count++) {
            Temp += Content[Count] + "\n";
        }
        Temp += "\0";

        std::fstream FileData(Path / FileName, std::ios::out);
        FileData << Temp;
        FileData.close();
    }

    void Array::Create(const std::string& FileName) {
        if (!std::filesystem::exists(Path / FileName)) {
            std::fstream Create(Path / FileName, std::ios::out);
            Create.close();
        };
    };

    void Array::Remove(const std::string& FileName) {
        std::filesystem::remove(Path / FileName);
    };

    bool Array::Exist(const std::string& FileName) {
        std::fstream FileData(Path / FileName, std::ios::in);
        std::string Check;
        FileData >> Check;
        FileData.close();
        if (Check == "") return false;
        return true;
    };

    //############################################## Vector ##############################################//

    Vector::Vector(const std::filesystem::path FilePath, const int FileSize)
        :Path(std::filesystem::current_path() / FilePath / "")
    {
        Content.reserve(FileSize);

        if (!std::filesystem::exists(Path)) std::filesystem::create_directory(Path);

        UpdateList();
    };

    void Vector::UpdateList() { 
        FileList.clear();
        for (const std::filesystem::directory_entry& element : std::filesystem::directory_iterator(Path))  
        FileList.push_back(element.path());
    };

    void Vector::Read(const std::string& FileName) {
        Create(FileName);

        std::fstream FileData(Path / FileName, std::ios::in);
        std::string Line;
        while (!FileData.eof()) {
            std::getline(FileData, Line);
            Content.emplace_back(Line);
        }
        FileData.close();
    };

    void Vector::Save(const std::string& FileName) {
        Create(FileName);

        std::string Temp;
        for (int Count = 0; Count < Content.size(); Count++) {
            Temp += Content[Count] + "\n";
        }
        Temp += "\0";

        std::fstream FileData(Path / FileName, std::ios::out);
        FileData << Temp;
        FileData.close();
    };

    void Vector::Create(const std::string& FileName){
        if (!std::filesystem::exists(Path / FileName)) {
            std::fstream Create(Path / FileName, std::ios::out);
            Create.close(); 
        }
    };

    void Vector::Remove(const std::string& FileName) { 
        std::filesystem::remove(Path / FileName); 
    };

    bool Vector::Exist(const std::string& FileName) {
        std::fstream FileData(Path / FileName, std::ios::in);
        std::string Check;
        FileData >> Check;
        FileData.close();
        if (Check == "") return false;
        return true;
    };
};
