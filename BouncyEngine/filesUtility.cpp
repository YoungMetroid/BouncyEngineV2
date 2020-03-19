#include "filesUtility.h"

filesUtility::filesUtility()
{

}

filesUtility::filesUtility(const char* filePath)
{
	this->filePath = filePath;
}

void filesUtility::readFile()
{
	try
	{
		file.open("E:\\Narrative.txt");
		std::string line;
		std::vector<std::string> paragraph;
		while (std::getline(file, line))
		{
			
			if(!line.empty() and !line.find("#"))
				paragraph.push_back(line);

			if (paragraph.size() >= 3)
			{
				allLines.push_back(paragraph);
				paragraph.clear();
			}
		}

	}
	catch (myException ex)
	{
		throw(ex);
	}
}