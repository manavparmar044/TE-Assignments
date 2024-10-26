CREATE TABLE Stud_Marks(
    s_id INT AUTO_INCREMENT PRIMARY KEY,
    s_name VARCHAR(100),
    marks INT
);

CREATE TABLE Result(
    r_id INT PRIMARY KEY,
    category VARCHAR(30),
    s_id INT,
    FOREIGN KEY (s_id) REFERENCES Stud_Marks(s_id) ON DELETE CASCADE
);

INSERT INTO Stud_Marks (s_name, marks) VALUES 
('Alice', 1200),
('Bob', 950),
('Charlie', 870),
('David', 1300),
('Eve', 880),
('Frank', 700),
('Grace', 890),
('Hannah', 990),
('Isaac', 1500),
('Judy', 600);

DELIMITER $$

CREATE FUNCTION classify (marks INT) RETURNS VARCHAR(50)
DETERMINISTIC
BEGIN
    IF marks BETWEEN 990 AND 1500 THEN
        RETURN 'Distinction';
    ELSEIF marks BETWEEN 900 AND 989 THEN
        RETURN 'First Class';
    ELSEIF marks BETWEEN 825 AND 899 THEN
        RETURN 'Higher Second Class';
    ELSE
        RETURN 'Pass';
    END IF;
END $$
DELIMITER ;

DELIMITER $$
CREATE PROCEDURE proc_grade(IN stud_name VARCHAR(100),IN roll INT)
BEGIN
DECLARE clss VARCHAR(25);
DECLARE studMarks INT;
DECLARE student_id INT;

SELECT s_id,marks INTO student_id,studMarks FROM Stud_Marks WHERE s_name = stud_name;

IF student_id IS NULL THEN
    SIGNAL SQLSTATE '45000' SET MESSAGE_TEXT = 'Student not found';
ELSE 
    set clss:= classify(studMarks);
    INSERT INTO Result (r_id,category,s_id) VALUES (roll,clss,student_id);
END IF;
END $$
DELIMITER ;

CALL proc_grade('Alice', 1);
CALL proc_grade('Bob', 2);
CALL proc_grade('Charlie', 3);
CALL proc_grade('David', 4);
CALL proc_grade('Eve', 5);
CALL proc_grade('Frank', 6);
CALL proc_grade('Grace', 7);
CALL proc_grade('Hannah', 8);
CALL proc_grade('Isaac', 9);
CALL proc_grade('Judy', 10);

SELECT * FROM Result;