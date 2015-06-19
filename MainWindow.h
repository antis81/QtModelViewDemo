#pragma once

#include <MyTableModel.h>

#include <QMainWindow>
#include <QStandardItemModel>
#include <QSortFilterProxyModel>

#include "ui_MainWindow.h"


class MainWindow : public QMainWindow, Ui::MainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

private slots:
    void on_btnCreateItems_clicked();

    void on_comboBox_currentIndexChanged(int index);

private:
    QStandardItemModel      mStandardModel;

    MyTableModel            mTableModel;
    QSortFilterProxyModel   mSortModel;

    void createStandardItems(int count);
    void createMyItems(int count);
};
