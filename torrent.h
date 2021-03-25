#ifndef TORRENT_H
#define TORRENT_H

#include <string>
#include <vector>


class Torrent
{
private:
    std::string src;
    std::string dest;
    int status;
    // torrent handler

public:
    Torrent();
    Torrent(std::string filename, std::string dest, std::vector<int> priorities, int overall_priority,
            bool imm_start);
    std::string get_filename() const;
    std::string get_destination() const;
    std::string get_status() const;
    int get_size() const;
    int get_downloaded() const;
    int get_speed() const;
    void start();
    void pause();
    void set_slow_mode(bool slow_mode);
    void delete_files();
    bool operator==(const Torrent& t) const;

};

#endif // TORRENT_H
