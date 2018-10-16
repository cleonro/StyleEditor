#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QApplication>
#include <styledialog.h>
#include <QFileDialog>
#include <QFileSystemWatcher>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_styleDialog = new StyleDialog(this);
    m_fileDialog = new QFileDialog(this, Qt::Dialog);
    m_fileSystemModel = new QFileSystemWatcher(this);

    connect(m_fileSystemModel, &QFileSystemWatcher::fileChanged, this, &MainWindow::onFileModified);
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

void MainWindow::on_action_Load_triggered()
{
    m_fileDialog->setFileMode(QFileDialog::AnyFile);
    m_fileDialog->setWindowTitle(tr("Load stylesheet file"));
    m_fileDialog->setNameFilters(QStringList() << tr("Stylesheets (*.stylesheet)")
                                                << tr("Css (*.css)")
                                                << tr("Any file (*.*)"));
    if(m_fileDialog->exec())
    {
        QStringList fileNames = m_fileDialog->selectedFiles();
        if(fileNames.count() == 0)
        {
            return;
        }
        QFile stylesheetFile(fileNames[0]);
        stylesheetFile.open(QIODevice::ReadOnly);
        QString style = stylesheetFile.readAll();
        stylesheetFile.close();
        qApp->setStyleSheet(style);
        m_fileSystemModel->removePaths(m_fileSystemModel->files());
        m_fileSystemModel->addPath(fileNames[0]);

        this->setWindowTitle(tr("MainWindow - ") + fileNames[0]);

        qDebug() << Q_FUNC_INFO << m_fileSystemModel->files();
    }
}

void MainWindow::onFileModified(const QString &filePath)
{
    QFile stylesheetFile(filePath);
    stylesheetFile.open(QIODevice::ReadOnly);
    QString style = stylesheetFile.readAll();
    qApp->setStyleSheet(style);

    //? whys is file watcher emty here?
    m_fileSystemModel->addPath(filePath);

    qDebug() << Q_FUNC_INFO << m_fileSystemModel->files();
}

void MainWindow::on_action_New_triggered()
{
    qApp->setStyleSheet("");
}
