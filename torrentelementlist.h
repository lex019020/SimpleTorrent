#ifndef TORRENTELEMENTLIST_H
#define TORRENTELEMENTLIST_H

#include <QWidget>
#include <QVBoxLayout>
#include <torrentmanager.h>
#include <torrentelement.h>
#include <vector>
#include <torrent.h>

class TorrentElementList : public QWidget
{
    Q_OBJECT
    TorrentManager& manager;
    std::vector<TorrentElement> torrent_elements;
    QVBoxLayout layout;
public:
    explicit TorrentElementList(QWidget *parent = nullptr);
    void set_manager(TorrentManager& manager);
    void update_data();

signals:

};

#endif // TORRENTELEMENTLIST_H
