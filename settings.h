#ifndef SETTINGS_H
#define SETTINGS_H

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <map>

//#include "constants.h"

class Settings
{
public:
    Settings(std::string file_path, std::map<std::string, std::string> config);
    ~Settings();

    int numberOfLines(std::string fileName);
    void processLines(std::string * lines, int numberOfLines);
    std::string& getElement(std::string key);

private:
    std::string m_file_path;
    std::map<std::string, std::string> m_config;
};

#endif // SETTINGS_H
