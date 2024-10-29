CREATE TABLE library1(
    book_id INT PRIMARY KEY NOT NULL AUTO_INCREMENT,
    book_name VARCHAR(100),
    isbn INT
);

CREATE TABLE library_audit1(
    update_id INT PRIMARY KEY NOT NULL AUTO_INCREMENT,
    book_id INT,
    old_book_name VARCHAR(100),
    old_isbn INT
);

INSERT INTO library1 (book_name, isbn) VALUES
    ('Book1', 12222),
    ('Book2', 22222),
    ('Book3', 32222),
    ('Book4', 42222);

DELIMITER $$

CREATE TRIGGER updateTriggerAudit1
BEFORE UPDATE ON library1
FOR EACH ROW
BEGIN
    INSERT INTO library_audit1(book_id,old_book_name,old_isbn) VALUES (OLD.book_id,OLD.book_name,OLD.isbn);
END $$
DELIMITER ;

UPDATE library1
SET book_name = 'Book1111'
WHERE book_id = 1;

DELIMITER $$

CREATE TRIGGER deleteTriggerAudit1
BEFORE DELETE ON library1
FOR EACH ROW
BEGIN
    INSERT INTO library_audit1(book_id,old_book_name,old_isbn) VALUES (OLD.book_id,OLD.book_name,OLD.isbn);
END $$
DELIMITER ;

DELETE FROM library1 WHERE book_id = 2;

SELECT * FROM library_audit1;
