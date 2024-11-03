CREATE TABLE circle(
    radius INT PRIMARY KEY,
    area DECIMAL(10,2)
);

DELIMITER $$

CREATE PROCEDURE area_proc()
BEGIN
    DECLARE r INT;
    SET r = 5;

    WHILE r<=9 DO
        INSERT INTO circle(radius,area)
        VALUES (r,(3.14*r*r));
        SET r = r + 1;
    END WHILE;
END $$

DELIMITER ;

call area_proc();

SELECT * from circle;

--Borrower Fine

CREATE TABLE borrower(
    roll INT PRIMARY KEY NOT NULL,
    name VARCHAR(20),
    doi DATE,
    book_name VARCHAR(20),
    status VARCHAR(1)
);

CREATE TABLE fine(
    roll INT,
    dor DATE,
    fine_amount INT,
    FOREIGN KEY(roll) REFERENCES borrower(roll)
);

INSERT INTO borrower (roll, name, doi, book_name, status) VALUES
(1, 'Amit', '2024-05-29', 'FDS', 'I'),
(2, 'Sita', '2024-07-21', 'OOP', 'I'),
(3, 'Ravi', '2024-07-09', 'PHY', 'I');

DELIMITER $$

CREATE PROCEDURE fill_fine(IN roll_no INT,IN name VARCHAR(20))
BEGIN
DECLARE today DATE;
DECLARE issueDate DATE;
DECLARE fine_amt INT;
DECLARE diff INT;

SET today = CURDATE();
SELECT doi INTO issueDate FROM borrower WHERE roll_no = roll;
SET diff = DATEDIFF(today,issueDate);
IF diff > 15 AND diff <= 30 THEN
    SET fine_amt = diff*3;
    INSERT INTO fine(roll,dor,fine_amount) VALUES(roll_no,today,fine_amt);
ELSEIF diff>30 THEN
    SET fine_amt = diff*15;
    INSERT INTO fine(roll,dor,fine_amount) VALUES(roll_no,today,fine_amt);
ELSE
    SET fine_amt = 0;
END IF;

UPDATE borrower SET status = 'R' where roll = roll_no;
END $$

DELIMITER ;

CALL fill_fine(1, 'FDS');
CALL fill_fine(2, 'OOP');
CALL fill_fine(3, 'PHY');

SELECT * FROM fine;

