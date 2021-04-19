#include "settings.h"

Settings::Settings()
{
    default_down_dir = QStandardPaths::writableLocation(QStandardPaths::DownloadLocation);
}

Settings* Settings::instance = nullptr;

void Settings::load_data()
{
    // todo
}

void Settings::save_data()
{
    // todo
}
