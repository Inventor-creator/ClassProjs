
BEGIN;


INSERT INTO Artist(artistId , artistName, genre) VALUES(6,'f','jazz');


SELECT * FROM Artist WHERE artistName = 'f';


ROLLBACK;



SELECT * FROM Artist WHERE artistName = 'f';


BEGIN;


UPDATE Users SET userName = 'user1_updated' WHERE userId = 1;


SELECT * FROM Users WHERE userId = 1;


COMMIT;

SELECT * FROM Users WHERE userId = 1;


BEGIN;
UPDATE Users SET userName = 'user1' WHERE userId = 1;
COMMIT;
