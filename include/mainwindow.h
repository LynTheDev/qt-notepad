//
// Created by nattie on 3/12/23.
//

#ifndef SIMPLE_MAINWINDOW_H
#define SIMPLE_MAINWINDOW_H

#include <QMainWindow>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow() override;

private slots:
    void on_actionNew_triggered();
    void on_actionQuit_triggered();
    void on_actionOpen_triggered();
    void on_actionSave_As_triggered();
    void on_actionSave_triggered();

    void on_actionCopy_triggered();
    void on_actionPaste_triggered();
    void on_actionCut_triggered();
    void on_actionUndo_triggered();
    void on_actionRedo_triggered();

private:
    QString openFile = "nil";
    Ui::MainWindow *ui;
};


#endif //SIMPLE_MAINWINDOW_H
