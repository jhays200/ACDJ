#ifndef PLAYLISTMODEL_H
#define PLAYLISTMODEL_H

#include <QAbstractTableModel>
#include <QStringList>

class Song;

template <typename T>
class QList;

class PlaylistModel : public QAbstractTableModel
{
	Q_OBJECT
public:
	//no default constructor because it would break the model
	PlaylistModel(QList<Song> * playlist = 0, QObject * parent = 0);

	//overloaded functions for the Abstract table model
	virtual int rowCount(const QModelIndex & parent = QModelIndex()) const;
	virtual int columnCount(const QModelIndex &parent = QModelIndex()) const;
	virtual QVariant data(const QModelIndex &index, int role) const;
	virtual QVariant headerData(int section, Qt::Orientation orientation,
								int role = Qt::DisplayRole) const;
	virtual void sort(int column, Qt::SortOrder order = Qt::AscendingOrder );

	void AddSong(const Song & aCopy);

private:
	QStringList m_headers;
	QList<Song> * m_playlist;
	
	int m_columnSorted;
	int m_as_or_de;

	typedef bool(*COMPARE)(const Song &s1, const Song &s2);
};

#endif