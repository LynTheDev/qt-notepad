//
// Created by nattie on 3/12/23.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include <QFileDialog>
#include <iostream>
#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    ui->editor->setTabStopDistance(20);
    this->setWindowIcon(QIcon(":/icon.png"));
    this->setCentralWidget(ui->editor);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_actionNew_triggered() {
    ui->editor->setPlainText(QString());
}

void MainWindow::on_actionOpen_triggered() {
    QString path = QFileDialog::getOpenFileName(this, "Open");
    if (path.isEmpty()) {
        return;
    }

    QFile file(path);
    openFile = path;

    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        setWindowTitle(path);
        ui->editor->setPlainText(file.readAll());
    } else {
        return;
    }

    file.close();
}

void MainWindow::on_actionSave_triggered() {
    if (openFile == "nil") {
        QString path = QFileDialog::getSaveFileName(
                this, "Save As", "",
                tr("Text Files (*.txt);;C++ Source Files (*.cpp);;C/C++ Header Files(*.h);;All Files (*)")
        );

        if (path.isEmpty()) {
            return;
        }

        QFile file_new(path);
        openFile = path;

        if (file_new.open(QIODevice::WriteOnly)) {
            setWindowTitle(path);
            file_new.write(ui->editor->toPlainText().toLatin1());
        } else {
            return;
        }

        file_new.close();

        return;
    }

    if (openFile.isEmpty()) {
        return;
    }

    QFile file(openFile);

    if (file.open(QIODevice::WriteOnly)) {
        setWindowTitle(openFile);
        file.write(ui->editor->toPlainText().toLatin1());
    } else {
        return;
    }

    file.close();
}

void MainWindow::on_actionSave_As_triggered() {
    QString path = QFileDialog::getSaveFileName(
            this, "Save As", "",
            tr("Text Files (*.txt);;C++ Source Files (*.cpp);;C/C++ Header Files(*.h);;All Files (*)")
    );

    if (path.isEmpty()) {
        return;
    }

    QFile file(path);
    openFile = path;

    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        setWindowTitle(path);
        file.write(ui->editor->toPlainText().toLatin1());
    } else {
        return;
    }

    file.close();
}

void MainWindow::on_actionQuit_triggered() {
    this->close();
}

void MainWindow::on_actionCopy_triggered() {
    ui->editor->copy();
}

void MainWindow::on_actionPaste_triggered() {
    ui->editor->paste();
}

void MainWindow::on_actionCut_triggered() {
    ui->editor->cut();
}

void MainWindow::on_actionRedo_triggered() {
    ui->editor->redo();
}


void MainWindow::on_actionUndo_triggered() {
    ui->editor->undo();
}
