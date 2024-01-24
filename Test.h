#pragma once
#include "Data.h"
#include <iostream>
#include <filesystem>

class TestVector
{
public:
	void ListFiles();

private:
	Data::Vector Vector = Data::Vector("Test");
};

class TestArray
{
public:
	void ListFiles();

private:

};
