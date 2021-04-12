#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <memory>
#include <torrentmanager.h>
#include "torrentelementlist.h"
#include "downloadmanager.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    TorrentManager manager;
    TorrentElementList list_torrent_elems;
    DownloadManager* down_manager;
    QTimer *timer_update;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void UpdateUI();

private slots:
    void on_btn_start_clicked();

    void on_btn_new_clicked();

    void on_btn_pause_clicked();

    void on_btn_slowmode_clicked();

    void on_btn_shutdown_clicked();

    void on_btn_settings_clicked();

    void on_btn_info_clicked();

    void on_btn_downloads_clicked();

    void on_btn_uploads_clicked();

    void on_btn_paused_clicked();

    void on_btn_finished_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
