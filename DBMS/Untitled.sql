CREATE TABLE Users(
	userId INT PRIMARY KEY,
	DOB VARCHAR(8),
	userName VARCHAR(20),
	passwords VARCHAR(20)

);

CREATE TABLE Playlists(
	playListId INT ,
	playlistName VARCHAR(20),
	creationDate VARCHAR(8),
	userId INT,
	FOREIGN KEY (userId ) REFERENCES Users(userId)

);
ALTER TABLE Playlists ADD PRIMARY KEY (playListId);
CREATE TABLE Artist(
	artistId INT PRIMARY KEY,
	artistName VARCHAR(20),
	genre VARCHAR(20)

);

CREATE TABLE Album(
	albumId INT PRIMARY KEY,
	title VARCHAR(20),
	genre VARCHAR(20),
	artistId INT,
	delCol INT,
	FOREIGN KEY(artistId) REFERENCES Artist(artistId)
);

ALTER TABLE ALBUM DROP COLUMN delCol;


CREATE TABLE Songs(
	songId INT PRIMARY KEY,
	title VARCHAR(20),
	albumId INT,
	genre VARCHAR(20),
	playListId INT,
	FOREIGN KEY(playListId) REFERENCES Playlists(playListId),
	FOREIGN KEY(albumId) REFERENCES Album(albumId)
	
);

CREATE TABLE delTable(
	delTableId INT PRIMARY KEY,
	delTableName VARCHAR(20)
);

DROP TABLE delTable;


DROP TABLE Songs;
DROP TABLE Album;
DROP TABLE Artist;
DROP TABLE Playlists;
DROP TABLE Users;


-- Inserting into stuff now

INSERT INTO Artist(artistId , artistName, genre) VALUES(1,'a','pop');
INSERT INTO Artist(artistId , artistName, genre) VALUES(2,'b','pop');
INSERT INTO Artist(artistId , artistName, genre) VALUES(3,'c','metal');
INSERT INTO Artist(artistId , artistName, genre) VALUES(4,'d','rock');
INSERT INTO Artist(artistId , artistName, genre) VALUES(5,'e','rock');

INSERT INTO Album(albumId , title , genre , artistId) VALUES(1,'album1' , 'pop' , 1);
INSERT INTO Album(albumId , title , genre , artistId) VALUES(2,'album2' , 'pop' , 1);
INSERT INTO Album(albumId , title , genre , artistId) VALUES(3,'album3' , 'pop' , 2);
INSERT INTO Album(albumId , title , genre , artistId) VALUES(6,'album3' , 'metal' , 2);
INSERT INTO Album(albumId , title , genre , artistId) VALUES(4,'album4' , 'metal' , 3);
INSERT INTO Album(albumId , title , genre , artistId) VALUES(5,'album5' , 'rock' , 4);

INSERT INTO Users(userId , DOB , userName , passwords) VALUES(1,'21202001' , 'user1' , 'user11');
INSERT INTO Users(userId , DOB , userName , passwords) VALUES(2,'22202002' , 'user2' , 'user22');
INSERT INTO Users(userId , DOB , userName , passwords) VALUES(3,'23202003' , 'user3' , 'user33');
INSERT INTO Users(userId , DOB , userName , passwords) VALUES(4,'24202004' , 'user4' , 'user44');
INSERT INTO Users(userId , DOB , userName , passwords) VALUES(5,'25202005' , 'user5' , 'user55');
INSERT INTO Users(userId , DOB , userName , passwords) VALUES(6,'22202005' , 'user25' , 'user255');

INSERT INTO Playlists(playlistId , playlistName , creationDate , userId) VALUES(1, 'list1' , '12042024' , 1);
INSERT INTO Playlists(playlistId , playlistName , creationDate , userId) VALUES(2, 'list2' , '13042024' , 1);
INSERT INTO Playlists(playlistId , playlistName , creationDate , userId) VALUES(3, 'list3' , '13042024' , 2);
INSERT INTO Playlists(playlistId , playlistName , creationDate , userId) VALUES(4, 'list4' , '13042025' , 3);
INSERT INTO Playlists(playlistId , playlistName , creationDate , userId) VALUES(5, 'list5' , '13052025' , 4);


INSERT INTO Songs(songId , title , albumId, genre , playListId) VALUES(1 , 'song1' , 1 , 'pop' , 5);
INSERT INTO Songs(songId , title , albumId, genre , playListId)	VALUES(2 , 'song2' , 1 , 'pop' , 3);
INSERT INTO Songs(songId , title , albumId, genre , playListId)	VALUES(3 , 'song2' , 1 , 'pop' , 3);
INSERT INTO Songs(songId , title , albumId, genre , playListId)	VALUES(4 , 'song3' , 2 , 'pop' , 4);
INSERT INTO Songs(songId , title , albumId, genre , playListId)	VALUES(5 , 'song2' , 2 , 'pop' , 3);
INSERT INTO Songs(songId , title , albumId, genre , playListId)	VALUES(6 , 'song4' , 3 , 'pop' , 2);
INSERT INTO Songs(songId , title , albumId, genre , playListId)	VALUES(7 , 'song5' , 4 , 'pop' , 4);


-- SELECT * FROM Songs;
-- SELECT * FROM Album;
-- SELECT * FROM Artist;
-- SELECT * FROM Playlists;
-- SELECT * FROM Users;
-- SELECT title FROM Songs WHERE albumid = 1;
-- SELECT genre FROM Songs WHERE albumid = 2;
-- SELECT * FROM Songs WHERE playlistId = 2;
-- SELECT * FROM Album WHERE artistId = 1;
-- SELECT * FROM Album WHERE genre = 'metal';
-- SELECT artistName FROM Artist WHERE genre = 'rock';
-- SELECT artistName FROM Artist WHERE genre = 'metal';


-- exp5
SELECT * FROM Songs ORDER BY songId DESC;
SELECT * FROM Users WHERE Users.userName LIKE '%5';
SELECT * FROM Users WHERE Users.userName LIKE '%5' ORDER BY userId DESC;
SELECT title , albumId FROM Songs GROUP BY songId ORDER BY albumId ASC ;
SELECT COUNT(songId) AS "Count" FROM Songs  WHERE albumId = 2 ;
SELECT albumId , COUNT(songId) FROM Songs GROUP BY albumId  HAVING COUNT(songId) >= 2 ORDER BY albumId ASC;
SELECT Artist.artistName FROM Artist, Album where (Artist.genre != Album.genre AND Artist.artistId = Album.artistId) GROUP BY artist.artistId ORDER BY artist.artistId ASC;
SELECT userId, COUNT(playListId) AS totalPlaylists FROM Playlists GROUP BY userId;
SELECT AVG(songCount) AS avgSongsPerPlaylist
FROM (
  SELECT playListId, COUNT(songId) AS songCount
  FROM Songs
  GROUP BY playListId
) AS playlistCounts;
SELECT MIN(creationDate) AS earliestPlaylist, MAX(creationDate) AS latestPlaylist FROM Playlists;
SELECT userId, COUNT(playListId) AS totalPlaylist FROM Playlists GROUP BY userId ORDER BY totalPlaylist DESC LIMIT 1;

SELECT genre FROM Artist UNION SELECT genre FROM Album;
SELECT title FROM Songs WHERE albumId = 1 UNION SELECT title FROM Songs WHERE albumId = 2;
SELECT userId AS id FROM Users UNION SELECT artistId AS id FROM Artist;
SELECT title FROM Songs WHERE albumId = 1 INTERSECT SELECT title FROM Songs WHERE albumId = 2;


--exp 6

SELECT userName 
FROM Users 
WHERE userId IN (
    SELECT userId 
    FROM Playlists 
    GROUP BY userId 
    HAVING COUNT(playListId) > 1
);


SELECT artistName 
FROM Artist 
WHERE artistId IN (
    SELECT artistId 
    FROM Album 
    WHERE genre = 'pop'
);


SELECT title 
FROM Songs 
WHERE playListId IN (
    SELECT playListId 
    FROM Playlists 
    WHERE userId = (
        SELECT userId 
        FROM Users 
        WHERE userName = 'user1'
    )
);


SELECT title 
FROM Album 
WHERE albumId IN (
    SELECT albumId 
    FROM Songs 
    GROUP BY albumId 
    HAVING COUNT(songId) > 1
);


SELECT userName 
FROM Users 
WHERE userId NOT IN (
    SELECT userId 
    FROM Playlists
);





SELECT s.title AS Song, a.title AS Album, ar.artistName AS Artist
FROM Songs s
JOIN Album a ON s.albumId = a.albumId
JOIN Artist ar ON a.artistId = ar.artistId;


SELECT p.playlistName, u.userName 
FROM Playlists p
JOIN Users u ON p.userId = u.userId;


SELECT s.title, p.playlistName 
FROM Songs s
JOIN Playlists p ON s.playListId = p.playListId
JOIN Users u ON p.userId = u.userId
WHERE u.userName = 'user2';


SELECT a.title AS Album, COUNT(s.songId) AS SongCount
FROM Album a
LEFT JOIN Songs s ON a.albumId = s.albumId
GROUP BY a.title;


SELECT u.userName, s.title AS Song
FROM Users u
JOIN Playlists p ON u.userId = p.userId
JOIN Songs s ON p.playListId = s.playListId;





CREATE VIEW SongDetails AS
SELECT s.songId, s.title AS Song, a.title AS Album, ar.artistName, ar.genre
FROM Songs s
JOIN Album a ON s.albumId = a.albumId
JOIN Artist ar ON a.artistId = ar.artistId;


CREATE VIEW PlaylistOwners AS
SELECT p.playlistName, u.userName 
FROM Playlists p
JOIN Users u ON p.userId = u.userId;


CREATE VIEW UserPlaylistCount AS
SELECT u.userName, COUNT(p.playListId) AS PlaylistCount
FROM Users u
LEFT JOIN Playlists p ON u.userId = p.userId
GROUP BY u.userName;


CREATE VIEW AlbumSongCount AS
SELECT a.title AS Album, COUNT(s.songId) AS SongCount
FROM Album a
LEFT JOIN Songs s ON a.albumId = s.albumId
GROUP BY a.title;


CREATE VIEW SongsByGenre AS
SELECT s.title AS Song, s.genre, ar.artistName
FROM Songs s
JOIN Album a ON s.albumId = a.albumId
JOIN Artist ar ON a.artistId = ar.artistId;

SELECT * FROM SongsByGenre;