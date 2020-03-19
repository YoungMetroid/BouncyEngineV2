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
		file.open("Narration.txt");
		if (!file.is_open())
		{
			throw myException();
		}
		std::string line;
		std::vector<std::string> paragraph;
		while (std::getline(file, line))
		{
			if(!line.empty() and line.find("#"))
				paragraph.push_back(line);

			if (paragraph.size() >= 3)
			{
				allLines.push_back(paragraph);
				paragraph.clear();
			}
		}
		if (paragraph.size() > 0)
			allLines.push_back(paragraph);
	}
	catch (myException & e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (std::exception& ex)
	{
		throw(ex);
	}
}
