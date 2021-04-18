#ifndef FILENAMEPRIORITY_H
#define FILENAMEPRIORITY_H
#include <libtorrent/download_priority.hpp>
#include <string>
#include <QString>
#include <cmath>


class FilePriority
{
    std::string filename;
    lt::download_priority_t priority;
    size_t filesize;
public:
    FilePriority();
    FilePriority(std::string filename, lt::download_priority_t priority, size_t filesize);
    QString getFilename();
    void setFilename(std::string filename);
    QString getPriority();
    void setPriority(lt::download_priority_t priority);
    QString getSize();
    size_t getSizeBytes();
    void setSize(size_t filesize);
    lt::download_priority_t getPriorityLT();
};

#endif // FILENAMEPRIORITY_H
