#include "iofile.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <map>

IOFile::IOFile(const char *fileName, std::map<std::string, std::string> config) : m_fileName(fileName)
{
    std::string line;
    std::string *lines = new std::string[numberOfLines(m_fileName.c_str())];
    int index = 0;
    std::ifstream inputStream;
    inputStream.open(m_fileName.c_str());
    if (inputStream.is_open())
    {
        while (getline(inputStream, line))
        {
            lines[index++] = line;
        }
        inputStream.close();
    }
    processLines(lines, numberOfLines(m_fileName), config);
    delete[] lines;
}

int IOFile::numberOfLines(std::string fileName)
{
    int numberOfLines = 0;
    std::string line;
    std::ifstream file(fileName.c_str());

    while (std::getline(file, line))
        numberOfLines++;

    return numberOfLines;
}

void IOFile::processLines (std::string *lines, int numberOfLines, std::map<std::string, std::string> config)
{
    for (int i = 0; i < numberOfLines; ++i)
    {
        std::string key = lines[i].substr(0, lines[i].find("="));
        std::string value = lines[i].substr(lines[i].find("=")+1, lines[i].length()-1);
        config.insert(std::pair<std::string, std::string> (key, value));
    }


}

std::string& getElement(std::string section, std::string key)
{

}

IOFile::~IOFile()
{

}

