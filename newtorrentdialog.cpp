#include "newtorrentdialog.h"
#include "ui_newtorrentdialog.h"
#include "QFileDialog"
#include "QFile"
#include "QDir"
#include "QStorageInfo"
#include "QMessageBox"

NewTorrentDialog::NewTorrentDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewTorrentDialog)
{
    ui->setupUi(this);
    //connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
    connect(ui->buttonBox, SIGNAL(rejected()), this, SLOT(reject()));
    QStorageInfo info = QStorageInfo::root();
    ui->label_diskfree->setText(QString("Storage free: %1 GiB")
                                .arg(info.bytesAvailable()/1024/1024/1024));
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
    QFileDialog dialog(this);
    dialog.setFileMode(QFileDialog::Directory);
    dialog.setOption(QFileDialog::ShowDirsOnly, true);
    dialog.setViewMode(QFileDialog::Detail);
    dialog.setDirectory("/home");
    if(dialog.exec())
        ui->le_dest->setText(dialog.selectedFiles().at(0));
}


void NewTorrentDialog::on_buttonBox_accepted()
{
    // todo check all
    if(check_data())
        this->accept();
    else{
        QMessageBox mbox_error;
        mbox_error.setText("Error");
        mbox_error.setInformativeText("Cannot add this torrent! Check parameters.");
        mbox_error.setStandardButtons(QMessageBox::Ok);
        mbox_error.exec();
    }
}

bool NewTorrentDialog::check_data(){// TODO
    return QFile(ui->le_source->text()).exists()
            || QDir(ui->le_dest->text()).exists();
}
