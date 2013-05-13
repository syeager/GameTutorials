#pragma once
#include "StdAfx.h"

class FileManager
{
public:
	FileManager(void);
	~FileManager(void);

	void LoadContent(const char *filename, std::vector<std::vector<std::string>> &attributes, std::vector<std::vector<std::string>> &contents);

private:
	std::vector<std::string> tempAttributes;
	std::vector<std::string> tempContents;
};

