#include "MainWindow.h"

#include <MyTableItem.h>
#include <MyTableModel.h>

#include <QStandardItem>
#include <QTime>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    setupUi(this);

    mSortModel.setSourceModel(&mTableModel);

    tableView->setSortingEnabled(true);
    on_comboBox_currentIndexChanged(comboBox->currentIndex());
}

void MainWindow::createStandardItems(int count)
{
    mStandardModel.setRowCount(count);
    mStandardModel.setColumnCount(2);
    tableView->setUpdatesEnabled(false);

    QStringList listOne = QStringLiteral("A B C D E F G H I J K L M N O P Q R S T U V W X Y Z")
                          .split(QLatin1Char(' '));

    for ( int row = 0; row < count; row++ ) {
        QList<QStandardItem*> columns;
        columns << new QStandardItem( QString::fromUtf8("#%1").arg(row, 4, 10, QLatin1Char('0')) )
                << new QStandardItem( listOne[row % listOne.size()] );

        for ( int col = 0; col < columns.size(); col++) {
            mStandardModel.setItem( row, col, columns[col] );
        }
    }

    tableView->setUpdatesEnabled(true);
    tableView->update();
}

void MainWindow::createMyItems(int count)
{
    QStringList listOne = QStringLiteral("A B C D E F G H I J K L M N O P Q R S T U V W X Y Z")
                          .split(QLatin1Char(' '));

    QVector<MyTableItem> rows;
    for ( int row = 0; row < count; row++ ) {
        MyTableItem newRow;
        newRow.setData( 0, QStringLiteral("#%1").arg(row, 6, 10, QLatin1Char('0')) );
        newRow.setData( 1, listOne[row % listOne.size()] );
        rows << newRow;
    }

    mTableModel.initModel( rows );
}

void MainWindow::on_btnCreateItems_clicked()
{
    QAbstractItemModel* model = tableView->model();
    const int count = spinBox->value();
    QTime stopWatch;
    stopWatch.start();

    qDebug("Creating %d items ...", count);
    if (model == &mStandardModel)   { createStandardItems(count); }
    else if (model == &mSortModel) { createMyItems(count); }
    qDebug("Created %d items in %d ms", model->rowCount(), stopWatch.elapsed());
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    Q_ASSERT(index < comboBox->count());

    QAbstractItemModel* model = nullptr;
    switch (index) {
    case 0: model = &mStandardModel; break;
    case 1: model = &mSortModel; break;
    default: break;
    }

    tableView->setModel( model );
}
