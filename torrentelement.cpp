#include "torrentelement.h"
#include "ui_torrentelement.h"
#include <QString>
#include <math.h>

TorrentElement::TorrentElement(Torrent &tor, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TorrentElement)
{
    t = std::make_shared<Torrent>(tor);
    ui->setupUi(this);
}

void TorrentElement::update_data()
{
    // TODO remove string construction somewhere
    if(!t) return;

    ui->label_name->setText(t->get_filename().c_str());



    ui->label_info->setText(QString(t->get_info_string().c_str()));
}

std::shared_ptr<Torrent> TorrentElement::get_object() const
{
    return this->t;
}

//void TorrentElement::set_name(std::string &name)
//{
//    ui->label_name->setText(name.c_str());
//}

//void TorrentElement::set_status(std::string &status)
//{
//    ui->label_info->setText(status.c_str());
//}

//void TorrentElement::set_progress(int percent)
//{
//    ui->progressBar->setValue(percent);
//}

TorrentElement::~TorrentElement()
{
    delete ui;
}
