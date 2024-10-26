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

--Find the Student details and Placement details using NATURAL JOIN.

SELECT *
FROM Student
NATURAL JOIN PlacementDrive;

--Find all the student details with Pcompany_name who have participated in the same drive.

SELECT s.*,p.Pcompany_name
FROM Student s
JOIN PlacementDrive p ON s.Drive_id = p.Drive_id;

-- List all the Student name and Student branch of Students having a package of 5 LPA.

SELECT s.s_name,s.s_branch
FROM Student s
JOIN PlacementDrive p ON S.Drive_id = P.Drive_id
WHERE p.package = 500000;

--List all student names and Pcompany_name for training fees more than 20000.

SELECT s.s_name,p.Pcompany_name
FROM Student s
JOIN Training t ON s.T_id = t.T_id
JOIN PlacementDrive p ON s.Drive_id = p.Drive_id
WHERE t.T_Fee > 20000;

--Display all training details attended by "Alice" in the year 2011.

SELECT t.*
FROM Student s
JOIN Training t ON t.T_id = s.T_id
WHERE s.s_name = "Alice" AND t.T_year = 2011;

--List the total number of companies that conducted training before 2015.

SELECT COUNT(DISTINCT Tcompany_name)
FROM Training
WHERE T_year < 2015;

--List the students' names with company Microsoft and location Thane.

SELECT s.s_name
FROM Student s
JOIN PlacementDrive p ON s.Drive_id = p.Drive_id
WHERE p.Pcompany_name = 'Microsoft' AND p.location = 'Thane';

--Find the names of all students who joined Microsoft training in 2015.

SELECT s.s_name
FROM Student s
JOIN Training t ON t.T_id = s.T_id
WHERE t.Tcompany_name = 'Microsoft' AND t.T_year = 2015;

-- Create a view showing the Student and Training details.

CREATE VIEW StudentTrainingDetails AS
SELECT s.s_id, s.s_name, s.s_branch, s.CGPA, t.Tcompany_name, t.T_Fee, t.T_year
FROM Student s
JOIN Training t ON s.T_id = t.T_id;

DROP VIEW StudentTrainingDetails;

--Perform Manipulation on Simple View - Insert, Update, Delete, Drop View

CREATE VIEW StudentCGPAView AS
SELECT s_name, CGPA
FROM Student;

INSERT INTO StudentCGPAView (s_name, CGPA)
VALUES ('Eve', 7.5);

SELECT * FROM StudentCGPAView;
UPDATE StudentCGPAView
SET CGPA = 8.8
WHERE s_name = 'Alice';

DELETE FROM StudentCGPAView
WHERE s_name = 'Bob';

DROP VIEW StudentCGPAView;





