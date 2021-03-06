#include "mainwidget.h"
#include "mainwindow.h"
#include "songinfowidget.h"
#include "playlistmodel.h"
#include <QtGui>
#include <QFileSystemModel>
#include <cstdlib>

bool MainWidget::playing = false; 

MainWidget::MainWidget(QWidget *parent): QWidget(parent), m_current(0),
m_parent(dynamic_cast<MainWindow *>(parent))
{
	//intialization stuff
	SetUpPlaylistView();

	//stuff
	QVBoxLayout * playlistLayout = new QVBoxLayout;
	m_infoWidget = new SongInfoWidget(this);
	playlistLayout->addWidget(m_infoWidget);
	playlistLayout->addWidget(m_playlistView);

	//main layout
	QHBoxLayout * mainLayout = new QHBoxLayout(this);
	mainLayout->addLayout(SetUpLibraryBrowser(), -50);
	mainLayout->addLayout(playlistLayout);
	setLayout(mainLayout);

	//setting up media objects
	SetUpPlayer();
	//meta handler to process media data
	m_metaHandler = new Phonon::MediaObject(this);
	connect(m_metaHandler, SIGNAL(stateChanged(Phonon::State,Phonon::State)), this, SLOT(NewMetaData(Phonon::State,Phonon::State)));
}

void MainWidget::AddFileSlot()
{
//	QMessageBox test(this);
//
//	test.setText(tr("This should add files"));
//	test.setStandardButtons(QMessageBox::Ok);
//	test.setDefaultButton(QMessageBox::Ok);
//	test.exec();

	QStringList files = QFileDialog::getOpenFileNames(this, tr("Select Music Files"),
						QDesktopServices::storageLocation(QDesktopServices::MusicLocation));

	if(files.isEmpty())
		return;

	foreach(QString string, files)
	{
		m_filesToBeAdded.append(string);
	}

	if(!m_filesToBeAdded.isEmpty())
	{
		Phonon::MediaSource source(m_filesToBeAdded.first());
		m_filesToBeAdded.removeFirst();
		m_metaHandler->setCurrentSource(source);
	}
}

void MainWidget::SkipBackSlot()
{
	if(m_current != 0)
	{
		--m_current;
		if(playing)
		{
			m_musicPlayer->setCurrentSource(m_playlist[m_current].media());
			m_infoWidget->SetCurrentSong(m_playlist[m_current]);
			m_musicPlayer->play();
		}
	}
}

void MainWidget::PlayPauseSlot()
{
//	QMessageBox test(this);
//
//	test.setText(tr("This should Play or Pause Song"));
//	test.setStandardButtons(QMessageBox::Ok);
//	test.setDefaultButton(QMessageBox::Ok);
//	test.exec();
	if(playing)
	{
		m_musicPlayer->pause();
		playing = false;
		m_parent->ChangeToPlay();
	}
	else if(!m_playlist.isEmpty())
	{
		playing = true;
		if(m_musicPlayer->state() != Phonon::PausedState)
		{
			m_infoWidget->SetCurrentSong(m_playlist[m_current]);
			m_musicPlayer->setCurrentSource(m_playlist[m_current].media());
		}
		m_parent->ChangeToPause();
		m_musicPlayer->play();

	}
}

void MainWidget::StopSlot()
{
//	QMessageBox test(this);
//
//	test.setText(tr("This should stop music"));
//	test.setStandardButtons(QMessageBox::Ok);
//	test.setDefaultButton(QMessageBox::Ok);
//	test.exec();

	m_musicPlayer->stop();
	playing = false;
	m_parent->ChangeToPlay();
}

void MainWidget::SkipForwardSlot()
{
	if(m_current != m_playlist.count() - 1)
	{
		++m_current;
		if(playing)
		{
			m_musicPlayer->stop();
			m_musicPlayer->setCurrentSource(m_playlist[m_current].media());
			m_infoWidget->SetCurrentSong(m_playlist[m_current]);
			m_musicPlayer->play();
		}
	}
}

void MainWidget::resizeEvent(QResizeEvent * event)
{
	m_playlistView->resizeColumnsToContents();
	QWidget::resizeEvent(event);
}

void MainWidget::NewMetaData(Phonon::State newState, Phonon::State)
{
	//Check if there was error reading the file
	if(newState == Phonon::ErrorState)
	{
		QMessageBox::warning(this, tr("Error Opening File"),
							 m_metaHandler->errorString());

		//Move on to next source
		if(!m_filesToBeAdded.isEmpty())
		{
			Phonon::MediaSource source(m_filesToBeAdded.first());
			m_filesToBeAdded.removeFirst();
			m_metaHandler->setCurrentSource(source);
		}
		return;
	}

	//valid states for the metaObject
	if(newState != Phonon::StoppedState && newState != Phonon::PausedState)
		return;

	//check if the media source has a valid type
	if(m_metaHandler->currentSource().type() == Phonon::MediaSource::Invalid)
		return;

	//now we can deal with the meta data without worries
	QMap<QString, QString> metadata = m_metaHandler->metaData();
	Song tmp(QString("%1").arg(m_playlist.count() + 1, 2),
			m_metaHandler->currentSource(),
			 metadata.value(tr("TITLE")),
			 metadata.value(tr("ARTIST")),
			 metadata.value(tr("ALBUM")),
			 metadata.value(tr("GENRE")) );
	m_playlistModel->AddSong(tmp);

	if(m_filesToBeAdded.isEmpty())
	{
		m_playlistView->resizeColumnsToContents();
		
		if(!playing)
		{
			m_current = 0;
		}
	}
	else
	{
		Phonon::MediaSource source(m_filesToBeAdded.first());
		m_filesToBeAdded.removeFirst();
		m_metaHandler->setCurrentSource(source);
	}
}

void MainWidget::FileSelected(const QModelIndex & index )
{
	QFileInfo info = m_fileModel->fileInfo(index);

	if(info.isFile())
	{
		m_selectedFile = m_fileModel->filePath(index);
	}
}

void MainWidget::AddFileBttn()
{
	if(!m_selectedFile.isNull())
	{
		Phonon::MediaSource source(m_selectedFile);
		m_metaHandler->setCurrentSource(source);
		m_selectedFile.clear();
	}
}

void MainWidget::EnqueNext()
{
	if(m_current != m_playlist.count() - 1)
	{
		++m_current;
		m_musicPlayer->enqueue( m_playlist[m_current].media());
		m_infoWidget->SetCurrentSong(m_playlist[m_current]);
	}
}

void MainWidget::SongFinished()
{
	if(m_current == m_playlist.count() - 1)
	{
		m_parent->ChangeToPlay();
		playing = false;
		m_current = 0;
	}
}

void MainWidget::SongDClicked(const QModelIndex &index)
{
	m_current = index.row();

	m_musicPlayer->stop();
	playing = false;
	PlayPauseSlot();
}

void MainWidget::LibDClicked(const QModelIndex & index)
{
	QString path = m_fileModel->filePath(index);

	if(!m_fileModel->isDir(index))
		m_metaHandler->setCurrentSource(Phonon::MediaSource(path));
}

void MainWidget::ClrBttn()
{
	m_playlistModel->ClearList();
	StopSlot();
}

QLayout * MainWidget::SetUpLibraryBrowser()
{
	//setup a model for the Tree view

	//Find the users Music directory or default to the home folder
	QDir musicFolder(QDir::homePath());
	if( !musicFolder.cd(tr("Music")) )
		musicFolder.setPath(QDir::homePath());

	//create the model to be used by the view
	m_fileModel = new QFileSystemModel(this);
	m_fileModel->setRootPath(musicFolder.path());

	//setup the tree view
	m_fileView = new QTreeView(this);
	m_fileView->setModel(m_fileModel);
	m_fileView->setRootIndex(m_fileModel->index(musicFolder.path()));
	m_fileView->setSortingEnabled(true);
	connect(m_fileView, SIGNAL(clicked(QModelIndex)), this, SLOT(FileSelected(QModelIndex)));
	connect(m_fileView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(LibDClicked(QModelIndex)));

	//add a button to the layout
	QPushButton * addBttn = new QPushButton(tr("Add File"), this);
	connect(addBttn, SIGNAL(clicked()), this, SLOT(AddFileBttn()));

	QPushButton * clearBttn = new QPushButton(tr("Clear Playlist"), this);
	connect(clearBttn, SIGNAL(clicked()), this, SLOT(ClrBttn()));

	QVBoxLayout * layout = new QVBoxLayout;
	layout->addWidget(m_fileView);
	layout->addWidget(addBttn);
	layout->addWidget(clearBttn);

	return layout;
}

void MainWidget::HelpSlot()
{
	system("hh.exe help.chm");
}

void MainWidget::SetUpPlaylistView()
{
	m_playlistModel = new PlaylistModel(&m_playlist, this);
	m_playlistView = new QTableView(this);

	//set the model to
	m_playlistView->setModel(m_playlistModel);
	//set sorting enabled
	m_playlistView->setSortingEnabled(true);
	//selects one row at a time
	m_playlistView->setSelectionBehavior(QAbstractItemView::SelectRows);
	//sets how things are selected from the table
	m_playlistView->setSelectionMode(QAbstractItemView::SingleSelection);
	//hide the verticle headers that aren't being used
	m_playlistView->verticalHeader()->hide();
	connect(m_playlistView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(SongDClicked(QModelIndex)));
}

void MainWidget::SetUpPlayer()
{
//	MainWidget * access = dynamic_cast<MainWidget *>(parent());
	m_musicPlayer = Phonon::createPlayer(Phonon::MusicCategory);
	m_musicPlayer->setParent(this);
	m_musicPlayer->setTransitionTime(500);
	m_musicPlayer->setTickInterval(1000);

	//add a seek slider to songinfowidget
	m_infoWidget->slider->setMediaObject(m_musicPlayer);

	connect(m_musicPlayer, SIGNAL(aboutToFinish()), this, SLOT(EnqueNext()));
	connect(m_musicPlayer, SIGNAL(finished()), this, SLOT(SongFinished()));
	connect(m_musicPlayer, SIGNAL(tick(qint64)), m_infoWidget, SLOT(setCurrentTime(qint64)));
	connect(m_musicPlayer, SIGNAL(totalTimeChanged(qint64)), m_infoWidget, SLOT(setTotalTime(qint64)));
}
