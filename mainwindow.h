#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}
class StyleDialog;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_action_Quit_triggered();

    void on_actionS_tyle_Dialog_triggered();

private:
    Ui::MainWindow *ui;
    StyleDialog *m_styleDialog;
};

#endif // MAINWINDOW_H
