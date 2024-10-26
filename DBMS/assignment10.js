db.footballers.insertMany([
    {
        name: 'Lionel Messi',
        age: 36,
        country: 'Argentina',
        club: 'Inter Miami',
        position: 'Forward',
        salary: 75000000,
        goals: 800,
        assists: 350,
        matches: 1010,
        skills: [
          { name: 'Dribbling', rating: 10 },
          { name: 'Finishing', rating: 9.8 },
          { name: 'Passing', rating: 9.5 }
        ],
        achievements: ['Ballon d\'Or', 'FIFA World Cup', 'Champions League'],
        playerId: 10
      },
      {
        name: 'Cristiano Ronaldo',
        age: 39,
        country: 'Portugal',
        club: 'Al-Nassr',
        position: 'Forward',
        salary: 60000000,
        goals: 830,
        assists: 250,
        matches: 1100,
        skills: [
          { name: 'Finishing', rating: 9.7 },
          { name: 'Heading', rating: 9.5 },
          { name: 'Speed', rating: 9.2 }
        ],
        achievements: ['Ballon d\'Or', 'UEFA Euro', 'Champions League'],
        playerId: 7
      },
      {
        name: 'Kylian Mbappé',
        age: 25,
        country: 'France',
        club: 'Paris Saint-Germain',
        position: 'Forward',
        salary: 50000000,
        goals: 300,
        assists: 150,
        matches: 350,
        skills: [
          { name: 'Speed', rating: 9.9 },
          { name: 'Finishing', rating: 9.5 },
          { name: 'Dribbling', rating: 9.3 }
        ],
        achievements: ['FIFA World Cup', 'Ligue 1 Top Scorer'],
        playerId: 7
      },
      {
        name: 'Kevin De Bruyne',
        age: 32,
        country: 'Belgium',
        club: 'Manchester City',
        position: 'Midfielder',
        salary: 45000000,
        goals: 150,
        assists: 200,
        matches: 520,
        skills: [
          { name: 'Passing', rating: 10 },
          { name: 'Vision', rating: 9.8 },
          { name: 'Crossing', rating: 9.7 }
        ],
        achievements: ['Premier League', 'UEFA Champions League'],
        playerId: 17
      }
    ]);
    
    //Create Index
    db.footballers.createIndex({name: 1});
    
    db.footballers.createIndex({playerId: 1},{unique: true});
    
    //Average goals per year
    
    db.footballers.aggregate([
    {
    $group: {
    _id: null,
    avgGoals: {$avg: "$goals"}
    }
    }
    ]);
    
    //Matches by club
    db.footballers.aggregate([
    {
    $group: {
    _id: "$club",
    totalMatches: {$sum: "$matches"}
    }
    }
    ]);
    
    //Highest skills in dribbling
    
    db.footballers.aggregate([
    {$unwind: "$skills"},
    {$match: {"skills.name": "Dribbling"}},
    {$group: {
    _id: { name: "$name", playerId: "$playerId" },
    avgDribblingRating: { $avg: "$skills.rating" }
    }},
     { $sort: { avgDribblingRating: -1 } },
      { $limit: 1 }
    ]);