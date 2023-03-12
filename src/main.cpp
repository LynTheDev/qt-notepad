#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow w;
    if (argc > 1) {
        w.open_window(argv[1]);
    } else {
        w.setWindowTitle("Untitled");
    }
    w.setMinimumSize(300, 200);
    w.show();

return QApplication::exec();
}
