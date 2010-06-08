#include "playlistmodel.h"
#include <QtGui>
#include "song.h"

//a compare lookup table for Songs
typedef bool(*COMPARE)(const Song &s1, const Song &s2);
const COMPARE COMPARES[10] = {   &Song::compare_uid_as,
								&Song::compare_title_as,
								&Song::compare_artist_as,
								&Song::compare_album_as,
								&Song::compare_genre_as,
								&Song::compare_uid_de,
								&Song::compare_title_de,
								&Song::compare_artist_de,
								&Song::compare_album_de,
								&Song::compare_genre_de
							};

PlaylistModel::PlaylistModel(QList<Song> * playlist, QObject * parent)
:QAbstractTableModel(parent), m_playlist(playlist), m_columnSorted(0), m_as_or_de(Qt::AscendingOrder)
{
	m_headers << tr("ID") << tr("Title") << tr("Artist") << tr("Album") << tr("Genre");
}

int PlaylistModel::rowCount(const QModelIndex & parent) const
{
	return m_playlist->count();
}

int PlaylistModel::columnCount(const QModelIndex &parent) const
{
	return 5;
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
			return item.uid();
		case 1:
			return item.title();
		case 2:
			return item.artist();
		case 3:
			return item.album();
		case 4:
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
	m_columnSorted = column;
	m_as_or_de = order;

	if(order != Qt::AscendingOrder)
		column += 5;

	qSort(m_playlist->begin(), m_playlist->end(), COMPARES[column]);
	reset();
}

void PlaylistModel::AddSong(const Song & aCopy)
{
	if(m_playlist->empty())
	{
		beginInsertRows(QModelIndex(), 0, 0);
		m_playlist->prepend(aCopy);
		endInsertRows();
	}
	else //insert ordered
	{
		int column = m_columnSorted;
		QList<Song>::Iterator iter = m_playlist->begin();

		//add offset for compare if ascending or descending
		if(m_as_or_de != Qt::AscendingOrder)
			column += 5;

		//get the function to use
		COMPARE compare = COMPARES[column];

		//Find where to insert
		while(iter != m_playlist->end())
		{
			if(compare(aCopy, *iter))
				break;
			++iter;
		}

		//check if it is the end
		if(iter == m_playlist->end())
		{
			beginInsertRows(QModelIndex(), m_playlist->count() - 1, m_playlist->count() - 1 );
			m_playlist->append(aCopy);
			endInsertRows();
		}
		else
		{
			//insert Node into list
			int offset = m_playlist->begin() - iter;
			--iter;

			//insert the row into the table
			beginInsertRows(QModelIndex(), offset, offset);
			m_playlist->insert(iter, aCopy);
			endInsertRows();
		}
	}

}

void PlaylistModel::ClearList()
{
	beginRemoveRows(QModelIndex(), 0, m_playlist->count() - 1);
	m_playlist->clear();
	endRemoveRows();
}
