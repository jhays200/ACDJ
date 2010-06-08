#include "songinfowidget.h"
#include <QtGui>
#include "song.h"

SongInfoWidget::SongInfoWidget(QWidget *parent): QWidget(parent)
{
	//setup timmer
	//SetUpTimer();

	//setup labels
	m_title = new QLabel(tr("Medicate"), this);
	m_artist = new QLabel(tr("Breaking Benjamin"), this);
	m_album = new QLabel(tr("Saturate"), this);;
	//m_time = new QLabel(this);

	/*QPushButton * bttnStart = new QPushButton(tr("Start Timer"), this);
	connect(bttnStart, SIGNAL(clicked()), this, SLOT(startTime()));*/

	QVBoxLayout * layout = new QVBoxLayout(this);
	layout->addWidget(m_title, 0, Qt::AlignHCenter);
	layout->addWidget(m_artist, 0, Qt::AlignHCenter);
	layout->addWidget(m_album, 0, Qt::AlignHCenter);
	//layout->addWidget(m_time);
}

void SongInfoWidget::SetCurrentSong(const Song & current)
{
	m_title->setText(current.title());
	m_artist->setText(current.artist());
	m_album->setText(current.album());
}

//void SongInfoWidget::stopTime()
//{
//	m_timer->stop();
//}
//
//void SongInfoWidget::startTime()
//{
//	m_timer->start();
//}
//
//void SongInfoWidget::incTime()
//{
//	QString time("%1:%2 / %3:%4");
//
//	if(++m_timePassedSec > m_timeEnd)
//	{
//		m_timePassedSec = 0;
//		m_timer->stop();
//	}
//
//	int secCurrent = m_timePassedSec % 60;
//	int minCurrent = m_timePassedSec / 60;
//	static int secEnd = m_timeEnd % 60;
//	static int minEnd = m_timeEnd / 60;
//
//	time = time.arg(minCurrent).arg(secCurrent, 2, 10, QChar('0')).arg(minEnd).arg(secEnd, 2);
//
//	m_time->setText(time);
//}
//
//void SongInfoWidget::SetUpTimer()
//{
//	m_timer = new QTimer(this);
//	m_timer->setSingleShot(false);
//	m_timer->setInterval(1000);
//
//	connect(m_timer, SIGNAL(timeout()), this, SLOT(incTime()) );
//}
