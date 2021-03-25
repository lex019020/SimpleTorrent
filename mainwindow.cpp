#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->statusbar->showMessage("Ready");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btn_start_clicked()
{
    // TODO
}

void MainWindow::on_btn_new_clicked()
{
    // TODO
}

void MainWindow::on_btn_pause_clicked()
{
    // TODO
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
