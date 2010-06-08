#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <Phonon/MediaObject>
#include <QtGui/QWidget>
#include <QList>
#include <QStringList>
#include "song.h"

class QTreeView;
class QTableView;
class QFileSystemModel;
class PlaylistModel;
class SongInfoWidget;
class QModelIndex;
class MainWindow;

class MainWidget: public QWidget
{
	Q_OBJECT

public:
	MainWidget(QWidget *parent = 0);

	static bool playing;

public slots:
	void AddFileSlot();
	void SkipBackSlot();
	void PlayPauseSlot();
	void StopSlot();
	void SkipForwardSlot();
	void HelpSlot();
	//void AboutToFinish();

protected:
	virtual void resizeEvent(QResizeEvent * event);

private slots:
	void NewMetaData(Phonon::State newState, Phonon::State);
	void FileSelected(const QModelIndex & index );
	void AddFileBttn();
	void ClearBttn();
	void EnqueNext();
	void SongFinished();

private:
	//private methods
	QLayout * SetUpLibraryBrowser();
	void SetUpPlaylistView();
	void SetUpPlayer();

	//private members

	//the playlist of songs
	QList<Song> m_playlist;
	QList<Song>::Iterator m_current;

	//The file browser for users
	QTreeView * m_fileView;
	QFileSystemModel * m_fileModel;
	QString m_selectedFile;

	//The Playlist MVC stuff
	QTableView * m_playlistView;
	PlaylistModel * m_playlistModel;

	//Media Objects one to process metadata and one to play music
	Phonon::MediaObject * m_musicPlayer;
	Phonon::MediaObject * m_metaHandler;

	//files needing to be added to the list
	QStringList m_filesToBeAdded;

	//song info widget
	SongInfoWidget * m_infoWidget;

	//parent *
	MainWindow * m_parent;
};

#endif
