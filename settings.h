#ifndef SETTINGS_H
#define SETTINGS_H


class Settings
{
public:
    int max_down_speed;
    int max_down_speed_slow;
    int max_up_speed;
    int max_up_speed_slow;
    int max_downloads;
    int max_uploads;
    string default_down_dir;

    Settings();
};

#endif // SETTINGS_H
