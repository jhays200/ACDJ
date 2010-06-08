#include "playlistmodel.h"
#include <QtGui>
#include "song.h"

PlaylistModel::PlaylistModel(QList<Song> * playlist, QObject * parent)
:QAbstractTableModel(parent), m_playlist(playlist), m_columnSorted(0), m_as_or_de(Qt::AscendingOrder)
{
	m_headers << tr("Title") << tr("Artist") << tr("Album") << tr("Genre");
}

int PlaylistModel::rowCount(const QModelIndex & parent) const
{
	return m_playlist->count();
}

int PlaylistModel::columnCount(const QModelIndex &parent) const
{
	return 4;
}

QVariant PlaylistModel::data(const QModelIndex &index, int role) const
{
	if(!index.isValid())
		return QVariant();

	if(index.row() >= m_playlist->count())
		return QVariant();

	if(role == Qt::DisplayRole)
	{
		/*QStringList stringList = m_playlist->at(index.row()).GetStringList();
		return stringList.at(index.column());*/

		const Song & item = m_playlist->at(index.row());

		switch(index.column())
		{
		case 0:
			return item.title();
		case 1:
			return item.artist();
		case 2:
			return item.album();
		case 3:
			return item.genre();
		default:
			return QVariant();
		}
	}
	else
		return QVariant();
}

QVariant PlaylistModel::headerData(int section, Qt::Orientation orientation,
							int role) const
{
	if(role != Qt::DisplayRole)
		return QVariant();

	if(orientation == Qt::Horizontal)
		return m_headers[section];
	else
		return QVariant();
}

void PlaylistModel::sort(int column, Qt::SortOrder order)
{
	//create a table of compare functions
	static COMPARE compares[8] = { &Song::compare_title_as,
									&Song::compare_artist_as,
									&Song::compare_album_as,
									&Song::compare_genre_as,
									&Song::compare_title_de,
									&Song::compare_artist_de,
									&Song::compare_album_de,
									&Song::compare_genre_de};
	m_columnSorted = column;
	m_as_or_de = order;

	if(order != Qt::AscendingOrder)
		column += 4;

	qSort(m_playlist->begin(), m_playlist->end(), compares[column]);
	dataChanged(createIndex(0, 0, this), createIndex(m_playlist->count() - 1, 0, this));
}

void PlaylistModel::AddSong(const Song & aCopy)
{
	beginInsertRows(QModelIndex(), 0, 0);
	m_playlist->prepend(aCopy);
	endInsertRows();
	sort(m_columnSorted, static_cast<Qt::SortOrder>(m_as_or_de));
}
