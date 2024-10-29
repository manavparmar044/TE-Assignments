CREATE TABLE PlacementDrive(
    Drive_id INT PRIMARY KEY AUTO_INCREMENT,
    Pcompany_name VARCHAR(50),
    package INT,
    location VARCHAR(50)
);

CREATE TABLE Training(
    T_id INT PRIMARY KEY AUTO_INCREMENT,
    Tcompany_name VARCHAR(50),
    T_Fee DECIMAL(10,2),
    T_year INT
);

CREATE TABLE Student(
    s_id INT PRIMARY KEY AUTO_INCREMENT,
    Drive_id INT,
    T_id INT,
    s_name VARCHAR(50),
    CGPA DECIMAL(3,2),
    s_branch VARCHAR(50),
    S_dob DATE,
    FOREIGN KEY (Drive_id) REFERENCES PlacementDrive(Drive_id) ON DELETE CASCADE,
    FOREIGN KEY (T_id) REFERENCES Training(T_id) ON DELETE CASCADE
);

SELECT * FROM Student
WHERE s_branch in ('Computer','IT')
AND (s_name LIKE 'a%' OR s_name LIKE 'd%');

SELECT COUNT(DISTINCT Pcompany_name)
FROM PlacementDrive;

UPDATE Training
SET T_Fee = T_Fee * 1.15
WHERE T_year = 2019;

DELETE FROM Student
WHERE CGPA < 7;

SELECT Pcompany_name
FROM PlacementDrive
WHERE location IN ('Pune','Mumbai');

SELECT s_name,Student.T_id,T_Fee
FROM Student
JOIN Training on Student.T_id = Training.T_id
ORDER BY T_Fee DESC;

SELECT Pcompany_name,s_name,location,package
package
FROM Student
JOIN PlacementDrive ON Student.Drive_id = PlacementDrive.Drive_id
WHERE package IN (30000,40000,50000);

CREATE VIEW ComputerIT AS
SELECT s_id,s_name,s_branch,CGPA,S_dob
FROM Student
WHERE s_branch IN ('Computer', 'IT');

SELECT * FROM ComputerIT;

CREATE UNIQUE INDEX idx_student ON Student(s_id);