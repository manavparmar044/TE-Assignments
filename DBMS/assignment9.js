dbms> db.createCollection("cricketers")
{ ok: 1 }
// dbms> db.cricketers.insertMany([
//     ...   {
//     ...     name: "Virat Kohli",
//     ...     country: "India",
//     ...     role: "Batsman",
//     ...     matches: 275,
//     ...     runs: 12898,
//     ...     centuries: 46
//     ...   },
//     ...   {
//     ...     name: "Rohit Sharma",
//     ...     country: "India",
//     ...     role: "Batsman",
//     ...     matches: 248,
//     ...     runs: 9782,
//     ...     centuries: 30
//     ...   },
//     ...   {
//     ...     name: "Joe Root",
//     ...     country: "England",
//     ...     role: "Batsman",
//     ...     matches: 156,
//     ...     runs: 8450,
//     ...     centuries: 24
//     ...   },
//     ...   {
//     ...     name: "Pat Cummins",
//     ...     country: "Australia",
//     ...     role: "Bowler",
//     ...     matches: 82,
//     ...     wickets: 325,
//     ...     bestBowling: "6/27"
//     ...   },
//     ...   {
//     ...     name: "Trent Boult",
//     ...     country: "New Zealand",
//     ...     role: "Bowler",
//     ...     matches: 99,
//     ...     wickets: 295,
//     ...     bestBowling: "7/34"
//     ...   }
//     ... ]);
//     {
//       acknowledged: true,
//       insertedIds: {
//         '0': ObjectId('6713269eaad6a209f733eaa0'),
//         '1': ObjectId('6713269eaad6a209f733eaa1'),
//         '2': ObjectId('6713269eaad6a209f733eaa2'),
//         '3': ObjectId('6713269eaad6a209f733eaa3'),
//         '4': ObjectId('6713269eaad6a209f733eaa4')
//       }
//     }
    dbms> db.cricketers.find().pretty()
    [
      {
        _id: ObjectId('6713269eaad6a209f733eaa0'),
        name: 'Virat Kohli',
        country: 'India',
        role: 'Batsman',
        matches: 275,
        runs: 12898,
        centuries: 46
      },
      {
        _id: ObjectId('6713269eaad6a209f733eaa1'),
        name: 'Rohit Sharma',
        country: 'India',
        role: 'Batsman',
        matches: 248,
        runs: 9782,
        centuries: 30
      },
      {
        _id: ObjectId('6713269eaad6a209f733eaa2'),
        name: 'Joe Root',
        country: 'England',
        role: 'Batsman',
        matches: 156,
        runs: 8450,
        centuries: 24
      },
      {
        _id: ObjectId('6713269eaad6a209f733eaa3'),
        name: 'Pat Cummins',
        country: 'Australia',
        role: 'Bowler',
        matches: 82,
        wickets: 325,
        bestBowling: '6/27'
      },
      {
        _id: ObjectId('6713269eaad6a209f733eaa4'),
        name: 'Trent Boult',
        country: 'New Zealand',
        role: 'Bowler',
        matches: 99,
        wickets: 295,
        bestBowling: '7/34'
      }
    ]
    dbms> db.cricketers.find({name: "Rohit Sharma"});
    [
      {
        _id: ObjectId('6713269eaad6a209f733eaa1'),
        name: 'Rohit Sharma',
        country: 'India',
        role: 'Batsman',
        matches: 248,
        runs: 9782,
        centuries: 30
      }
    ]
    dbms> db.cricketers.find({centuries: {$gt: 20}})
    [
      {
        _id: ObjectId('6713269eaad6a209f733eaa0'),
        name: 'Virat Kohli',
        country: 'India',
        role: 'Batsman',
        matches: 275,
        runs: 12898,
        centuries: 46
      },
      {
        _id: ObjectId('6713269eaad6a209f733eaa1'),
        name: 'Rohit Sharma',
        country: 'India',
        role: 'Batsman',
        matches: 248,
        runs: 9782,
        centuries: 30
      },
      {
        _id: ObjectId('6713269eaad6a209f733eaa2'),
        name: 'Joe Root',
        country: 'England',
        role: 'Batsman',
        matches: 156,
        runs: 8450,
        centuries: 24
      }
    ]
    dbms> db.cricketers.updateOne({name: "Rohit Sharma"},{$set: {centuries: 48}});
    // {
    //   acknowledged: true,
    //   insertedId: null,
    //   matchedCount: 1,
    //   modifiedCount: 1,
    //   upsertedCount: 0
    // }
    dbms> db.cricketers.find({name: "Rohit Sharma"});
    [
      {
        _id: ObjectId('6713269eaad6a209f733eaa1'),
        name: 'Rohit Sharma',
        country: 'India',
        role: 'Batsman',
        matches: 248,
        runs: 9782,
        centuries: 48
      }
    ]
    dbms> db.cricketers.deleteOne({name: "Joe Root"});
    // { acknowledged: true, deletedCount: 1 }
    dbms> db.cricketers.find({$or: [{name: "Rohit Sharma"},{centuries: 46}]});
    [
      {
        _id: ObjectId('6713269eaad6a209f733eaa0'),
        name: 'Virat Kohli',
        country: 'India',
        role: 'Batsman',
        matches: 275,
        runs: 12898,
        centuries: 46
      },
      {
        _id: ObjectId('6713269eaad6a209f733eaa1'),
        name: 'Rohit Sharma',
        country: 'India',
        role: 'Batsman',
        matches: 248,
        runs: 9782,
        centuries: 48
      }
    ]
