#include "MainWindowe.hxx"

#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindowe window;

    window.show();
    return a.exec();
}
