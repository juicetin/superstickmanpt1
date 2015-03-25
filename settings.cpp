#include "settings.h"

Settings::Settings(std::string file_path, std::map<std::string, std::string> config) : m_file_path(file_path), m_config(config)
{
	std::string line;
    std::string *lines = new std::string[numberOfLines(m_file_path.c_str())];
    int index = 0;
    std::ifstream inputStream;
    inputStream.open(m_file_path.c_str());
    if (inputStream.is_open())
    {
        while (getline(inputStream, line))
        {
            lines[index++] = line;
        }
        inputStream.close();
    }
    processLines(lines, numberOfLines(m_file_path));
    delete[] lines;
}

void Settings::processLines (std::string *lines, int numberOfLines)
{
    for (int i = 0; i < numberOfLines; ++i)
    {
    	// std::cout << 
        std::string key = lines[i].substr(0, lines[i].find("=")); 
        std::string value = lines[i].substr(lines[i].find("=")+1, lines[i].length()-1); 
        m_config.insert(std::pair<std::string, std::string> (key, value));

        // std::cout << config.find(key)-> second << std::endl; 
    }
}

int Settings::numberOfLines(std::string fileName)
{
	int numberOfLines = 0;
	std::string line;
	std::ifstream file(fileName.c_str());

	while (std::getline(file, line))
		numberOfLines++;

	return numberOfLines;
}



std::string& Settings::getElement(std::string key)
{
	return m_config.find(key)->second;
}

Settings::~Settings()
{

}

