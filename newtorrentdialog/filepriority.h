#ifndef FILENAMEPRIORITY_H
#define FILENAMEPRIORITY_H
#include <libtorrent/download_priority.hpp>
#include <string>
#include <QString>
#include "utils.h"


class FilePriority
{
    std::string filename;
    lt::download_priority_t priority;
    size_t filesize;
public:
    FilePriority();
    FilePriority(std::string filename, lt::download_priority_t priority, size_t filesize);
    QString get_filename();
    void set_filename(std::string filename);
    QString get_priority();
    void set_priority(lt::download_priority_t priority);
    QString get_size();
    size_t get_size_bytes();
    void set_size(size_t filesize);
    lt::download_priority_t get_priority_lt();
};

#endif // FILENAMEPRIORITY_H
