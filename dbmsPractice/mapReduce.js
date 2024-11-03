db.createCollection("students");

db.students.insertMany([
    { name: "Alice", age: 20, department: "Physics", marks: 85 },
    { name: "Bob", age: 22, department: "Mathematics", marks: 90 },
    { name: "Charlie", age: 23, department: "Physics", marks: 75 },
    { name: "David", age: 21, department: "Computer Science", marks: 95 },
    { name: "Eve", age: 22, department: "Mathematics", marks: 80 },
    { name: "Frank", age: 20, department: "Computer Science", marks: 88 }
  ]);

db.students.mapReduce(
    function() {emit(this.department,this.marks);},
    function(key,values) {return Array.sum(values);},
    {out: "total_marks_by_department"}
);

db.total_marks_by_department.find()

db.students.mapReduce(
    function() {emit(this.department,1);},
    function(key,values) {
        return Array.sum(values);
    },
    {out: "student_count_by_department"}
);

db.student_count_by_department.find()

//Average Marks

var mapFunction = function() { emit(this.department, this.marks); };

var reduceFunction = function(key, values) {
    var sum = Array.sum(values);
    return sum / values.length; // Calculate the average
};

// Query for "Physics" department only
db.students.mapReduce(
    mapFunction,
    reduceFunction,
    {
        out: "average_marks",
        query: { department: "Physics" }
    }
);

db.average_marks.find();

// Calculate average for all departments
db.students.mapReduce(
    mapFunction,
    reduceFunction,
    { out: "average_marks_all" }
);

db.average_marks_all.find();
