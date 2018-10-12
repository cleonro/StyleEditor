#ifndef STYLEDIALOG_H
#define STYLEDIALOG_H

#include <QDialog>

namespace Ui {
class StyleDialog;
}

class StyleDialog : public QDialog
{
    Q_OBJECT

public:
    explicit StyleDialog(QWidget *parent = nullptr);
    ~StyleDialog();

private:
    Ui::StyleDialog *ui;
};

#endif // STYLEDIALOG_H
