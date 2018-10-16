#include "styledialog.h"
#include "ui_styledialog.h"


StyleDialog::StyleDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StyleDialog)
{
    ui->setupUi(this);
    ui->color->setWindowFlags(Qt::Widget);
    ui->color->show();
}

StyleDialog::~StyleDialog()
{
    delete ui;
}
