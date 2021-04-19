#include "qtableviewmodel1.h"

QTableViewModel1::QTableViewModel1(QObject *parent) : QAbstractListModel(parent)
{
    values = new std::vector<FilePriority>();
}

int QTableViewModel1::rowCount(const QModelIndex &parent) const
{
    return values->size();
}

int QTableViewModel1::columnCount(const QModelIndex &parent) const
{
    return 3;
}

QVariant QTableViewModel1::data(const QModelIndex &index, int role) const
{
    QVariant val;
    switch (role) {
    case Qt::DisplayRole:
        switch(index.column()){
        case 0:
            val = this->values->at(index.row()).get_filename();
            break;
        case 1:
            val = this->values->at(index.row()).get_size();
            break;
        case 2:
            val = this->values->at(index.row()).get_priority();
            break;
        }

        break;
    case Qt::UserRole:
        // is it needed?
        val = this->values->at(index.row()).get_filename();
        break;
    }

    return val;
}

void QTableViewModel1::populate(std::vector<FilePriority> *values)
{
    auto idx = this->values->size();
    this->beginInsertRows(QModelIndex(), 1, idx);
    this->values = values;
    endInsertRows();
}

void QTableViewModel1::update(int idx, FilePriority value)
{
    (*this->values)[idx] = value;

    QModelIndex item_index_s = this->index(idx, 0);
    QModelIndex item_index_e = this->index(idx, this->columnCount(QModelIndex()));

    emit this->dataChanged(item_index_s, item_index_e);
}

QVariant QTableViewModel1::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(role == Qt::DisplayRole && orientation == Qt::Horizontal){
        switch (section) {
        case 0:
            return QString("File");
        case 1:
            return QString("Size");
        case 2:
            return QString("Priority");
        }
    }
    return QVariant();
}
