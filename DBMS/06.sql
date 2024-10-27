CREATE TABLE new_emp(
    emp_id INT PRIMARY KEY,
    emp_name VARCHAR(20),
    emp_dept VARCHAR(20),
    emp_salary INT
);

CREATE TABLE old_emp(
    emp_id INT PRIMARY KEY,
    emp_name VARCHAR(20),
    emp_dept VARCHAR(20),
    emp_salary INT
);

INSERT INTO old_emp VALUES
(1,'Kunal','Sales',10000),
(2,'Abhinandan','SDE',10000);

INSERT INTO new_emp VALUES
(3,'Utsaah','Data',10000),
(4,'Varad','SDE',10000);

--Cursor

DELIMITER $$

CREATE PROCEDURE copy_data()
BEGIN
DECLARE v_emp_id INT;
DECLARE done INT default FALSE;

DECLARE cur CURSOR FOR SELECT emp_id FROM old_emp;
DECLARE CONTINUE HANDLER FOR NOT FOUND SET done = TRUE;

OPEN cur;

read_loop: LOOP
    FETCH cur INTO v_emp_id;

    IF done THEN
        LEAVE read_loop;
    END IF;

    IF NOT EXISTS (SELECT 1 FROM new_emp WHERE emp_id = v_emp_id) THEN
    INSERT INTO new_emp(emp_id, emp_name, emp_dept, emp_salary)
    SELECT emp_id, emp_name, emp_dept, emp_salary FROM old_emp
    WHERE emp_id = v_emp_id;
    END IF;
END LOOP;
CLOSE cur;
END $$
DELIMITER ;

CALL copy_data();

SELECT * FROM new_emp;