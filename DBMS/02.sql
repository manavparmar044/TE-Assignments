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

INSERT INTO PlacementDrive (Pcompany_name, package, location) VALUES
('Google', 50000, 'Pune'),
('Microsoft', 60000, 'Mumbai'),
('Amazon', 55000, 'Bangalore'),
('Facebook', 65000, 'Hyderabad'),
('Apple', 70000, 'Mumbai'),
('TCS', 30000, 'Pune'),
('Infosys', 40000, 'Chennai'),
('Wipro', 35000, 'Delhi'),
('Oracle', 45000, 'Gurgaon'),
('Adobe', 50000, 'Noida');

INSERT INTO Training (Tcompany_name, T_Fee, T_year) VALUES
('Udacity', 2000, 2019),
('Coursera', 2500, 2020),
('LinkedIn Learning', 1800, 2019),
('edX', 2200, 2021),
('Udemy', 2400, 2021),
('Pluralsight', 2600, 2020),
('Khan Academy', 0, 2019),
('FutureLearn', 2300, 2020),
('Skillshare', 2100, 2021),
('Codecademy', 2500, 2019);

INSERT INTO Student (Drive_id, T_id, s_name, CGPA, s_branch, S_dob) VALUES
(1, 1, 'Alice', 8.5, 'Computer', '2000-01-15'),
(2, 2, 'David', 7.9, 'IT', '2001-03-20'),
(3, 3, 'Amit', 9.2, 'Mechanical', '1999-12-25'),
(4, 4, 'Deepak', 6.8, 'Computer', '2002-06-05'),
(5, 5, 'Akash', 7.4, 'Civil', '2001-07-12'),
(6, 6, 'Diana', 8.1, 'IT', '2000-11-11'),
(7, 7, 'Neha', 6.5, 'Computer', '2001-10-17'),
(8, 8, 'Raj', 8.7, 'IT', '1999-05-05'),
(9, 9, 'Sara', 9.0, 'Electrical', '2002-02-28'),
(10, 10, 'Tom', 7.8, 'Computer', '2000-04-19');

--Queries

--Display all students’ details with branch ‘Computer’ and ‘IT’ and student name starting with 'a' or 'd'.

SELECT *
From Student
WHERE s_branch IN ('Computer','IT')
AND (s_name LIKE 'a%' OR s_name LIKE 'd%');

--List the number of different companies. (Use DISTINCT)

SELECT COUNT(DISTINCT Pcompany_name)
FROM PlacementDrive;

--Give a 15% increase in fee of the Training whose joining year is 2019.

UPDATE Training
SET T_Fee  = T_Fee * 1.15
WHERE T_year = 2019;

--Delete Student details having CGPA score less than 7.

DELETE FROM Student
WHERE CGPA < 7;

--Find the names of companies belonging to Pune or Mumbai.

SELECT Pcompany_name
FROM PlacementDrive
WHERE location IN ('Pune','Mumbai');

--Find the student name who joined training on 1-1-2019 as well as on 1-1-2021.

SELECT s_name
FROM Student
JOIN Training ON Student.T_id = Training.T_id
WHERE (T_year = 2019) OR (T_year = 2021)
GROUP BY s_name
HAVING COUNT(DISTINCT T_year) = 2;

--Find the student name having the maximum CGPA score and names of students having CGPA score between 7 and 9.

SELECT s_name,CGPA
FROM Student
WHERE CGPA = (SELECT MAX(CGPA) FROM Student);

SELECT s_name,CGPA
FROM Student
WHERE CGPA BETWEEN 7 AND 9;

--Display all Student names with T_id in decreasing order of Fees.

SELECT s_name,Student.T_id,T_Fee
FROM Student
JOIN Training on Student.T_id = Training.T_id
ORDER BY T_Fee DESC;

--Display Pcompany_name, s_name, location, and Package for packages of 30K, 40K, and 50K.

SELECT Pcompany_name,s_name,location,package
FROM Student
JOIN PlacementDrive ON Student.Drive_id = PlacementDrive.Drive_id
WHERE package IN (30000,40000,50000);

--Simple view for CSIT

CREATE VIEW ComputerIT AS
SELECT s_id,s_name,s_branch,CGPA,S_dob
FROM Student
WHERE s_branch IN ('Computer', 'IT');

SELECT * FROM ComputerIT;

--Unique Index

CREATE UNIQUE INDEX idx_student ON Student(s_id);