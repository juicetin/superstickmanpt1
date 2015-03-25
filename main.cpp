#include "dialog.h"
#include <QApplication>
#include "iofile.h"

#include <QImage>
#include <QLabel>

//extern std::map<std::string, std::string> config;

int main(int argc, char *argv[])
{
    std::map<std::string, std::string> config;
    IOFile file("config.ini", config);
    std::cout << config.find("size") -> second << std::endl;

    QApplication a(argc, argv);
    Dialog w;
    w.show();

    return a.exec();
}
