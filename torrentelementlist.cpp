#include "torrentelementlist.h"

TorrentElementList::TorrentElementList(QWidget *parent) : QWidget(parent)
{
    // todo customize layout
    layout.setAlignment(Qt::AlignTop);
    this->setLayout(layout.layout());
}

void TorrentElementList::set_manager(TorrentManager *manager)
{
    this->manager = manager;
}

void TorrentElementList::update_data()
{
    if(manager == nullptr) return;

    // check torrents list equality
    bool list_is_okay = torrent_elements.size() == manager->get_torrents().size();
    for (size_t i = 0; i < torrent_elements.size() && list_is_okay; ++i) {
        if(*(torrent_elements[i]->get_object()) != (Torrent)*(manager->get_torrents()[i])){
            list_is_okay = false;
        }
    }

    if(!list_is_okay){// rebuild list

        for (auto& v: torrent_elements){
            v->deleteLater();
        }
        for(auto& x: torrent_elements)
            delete x;
        torrent_elements.clear();

        for (size_t i = 0; i < manager->get_torrents().size(); i++) {
            auto *el = new TorrentElement(manager->get_torrents()[i]);
            layout.addWidget(el);
            torrent_elements.push_back(el);// add to vector??
        }
    }

    for(auto& x: torrent_elements){ // update data
        x->update_data();
    }

}
