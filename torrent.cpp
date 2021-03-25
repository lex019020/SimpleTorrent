#include "torrent.h"

Torrent::Torrent()
{

}

Torrent::Torrent(std::string filename, std::string dest, std::vector<int> priorities,
                 int overall_priority, bool imm_start){
    this->src = filename;
    this->dest = dest;
    // TODO connect to Downloader
}

bool Torrent::operator ==(const Torrent& t) const{
    return t.get_destination() == this->dest
        && t.get_filename() == this->src;
}

std::string Torrent::get_filename() const{
    return this->src;
}

std::string Torrent::get_destination() const{
    return this->dest;
}

void Torrent::delete_files(){
    // TODO
}
