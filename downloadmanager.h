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
    bool AddTorrent(Torrent& t);
    void SetMaxDownRate(size_t rate);
    void SetMaxUpRate(size_t rate);
    void RemoveTorrent(Torrent& t);

};

#endif // DOWNLOADMANAGER_H
