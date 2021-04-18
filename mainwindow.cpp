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

    down_manager = new DownloadManager();
    manager.set_down_manager(down_manager);

    ui->scrollArea->setWidget(&list_torrent_elems);

    timer_update = new QTimer(this);
    connect(timer_update, &QTimer::timeout, this, QOverload<>::of(&MainWindow::UpdateUI));
    timer_update->start(1000);
}

MainWindow::~MainWindow()
{
    delete down_manager;
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
        Torrent tor(dialog.GetResult().src.toStdString(), dialog.GetResult().dest.toStdString(),
                    dialog.GetResult().priors, 0, true);

        if(manager.add_torrent(tor)){
            UpdateUI();
        }
        else{
            QMessageBox mbox_error;
            mbox_error.setText("Error");
            mbox_error.setInformativeText("Cannot add this torrent!");
            mbox_error.setStandardButtons(QMessageBox::Ok);
            mbox_error.exec();
        }
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
