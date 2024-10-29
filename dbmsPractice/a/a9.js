db.createCollection("mobiles")

db.mobiles.insertMany([
    {name: "Iphone 16 Pro Max", price: 160000},
    {name: "Iphone 15", price: 100000},
    {name: "Note 5", price: 60000},
    {name: "S25", price: 50000},
]);

db.mobiles.find().pretty();

db.mobiles.findOne({name: "Iphone 15"})

db.mobiles.updateOne({name: "Iphone 15"},{$set: {name: "Iphone 15 Pro"}});

db.mobiles.deleteOne({name: "Note 5"});