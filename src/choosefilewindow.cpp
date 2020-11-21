#include "choosefilewindow.h"
#include "ui_choosefilewindow.h"

ChooseFileWindow::ChooseFileWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChooseFileWindow)
{
    ui->setupUi(this);
}

ChooseFileWindow::~ChooseFileWindow()
{
    if(w!=nullptr) delete w;
    delete ui;
}

void ChooseFileWindow::on_pushButton_clicked()
{
    name = QFileDialog::getOpenFileName(0, "Open Dialog", "", "*.xml");
    if(name.isEmpty()) return;
    w = new Widget(name);
    w->show();
}
