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
    std::shared_ptr<Torrent> t;
public:
    explicit TorrentElement(Torrent& t, QWidget *parent = nullptr);
    void update_data();
    std::shared_ptr<Torrent> get_object() const;
    /*
    void set_name(std::string& name);
    void set_status(std::string& status);
    void set_progress(int percent);*/
    ~TorrentElement();

private:
    Ui::TorrentElement *ui;
};

#endif // TORRENTELEMENT_H
