#include "dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog),
    m_background(0),
    m_stickman(0),
    m_counter(0)
{
    ui->setupUi(this);
    this->setFixedSize(1000,600);
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(nextFrame()));
    timer->start(32);

    //Store config variables in a map as part of a Settings class
    std::map<std::string, std::string> config;
    m_settings = new Settings(config_file, config);

    //Load background image - CONFIG VARIABLE (issues with using resources...)
    std::string bg_img_path = ":/Images/";
    bg_img_path.append(m_settings->getElement(settings_background_tag));
    m_bg_img.load(bg_img_path.c_str());

    //Load stickman sprites
    for (int i = 0; i < 7; ++i)
    {
        std::stringstream mario_frame;
        mario_frame << i+1;
        std::string mario_file;
        mario_file.append(image_resources).append("/mario").append(mario_frame.str()).append(".png");
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
    m_background.render(painter, m_counter, m_bg_img, m_settings);
    m_stickman.render(painter, m_counter, m_stickman_anim, m_settings);
    m_counter++;
}

Dialog::~Dialog()
{
    delete ui;
}
