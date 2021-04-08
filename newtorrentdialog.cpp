#include "newtorrentdialog.h"
#include "ui_newtorrentdialog.h"
#include "QFileDialog"

NewTorrentDialog::NewTorrentDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewTorrentDialog)
{
    ui->setupUi(this);
    connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
    connect(ui->buttonBox, SIGNAL(rejected()), this, SLOT(reject()));
}

NewTorrentDialog::~NewTorrentDialog()
{
    delete ui;
}

NewTorrentDialog::Result NewTorrentDialog::GetResult()
{
    return {ui->le_source->text(), ui->le_dest->text()};
}

void NewTorrentDialog::on_btn_browse_src_clicked()
{
    QFileDialog dialog(this);
    dialog.setFileMode(QFileDialog::ExistingFile);
    dialog.setNameFilter(tr("Torrent files (*.torrent)"));
    dialog.setViewMode(QFileDialog::Detail);
    dialog.setDirectory("/home");
    if(dialog.exec())
        ui->le_source->setText(dialog.selectedFiles().at(0));

}

void NewTorrentDialog::on_btn_browse_dest_clicked()
{
    // todo open dialog
}

//void NewTorrentDialog::on_buttonBox_accepted()
//{
//    // todo
//}

//void NewTorrentDialog::on_buttonBox_rejected()
//{
//    // todo
//}
