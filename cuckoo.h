#ifndef CUCKOO_H
#define CUCKOO_H

#include <QMainWindow>
#include <QMessageBox>
#include <QFileDialog>
#include <QtNetwork/QtNetwork>
#include <QUrl>

namespace Ui {
    class Cuckoo;
}

class Cuckoo : public QMainWindow
{
    Q_OBJECT

public:
    explicit Cuckoo(QWidget *parent = 0);
    void checkReady();
    void connectTwitter();
    void requestToken();
    ~Cuckoo();

private slots:
    void on_actionQuit_triggered();
    void on_actionAuthor_triggered();
    void on_actionQt_triggered();
    void on_browseFilesButton_clicked();
    void on_timeBetween_dateTimeChanged();
    void on_twitterUsername_textChanged(const QString & text );
    void on_twitterPassword_textChanged(const QString & text );

private:
    Ui::Cuckoo *ui;
    QNetworkAccessManager* _nam;
    QString _file;
    QString _username;
    QString _password;
    QString _connectionStatus;
    QString _consumerKey;
    QString _consumerSecret;
    bool _started;
    bool _ready;


};

#endif // CUCKOO_H
