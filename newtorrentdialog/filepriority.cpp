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

QString FilePriority::getFilename()
{
    return QString(filename.c_str());
}

void FilePriority::setFilename(std::string filename)
{
    this->filename = filename;
}

QString FilePriority::getPriority()
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

void FilePriority::setPriority(libtorrent::download_priority_t priority)
{
    this->priority = priority;
}

QString FilePriority::getSize()
{
    auto size_tmp = filesize;
    QString prefix = "";

    if(filesize >= pow(2, 30))
    {
        prefix = "Gi";
        size_tmp /= pow(2, 30);
    }
    else if(filesize >= pow(2, 20)){
        prefix = "Mi";
        size_tmp /= pow(2, 20);
    }
    else if(filesize >= pow(2, 10)){
        prefix = "Ki";
        size_tmp /= pow(2, 10);
    }

    return QString("%1 %2B").arg(size_tmp).arg(prefix);
}

size_t FilePriority::getSizeBytes()
{
    return filesize;
}

void FilePriority::setSize(size_t filesize)
{
    this->filesize = filesize;
}

libtorrent::download_priority_t FilePriority::getPriorityLT()
{
    return priority;
}
