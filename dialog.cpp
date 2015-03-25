#include "dialog.h"
#include "ui_dialog.h"
#include "stickman.h"

std::map<std::string, std::string> config;

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog),
    m_background(0),
    m_stickman(0),
    m_counter(0)
//    m_config(":/config.ini", config)
{
    ui->setupUi(this);
    this->setFixedSize(1000,600);
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(nextFrame()));
    timer->start(32);

    //Load background image - CONFIG VARIABLE
    m_bg_img.load(":/Images/bg_img.jpg");

    //Load stickman sprites
    for (int i = 0; i < 7; ++i)
    {
        std::stringstream mario_frame;
        mario_frame << i+1;
        std::string mario_file;
        mario_file.append(":/Images").append("/mario").append(mario_frame.str()).append(".png");
        m_stickman_anim[i].load(mario_file.c_str());
    }
}

void Dialog::nextFrame()
{
    update();
}

void Dialog::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    m_background.render(painter, m_counter, m_bg_img);
    m_stickman.render(painter, m_counter, m_stickman_anim);
    m_counter++;

//    std::cout << config.find("size") -> second << std::endl;
}

Dialog::~Dialog()
{
    delete ui;
}
