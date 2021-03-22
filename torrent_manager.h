#ifndef TORRENT_MANAGER_H
#define TORRENT_MANAGER_H

#include <vector>

class torrent_manager
{
private:
    std::vector<torrent> torrents;
public:

    torrent_manager();
    bool add_torrent(Torrent& t);
    void get_torrents(const std::vector<torrent>& torrents);
    bool remove_torrent(int n, bool del_files);

};

#endif // TORRENT_MANAGER_H
