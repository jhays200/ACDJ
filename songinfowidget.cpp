#include "songinfowidget.h"
#include <QtGui>
#include "song.h"

SongInfoWidget::SongInfoWidget(QWidget *parent): QWidget(parent)
{
	//setup labels
	m_title = new QLabel(this);
	m_artist = new QLabel(this);
	m_album = new QLabel(this);
	slider = new Phonon::SeekSlider(this);
	slider->setIconVisible(false);
	m_time = new QLabel(this);

	QVBoxLayout * layout = new QVBoxLayout(this);
	layout->addWidget(m_title, 0, Qt::AlignHCenter);
	layout->addWidget(m_artist, 0, Qt::AlignHCenter);
	layout->addWidget(m_album, 0, Qt::AlignHCenter);
	layout->addWidget(slider);
	layout->addWidget(m_time);
}

void SongInfoWidget::SetCurrentSong(const Song & current)
{
	m_title->setText(current.title());
	m_artist->setText(current.artist());
	m_album->setText(current.album());
}

void SongInfoWidget::setTotalTime(qint64 total)
{
	m_timeEndSec = total % 1000;
	m_timeEndMin = m_timeEndSec / 60;
	m_timeEndSec %= 60;

	m_timePassedSec = 0;
	m_timePassedMin = 0;
	updateTime();
}

void SongInfoWidget::setCurrentTime(qint64 current)
{
	++m_timePassedSec;

	m_timePassedMin = m_timePassedSec / 60;
	m_timePassedSec %= 60;

	updateTime();
}

void SongInfoWidget::updateTime()
{
	QString text = tr("%1:%2 / %3:%4")
			.arg(m_timePassedMin).arg(m_timePassedSec, 2, 10, QChar('0'))
			.arg(m_timeEndMin).arg(m_timeEndSec, 2, 10, QChar('0'));
	m_time->setText(text);
}
