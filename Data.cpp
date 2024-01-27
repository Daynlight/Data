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

    bool Array::FolderChange()
    {
        std::vector<std::filesystem::path> Last = FileList;
        UpdateList();
        return (Last != FileList);
    };

    void Array::Read(const std::string& FileName, std::function<std::string(std::string)> UnHashFunction) {
        Create(FileName);

        std::fstream FileData(Path / FileName, std::ios::in);
        std::string Line = "";
        for (int Count = 0; Count < Size; Count++) {
            std::getline(FileData, Line);
            if (Line != "")
            {
                if (UnHashFunction) Line = UnHashFunction(Line);
                for (size_t j = 0; j < Line.size(); j = j + 3)
                {
                    uint8_t Num = std::stoul(Line.substr(j, 3));
                    Content[Count] += Num;
                }
            }
        }
        FileData.close();
    };

    void Array::Save(const std::string& FileName, std::function<std::string(std::string)> HashFunction) {
        Create(FileName);

        std::string Temp = "";
        std::string Line = "";
        for (int Count = 0; Count < Size; Count++) {
            Line = "";
            for (size_t j = 0; j < Content[Count].size(); j++)
            {
                uint8_t Data = Content[Count][j];
                if (Data < 100) Line += "0";
                if (Data < 10) Line += "0";
                Line += std::to_string(Data);
            }
            if (HashFunction && Content[Count] != "") Line = HashFunction(Line);
            Temp += Line;
            if (Count < Size - 1) Temp += "\n";
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

    bool Array::IsEmpty(const std::string FileName) {
        std::fstream FileData(Path / FileName, std::ios::in);
        std::string Check;
        FileData >> Check;
        FileData.close();
        if (Check == "") return true;
        return false;
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
    }

    bool Vector::FolderChange()
    {
        std::vector<std::filesystem::path> Last = FileList;
        UpdateList();
        return (Last != FileList);
    };

    void Vector::Read(const std::string& FileName, std::function<std::string(std::string)> UnHashFunction) {
        Create(FileName);

        std::fstream FileData(Path / FileName, std::ios::in);
        std::string Line = "";
        std::string Temp = "";
        while (!FileData.eof()) {
            Temp = "";
            std::getline(FileData, Line);
            if (Line != "")
            {
                if (UnHashFunction) Line = UnHashFunction(Line);
                for (size_t j = 0; j < Line.size(); j = j + 3)
                {
                    uint8_t Num = std::stoul(Line.substr(j, 3));
                    Temp += Num;
                }
                Content.emplace_back(Temp);
            }
        }
        FileData.close();
    };

    void Vector::Save(const std::string& FileName, std::function<std::string(std::string)> HashFunction) {
        Create(FileName);

        std::string Temp = "";
        std::string Line = "";
        for (int Count = 0; Count < Content.size(); Count++) {
            Line = "";
            for (size_t j = 0; j < Content[Count].size(); j++)
            {
                uint8_t Data = Content[Count][j];
                if (Data < 100) Line += "0";
                if (Data < 10) Line += "0";
                Line += std::to_string(Data);
            }
            if (HashFunction && Content[Count] != "") Line = HashFunction(Line);
            Temp += Line;
            if (Count < Content.size() - 1) Temp += "\n";
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

    bool Vector::IsEmpty(const std::string FileName) {
        std::fstream FileData(Path / FileName, std::ios::in);
        std::string Check;
        FileData >> Check;
        FileData.close();
        if (Check == "") return true;
        return false;
    };
};
