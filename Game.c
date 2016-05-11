#include <stdio.h>
#include <stdlib.h>
#include "Game.h"

//For vertices and arcs
#define MAX_COLUMNS 6
#define MAX_ROWS 11
#define MAX_ARCS_PER_COLUMN 10

//For regions
#define MAX_REGION_ROWS 5
#define MAX_REGION_COLUMNS 5


#define DEFAULT_DISCIPLINES {STUDENT_BQN, STUDENT_MMONEY, STUDENT_MJ, \
                STUDENT_MMONEY, STUDENT_MJ, STUDENT_BPS, STUDENT_MTV, \
                STUDENT_MTV, STUDENT_BPS,STUDENT_MTV, STUDENT_BQN, \
                STUDENT_MJ, STUDENT_BQN, STUDENT_THD, STUDENT_MJ, \
                STUDENT_MMONEY, STUDENT_MTV, STUDENT_BQN, STUDENT_BPS}
#define DEFAULT_DICE {9,10,8,12,6,5,3,11,3,11,4,6,4,7,9,2,8,10,5}

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

typedef struct _region {
    int boardRegions[MAX_REGION_COLUMNS][MAX_REGION_ROWS];
    int diceVal[MAX_REGION_COLUMNS][MAX_REGION_ROWS];
} region;

typedef struct _game {
    int turnNumber; 
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
    int boardVertices[MAX_COLUMNS][MAX_ROWS];
    
    /*2 dimensional array of the
    //form [row][arc] conataining the contents of the arc.
    */
    int boardArcs[MAX_COLUMNS][MAX_ARCS_PER_COLUMN];
    
    region bRegion;

    stats University[NUM_UNIS];
} game;


Game newGame(int discipline[], int dice[]){
    Game new = malloc(sizeof(struct _game));
    int rowCount = 0;
    int columnCount = 0;
    int maxRows = 3;
    int disciplineCount = 0;
    short reverse = FALSE;

    while (columnCount < 5){
	while (rowCount < maxRows){
	    new->bRegion.boardRegions[columnCount][rowCount] = discipline[disciplineCount];
	    new->bRegion.diceVal[columnCount][rowCount] = dice[disciplineCount];
	    rowCount++;
   	    disciplineCount++;
	}

	rowCount = 0;	
	
	if (maxRows == MAX_REGION_ROWS){
	    reverse = TRUE;
	}

	if (reverse == TRUE){
	    maxRows--;
	} else {
	    maxRows++;
	}

        columnCount++;
    }

    new->turnNumber = 0;

    new->whoseTurn = NO_ONE;
    
    //initialising stats
    int uniCount = 0;
    while (uniCount < NUM_UNIS){
	new->University[uniCount].KPIs = 0;
	new->University[uniCount].Campuses = 2;
	new->University[uniCount].ARCGrants = 0;
	new->University[uniCount].Group = 0;
	new->University[uniCount].Patents = 0;
	new->University[uniCount].Papers = 0;
	new->University[uniCount].THDs = 0;
	new->University[uniCount].BQNs = 3;
	new->University[uniCount].BPSs = 3;
	new->University[uniCount].MJs = 1;
	new->University[uniCount].MMONEYs = 1;
	new->University[uniCount].MTVs = 1;
	new->University[uniCount].Prestige = FALSE;
	uniCount++;
    }
    

    //initialising the gameboard
    columnCount = 0;
    while (columnCount < MAX_COLUMNS){
	rowCount = 0;    
	while (rowCount < MAX_ROWS){
		new->boardVertices[columnCount][rowCount] = NO_ONE;
		rowCount++; 
	}
	
	columnCount++;
    }

    columnCount = 0;
    while (columnCount < MAX_COLUMNS){
	int arcCount = 0;    
	while (arcCount < MAX_ARCS_PER_COLUMN){
		new->boardArcs[columnCount][arcCount] = NO_ONE;
		arcCount++; 
	}
	
	columnCount++;
    }
   
    //initialising the starting positions for each uni.
    new->boardVertices[3][0] = UNI_A;
    new->boardVertices[4][10] = UNI_A;
    new->boardVertices[0][1] = UNI_B;
    new->boardVertices[5][5] = UNI_B;
    new->boardVertices[0][6] = UNI_C;
    new->boardVertices[5][0] = UNI_C;

    return new;
}

void disposeGame(Game g){
    free(g);
}
