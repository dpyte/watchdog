#ifndef MAINWINDOWE_HXX
#define MAINWINDOWE_HXX

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindowe; }
QT_END_NAMESPACE

class MainWindowe : public QMainWindow {
    Q_OBJECT
public:
    MainWindowe(QWidget *parent = nullptr);
    ~MainWindowe();

private:
    Ui::MainWindowe *ui;
};
#endif // MAINWINDOWE_HXX
