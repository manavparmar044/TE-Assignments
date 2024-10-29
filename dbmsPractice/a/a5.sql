CREATE TABLE Stud_Marks1(
    s_id INT PRIMARY KEY AUTO_INCREMENT,
    s_name VARCHAR(100),
    marks INT
);

CREATE TABLE Result1(
    r_id INT PRIMARY KEY,
    category VARCHAR(30),
    s_id INT,
    FOREIGN KEY (s_id) REFERENCES Stud_Marks1(s_id) ON DELETE CASCADE
);

INSERT INTO Stud_Marks1 (s_name, marks) VALUES 
('Alice', 1200),
('Bob', 950);

DELIMITER $$

CREATE FUNCTION classify1(marks INT) RETURNS VARCHAR(50)
DETERMINISTIC
BEGIN
    IF MARKS BETWEEN 990 AND 1500 THEN
        RETURN 'Distinction';
    ELSEIF MARKS BETWEEN 990 AND 1500 THEN
        RETURN 'First Class';
    ELSEIF MARKS BETWEEN 990 AND 1500 THEN
        RETURN 'Higher Second Class';
    ELSE RETURN 'Pass';
    END IF;
END $$
DELIMITER ;

DELIMITER $$

CREATE PROCEDURE proc_grade1(IN stud_name VARCHAR(100),IN roll INT)
BEGIN
DECLARE clss varchar(25);
DECLARE studMarks INT;
DECLARE student_id INT;

SELECT s_id,marks INTO student_id,studMarks FROM Stud_Marks1 WHERE s_name = stud_name;

IF student_id IS NULL THEN
    SIGNAL SQLSTATE '45000' SET MESSAGE_TEXT = 'Student not found';
ELSE
    set clss:=classify(studMarks);
    INSERT INTO Result1(r_id,category,s_id) VALUES (roll,clss,student_id);
END IF;
END $$
DELIMITER ;

CALL proc_grade1('Alice', 1);
CALL proc_grade1('Bob', 2);

SELECT * FROM Result1;