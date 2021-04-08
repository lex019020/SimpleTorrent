#ifndef TORRENT_MANAGER_H
#define TORRENT_MANAGER_H

#include <vector>
#include <torrent.h>
#include <libtorrent/session.hpp>

class TorrentManager
{
private:
    std::vector<Torrent> torrents;
    lt::session session;
public:

    TorrentManager();
    bool add_torrent(Torrent& t);
    std::vector<Torrent>& get_torrents();
    bool remove_torrent(int n, bool del_files);


};

#endif // TORRENT_MANAGER_H
