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

Torrent::Torrent(std::string filename, std::string dest, std::vector<lt::download_priority_t> priorities,
                 int overall_priority, bool imm_start){
    this->src = filename;
    this->dest = dest;
    this->priorities = priorities;
}

bool Torrent::operator ==(const Torrent& t) const{
    return t.handle == handle;
}

bool Torrent::operator!=(const Torrent &t) const
{
    return !(*this == t);
}

std::string Torrent::get_filename() const{
    return src;
}

std::string Torrent::get_destination() const{
    return dest;
}


QString Torrent::get_status() const
{
    //libtorrent::torrent_handle::status()::state;
    if(!handle.is_valid()) return QString("no handle!");
    auto st = handle.status();
    return QString(state_str(st.state));
}

QString Torrent::get_info_string() const
{
    QString info = get_status();
    if(!handle.is_valid()) return info;

    auto st = handle.status();
    if(st.paused){
        info.append(" paused");
        return info;
    }

    if(st.state != lt::torrent_status::downloading)
        return info;

    int s_total, s_down, d_speed, seeds;
    QString size_prefix = "";
    QString speed_prefix = "";
    s_total = get_size();
    s_down = get_downloaded();
    d_speed = get_speed();
    int time;
    if(d_speed > 0)
        time = (s_total - s_down) / d_speed / 60; // minutes remaining
    else
        time = INT_MAX;
    seeds = get_seeds();

    info.append(QString("    %1 / %2").arg(Utils::get_size_string(s_down))
                .arg(Utils::get_size_string(s_total))); // progress label

    info.append(QString("    %1 seeds").arg(get_seeds()));

    info.append(QString("    %1/s").arg(Utils::get_size_string(d_speed)));

    if(time == 0){
        info.append("    <1 min remaining");
    }
    else if(time == INT_MAX){
        info.append("    calculating time...");
    }
    else{
        if(time > 120){
            time /= 60;
            info.append(QString("    %1 h remaining").arg(time));
        }
        else{
            info.append(QString("    %1 min remaining").arg(time));
        }
    }

    return info;
}

std::string Torrent::get_name() const
{
    if(!handle.is_valid()) return "error";
    return handle.status().name;
}

std::int64_t Torrent::get_downloaded() const
{
    if(!handle.is_valid()) return -1;
    return handle.status().total_done;
}

int64_t Torrent::get_speed() const
{
    if(!handle.is_valid()) return -1;
    return handle.status().download_rate;
}

int64_t Torrent::get_seeds() const
{
    if(!handle.is_valid()) return -1;
    return handle.status().num_seeds;
}

std::vector<libtorrent::download_priority_t> Torrent::get_priorities()
{
    return priorities;
}

void Torrent::start()
{
    if(!handle.is_valid()) return;
    handle.resume();
}

void Torrent::pause()
{
    if(!handle.is_valid() || handle.is_paused()) return;
    handle.pause();
}

std::int64_t Torrent::get_size() const
{
    if(!handle.is_valid()) return -1;
    return handle.get_torrent_info().total_size();
}

void Torrent::delete_files(){
    // TODO
}

void Torrent::set_handle(libtorrent::torrent_handle &handle)
{
    this->handle = handle;
}

