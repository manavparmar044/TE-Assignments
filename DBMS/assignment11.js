db.studentsMR.insertMany([
  { name: "Alice", age: 20, subject: "Mathematics", marks: 85 },
  { name: "Bob", age: 21, subject: "Mathematics", marks: 90 },
  { name: "Charlie", age: 22, subject: "Physics", marks: 70 },
  { name: "David", age: 20, subject: "Physics", marks: 60 },
  { name: "Eve", age: 21, subject: "Chemistry", marks: 95 },
]);

//Total marks by subject
db.studentsMR.mapReduce(
  function () {
    emit(this.subject, this.marks);
  },
  function (key, values) {
    return Array.sum(values);
  },
  {
    out: "total_marks_by_subject",
  }
);

db.studentsMR.mapReduce(
  function () {
    emit(this.subject, 1);
  },
  function (key, values) {
    return Array.sum(values);
  },
  {
    out: "student_count_by_subject", // Output collection
  }
);
