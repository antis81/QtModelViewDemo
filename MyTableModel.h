#pragma once

#include <MyTableItem.h>

#include <QAbstractTableModel>

class MyTableModel : public QAbstractTableModel
{
public:
    MyTableModel();

public: // QAbstractItemModel interface
    int rowCount(const QModelIndex& parent) const;
    int columnCount(const QModelIndex& parent) const;
    QVariant data(const QModelIndex& index, int role) const;

public:
    void initModel(const QVector<MyTableItem>& rows);

private:
    QVector<MyTableItem>    mRows;
};
