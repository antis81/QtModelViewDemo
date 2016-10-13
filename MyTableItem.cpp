#include "MyTableItem.h"


MyTableItem::MyTableItem()
{
}

QVariant MyTableItem::data(int column, int role) const
{
    Q_ASSERT(column >= 0 && column < columnCount() );

    return _columns.at(column)[role];
}

void MyTableItem::setData(int column, const QVariant& value, int role)
{
    Q_ASSERT(column >= 0);

    while (columnCount() <= column) {
        mColumns << Data();
    }

    mColumns[column][role] = value;
}


