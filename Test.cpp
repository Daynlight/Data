#include "Test.h"

int main() {
	TestArray ArrayTest = TestArray();
	TestVector VerctorTest = TestVector();

	VerctorTest.ShowAll();
	ArrayTest.ShowAll();

	return 0;
}

void TestArray::ShowAll()
{
	Exist();
	GetSize();
	FolderChange();
	CreateFile();
	RemoveFile();
	SaveFile();
	ReadFile();
	ManageData();
	PrintData();
	UpdateFilesList();
	HashTest();
}

void TestVector::ShowAll()
{
	Exist();
	GetSize();
	FolderChange();
	CreateFile();
	RemoveFile();
	SaveFile();
	ReadFile();
	ManageData();
	PrintData();
	UpdateFilesList();
	HashTest();
}

void TestArray::Exist()
{
	std::cout << "\n------------ Check Exist ------------\n";

	std::cout << "File Test1 Exist condition " << Array.IsEmpty("Test1") << "\n";

	Array.Create("TestExist");
	std::cout << "File Test1 Exist condition " << Array.IsEmpty("Test1") << "\n";

	Array.Content[0] = "Test1";
	Array.Save("TestExist");
	std::cout << "File Test1 Exist condition " << Array.IsEmpty("Test1") << "\n";

	Array.Remove("TestExist");
}

void TestArray::CreateFile()
{
	std::cout << "\n------------ TestCreate ------------\n";

	Array.Create("Test");

	std::cout << "Created Test\n";
}

void TestArray::RemoveFile()
{
	std::cout << "\n------------ TestRemove ------------\n";

	Array.Remove("Test");

	std::cout << "Removed Test\n";
}

void TestArray::SaveFile()
{
	std::cout << "\n------------ TestSave ------------\n";

	Array.Content[0] = "Test";
	Array.Content[2] = "Test2";
	Array.Save("Test");

	std::cout << "Saved to Test\n";
}

void TestArray::ReadFile()
{
	std::cout << "\n------------ TestRead ------------\n";
	PrintData();

	Array.Content[0] = "Test";
	Array.Content[2] = "Test2";
	Array.Content[5] = "£";
	std::cout << "£";
	Array.Save("Test");
	PrintData();
	std::cout << "Saved\n";

	for (size_t i = 0; i < Array.Size; i++)
	{
		Array.Content[i] = "";
	}

	std::cout << "Cleared\n";
	PrintData();

	Array.Read("Test");

	std::cout << "Readed from Test\n";
	PrintData();
}

void TestArray::FolderChange()
{
	std::cout << "\n------------ FolderChange ------------\n";

	std::cout << Array.FolderChange() << "\n";
	Array.Create("Test5");
	std::cout << Array.FolderChange() << "\n";
	Array.Remove("Test5");
	std::cout << Array.FolderChange() << "\n";
}

void TestArray::ManageData()
{
	std::cout << "\n------------ TestManage ------------\n";

	Array.Content[0] = "A";
	Array.Content[1] = "A";
	Array.Content[2] = "A";

	std::cout << Array.Content[0];
	std::cout << Array.Content[1];
	std::cout << Array.Content[2];
}

void TestArray::PrintData()
{
	std::cout << "\n------------ PrintData ------------\n";
	for (size_t i = 0; i < Array.Size; i++)
	{
		std::cout << i << " " << Array.Content[i] << "\n";
	};
}

void TestArray::UpdateFilesList()
{
	std::cout << "\n------------ UpdateFilesList ------------\n";
	Array.UpdateList();
	ListFiles();
	Array.Create("Test3");
	ListFiles();
	Array.Remove("Test3");
}

void TestArray::ListFiles()
{
	std::cout << "\n------------ PrintFilesList ------------\n";
	for (size_t i = 0; i < Array.FileList.size(); i++)
	{
		std::cout << Array.FileList[i].string() << "\n";
	};
}

void TestArray::GetSize()
{
	std::cout << "\n------------ GetSize ------------\n";
	std::cout << "Size: " << Array.Size << "\n";
}

std::string Hash(std::string Data) {
	for (size_t i = 0; i < Data.size(); i++)
	{
		Data[i] = Data[i] * 2;
	}
	return Data;
}

std::string UnHash(std::string Data) {
	for (size_t i = 0; i < Data.size(); i++)
	{
		Data[i] = Data[i] / 2;
	}
	return Data;
}

void TestArray::HashTest()
{
	std::cout << "\n------------ Hash Test ------------\n";
	Array.Content[0] = "Test";
	Array.Content[4] = "Test2";
	Array.Content[7] = "£";
	std::cout << "\n------------ Data ------------\n";
	PrintData();
	Array.Save("TestHash", &Hash);
	
	for (size_t i = 0; i < Array.Size; i++)
	Array.Content[i] = "";

	std::cout << "\n------------ Cleared ------------\n";
	PrintData();

	std::cout << "\n------------ Cleared ------------\n";
	Array.Read("TestHash", &UnHash);
	PrintData();
}

void TestVector::HashTest()
{
	std::cout << "\n------------ Hash Test ------------\n";
	Vector.Content.emplace_back("Test");
	Vector.Content.emplace_back("Test2");
	Vector.Content.emplace_back("£");

	std::cout << "\n------------ Data ------------\n";
	PrintData();
	Vector.Save("TestHash", &Hash);

	Vector.Content.clear();

	std::cout << "\n------------ Cleared ------------\n";
	PrintData();

	std::cout << "\n------------ Cleared ------------\n";
	Vector.Read("TestHash", &UnHash);
	PrintData();

}

void TestVector::Exist()
{
	std::cout << "\n------------ Check Exist ------------\n";

	std::cout << "File Test1 Exist condition " << Vector.IsEmpty("Test1") << "\n";

	Vector.Create("TestExist");
	std::cout << "File Test1 Exist condition " << Vector.IsEmpty("Test1") << "\n";

	Vector.Content.emplace_back("Test1");
	Vector.Save("TestExist");
	std::cout << "File Test1 Exist condition " << Vector.IsEmpty("Test1") << "\n";

	Vector.Remove("TestExist");
}

void TestVector::CreateFile()
{
	std::cout << "\n------------ TestCreate ------------\n";

	Vector.Create("Test");

	std::cout << "Created Test\n";
}

void TestVector::RemoveFile()
{
	std::cout << "\n------------ TestRemove ------------\n";

	Vector.Remove("Test");

	std::cout << "Removed Test\n";
}

void TestVector::SaveFile()
{
	std::cout << "\n------------ TestSave ------------\n";

	Vector.Content.emplace_back("Test");
	Vector.Save("Test");

	std::cout << "Saved to Test\n";
}

void TestVector::ReadFile()
{
	std::cout << "\n------------ TestRead ------------\n";
	PrintData();

	Vector.Content.emplace_back("Test");
	Vector.Content.emplace_back("Test2");
	Vector.Content.emplace_back("£");
	std::cout << "£";
	Vector.Save("Test");
	PrintData();
	std::cout << "Saved\n";

	Vector.Content.clear();
	

	std::cout << "Cleared\n";
	PrintData();

	Vector.Read("Test");

	std::cout << "Readed from Test\n";
	PrintData();
}

void TestVector::FolderChange()
{
	std::cout << "\n------------ FolderChange ------------\n";
	
	std::cout << Vector.FolderChange() << "\n";
	Vector.Create("Test5");
	std::cout << Vector.FolderChange() << "\n";
	Vector.Remove("Test5");
	std::cout << Vector.FolderChange() << "\n";
}

void TestVector::ManageData()
{
	std::cout << "\n------------ TestManage ------------\n";

	Vector.Content.emplace_back("A");
	Vector.Content.emplace_back("A");
	Vector.Content.emplace_back("A");

	std::cout << Vector.Content[0];
	std::cout << Vector.Content[1];
	std::cout << Vector.Content[2];
}

void TestVector::PrintData()
{
	std::cout << "\n------------ PrintData ------------\n";
	for (size_t i = 0; i < Vector.Content.size(); i++)
	{
		std::cout << i << " " << Vector.Content[i] << "\n";
	};
}

void TestVector::UpdateFilesList()
{
	std::cout << "\n------------ UpdateFilesList ------------\n";
	Vector.UpdateList();
	ListFiles();
	Vector.Create("Test3");
	ListFiles();
	Vector.Remove("Test3");
}

void TestVector::ListFiles()
{
	std::cout << "\n------------ PrintFilesList ------------\n";
	for (size_t i = 0; i < Vector.FileList.size(); i++)
	{
		std::cout << Vector.FileList[i].string() << "\n";
	};
}

void TestVector::GetSize()
{
	std::cout << "\n------------ GetSize ------------\n";
	std::cout << "Size: " << Vector.Content.size() << "\n";
}
