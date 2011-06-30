#include <QMessageBox>
#include <QFileDialog>
#include <QtNetwork/QtNetwork>
#include <QUrl>
#include <cstdlib>
#include <string>
#include "cuckoo.h"
#include "ui_cuckoo.h"

Cuckoo::Cuckoo(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Cuckoo), _file(""), _username(""), _password(""), _connectionStatus(""),
    _consumerKey("A1UK5a0ZDRmQ1YIQTq58eA"), _consumerSecret("2eeFnhWzYNYOp0ync3U3oQxHFo3xm5N2izrz1b2I3bg"),
    _started(false), _ready(false)
{
    ui->setupUi(this);
    ui->timeLeft->setTime(ui->timeBetween->time());
    QNetworkAccessManager* _nam = new QNetworkAccessManager(this);
}

Cuckoo::~Cuckoo()
{
    delete ui;
    delete _nam;
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
    requestToken();

}

void Cuckoo::requestToken()
{
    QDateTime date;
    uint timestamp = date.toTime_t();
    QString timestampStr;
    timestampStr.setNum(timestamp);

    QByteArray data = QByteArray("POST") + "&" +
            QUrl::toPercentEncoding("http://api.twitter.com/oauth/request_token") + "&" +
            "oauth_callback" + "%3D" +
            QUrl::toPercentEncoding("http://localhost:3005/the_dance/process_callback?service_provider_id=11") + "%26" +
            "oauth_consumer_key" + "%3D" +
            QUrl::toPercentEncoding(_consumerKey) + "%26" +
            "oauth_nonce" + "%3D" +
            QUrl::toPercentEncoding(_file.toAscii().toBase64()) + "%26" +
            "oauth_signature_method" + "%3D" +
            QUrl::toPercentEncoding("HMAC-SHA1") + "%26" +
            "oauth_timestamp" + "%3D" +
            QUrl::toPercentEncoding(timestampStr) + "%26" +
            "oauth_version" + "%3D" +
            QUrl::toPercentEncoding("1.0");
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
