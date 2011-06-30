#ifndef CUCKOO_H
#define CUCKOO_H

#include <QMainWindow>
#include <QMessageBox>
#include <QFileDialog>

namespace Ui {
    class Cuckoo;
}

class Cuckoo : public QMainWindow
{
    Q_OBJECT

public:
    explicit Cuckoo(QWidget *parent = 0);
    ~Cuckoo();

private slots:
    void on_actionQuit_triggered();
    void on_actionAuthor_triggered();
    void on_actionQt_triggered();
    void on_browseFilesButton_clicked();

private:
    Ui::Cuckoo *ui;
    QString _file;
};

#endif // CUCKOO_H
