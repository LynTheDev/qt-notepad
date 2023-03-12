#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    MainWindow w;
    w.setWindowTitle("Untitled");
    w.setMinimumSize(300, 200);
    w.show();

return QApplication::exec();
}
