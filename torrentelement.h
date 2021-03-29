#ifndef TORRENTELEMENT_H
#define TORRENTELEMENT_H

#include <QWidget>
#include <string>
#include <torrent.h>

namespace Ui {
class TorrentElement;
}

class TorrentElement : public QWidget
{
    Q_OBJECT
    Torrent& t;
public:
    explicit TorrentElement(Torrent& t, QWidget *parent = nullptr);
    void update_data();
    Torrent &get_object() const;
    /*
    void set_name(std::string& name);
    void set_status(std::string& status);
    void set_progress(int percent);*/
    ~TorrentElement();

private:
    Ui::TorrentElement *ui;
};

#endif // TORRENTELEMENT_H
