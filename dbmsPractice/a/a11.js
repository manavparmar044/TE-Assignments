db.students.mapReduce(
    function(){emit(this.department,this.marks);},
    function(keys,values){
        return Array.sum(values);
    },
    {out: "total_marks_by_department"}
);

db.total_marks_by_department.find()

db.students.mapReduce(
    function(){emit(this.department,1);},
    function(keys,values){
        return Array.sum(values);
    },
    {out: "student_count_by_department"}
);

db.student_count_by_department.find()

var mapFunction = function(){
    emit(this.department,this.marks)
}

var reduceFunction = function(keys,values){
    var sum = 0;
    for(var i = 0;i<values.length;i++){
        sum+=values[i];
    }
    return sum/values.length;
}

db.students.mapReduce(mapFunction,reduceFunction,{
    out: "average_marks",
    query: {department: "physics"}
});