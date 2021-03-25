#include "torrentelement.h"
#include "ui_torrentelement.h"
#include <QString>

TorrentElement::TorrentElement(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TorrentElement)
{
    ui->setupUi(this);
}

void TorrentElement::set_neme(std::string &name)
{
    ui->label_name->setText(name.c_str());
}

void TorrentElement::set_status(std::string &status)
{
    ui->label_info->setText(status.c_str());
}

void TorrentElement::set_progress(int percent)
{
    ui->progressBar->setValue(percent);
}

TorrentElement::~TorrentElement()
{
    delete ui;
}
