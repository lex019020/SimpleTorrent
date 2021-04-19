#ifndef SETTINGS_H
#define SETTINGS_H
#include <string>
#include <QStandardPaths>
#include <QString>


class Settings
{
private:
    Settings();
    static Settings *instance;
public:
    size_t max_down_speed = INT64_MAX;
    size_t max_down_speed_slow = 1024*1024;
    size_t max_up_speed = INT64_MAX;
    size_t max_up_speed_slow = 512*1024;
    size_t max_downloads = INT64_MAX;
    size_t max_uploads = INT64_MAX;
    QString default_down_dir = "";
    static Settings *get_instance(){
        if(instance == nullptr)
            instance = new Settings();
        return instance;
    }
    void load_data();
    void save_data();

};

#endif // SETTINGS_H
