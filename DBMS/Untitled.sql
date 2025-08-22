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
INSERT INTO Songs(songId , title , albumId, genre , playListId)	VALUES(3 , 'song3' , 2 , 'pop' , 4);
INSERT INTO Songs(songId , title , albumId, genre , playListId)	VALUES(4 , 'song4' , 3 , 'pop' , 2);
INSERT INTO Songs(songId , title , albumId, genre , playListId)	VALUES(5 , 'song5' , 4 , 'pop' , 4);


SELECT * FROM Songs;
SELECT * FROM Album;
SELECT * FROM Artist;
SELECT * FROM Playlists;
SELECT * FROM Users;
SELECT title FROM Songs WHERE albumid = 1;
SELECT genre FROM Songs WHERE albumid = 2;
SELECT * FROM Songs WHERE playlistId = 2;
SELECT * FROM Album WHERE artistId = 1;
SELECT * FROM Album WHERE genre = 'metal';
SELECT artistName FROM Artist WHERE genre = 'rock';
SELECT artistName FROM Artist WHERE genre = 'metal';


SELECT * FROM Songs ORDER BY songId DESC;
SELECT * FROM Users WHERE Users.userName LIKE '%5';
SELECT * FROM Users WHERE Users.userName LIKE '%5' ORDER BY userId DESC;
SELECT title , albumId FROM Songs GROUP BY songId ORDER BY albumId ASC ;
SELECT COUNT(songId) AS "Count" FROM Songs  WHERE albumId = 2 ;

