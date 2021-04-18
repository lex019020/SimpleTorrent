#include "newtorrentdialog.h"

NewTorrentDialog::NewTorrentDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewTorrentDialog)
{
    ui->setupUi(this);
    connect(ui->buttonBox, SIGNAL(rejected()), this, SLOT(reject()));
    QStorageInfo info = QStorageInfo::root();
    ui->label_diskfree->setText(QString("Storage free: %1 GiB")
                                .arg(info.bytesAvailable()/1024/1024/1024));

    this->ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    this->ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    this->ui->tableView->horizontalHeader()->setStretchLastSection(true);
}

NewTorrentDialog::~NewTorrentDialog()
{
    delete ui;
}

NewTorrentDialog::Result NewTorrentDialog::GetResult()
{
    std::vector<lt::download_priority_t> proirs;
    for (auto& x : *priorities) {
        proirs.push_back(x.getPriorityLT());
    }
    return {ui->le_source->text(), ui->le_dest->text(), proirs};
}

void NewTorrentDialog::on_btn_browse_src_clicked()
{
    QFileDialog dialog(this);
    dialog.setFileMode(QFileDialog::ExistingFile);
    dialog.setNameFilter(tr("Torrent files (*.torrent)"));
    dialog.setViewMode(QFileDialog::Detail);
    dialog.setDirectory("/home");

    if(dialog.exec()){

        lt::torrent_info info(dialog.selectedFiles().at(0).toStdString());
        if(!info.is_valid()){
            return;
        }

        auto &storage = info.files();
        files_count = storage.num_files();
        for(auto i = 0; i < files_count; ++i){
            priorities->push_back(
                        FilePriority(static_cast<std::string>(storage.file_name(i)),
                                     lt::default_priority,
                                     storage.file_size(i)));
        }
        model->populate(priorities);
        this->ui->tableView->setModel(model);
        this->ui->tableView->resizeColumnsToContents();
        this->ui->tableView->update();

        ui->le_source->setText(dialog.selectedFiles().at(0));


    }

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

bool NewTorrentDialog::check_data(){
    lt::torrent_info info(ui->le_source->text().toStdString());

    return info.is_valid()
            && QFile(ui->le_source->text()).exists()
            && QDir(ui->le_dest->text()).exists();
}

void NewTorrentDialog::on_tableView_doubleClicked(const QModelIndex &index)
{
    FilePriority f = priorities->at(index.row());

    switch (f.getPriorityLT()) {
    case lt::default_priority:
        f.setPriority(lt::dont_download);
        break;
    case lt::dont_download:
        f.setPriority(lt::top_priority);
        break;
    case lt::top_priority:
        f.setPriority(lt::low_priority);
        break;
    case lt::low_priority:
        f.setPriority(lt::default_priority);
        break;
    }
     model->update(index.row(), f);
}
