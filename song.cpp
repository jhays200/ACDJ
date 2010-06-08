#include "song.h"

Song::Song(Phonon::MediaSource media, QString title, QString artist, QString album, QString genre)
: m_media(media), m_title(title), m_artist(artist), m_album(album), m_genre(genre)
{}

Song::Song(const Song & aCopy)
{
	*this = aCopy;
}

Song & Song::operator=(const Song & aCopy)
{
	m_media = aCopy.m_media;
	m_title = aCopy.m_title;
	m_artist  = aCopy.m_artist;
	m_album = aCopy.m_album;
	m_genre = aCopy.m_genre;

	return *this;
}

const Phonon::MediaSource & Song::media() const
{
	return m_media;
}

const QString & Song::title() const
{
	return m_title;
}

const QString & Song::artist() const
{
	return m_artist;
}

const QString & Song::album() const
{
	return m_album;
}

const QString & Song::genre() const
{
	return m_genre;
}

bool Song::compare_title_as(const Song &s1, const Song &s2)
{
	return s1.title() < s2.title();
}

bool Song::compare_title_de(const Song &s1, const Song &s2)
{
	return s1.title() > s2.title();
}

bool Song::compare_artist_as(const Song &s1, const Song &s2)
{
	return s1.artist() < s2.artist();
}

bool Song::compare_artist_de(const Song &s1, const Song &s2)
{
	return s1.artist() > s2.artist();
}

bool Song::compare_album_as(const Song &s1, const Song &s2)
{
	return s1.album() < s2.album();
}

bool Song::compare_album_de(const Song &s1, const Song &s2)
{
	return s1.album() > s2.album();
}

bool Song::compare_genre_as(const Song &s1, const Song &s2)
{
	return s1.genre() < s2.genre();
}

bool Song::compare_genre_de(const Song &s1, const Song &s2)
{
	return s1.genre() > s2.genre();
}