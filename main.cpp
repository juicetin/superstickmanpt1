#include "dialog.h"
#include <QApplication>
#include "iofile.h"

#include <QImage>
#include <QLabel>

int main(int argc, char *argv[])
{
    std::map<std::string, std::string> config;
    IOFile file("config.ini", config);

    QApplication a(argc, argv);
    Dialog w;
    w.show();

    return a.exec();
}
