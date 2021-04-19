#include "downloadmanager.h"
#include <libtorrent/add_torrent_params.hpp>
#include <libtorrent/torrent_flags.hpp>
#include <libtorrent/torrent_handle.hpp>
#include "libtorrent/session.hpp"
#include <cstdlib>

DownloadManager::DownloadManager()
{
    session = new lt::session();
}

DownloadManager::~DownloadManager()
{
    delete session;
    // TODO?
}

bool DownloadManager::add_torrent(Torrent &t) try
{
    lt::add_torrent_params p;

    p.flags &= ~lt::torrent_flags::paused;
    p.flags &= ~lt::torrent_flags::auto_managed;
    lt::torrent_info info(t.get_filename());
    p.ti = std::make_shared<lt::torrent_info>(info);
    p.save_path = t.get_destination().c_str();
    p.file_priorities = t.get_priorities();
    lt::torrent_handle handle = session->add_torrent(p);
    auto v = handle.is_valid();
    t.set_handle(handle);

    return true;
}
catch (std::exception const& e) {
    printf(e.what());
  return false;
}

void DownloadManager::set_max_down_rate(size_t rate)
{
    session->set_download_rate_limit(rate);
}

void DownloadManager::set_max_up_rate(size_t rate)
{
    session->set_upload_rate_limit(rate);
}

void DownloadManager::remove_torrent(Torrent &t)
{
    // TODO
}

void DownloadManager::toggle_slowmode()
{
    Settings* set = Settings::get_instance();
    if(slowmode){
        set_max_down_rate(set->max_down_speed);
        set_max_up_rate(set->max_up_speed);
    }
    else{
        set_max_down_rate(set->max_down_speed_slow);
        set_max_up_rate(set->max_up_speed_slow);
    }
    slowmode = !slowmode;
}

bool DownloadManager::is_slowmode()
{
    return slowmode;
}
