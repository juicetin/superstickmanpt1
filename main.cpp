#include "dialog.h"
#include "iofile.h"
#include "settings.h"

#include <QApplication>
#include <QImage>
#include <QLabel>

//extern std::map<std::string, std::string> config;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog w;
    w.show();

    return a.exec();
}
