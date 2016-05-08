typedef struct _stats{
    int KPIs;
    int Campuses;
    int Group;
    int ARC Grants;
    int Patents;
    int Papers
    int THDs;
    int BPSs;
    int BQNs;
    int MJs;
    int MTVs;
    int MMONEYs;
    // prestige will either be true or false
    int Prestige;
} stats;

typedef struct _game {
    int turnNumber; 
    int currentTurn;
    int whoseTurn;
    int currentDice;
    
    //3 dimensional array
    //of the form [column][vertex][contents] specifiyng a point
    //Note that:
    //for rows 0 and 10 if [vertex] > 1 then point is outside board
    //for rows 1 and 9 if [vertex] > 3 then the point is outside the board
    //[contents] specifies what is on the point
    int gameBoard[11][6][1];
    
    stats PlayerA;
    stats PlayerB;
    stats PlayerC;
}

