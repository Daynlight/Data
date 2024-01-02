#include "Data.h"

int main(){
    Data::Array Test = Data::Array("Data", 3);
    Test.Content[0] = "A";
    Test.Content[1] = "BA";
    Test.Content[2] = "CA";
    Test.Save("Test.txt");
    // Test.SaveBin("TestBin.txt");


}