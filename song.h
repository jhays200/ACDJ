#ifndef SONG_H
#define SONG_H

#include <QString>
#include <Phonon/MediaSource>

class Song
{
public:
	Song(Phonon::MediaSource media = Phonon::MediaSource(), QString title = QString(), QString artist = QString(), 
		QString album = QString(), QString genre = QString() );
	Song(const Song & aCopy);
	Song & operator=(const Song & aCopy);

	const Phonon::MediaSource & media() const;
	const QString & title() const;
	const QString & artist() const;
	const QString & album() const;
	const QString & genre() const;

	static bool compare_title_as(const Song &s1, const Song &s2);
	static bool compare_title_de(const Song &s1, const Song &s2);
	static bool compare_artist_as(const Song &s1, const Song &s2);
	static bool compare_artist_de(const Song &s1, const Song &s2);
	static bool compare_album_as(const Song &s1, const Song &s2);
	static bool compare_album_de(const Song &s1, const Song &s2);
	static bool compare_genre_as(const Song &s1, const Song &s2);
	static bool compare_genre_de(const Song &s1, const Song &s2);

private:
	Phonon::MediaSource m_media;
	QString m_title;
	QString m_artist;
	QString m_album;
	QString m_genre;
};

#endif
