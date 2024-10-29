CREATE TABLE circle1(
    radius INT PRIMARY KEY,
    area DECIMAL(10,2)
);

DELIMITER $$

CREATE PROCEDURE area_proc1()
BEGIN
    DECLARE r INT;
    SET r = 5;
    WHILE r<=9 DO
        INSERT INTO circle1(radius,area) VALUES (r,(3.14*r*r));
        SET r  = r + 1;
    END WHILE;
END $$

DELIMITER ;

call area_proc1();

SELECT * from circle1;
