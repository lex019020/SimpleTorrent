#include "mainwindow.h"
#include "torrent.h"
#include "newtorrentdialog.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->statusbar->showMessage("Ready");
    list_torrent_elems.set_manager(&manager);

    ui->scrollArea->setWidget(&list_torrent_elems);

    timer_update = new QTimer(this);
    connect(timer_update, &QTimer::timeout, this, QOverload<>::of(&MainWindow::UpdateUI));
    //timer_update->start(2000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::UpdateUI()
{
    list_torrent_elems.update_data();
    // todo: status bar, something
}


void MainWindow::on_btn_start_clicked()
{
    manager.resume_all();
    UpdateUI();
}

void MainWindow::on_btn_new_clicked()
{
    NewTorrentDialog dialog;
    dialog.setModal(true);
    if(dialog.exec() == QDialog::Accepted){
        // TODO parameters
        std::vector<int> v;
        Torrent tor(dialog.GetResult().src.toStdString(), dialog.GetResult().dest.toStdString(), v, 0, true);
        manager.add_torrent(tor);
        UpdateUI();
    }
}

void MainWindow::on_btn_pause_clicked()
{
    manager.pause_all();
    UpdateUI();
}

void MainWindow::on_btn_slowmode_clicked()
{
    // TODO
}

void MainWindow::on_btn_shutdown_clicked()
{
    // TODO
}

void MainWindow::on_btn_settings_clicked()
{
    // TODO
}

void MainWindow::on_btn_info_clicked()
{
    // TODO
}

void MainWindow::on_btn_downloads_clicked()
{
    // TODO
}

void MainWindow::on_btn_uploads_clicked()
{
    // TODO
}

void MainWindow::on_btn_paused_clicked()
{
    // TODO
}

void MainWindow::on_btn_finished_clicked()
{
    // TODO
}

void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    /*
     * if(arg1.size() > 0)
        ui->lbl_pic_search->hide();
    else
        ui->lbl_pic_search->show();
    */
}
