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