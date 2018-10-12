#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QApplication>
#include <styledialog.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_styleDialog = new StyleDialog(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_action_Quit_triggered()
{
    qApp->quit();
}

void MainWindow::on_actionS_tyle_Dialog_triggered()
{
    m_styleDialog->show();
}
