#pragma once

#include <QVariant>
#include <QVector>

class MyTableItem
{
public:
    typedef QHash < int, QVariant > Data;

public:
    MyTableItem();

    int columnCount() const;

    QVariant data(int column, int role) const;
    void setData(int column, const QVariant& value, int role = Qt::DisplayRole);

private:
    QVector<Data>   mColumns;
};

inline int MyTableItem::columnCount() const {
    return mColumns.size();
}
