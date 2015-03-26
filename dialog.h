#ifndef DIALOG_H
#define DIALOG_H

#include "background.h"
#include "stickman.h"
#include "settings.h"
//#include "iofile.h"
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
    
    Background m_background;
    Settings * m_settings;
    Stickman m_stickman;
   	
    QPixmap m_bg_img;
    QPixmap m_stickman_anim[7];
    int m_counter;
};

#endif // DIALOG_H
