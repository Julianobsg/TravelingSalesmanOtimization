
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    graph = new GraphWidget;
    resize(700, this->height());
    this->setCentralWidget(graph);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOpen_lp_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this);
    if (!fileName.isEmpty())
        graph->LoadFile(fileName);
}
