CREATE TABLE library(
    book_id INT PRIMARY KEY NOT NULL AUTO_INCREMENT,
    book_name VARCHAR(100),
    isbn INT
);

CREATE TABLE library_audit(
    update_id INT PRIMARY KEY NOT NULL AUTO_INCREMENT,
    book_id INT,
    old_book_name VARCHAR(100),
    old_isbn INT
);

INSERT INTO library (book_name, isbn) VALUES
    ('Book1', 12222),
    ('Book2', 22222),
    ('Book3', 32222),
    ('Book4', 42222);

DELIMITER $$

CREATE TRIGGER updateTriggerAudit
BEFORE UPDATE ON library
FOR EACH ROW
BEGIN
    INSERT INTO library_audit(book_id,old_book_name,old_isbn) VALUES (OLD.book_id,OLD.book_name,OLD.isbn);
END $$

DELIMITER ;

--Update trigger invoked
UPDATE library
SET book_name = 'Book1111'
WHERE book_id = 1;

SELECT * FROM library_audit;

DELIMITER $$

CREATE TRIGGER deleteTriggerAudit
BEFORE DELETE ON library
FOR EACH ROW
BEGIN
    INSERT INTO library_audit (book_id, old_book_name, old_isbn)
    VALUES (OLD.book_id, OLD.book_name, OLD.isbn);
END $$

DELIMITER ;

DELETE FROM library WHERE book_id = 2;

SELECT * FROM library_audit;

