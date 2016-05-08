#include <stdio.h>
#include <stdlib.h>
#include "game.h"

//For vertices and arcs
#define MAX_VERTICES 6
#define MAX_ROWS 12
#define MAX_ARCS_PER_ROW 8

//For regions
#define MAX_REGION_ROWS 9
#define MAX_REGION_COLUMNS 3



typedef struct _stats{
    int KPIs;
    int Campuses;
    int Group;
    int ARCGrants;
    int Patents;
    int Papers;
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
    action currentAction;
    
    
    //3 dimensional array
    //of the form [column][vertex][contents] specifiyng a point
    //Note that:
    //for rows 0 and 10 if [vertex] > 1 then point is outside board
    //for rows 1 and 9 if [vertex] > 3 then the point is outside the board
    //[contents] specifies what is on the point
    //int gameBoard[11][6][1];
    
    /*2 dimensional array
    //of the form [column][vertex] containing the contents of the vertex
    //specifiyng a point
    //Note that:
    //for rows 0 and 10 if[vertex] > 1 then point is outside board
    //for rows 1 and 9 if [vertex] > 3 then the point is outside the board
    //
    */
    int boardVertices[MAX_ROWS][MAX_VERTICES];
    
    /*2 dimensional array of the
    //form [row][arc] conataining the contents of the arc.
    */
    int boardArcs[MAX_ROWS][MAX_ARCS_PER_ROW];
    
    /*2D array whihc stores the 
    //constents of the regions
    */
    int boardRegions[MAX_REGION_ROWS][MAX_REGION_COLUMNS];
    
    stats PlayerA;
    stats PlayerB;
    stats PlayerC;
} game;
