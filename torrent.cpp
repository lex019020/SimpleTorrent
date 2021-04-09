#include "torrent.h"

// return the name of a torrent status enum
char const* state_str(lt::torrent_status::state_t s)
{
  switch(s) {
    case lt::torrent_status::checking_files: return "checking";
    case lt::torrent_status::downloading_metadata: return "dl metadata";
    case lt::torrent_status::downloading: return "downloading";
    case lt::torrent_status::finished: return "finished";
    case lt::torrent_status::seeding: return "seeding";
    case lt::torrent_status::checking_resume_data: return "checking resume";
    default: return "<>";
  }
}

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

bool Torrent::operator!=(const Torrent &t) const
{
    return !(*this == t);
}

std::string Torrent::get_filename() const{
    if(!handle) return std::string("error");
    return src;
}

std::string Torrent::get_destination() const{
    if(!handle) return std::string("error");
    return dest;
}


std::string Torrent::get_status() const
{
    //libtorrent::torrent_handle::status()::state;
    if(!handle) return std::string("no handle!");
    auto st = handle->status();
    return std::string(state_str(st.state));
}

std::string Torrent::get_info_string() const
{
    QString info = get_status().c_str();
    if(!handle) return info.toStdString();

    int s_total, s_down, d_speed, seeds;
    QString size_prefix = "";
    QString speed_prefix = "";
    s_total = get_size();
    s_down = get_downloaded();
    d_speed = get_speed();
    int time = (s_total - s_down) / d_speed / 60; // minutes remaining
    seeds = 12; // TODO

    if(s_total >= pow(2, 30))
    {
        size_prefix = "Gi";
        s_total /= pow(2, 30);
        s_down /= pow(2, 30);
    }
    else if(s_total >= pow(2, 20)){
        size_prefix = "Mi";
        s_total /= pow(2, 20);
        s_down /= pow(2, 20);
    }
    else if(s_total >= pow(2, 10)){
        size_prefix = "Ki";
        s_total /= pow(2, 10);
        s_down /= pow(2, 10);
    }

    info.append(QString("    %1 / %2 %3B").arg(s_down).arg(s_total).arg(size_prefix)); // progress label

    if(d_speed >= pow(2, 30))
    {
        speed_prefix = "Gi";
        d_speed /= pow(2, 30);
    }
    else if(d_speed >= pow(2, 20)){
        speed_prefix = "Mi";
        d_speed /= pow(2, 20);
    }
    else if(d_speed >= pow(2, 10)){
        speed_prefix = "Ki";
        d_speed /= pow(2, 10);
    }

    info.append(QString("    %1 %2B/s"));

    if(time == 0){
        info.append("    <1 min remaining");
    }
    else{
        if(time > 120){
            time /= 60;
            info.append(QString("    %1 h remaining"));
        }
        else{
            info.append(QString("    %1 min remaining"));
        }
    }

    return info.toStdString();
}

std::int64_t Torrent::get_downloaded() const
{
    if(!handle) return -1;
    return handle->status().total_done;
}

int64_t Torrent::get_speed() const
{
    if(!handle) return -1;
    return handle->status().download_rate;
}

int64_t Torrent::get_seeds() const
{
    if(!handle) return -1;
    return handle->status().num_seeds;
}

void Torrent::start()
{
    if (!handle || !handle->is_paused()) return;
    handle->resume();
}

void Torrent::pause()
{
    if (!handle || handle->is_paused()) return;
    handle->pause();
}

std::int64_t Torrent::get_size() const
{
    if(!handle) return -1;
    return handle->get_torrent_info().total_size();
}

void Torrent::delete_files(){
    // TODO
}

void Torrent::set_handle(libtorrent::torrent_handle &handle)
{
    this->handle = std::make_shared<libtorrent::torrent_handle>(handle);
}
