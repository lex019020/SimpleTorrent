#ifndef TORRENTELEMENT_H
#define TORRENTELEMENT_H

#include <QWidget>
#include <string>

namespace Ui {
class TorrentElement;
}

class TorrentElement : public QWidget
{
    Q_OBJECT

public:
    explicit TorrentElement(QWidget *parent = nullptr);
    void set_neme(std::string& name);
    void set_status(std::string& status);
    void set_progress(int percent);
    ~TorrentElement();

private:
    Ui::TorrentElement *ui;
};

#endif // TORRENTELEMENT_H
