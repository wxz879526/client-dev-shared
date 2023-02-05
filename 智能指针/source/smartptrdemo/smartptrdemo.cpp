#include "smartptrdemo.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QDialog>
#include <QTimer>
#include <QPointer>

smartptrdemo::smartptrdemo(QWidget *parent)
    : QDialog(parent)
{
	QVBoxLayout *root = new QVBoxLayout;
	QPushButton *btn = new QPushButton("pop dialog");
	root->addWidget(btn);
	setLayout(root);

	connect(btn, &QPushButton::clicked, this, [&]() {
		QPointer<MyDialog> pDialog = new MyDialog(this);
		if (pDialog)
		{
			int x = 0;
		}
		if (pDialog->exec() == QDialog::Accepted)
		{
			
		}

		if (pDialog)
			delete pDialog;
	});
	resize(600, 400);
}

MyDialog::MyDialog(QWidget *parent)
	: QDialog(parent)
{
	QVBoxLayout *root = new QVBoxLayout;
	QPushButton *btn = new QPushButton("close parent");
	root->addWidget(btn);
	setLayout(root);
	resize(300, 200);

	connect(btn, &QPushButton::clicked, this, [=]() {
		delete parent;
	});
}

MyDialog::~MyDialog()
{

}