#ifndef TORRENT_MANAGER_H
#define TORRENT_MANAGER_H

#include <vector>
#include <torrent.h>

class torrent_manager
{
private:
    std::vector<Torrent> torrents;
public:

    torrent_manager();
    bool add_torrent(Torrent& t);
    const std::vector<Torrent>& get_torrents();
    bool remove_torrent(int n, bool del_files);

};

#endif // TORRENT_MANAGER_H
