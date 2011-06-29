#include "cuckoo.h"
#include "ui_cuckoo.h"

Cuckoo::Cuckoo(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Cuckoo)
{
    ui->setupUi(this);
}

Cuckoo::~Cuckoo()
{
    delete ui;
}
