#include "settings.h"

Settings::Settings(std::string file_path, std::map<std::string, std::string> config) : m_file_path(file_path), m_config(config)
{
    //Function taken out/separated to allow real-time updating by calling load
    load(file_path, config);
}

void Settings::load(std::string file_path, std::map<std::string, std::string> config)
{
    std::string line;
    int num_lines = numberOfLines(m_file_path.c_str());
    std::string *lines = new std::string[num_lines];
    int index = 0;
    std::ifstream inputStream;
    inputStream.open(m_file_path.c_str());

    //File exists
    if (!inputStream.is_open())
    {
        //Generate a file with default values
        std::ofstream config(m_file_path.c_str());

        config << "[Window]" << std::endl;
        config << config_window_height << "=700" << std::endl;
        config << config_window_width << "=1200" << std::endl << std::endl;
        config << "[Gameworld]" << std::endl;
        config << settings_background_tag << "=Images/bg_img.jpg" << std::endl << std::endl;
        config << "[Stickman]" << std::endl;
        config << size_tag << "=normal" << std::endl;
        config << stickman_start_x << "=120" << std::endl;
        config << stickman_folder << "=Images" << std::endl;
        config << stickman_character << "=mario" << std::endl;
        config << stickman_anim_length << "=7" << std::endl;
        config << image_type << "=.png" << std::endl;
        config << stickman_start_v << "=7" << std::endl;

        //Alert user of default values that have been set
        std::string default_values;
        default_values
                .append("No config.ini file was found. One will be"
                        "generated for you automatically with"
                        "the following settings:\n\n")
                .append("[Window]\n")
                .append(config_window_height).append("=700\n")
                .append(config_window_width).append("1200\n\n")
                .append("[Gameworld]\n")
                .append(settings_background_tag).append("=Images/bg_img.jpg\n\n")
                .append("[Stickman]\n")
                .append(size_tag).append("=normal\n")
                .append(stickman_start_x).append("120\n")
                .append(stickman_folder).append("=Images\n")
                .append(stickman_character).append("=mario\n")
                .append(stickman_anim_length).append("=7\n")
                .append(image_type).append("=.png\n")
                .append(stickman_start_v).append("=7\n\n")
                .append("The program will now close.\n"
                        "It will load with default values on next launch.");

        QMessageBox msgBox;
        msgBox.setText(default_values.c_str());
        msgBox.exec();
        exit(0);
    }

    while (getline(inputStream, line))
    {
        lines[index++] = line;
    }
    inputStream.close();
    processLines(lines, num_lines);

    delete[] lines;
}

void Settings::processLines (std::string *lines, int numberOfLines)
{
    //Set default values in case config.ini is missing values
    m_config[config_window_height] = default_window_height;
    m_config[config_window_width] = default_window_width;
    m_config[settings_background_tag] = default_background_image_path;
    m_config[size_tag] = default_size;
    m_config[stickman_start_x] = default_start_xcoord;
    m_config[stickman_folder] = default_player_sprite_folder;
    m_config[stickman_character] = default_character;
    m_config[stickman_anim_length] = default_animation_length;
    m_config[image_type] = default_image_type;
    m_config[stickman_start_v] = default_starting_velocity;

    for (int i = 0; i < numberOfLines; ++i)
    {
        //Split string by "=" into key and value and store in map of configuration settings
        if (!lines[i].empty() && lines[i][0] != '[' && lines[i][0] != ';')
        {
            std::string key = lines[i].substr(0, lines[i].find("="));
            std::string value = lines[i].substr(lines[i].find("=")+1, lines[i].length()-1);
            m_config[key] = value;
        }
    }
}

int Settings::numberOfLines(std::string fileName)
{
    int numberOfLines = 0;
    std::string line;
    std::ifstream file(fileName.c_str());

    while (std::getline(file, line))
        numberOfLines++;

    return numberOfLines;
}

std::string& Settings::getElement(std::string key)
{
    return m_config[key];
}

Settings::~Settings()
{

}

