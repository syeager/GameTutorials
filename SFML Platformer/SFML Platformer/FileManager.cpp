#include "StdAfx.h"



FileManager::FileManager(void)
{
}


FileManager::~FileManager(void)
{
}


enum LoadState {Attributes, Contents};
int state;


void FileManager::LoadContent(const char *filename, std::vector<std::vector<std::string>> &attributes, std::vector<std::vector<std::string>> &contents)
{
	attributes.clear();
	contents.clear();

	std::ifstream openfile(filename);
	if (openfile.is_open())
	{
		while (!openfile.eof())
		{
			std::string line;
			std::getline(openfile, line);

			line.erase(std::remove(line.begin(), line.end(), ' '), line.end());

			if (line.find("Load=") != std::string::npos)
			{
				state = Attributes;
				line.erase(0, line.find('=')+1);
				tempAttributes.clear();
			}
			else
			{
				state = Contents;
				tempContents.clear();
			}

			line.erase(std::remove(line.begin(), line.end(), '['));

			std::stringstream str(line);

			while (str)
			{
				std::getline(str, line, ']');
				if (line != "")
				{
					if (state == Attributes)
					{
						tempAttributes.push_back(line);
					}
					else
					{
						tempContents.push_back(line);
					}
					std::cout << line << std::endl;
				}
			}

			if (state == Contents && tempContents.size() > 0)
			{
				attributes.push_back(tempAttributes);
				contents.push_back(tempContents);
			}
		}
	}
	else
	{

	}
} // end LoadContent


void FileManager::LoadContent(const char *filename, std::vector<std::vector<std::string>> &attributes, std::vector<std::vector<std::string>> &contents,	std::string id)
{
	attributes.clear();
	contents.clear();
	idFound = false;

	std::ifstream openfile(filename);
	if (openfile.is_open())
	{
		while (!openfile.eof())
		{
			std::string line;
			std::getline(openfile, line);

			line.erase(std::remove(line.begin(), line.end(), ' '), line.end());

			if (line.find("Start=[" + id + "]") != std::string::npos)
			{
				idFound = true;
				continue;
			}
			else if (line.find("End=") != std::string::npos && line.find(id) != std::string::npos)
			{
				idFound = false;
				break;
			}


			if (idFound)
			{
				if (line.find("Load=") != std::string::npos)
				{
					state = Attributes;
					line.erase(0, line.find('=')+1);
					tempAttributes.clear();
				}
				else
				{
					state = Contents;
					tempContents.clear();
				}

				line.erase(std::remove(line.begin(), line.end(), '['));

				std::stringstream str(line);

				while (str)
				{
					std::getline(str, line, ']');
					if (line != "")
					{
						if (state == Attributes)
						{
							tempAttributes.push_back(line);
						}
						else
						{
							tempContents.push_back(line);
						}
						std::cout << line << std::endl;
					}
				}

				if (state == Contents && tempContents.size() > 0)
				{
					attributes.push_back(tempAttributes);
					contents.push_back(tempContents);
				}
			}
		}
	}
	else
	{

	}
} // end LoadContent
