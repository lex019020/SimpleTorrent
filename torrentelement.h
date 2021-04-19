#ifndef TORRENTELEMENT_H
#define TORRENTELEMENT_H

#include <QWidget>
#include <string>
#include <torrent.h>
#include <memory>

namespace Ui {
class TorrentElement;
}

class TorrentElement : public QWidget
{
    Q_OBJECT
    Torrent* t;
public:
    explicit TorrentElement(Torrent* tor, QWidget *parent = nullptr);
    void update_data();
    Torrent* get_object() const;
    ~TorrentElement();

private:
    Ui::TorrentElement *ui;
};

#endif // TORRENTELEMENT_H
