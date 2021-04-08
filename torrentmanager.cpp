#include "torrentmanager.h"

TorrentManager::TorrentManager()
{

}

bool TorrentManager::add_torrent(Torrent &t){
    for(auto& x: this->torrents)
        if(x == t)
            return false;

    this->torrents.push_back(t);
    // TODO add to queue
    return true;
}

std::vector<Torrent>& TorrentManager::get_torrents(){
    return this->torrents;
}

bool TorrentManager::remove_torrent(int n, bool del_files){
    if(this->torrents.size() <= n) return false;
    if(del_files)
        this->torrents[n].delete_files();
    this->torrents.erase(this->torrents.begin() + n);
    return true;
}
