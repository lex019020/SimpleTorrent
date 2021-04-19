#ifndef TORRENT_MANAGER_H
#define TORRENT_MANAGER_H

#include <vector>
#include <memory>
#include <torrent.h>
#include <downloadmanager.h>
#include <libtorrent/session.hpp>

class TorrentManager
{
private:
    std::vector<Torrent> torrents;
    DownloadManager* manager;
public:

    TorrentManager();
    void set_down_manager(DownloadManager *mgr);
    bool add_torrent(Torrent t);
    std::vector<Torrent *> get_torrents();
    bool remove_torrent(size_t n, bool del_files);
    void pause_all();
    void resume_all();

};

#endif // TORRENT_MANAGER_H
