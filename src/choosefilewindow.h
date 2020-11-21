#ifndef CHOOSEFILEWINDOW_H
#define CHOOSEFILEWINDOW_H

#include <QWidget>
#include <QFileDialog>
#include "widget.h"

namespace Ui {
class ChooseFileWindow;
}

class ChooseFileWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ChooseFileWindow(QWidget *parent = nullptr);
    ~ChooseFileWindow();
    QString name;

private slots:
    void on_pushButton_clicked();

private:
    Ui::ChooseFileWindow *ui;
    QWidget* w = nullptr;
signals:
    void operate(QString);
};

#endif // CHOOSEFILEWINDOW_H
