#include "filepriority.h"

FilePriority::FilePriority()
{

}

FilePriority::FilePriority(std::string filename, libtorrent::download_priority_t priority, size_t filesize)
{
    this->filename = filename;
    this->priority = priority;
    this->filesize = filesize;
}

QString FilePriority::get_filename()
{
    return QString(filename.c_str());
}

void FilePriority::set_filename(std::string filename)
{
    this->filename = filename;
}

QString FilePriority::get_priority()
{
    switch (priority) {
    case lt::default_priority:
        return "Default";
        break;
    case lt::dont_download:
        return "Dont download";
        break;
    case lt::top_priority:
        return "Top";
        break;
    case lt::low_priority:
        return "Low";
        break;
    default:
        break;
    }
}

void FilePriority::set_priority(libtorrent::download_priority_t priority)
{
    this->priority = priority;
}

QString FilePriority::get_size()
{
    return Utils::get_size_string(filesize);
}

size_t FilePriority::get_size_bytes()
{
    return filesize;
}

void FilePriority::set_size(size_t filesize)
{
    this->filesize = filesize;
}

libtorrent::download_priority_t FilePriority::get_priority_lt()
{
    return priority;
}
