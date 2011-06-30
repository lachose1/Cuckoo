#include <QMessageBox>
#include <QFileDialog>
#include "cuckoo.h"
#include "ui_cuckoo.h"

Cuckoo::Cuckoo(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Cuckoo), _file("")
{
    ui->setupUi(this);
}

Cuckoo::~Cuckoo()
{
    delete ui;
}

void Cuckoo::on_actionQuit_triggered()
{
    QCoreApplication::quit();
}

void Cuckoo::on_actionAuthor_triggered()
{
    QMessageBox::information(this, "About author", "Coded by : Hugo Laliberté");
}

void Cuckoo::on_actionQt_triggered()
{
    QMessageBox::aboutQt(this);
}

void Cuckoo::on_browseFilesButton_clicked()
{
    _file = QFileDialog::getOpenFileName(this, "Choose file", "", "Text files (*.txt)");
    ui->tweetFile->setText(_file);
}
