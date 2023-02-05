#include "mainwindow.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QDialog>
#include <QTimer>
#include "smartptrdemo.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
	QVBoxLayout *root = new QVBoxLayout;
	setWindowTitle("mainwindow");
	resize(600, 400);

	smartptrdemo *dlg = new smartptrdemo(this);
	dlg->resize(300, 200);
	dlg->show();
}