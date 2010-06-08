#ifndef SONGINFOWIDGET_H
#define SONGINFOWIDGET_H

#include <QtGui/QWidget>

class QLabel;
class QTimer;
class Song;

class SongInfoWidget: public QWidget
{
	Q_OBJECT

public:
	SongInfoWidget(QWidget *parent = 0);
	void SetCurrentSong(const Song & current);

//public slots:
//	void stopTime();
//	void startTime();
//
//private slots:
//	void incTime();

private:
	//private methods
	//void SetUpTimer();

	//private members
	QLabel * m_title;
	QLabel * m_artist;
	QLabel * m_album;
	//QLabel * m_time;
	/*QTimer * m_timer;

	int m_timeEnd;
	int m_timePassedSec;*/
};

#endif