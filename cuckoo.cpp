#include <QMessageBox>
#include <QFileDialog>
#include "cuckoo.h"
#include "ui_cuckoo.h"

Cuckoo::Cuckoo(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Cuckoo), _file(""), _username(""), _password(""), _connectionStatus(""), _started(false), _ready(false)
{
    ui->setupUi(this);
    ui->timeLeft->setTime(ui->timeBetween->time());
}

Cuckoo::~Cuckoo()
{
    delete ui;
}

void Cuckoo::checkReady()
{
    if(!ui->twitterUsername->text().isEmpty() && !ui->twitterUsername->text().isEmpty())
    {
        _ready = true;
        connectTwitter();
    }
    else
        _ready = false;
}

void Cuckoo::connectTwitter()
{

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
    checkReady();
}

void Cuckoo::on_timeBetween_dateTimeChanged()
{
    ui->timeLeft->setTime(ui->timeBetween->time());
}

void Cuckoo::on_twitterUsername_textChanged(const QString & text )
{
    _username = text;
    checkReady();
}

void Cuckoo::on_twitterPassword_textChanged(const QString & text )
{
    _password = text;
    checkReady();
}
