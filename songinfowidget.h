#ifndef SONGINFOWIDGET_H
#define SONGINFOWIDGET_H

#include <QtGui/QWidget>
#include <Phonon/SeekSlider>

class QLabel;
class QTimer;
class Song;

class SongInfoWidget: public QWidget
{
	Q_OBJECT

public:
	SongInfoWidget(QWidget *parent = 0);
	void SetCurrentSong(const Song & current);

	//public widget
	Phonon::SeekSlider * slider;

public slots:
	void setTotalTime(qint64 total);
	void setCurrentTime(qint64 current);

private:
	//private methods
	void updateTime();

	//private members
	QLabel * m_title;
	QLabel * m_artist;
	QLabel * m_album;
	QLabel * m_time;

	int m_timeEndSec;
	int m_timeEndMin;
	int m_timePassedSec;
	int m_timePassedMin;
};

#endif
