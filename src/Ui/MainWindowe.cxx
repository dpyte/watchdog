#include "MainWindowe.hxx"
#include "./ui_MainWindowe.h"

MainWindowe::MainWindowe(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindowe) {
    QMainWindow::showFullScreen();
    ui->setupUi(this);
}

MainWindowe::~MainWindowe() {
    delete ui;
}

