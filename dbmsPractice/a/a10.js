db.students.aggregate([
    {$group: {_id: "$department",count: {$sum: 1}}}
]);

db.students.aggregate([
    {$group: {_id: "$department",averageMarks: {$avg: "$marks"}}}
]);

db.students.aggregate([
    {$group: {_id: "$department",totalMarks: {$sum: "$marks"}}}
]);

db.students.aggregate([
    {$match: {marks: {$gt: 85}}},
    {$project: {name: 1,department: 1,marks: 1,_id: 0}}
]);

db.students.createIndex({name: 1});
db.students.createIndex({name: 1,department: 1});