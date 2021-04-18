#ifndef NEWTORRENTDIALOG_H
#define NEWTORRENTDIALOG_H

#include <QDialog>
#include "QMessageBox"
#include <libtorrent/download_priority.hpp>
#include "ui_newtorrentdialog.h"
#include "QFileDialog"
#include "QFile"
#include "QDir"
#include "QStorageInfo"
#include "QString"
#include <libtorrent/add_torrent_params.hpp>
#include <libtorrent/torrent_flags.hpp>
#include <libtorrent/torrent_handle.hpp>
#include "libtorrent/session.hpp"
#include <libtorrent/file_storage.hpp>
#include <libtorrent/download_priority.hpp>
#include "newtorrentdialog/filepriority.h"
#include "newtorrentdialog/qtableviewmodel1.h"

namespace Ui {
class NewTorrentDialog;
}

class NewTorrentDialog : public QDialog
{
    Q_OBJECT

    bool check_data();
    size_t files_count;
    std::vector<FilePriority> *priorities = new std::vector<FilePriority>;
    QTableViewModel1 *model = new QTableViewModel1();
public:
    struct Result{
        QString src;
        QString dest;
        std::vector<lt::download_priority_t> priors;
    };
    explicit NewTorrentDialog(QWidget *parent = nullptr);
    ~NewTorrentDialog();
    Result GetResult();


private slots:
    void on_btn_browse_src_clicked();

    void on_btn_browse_dest_clicked();

    //void on_buttonBox_accepted();

    //void on_buttonBox_rejected();

    void on_buttonBox_accepted();

    void on_tableView_doubleClicked(const QModelIndex &index);

private:
    Ui::NewTorrentDialog *ui;
};

#endif // NEWTORRENTDIALOG_H
