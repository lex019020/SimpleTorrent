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

bool DownloadManager::AddTorrent(Torrent &t) try
{
    lt::add_torrent_params p;

    p.flags &= ~lt::torrent_flags::paused;
    p.flags &= ~lt::torrent_flags::auto_managed;
    lt::torrent_info info(t.get_filename());
    p.ti = std::make_shared<lt::torrent_info>(info);
    p.save_path = t.get_destination().c_str();
    p.file_priorities = t.get_priorities();
    // todo priorities
    lt::torrent_handle handle = session->add_torrent(p);
    auto v = handle.is_valid();
    t.set_handle(handle);

    return true;
}
catch (std::exception const& e) {
    printf(e.what());
  //std::cout << "ERROR: " <<  << "\n";
  return false;
}

void DownloadManager::SetMaxDownRate(size_t rate)
{
    session->set_download_rate_limit(rate);
}

void DownloadManager::SetMaxUpRate(size_t rate)
{
    session->set_upload_rate_limit(rate);
}

void DownloadManager::RemoveTorrent(Torrent &t)
{
    // TODO
}
