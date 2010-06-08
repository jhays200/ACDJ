#include "mainwindow.h"
#include "mainwidget.h"
#include <QtGui>

MainWindow::MainWindow(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);
	SetUpToolbar();

	MainWidget * mainW = new MainWidget(this);
	setCentralWidget(mainW);

	//connect Actions
	//music actions
	connect(ui.actionSkip_Backward, SIGNAL(triggered()), mainW, SLOT(SkipBackSlot()));
	connect(ui.action_Play_Pause, SIGNAL(triggered()), mainW, SLOT(PlayPauseSlot()));
	connect(ui.action_Stop, SIGNAL(triggered()), mainW, SLOT(StopSlot()));
	connect(ui.actionSkip_Forward, SIGNAL(triggered()), mainW, SLOT(SkipForwardSlot()));

	//Exit should close window
	connect(ui.action_Exit, SIGNAL(triggered()), this, SLOT(close()));

	//Add Action
	connect(ui.actionAdd_File, SIGNAL(triggered()), mainW, SLOT(AddFileSlot()));

	//help Action
	connect(ui.actionHelp, SIGNAL(triggered()), mainW, SLOT(HelpSlot()));

	//about Action
	connect(ui.actionAbout, SIGNAL(triggered()), this, SLOT(AboutSlot()));
}

MainWindow::~MainWindow()
{
	
}

void MainWindow::ChangeToPlay()
{
	ui.action_Play_Pause->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
	ui.action_Play_Pause->setText(tr("Play"));
}

void MainWindow::ChangeToPause()
{
	ui.action_Play_Pause->setIcon(style()->standardIcon(QStyle::SP_MediaPause));
	ui.action_Play_Pause->setText(tr("Pause"));
}

void MainWindow::AboutSlot()
{
	QMessageBox msgBox;
	msgBox.setText(tr("Made by Jonathan Hays\nFor CST 238: GUI"));
	msgBox.setStandardButtons(QMessageBox::Ok);
	msgBox.setDefaultButton(QMessageBox::Ok);
	msgBox.exec();
}

//void MainWindow::NewState(Phonon::State newState, Phonon::State)
//{
//	switch (newState)
//	{
//	 case Phonon::ErrorState:
////		 if (mediaObject->errorType() == Phonon::FatalError) {
////			 QMessageBox::warning(this, tr("Fatal Error"),
////			 mediaObject->errorString());
////		 } else {
////			 QMessageBox::warning(this, tr("Error"),
////			 mediaObject->errorString());
////		 }
//		 break;
//	 case Phonon::PlayingState:
//			 ui.action_Play_Pause->setIcon(style()->standardIcon(QStyle::SP_MediaPause));
//			 ui.action_Play_Pause->setText(tr("Pause"));
//			 MainWidget::playing = true;
//			 break;
//	 case Phonon::StoppedState:
//			 ui.action_Play_Pause->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
//			 ui.action_Play_Pause->setText(tr("Play"));
//			 MainWidget::playing = false;
//			 break;
//	 case Phonon::PausedState:
//			 ui.action_Play_Pause->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
//			 ui.action_Play_Pause->setText(tr("Play"));
//			 MainWidget::playing = false;
//			 break;
//	 case Phonon::BufferingState:
//			 break;
//	 default:
//		 ;
//	}
//}

void MainWindow::SetUpToolbar()
{
	//add icon's from window style
	ui.actionSkip_Backward->setIcon(style()->standardIcon(QStyle::SP_MediaSkipBackward));
	ui.action_Play_Pause->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
	ui.action_Stop->setIcon(style()->standardIcon(QStyle::SP_MediaStop));
	ui.actionSkip_Forward->setIcon(style()->standardIcon(QStyle::SP_MediaSkipForward));

	//make a toolbar and add actions to it
	QToolBar * toolbar = new QToolBar(this);
	toolbar->setFloatable(false);
	toolbar->setMovable(false);

	//add actions to toolbar
	toolbar->addAction(ui.actionSkip_Backward);
	toolbar->addAction(ui.action_Play_Pause);
	toolbar->addAction(ui.action_Stop);
	toolbar->addAction(ui.actionSkip_Forward);

	//add toolbar to main window
	addToolBar(Qt::TopToolBarArea, toolbar);
}
