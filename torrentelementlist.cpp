#include "torrentelementlist.h"

TorrentElementList::TorrentElementList(QWidget *parent) : QWidget(parent)
{
    // todo customize layout
    this->setLayout(layout);
}

void TorrentElementList::set_manager(TorrentManager &manager)
{
    this->manager = manager;
}

void TorrentElementList::update_data()
{
    if(manager == nullptr) return;

    // check torrents list equality
    bool list_is_okay = torrent_elements.size() == manager.get_torrents().size();
    for (int i = 0; i < torrent_elements.size() && list_is_okay; ++i) {
        if(torrent_elements[i].get_object() != manager.get_torrents()[i]){
            list_is_okay = false;
        }
    }

    if(!list_is_okay){// rebuild list

        for (auto v: torrent_elements){
            v.deleteLater();
        }

        torrent_elements.clear();

        for (auto& x : manager.get_torrents()) {
            auto *el = new TorrentElement(x);
            layout.addWidget(el);
        }
    }

}
