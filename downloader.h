#ifndef DOWNLOADER_H
#define DOWNLOADER_H

#include <torrent.h>


class Downloader
{
private:
    //
public:
    virtual void start_downloading(Torrent& t);
};

#endif // DOWNLOADER_H
