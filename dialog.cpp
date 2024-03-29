#include "dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog),

    m_counter(0)
{
    ui->setupUi(this);

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(nextFrame()));
    timer->start(32);

    //Store config variables in a map as part of a Settings class
    std::map<std::string, std::string> config;
    m_settings = new Settings(config_file, config);

    //Set size of game window
    this->setFixedSize(std::atoi(m_settings->getElement(window_section, config_window_width).c_str()),
                       std::atoi(m_settings->getElement(window_section, config_window_height).c_str()));

    //Create game map and objectsl
    Background background;
    Stickman stickman;
    QPixmap bg_img;
    QPixmap * stickman_animations;
    stickman_animations =
            (QPixmap*)calloc(std::atoi(m_settings->getElement(stickman_section, stickman_anim_length).c_str()), sizeof(QPixmap));

    m_map = GameMap::Builder().setBackground(background).
            setStickman(stickman).
            setBackgroundImage(bg_img).
            setStickmanAnimations(stickman_animations).
            build();

    //Load image resources
    stickman.loadSprites(stickman_animations, m_settings);
    m_map.loadBackgroundImage(m_settings);
}

void Dialog::nextFrame()
{
    update();
}

void Dialog::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    m_map.getBackground().render
            (painter,
             m_counter,
             m_map.getBackgroundImage(),
             m_settings);

    m_map.getStickman().render
            (painter,
             m_counter,
             m_map.getStickmanAnimations(),
             m_settings);

    m_counter++;
}

Dialog::~Dialog()
{
    delete ui;
    delete m_settings;
    free(m_map.getStickmanAnimations());
}
