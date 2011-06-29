#ifndef CUCKOO_H
#define CUCKOO_H

#include <QMainWindow>

namespace Ui {
    class Cuckoo;
}

class Cuckoo : public QMainWindow
{
    Q_OBJECT

public:
    explicit Cuckoo(QWidget *parent = 0);
    ~Cuckoo();

private:
    Ui::Cuckoo *ui;
};

#endif // CUCKOO_H
