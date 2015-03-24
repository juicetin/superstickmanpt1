#ifndef IOFILE_H
#define IOFILE_H

#include <iostream>
#include <cstdlib>
#include <map>

class IOFile
{
public:
    IOFile(const char *fileName, std::map<std::string, std::string> config);
    ~IOFile();

    void addElement (std::string section, std::string key, std::string value);
    void updateElement(std::string section, std::string key, std::string value);

    int numberOfLines(std::string fileName);

    void processLines (std::string *lines, int numberOfLines, std::map<std::string, std::string> config);

    std::string& getElement(std::string section, std::string key);

protected:
    std::string m_fileName;

};

#endif // IOFILE_H
