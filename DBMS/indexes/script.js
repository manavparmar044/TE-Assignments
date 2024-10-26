dbms> db.createCollection("teachers");
{ ok: 1 }
// dbms> db.teachers.insertMany([
// ...     { "_id": 1, "name": "John Doe", "age": 35, "gender": "male" },
// ...     { "_id": 2, "name": "Jane Smith", "age": 40, "gender": "female" },
// ...     { "_id": 3, "name": "Michael Johnson", "age": 45, "gender": "male" },
// ...     { "_id": 4, "name": "Emily Williams", "age": 30, "gender": "female" },
// ...     { "_id": 5, "name": "Robert Brown", "age": 38, "gender": "male" },
// ...     { "_id": 6, "name": "Emma Jones", "age": 33, "gender": "female" },
// ...     { "_id": 7, "name": "William Davis", "age": 37, "gender": "male" },
// ...     { "_id": 8, "name": "Olivia Miller", "age": 41, "gender": "female" },
// ...     { "_id": 9, "name": "David Wilson", "age": 36, "gender": "male" },
// "gender": "female" },
//     { "_id": 15, "name": "Charles White", "age": 36, "gender": "male" },
//     { "_id": 16, "name": "Abigail Harris", "age": 31, "gender": "female" },
//     { "_id": 17, "name": "Daniel Martin", "age": 44, "gender": "male" },
//     { "_id": 18, "name": "Evelyn Thompson", "age": 38, "gender": "female" },
//     { "_id": 19, "name": "Matthew Garcia", "age": 37, "gender": "male" },
//     { "_id": 20, "name": "Sofia Martinez", "age": 35, "gender": "female" },
//     { "_id": 21, "name": "Andrew Robinson", "age": 40, "gender": "male" },
//     { "_id": 22, "name": "Grace Clark", "age": 33, "gender": "female" },
//     { "_id": 23, "name": "Joshua Rodriguez", "age": 39, "gender": "male" },
//     { "_id": 24, "name": "Avery Lewis", "age": 42, "gender": "female" },
//     { "_id": 25, "name": "Christopher Lee", "age": 37, "gender": "male" },
//     { "_id": 26, "name": "Chloe Walker", "age": 31, "gender": "female" },
//     { "_id": 27, "name": "Kevin Hall", "age": 44, "gender": "male" },
// ...     { "_id": 10, "name": "Sophia Moore", "age": 32, "gender": "female" },
// ...     { "_id": 11, "name": "Richard Taylor", "age": 39, "gender": "male" },
// ...     { "_id": 12, "name": "Isabella Anderson", "age": 43, "gender": "female" },
// ...     { "_id": 13, "name": "Joseph Thomas", "age": 34, "gender": "male" },
// ...     { "_id": 14, "name": "Mia Jackson", "age": 42, "gender": "female" },
// ...     { "_id": 15, "name": "Charles White", "age": 36, "gender": "male" },
// ...     { "_id": 16, "name": "Abigail Harris", "age": 31, "gender": "female" },
// ...     { "_id": 17, "name": "Daniel Martin", "age": 44, "gender": "male" },
// ...     { "_id": 18, "name": "Evelyn Thompson", "age": 38, "gender": "female" }, 
// ...     { "_id": 19, "name": "Matthew Garcia", "age": 37, "gender": "male" },
// ...     { "_id": 20, "name": "Sofia Martinez", "age": 35, "gender": "female" },
// ...     { "_id": 21, "name": "Andrew Robinson", "age": 40, "gender": "male" },
// ...     { "_id": 22, "name": "Grace Clark", "age": 33, "gender": "female" },
// ...     { "_id": 23, "name": "Joshua Rodriguez", "age": 39, "gender": "male" },
// ...     { "_id": 24, "name": "Avery Lewis", "age": 42, "gender": "female" },
// ...     { "_id": 25, "name": "Christopher Lee", "age": 37, "gender": "male" },
// ...     { "_id": 26, "name": "Chloe Walker", "age": 31, "gender": "female" },
// ...     { "_id": 27, "name": "Kevin Hall", "age": 44, "gender": "male" },
// ...     { "_id": 28, "name": "Zoey Allen", "age": 38, "gender": "female" },
// ...     { "_id": 29, "name": "Brian Young", "age": 36, "gender": "male" },
// ...     { "_id": 30, "name": "Harper King", "age": 34, "gender": "female" }
// ... ]);

dbms> db.teachers.createIndex({"age": 1})
age_1
dbms> db.teachers.getIndexes()
[
  { v: 2, key: { _id: 1 }, name: '_id_' },
  { v: 2, key: { age: 1 }, name: 'age_1' }
]
dbms> db.teachers.dropIndex("age_1");
// { nIndexesWas: 2, ok: 1 }
dbms> db.teachers.getIndexes()
[ { v: 2, key: { _id: 1 }, name: '_id_' } ]
dbms> db.teachers.createIndex({"age": 1})

dbms> db.teachers.createIndex({"age": 1,"gender": 1})
age_1_gender_1
dbms> db.teachers.getIndexes()
[
  { v: 2, key: { _id: 1 }, name: '_id_' },
  { v: 2, key: { age: 1, gender: 1 }, name: 'age_1_gender_1' }
]

dbms> db.sampleMultiIndex.createIndex({languages: 1})
languages_1
// dbms> db.sampleMultiIndex.insertMany([
//     ...   {
//     ...     "name": "John Doe",
//     ...     "age": 28,
//     ...     "skills": ["JavaScript", "Python", "MongoDB"],
//     ...     "projects": [
//     ...       {
//     ...         "projectName": "Website Development",
//     ...         "role": "Frontend Developer",
//     ...         "technologies": ["HTML", "CSS", "JavaScript"]
//     ...       },
//     ...       {
//     ...         "projectName": "Data Analysis",
//     ...         "role": "Data Scientist",
//     ...         "technologies": ["Python", "Pandas", "NumPy"]
//     ...       }
//     ...     ],
//     ...     "languages": ["English", "Spanish"]
//     ...   },
//     ...   {
//     ...     "name": "Jane Smith",
//     ...     "age": 34,
//     ...     "skills": ["Java", "C#", "SQL"],
//     ...     "projects": [
//     ...       {
//     ...         "projectName": "E-commerce Platform",
//     ...         "role": "Backend Developer",
//     ...         "technologies": ["Java", "Spring", "MySQL"]
//     ...       },
//     ...       {
//     ...         "projectName": "Mobile App",
//     ...         "role": "Full Stack Developer",
//     ...         "technologies": ["React Native", "Node.js"]
//     ...       }
//     ...     ],
//     ...     "languages": ["English", "French"]
//     ...   },
//     ...   {
//     ...     "name": "Emily Johnson",
//     ...     "age": 22,
//     ...     "skills": ["Ruby", "HTML", "CSS"],
//     ...     "projects": [
//     ...       {
//     ...         "projectName": "Portfolio Website",
//     ...         "role": "Web Designer",
//     ...         "technologies": ["HTML", "CSS", "JavaScript"]
//     ...       }
//     ...     ],
//     ...     "languages": ["English"]
//     ...   }
//     ... ]);
    // {
    //   acknowledged: true,
    //   insertedIds: {
    //     '0': ObjectId('671330febf7dbafd04648198'),
    //     '1': ObjectId('671330febf7dbafd04648199'),
    //     '2': ObjectId('671330febf7dbafd0464819a')
    //   }
    // }
dbms> db.sampleMultiIndex.getIndexes();
[
  { v: 2, key: { _id: 1 }, name: '_id_' },
  { v: 2, key: { languages: 1 }, name: 'languages_1' }
]
