#ifndef TORRENT_H
#define TORRENT_H

#include <string>
#include <vector>


class Torrent
{
private:
    string src;
    string dest;
    int status;

public:
    Torrent();
    Torrent(string filename, string dest, vector<int> priorities, int overall_priority,
            bool imm_start, bool add_shutdown_task, int shutdown_type);
    string get_filename();
    string get_destination();
    string get_status();
    int get_size();
    int get_downloaded();
    int get_speed();
    void start();
    void pause();
    void set_slow_mode(bool slow_mode);
    void delete_files();

};

#endif // TORRENT_H
