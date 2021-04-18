#ifndef QTABLEVIEWMODEL1_H
#define QTABLEVIEWMODEL1_H

#include "filepriority.h"
#include <QModelIndex>
#include <vector>

class QTableViewModel1 : public QAbstractListModel
{
public:
    QTableViewModel1(QObject *parent = nullptr);
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    void populate(std::vector<FilePriority>* values);
    void update(int idx, FilePriority value);
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
private:
    std::vector<FilePriority> *values;
};

#endif // QTABLEVIEWMODEL1_H
