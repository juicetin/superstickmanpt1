#ifndef DIALOG_H
#define DIALOG_H

#include "background.h"
#include "stickman.h"
#include "settings.h"
#include "ui_dialog.h"
#include "stickman.h"
#include "settings.h"
#include "constants.h"
#include "gamemap.h"

#include <QDialog>
#include <QImage>
#include <QTimer>
#include <QPainter>
#include <QPixmap>
#include <QLabel>
#include <QImage>
#include <cstdlib>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

public slots:
    void nextFrame();

protected:
    void paintEvent(QPaintEvent *event);

private:
    Ui::Dialog *ui;
    Settings * m_settings;
    GameMap m_map;
    int m_counter;

};

#endif // DIALOG_H
