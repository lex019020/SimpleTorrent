#include "torrentmanager.h"

TorrentManager::TorrentManager()
{

}

void TorrentManager::set_down_manager(DownloadManager* mgr)
{
    manager = mgr;
}



bool TorrentManager::add_torrent(Torrent t){
    if(!manager) return false;
    for(auto& x: this->torrents)
        if(x == t)
            return false;

    manager->add_torrent(t);
    this->torrents.push_back(t);
    return true;
}

std::vector<Torrent *> TorrentManager::get_torrents(){
    std::vector<Torrent*> ret;
    for(auto& x: this->torrents)
        ret.push_back(&x);
    return ret;
}

bool TorrentManager::remove_torrent(size_t n, bool del_files){
    if(this->torrents.size() <= n) return false;
    if(del_files)
        this->torrents[n].delete_files();
    this->torrents.erase(this->torrents.begin() + n);
    return true;
}

void TorrentManager::pause_all()
{
    for(auto& t: torrents)
        t.pause();
}

void TorrentManager::resume_all()
{
    for(auto& t: torrents)
        t.start();
}

size_t TorrentManager::get_down_rate()
{
    size_t downrate = 0;
    for(auto& t: torrents)
        downrate += t.get_down_speed();
    return downrate;
}

size_t TorrentManager::get_up_rate()
{
    size_t uprate = 0;
    for(auto& t: torrents)
        uprate += t.get_up_speed();
    return uprate;
}
