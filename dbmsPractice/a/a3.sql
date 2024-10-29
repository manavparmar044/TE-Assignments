SELECT s.*,p.* FROM Student s
NATURAL JOIN PlacementDrive p;

SELECT s.*,Pcompany_name
FROM Student s
JOIN PlacementDrive p on s.Drive_id = p.Drive_id;

SELECT s.s_name,s.s_branch
FROM Student s JOIN PlacementDrive p
ON s.Drive_id = p.Drive_id
WHERE p.package = 50000;

SELECT s.s_name,p.Pcompany_name
FROM Student s
JOIN Training t ON s.T_id = t.T_id
JOIN PlacementDrive p ON s.Drive_id = p.Drive_id
WHERE t.T_Fee > 20000; 

SELECT t.*
FROM Student s
JOIN Training t ON t.T_id = s.T_id
WHERE s.s_name = "Alice" AND t.T_year = 2011;

SELECT COUNT(DISTINCT Tcompany_name)
FROM Training
WHERE T_year<2015;

SELECT s.s_name
FROM Student s
JOIN PlacementDrive p ON s.Drive_id = p.Drive_id
WHERE p.Pcompany_name = 'Microsoft' AND p.location = 'Thane';

SELECT s.s_name
FROM Student s
JOIN Training t ON t.T_id = s.T_id
WHERE t.Tcompany_name = 'Microsoft' AND t.T_year = 2015;

CREATE VIEW StudentTrainingDetails AS
SELECT s.s_id, s.s_name, s.s_branch, s.CGPA, t.Tcompany_name, t.T_Fee, t.T_year
FROM Student s
JOIN Training t ON s.T_id = t.T_id;

DROP VIEW StudentTrainingDetails;

CREATE VIEW StudentCGPAView AS
SELECT s_name, CGPA
FROM Student;

UPDATE StudentCGPAView
SET CGPA = 8.8
WHERE s_name = 'Alice';

DELETE FROM StudentCGPAView
WHERE s_name = 'Bob';

DROP VIEW StudentCGPAView;
