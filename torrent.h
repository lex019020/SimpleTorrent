#ifndef TORRENT_H
#define TORRENT_H

#include <string>
#include <vector>
#include <qstring.h>
#include <memory>
#include <libtorrent/torrent_handle.hpp>
#include <libtorrent/torrent_status.hpp>
#include <libtorrent/torrent_info.hpp>

class Torrent
{
private:
    std::string src;
    std::string dest;
    int status;
    lt::torrent_handle handle;

public:
    Torrent();
    Torrent(std::string filename, std::string dest, std::vector<int> priorities, int overall_priority,
            bool imm_start);
    std::string get_filename() const;
    std::string get_destination() const;
    std::string get_status() const;
    std::string get_info_string() const;
    std::string get_name() const;
    std::int64_t get_size() const;
    std::int64_t get_downloaded() const;
    std::int64_t get_speed() const;
    std::int64_t get_seeds() const;
    void start();
    void pause();
    void set_slow_mode(bool slow_mode);
    void delete_files();
    void set_handle(libtorrent::torrent_handle &handle);
    bool operator==(const Torrent& t) const;
    bool operator!=(const Torrent& t) const;

};

#endif // TORRENT_H
