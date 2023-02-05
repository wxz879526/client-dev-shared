#pragma once

#include <QtWidgets/QWidget>
#include <QDialog>
#include "ui_smartptrdemo.h"

class MyDialog : public QDialog
{
	Q_OBJECT

public:
	MyDialog(QWidget *parent);
	~MyDialog();
};

class smartptrdemo : public QDialog
{
    Q_OBJECT

public:
    smartptrdemo(QWidget *parent = Q_NULLPTR);

private:
};
