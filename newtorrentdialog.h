#ifndef NEWTORRENTDIALOG_H
#define NEWTORRENTDIALOG_H

#include <QDialog>

namespace Ui {
class NewTorrentDialog;
}

class NewTorrentDialog : public QDialog
{
    Q_OBJECT

public:
    struct Result{
        QString src;
        QString dest;
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

private:
    Ui::NewTorrentDialog *ui;
};

#endif // NEWTORRENTDIALOG_H
