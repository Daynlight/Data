#include "Scripts.h"

//############################################## Data ##############################################//

Data::Data(const int FileSize, const std::string FileName, const std::string FilePath)
{
    //Set Size
    Size = FileSize;
    Content = new std::string[Size];

    //Create File Paths
    Path = std::filesystem::current_path() / FilePath / FileName;

    //Create File IF Not Exist
    if(!std::filesystem::exists(Path)){
        std::filesystem::create_directory(Path.parent_path());
        std::fstream Create(Path, std::ios::out);
        Create.close();
    }

    //Read File
    std::fstream FileData(Path, std::ios::in);
    std::string Line;
    for(int Count = 0; Count < Size; Count++){
        std::getline(FileData, Line);
        Content[Count] = Line;
    }
    FileData.close();

}

void Data::Save(){
    //Create Temp String
    std::string Temp;
    for(int Count = 0; Count < Size; Count++){
        Temp += Content[Count]  + "\n";
    }
    Temp += "\0";

    //Save Data
    std::fstream FileData(Path, std::ios::out);
    FileData << Temp;
    FileData.close();

}

void Data::Add(const int Slot, const std::string Element){
    Content[Slot] = Element;
}

bool Data::Exist(){
    std::fstream FileData(Path, std::ios::in);
    std::string Check;
    FileData >> Check;
    FileData.close();
    if(Check == "") return false;
    return true;

}

Data::~Data(){
    delete[] Content;
}