db.createCollection("students");

db.students.insertMany([
    { name: "Alice", age: 20, department: "Physics", marks: 85 },
    { name: "Bob", age: 22, department: "Mathematics", marks: 90 },
    { name: "Charlie", age: 23, department: "Physics", marks: 75 },
    { name: "David", age: 21, department: "Computer Science", marks: 95 },
    { name: "Eve", age: 22, department: "Mathematics", marks: 80 },
    { name: "Frank", age: 20, department: "Computer Science", marks: 88 }
  ]);

  //Count students in each department

  db.students.aggregate([
    {$group: {_id: "$department",count: {$sum: 1}}}
  ]);

//Average marks by department

db.students.aggregate([
    {$group: {_id: "$department",averageMarks: {$avg: "$marks"}}}
]);

//Highest marks in each department

db.students.aggregate([
    {$group: {_id: "$department", maxMarks: {$max: "$marks"}}}
]);

//Total marks

db.students.aggregate([
    {$group: {_id: "$department", totalMarks: {$sum: "$marks"}}}
]);

//Students above 85

db.students.aggregate([
    {$match: {marks: {$gt: 85}}},
    {$project: {name: 1,department: 1,marks: 1,_id: 0}}
]);

db.students.createIndex({name: 1});
db.students.createIndex({name: 1,department: 1});
// db.students.createIndex({name: 1},{unique: true});