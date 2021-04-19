#ifndef DOWNLOADMANAGER_H
#define DOWNLOADMANAGER_H

#include "torrent.h"
#include <memory>
#include <string>
#include <QFileInfo>
#include "settings.h"


class DownloadManager
{
    lt::session* session;
    bool slowmode = false;
public:
    DownloadManager();
    ~DownloadManager();
    bool add_torrent(Torrent& t);
    void set_max_down_rate(size_t rate);
    void set_max_up_rate(size_t rate);
    void remove_torrent(Torrent& t);
    void toggle_slowmode();
    bool is_slowmode();

};

#endif // DOWNLOADMANAGER_H
