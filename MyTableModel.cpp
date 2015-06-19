#include "MyTableModel.h"

MyTableModel::MyTableModel()
{

}

int MyTableModel::rowCount(const QModelIndex& parent) const
{
    Q_UNUSED(parent);
    return mRows.size();
}

int MyTableModel::columnCount(const QModelIndex& parent) const
{
    Q_UNUSED(parent);
    return mRows.size() ? mRows[0].columnCount() : 0;
}

QVariant MyTableModel::data(const QModelIndex& index, int role) const
{
    if (!index.isValid()) {
        return QVariant();
    }

    const int row = index.row();
    Q_ASSERT(row < mRows.size());

    return mRows[row].data(index.column(), role);
}

void MyTableModel::initModel(const QVector<MyTableItem>& rows)
{
    beginResetModel();
    mRows.clear();
    mRows = rows;
    endResetModel();
}
