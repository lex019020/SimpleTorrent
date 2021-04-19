#ifndef DOWNLOADMANAGER_H
#define DOWNLOADMANAGER_H

#include "torrent.h"
#include <memory>
#include <string>
#include <QFileInfo>
//#include <libtorrent/session_handle.hpp>
//#include <libtorrent/torrent.hpp>
//#include "libtorrent/entry.hpp"
//#include "libtorrent/bencode.hpp"
//#include "libtorrent/torrent_info.hpp"


class DownloadManager
{
    lt::session* session;
public:
    DownloadManager();
    ~DownloadManager();
    bool add_torrent(Torrent& t);
    void set_max_down_rate(size_t rate);
    void set_max_up_rate(size_t rate);
    void remove_torrent(Torrent& t);

};

#endif // DOWNLOADMANAGER_H
