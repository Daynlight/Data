#include "Test.h"

int main() {
	TestVector VectorTest = TestVector();
	VectorTest.ListFiles();

	return 0;
}

void TestVector::ListFiles()
{
	for (size_t i = 0; i < Vector.FileList.size(); i++)
	std::cout << Vector.FileList[i].string() + "\n";
}
