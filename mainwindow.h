#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include "ui_mainwindow.h"
#include <Phonon/MediaObject>

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = 0, Qt::WFlags flags = 0);
	~MainWindow();
	void ChangeToPause();
	void ChangeToPlay();

public slots:
	void AboutSlot();

private:
	Ui::MainWindowClass ui;

	//private methods
	void SetUpToolbar();
};

#endif // MAINWINDOW_H
