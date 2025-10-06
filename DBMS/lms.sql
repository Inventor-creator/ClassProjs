SELECT * FROM student;
SELECT * FROM student_info;
select * from branches;
SELECT * FROM instructors;
SELECT * FROM student_pass;

select * from courses NATURAL JOIN instructors ORDER BY instructor_id ASC;
select * from enrollment_info ORDER BY student_id ASC;


DELETE FROM student WHERE 1 = 1;
DELETE FROM student_info WHERE 1 = 1;

INSERT INTO branches VALUES (1, 'AIDS');
INSERT INTO branches VALUES (2, 'COMPS');
INSERT INTO student_pass VALUES(1 , 'nigga' ,'nigga@somaiya');


SELECT * FROM student s , branches b , student_info si WHERE s.student_id = si.student_id AND s.branch_id = b.branch_id;

SELECT * FROM (SELECT * FROM student s NATURAL JOIN student_info si LEFT JOIN branches b USING (branch_id) );

DELETE FROM branches WHERE branch_id = 9;

DROP TABLE student_pass;
DROP TABLE student_info;
DROP TABLE enrollment_info;
DROP TABLE student;
DROP TABLE branches;
DROP TABLE courses;
DROP TABLE instructors;
