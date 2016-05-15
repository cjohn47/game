#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Game.h"

//For vertices and arcs
#define MAX_COLUMNS 6
#define MAX_ROWS 11
#define MAX_ARCS_PER_COLUMN 10

//For regions
#define MAX_REGION_ROWS 5
#define MAX_REGION_COLUMNS 5

#define FAILED -1
#define OUT_OF_BOUNDS -1


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
    int GO8s;
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

typedef char path[PATH_LIMIT];

Game newGame(int discipline[], int dice[]){
    Game new = malloc(sizeof(struct _game));
    int rowCount = 0;
    int columnCount = 0;
    int maxRows = 3;
    int disciplineCount = 0;
    short reverse = FALSE;

    int r_count = 0;
    int c_count = 0;
    while (c_count < MAX_REGION_COLUMNS){
	r_count = 0;
	while (r_count < MAX_REGION_ROWS){
	    new->bRegion.boardRegions[c_count][r_count] = OUT_OF_BOUNDS;
            new->bRegion.diceVal[c_count][r_count] = OUT_OF_BOUNDS;
	    r_count++;
	}
        c_count++;
    }

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

    new->turnNumber = -1;

    new->whoseTurn = NO_ONE;

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
    new->boardVertices[2][0] = CAMPUS_A;
    new->boardVertices[3][10] = CAMPUS_A;
    new->boardVertices[0][1] = CAMPUS_B;
    new->boardVertices[5][5] = CAMPUS_B;
    new->boardVertices[0][6] = CAMPUS_C;
    new->boardVertices[5][0] = CAMPUS_C;

    return new;
}

void disposeGame(Game g){
    free(g);
}

void makeAction (Game g, action a);

void throwDice(Game g, int diceScore){
    int v_rowCount = 0;
    int v_colCount = 0;
    int r_rowCount = 0;
    int r_colCount = 0;
	    
    int uniCount = 0;
    g->currentDice = diceScore;
    while (uniCount < NUM_UNIS){
	v_colCount = 0;
        while (v_colCount < MAX_COLUMNS){
	    v_rowCount = 0;
            while (v_rowCount < MAX_ROWS){
                r_colCount = 0;
                while (r_colCount < MAX_REGION_COLUMNS){
                    r_rowCount = 0;
		    		while (r_rowCount < MAX_REGION_ROWS){
                      
			    		short condition1 = FALSE;
						if (v_colCount != 0 && v_colCount != MAX_COLUMNS - 1 && v_colCount != 0){    
							condition1 = v_colCount == r_colCount || v_colCount == r_colCount-1;
						} else if (v_colCount == 0){
							condition1 = v_colCount == r_colCount;
						} else if (v_colCount == MAX_COLUMNS - 1){
							condition1 = v_colCount == r_colCount + 1;
						}
						if (v_colCount < 3 && v_rowCount == 0){
							condition1 = v_colCount == r_colCount;
						} else if (v_colCount > 2 && v_rowCount == 0){
							condition1 = v_colCount == r_colCount + 1;
						} 

						int loopCount = 0;
						int maxRows = 6;
						while (loopCount < MAX_COLUMNS){
							if (v_rowCount == maxRows && v_colCount < 3){
								condition1 = v_colCount == r_colCount;
							}else if (v_rowCount == maxRows && v_colCount > 2){
								condition1 = v_colCount == r_colCount + 1;
							}

							if (loopCount > 2){
								maxRows -= 2;
							} else if (loopCount < 2){
								maxRows +=2;
							}
							loopCount++;
						}

						short condition2 = (v_rowCount >= 2 * r_rowCount && v_rowCount <= 2 * r_rowCount + 2);
	        			short condition3 = g->bRegion.diceVal[r_colCount][r_rowCount] == diceScore;
            			short condition4 = g->boardVertices[v_colCount][v_rowCount] == uniCount + 1;

	
		                if (condition1 && condition2 && condition3 && condition4){

				    		if (g->bRegion.boardRegions[r_colCount][r_rowCount] == STUDENT_THD){
								g->University[uniCount].THDs++;
				    		}
					    	if (g->bRegion.boardRegions[r_colCount][r_rowCount] == STUDENT_BPS){
								g->University[uniCount].BPSs++;
					    	}
					   	if (g->bRegion.boardRegions[r_colCount][r_rowCount] == STUDENT_BQN){
		                        			g->University[uniCount].BQNs++;
					    	}
					    	if (g->bRegion.boardRegions[r_colCount][r_rowCount] == STUDENT_MJ){
								g->University[uniCount].MJs++;
					    	}
				            if (g->bRegion.boardRegions[r_colCount][r_rowCount] == STUDENT_MTV){							
								g->University[uniCount].MTVs++;
					    	}
					    	if (g->bRegion.boardRegions[r_colCount][r_rowCount] == STUDENT_MMONEY){
								g->University[uniCount].MMONEYs++;
					    	}
				        }
		
					r_rowCount++;
				    }
		
				    r_colCount++;
			        }   
				
					v_rowCount++;
				    }
				
    	        v_colCount++;
    	    }


    	    if (diceScore == 7){
		    g->University[uniCount].THDs += g->University[uniCount].MTVs + g->University[uniCount].MMONEYs;
   	        g->University[uniCount].MTVs = 0;
		    g->University[uniCount].MMONEYs = 0;  
		}

     
        uniCount++;
    }
}

int getDiscipline(Game g, int regionID){
    assert(regionID >= 0 && regionID < NUM_REGIONS);
    int discipline = FAILED; 
    if (regionID < 3){
        discipline = g->bRegion.boardRegions[0][regionID];
    } else if (regionID < 7){
	discipline = g->bRegion.boardRegions[1][regionID - 3];
    } else if (regionID < 12){
	discipline = g->bRegion.boardRegions[2][regionID - 7];
    } else if (regionID < 16){
	discipline = g->bRegion.boardRegions[3][regionID - 12];
    } else if (regionID < NUM_REGIONS){
	discipline = g->bRegion.boardRegions[4][regionID - 16];
    }
    
    assert(discipline != FAILED);

    return discipline;
}

int getDiceValue(Game g, int regionID){
    assert(regionID >= 0 && regionID < NUM_REGIONS);
    int diceVal = FAILED; 
    if (regionID < 3){
        diceVal = g->bRegion.diceVal[0][regionID];
    } else if (regionID < 7){
	diceVal = g->bRegion.diceVal[1][regionID - 3];
    } else if (regionID < 12){
	diceVal = g->bRegion.diceVal[2][regionID - 7];
    } else if (regionID < 16){
	diceVal = g->bRegion.diceVal[3][regionID - 12];
    } else if (regionID < NUM_REGIONS){
	diceVal = g->bRegion.diceVal[4][regionID - 16];
    }
    
    assert(diceVal != FAILED);

    return diceVal;
}

int getMostARCs (Game g) {
    int university = -1;
    int NUM_ARCS = 0;
    int i = 0;
    
    while (i<NUM_UNIS) {
        if (g-> University[i] . ARCGrants > NUM_ARCS) {
            university = i;
        } else if (NUM_ARCS == (g-> University[i] . ARCGrants)) {
            university = -1;
        }
        i++;
    }
    return university;
}

int getMostPublications (Game g) {
    int university = -1;
    int NUM_PUBS = 0;
    int i = 0;
    
    while (i<NUM_UNIS) {
        if ((g-> University[i] . Papers + g-> University[i] . Patents) > NUM_PUBS) {
            university = i;
        }
        else if (NUM_PUBS == (g-> University[i] . Papers + g-> University[i] . Patents)) {
            university = -1;
        }
        i++;
    }
    return university;
}

int getTurnNumber (Game g){
    return g -> turnNumber;
}

int getWhoseTurn (Game g) {
    return g -> whoseTurn;
}

int getCampuses(Game g, int player) {
        return g-> University[player-1] . Campuses;
}

int getARC(Game g, path pathToEdge);

int isLegalAction (Game g, action a) {
   int isLegal = FALSE;
   //check path
   //path must be RLB
   //path must be less than 150 characters
   //path must not leave the board
   //check all adjacent vertexes
   //record in:
   //if boardVertices[path destination][path destination] == 0 then empty
   //if boardArcs[path destination][pathdestination] == 0 then empty
   typedef struct _pathTrack {
      int currCollumn;
      int currRow;
      int validPath;
     
      int prevCollumn;
      int prevRow;
    } pathTrack;
    
    pathTrack track;

    track.currCollumn = 5;
    track.currRow = 0;
    track.validPath = TRUE;

   if (a.destination[0] != 'R' && a.destination[0] != 'L') {
      track.validPath = FALSE;
   } else {
      track.prevCollumn = 5;
      track.prevRow = 0;

      if (a.destination[0] == 'R') {
         track.currCollumn = (track.prevCollumn - 1);
         track.currRow = (track.prevRow + 1);
      } else if (a.destination[0] == 'L') {
         track.currCollumn = (track.prevCollumn + 1);
         track.currRow = (track.prevRow);
      }
    }

      int i = 1;
      while ((a.destination[i] == 'R' ||
               a.destination[i] == 'L' ||
                a.destination[i] == 'B') && 
              track.validPath == TRUE) {
         if (track.currCollumn > 11 ||  track.currCollumn < 0  ||
             track.currRow > 10 || track.currRow < 0) {
             
            track.validPath = FALSE;

         } else if (a.destination[i] == 'R') {
            
            if ((track.currCollumn - 1) == (track.prevCollumn) 
            && (track.currRow - 1) == (track.prevRow)) {
    
               track.prevCollumn = track.currCollumn;
               track.prevRow = track.currRow;
               track.currCollumn = track.currCollumn - 1;
               track.currRow = track.currRow + 1;

            } else if ((track.currCollumn + 1) == (track.prevCollumn) 
                        && (track.currRow) == (track.prevRow)) {
              //execute movement
               track.prevCollumn = track.currCollumn;
               track.prevRow= track.currRow;
               track.currCollumn = track.currCollumn - 1;
               track.currRow = track.currRow - 1;

            } else if ((track.currCollumn - 1) == (track.prevCollumn) 
                       && (track.currRow + 1) == (track.prevRow)) {
                       //execute movement
               track.prevCollumn = track.currCollumn;
               track.prevRow = track.currRow;
               track.currCollumn++;


            } else if ((track.currCollumn + 1) == (track.prevCollumn) 
                       && (track.currRow - 1) == (track.prevRow)) {
              //execute movement
              track.prevCollumn = track.currCollumn;
              track.prevRow = track.currRow;
              track.currCollumn--;


            } else if ((track.currCollumn - 1) == (track.prevCollumn) 
                       && (track.currRow) == (track.prevRow)) {
               //execute movement
               track.prevCollumn = track.currCollumn;
               track.prevRow = track.currRow;
               track.currCollumn++;
               track.currRow++;


            } else if ((track.currCollumn + 1) == (track.prevCollumn) 
                       && (track.currRow + 1) == (track.prevRow)) {
               //execute movement
               track.prevCollumn = track.currCollumn;
               track.prevRow = track.currRow;
               track.currCollumn++;
               track.currRow--;
            }

         } else if (a.destination[i] == 'L') {
               
            if ((track.currCollumn - 1) == (track.prevCollumn) 
                && (track.currRow - 1) == (track.prevRow)) {
    
               track.prevCollumn = track.currCollumn;
               track.prevRow = track.currRow;
               track.currCollumn++;

            } else if ((track.currCollumn + 1) == (track.prevCollumn) 
                        && (track.currRow) == (track.prevRow)) {
              //execute movement
               track.prevCollumn = track.currCollumn;
               track.prevRow = track.currRow;
               track.currCollumn--;
               track.currRow++;

            } else if ((track.currCollumn - 1) == (track.prevCollumn) 
                       && (track.currRow + 1) == (track.prevRow)) {
                       //execute movement
               track.prevCollumn = track.currCollumn;
               track.prevCollumn = track.currRow;
               track.currCollumn--;
               track.currRow--;


            } else if ((track.currCollumn + 1) == (track.prevCollumn) 
                       && (track.currRow - 1) == (track.prevRow)) {
              //execute movement
              track.prevCollumn = track.currCollumn;
              track.prevRow = track.currRow;
              track.currCollumn++;
              track.currRow++;


            } else if ((track.currCollumn - 1) == (track.prevCollumn ) 
                       && (track.currRow) == (track.prevRow)) {
               //execute movement
               track.prevCollumn = track.currCollumn;
               track.prevRow = track.currRow;
               track.currCollumn++;
               track.currRow--;


            } else if ((track.currCollumn + 1) == (track.prevCollumn) 
                       && (track.currRow + 1) == (track.prevRow)) {
               //execute movement
               track.prevCollumn = track.currCollumn;
               track.prevRow = track.currRow;
               track.currCollumn--;
               track.currRow++;
            }
           }
           i++;
         }

    int C = track.currCollumn;
    int R = track.currRow;

    if (track.currCollumn == 0 || track.currCollumn == 1) {
       C = 0;
    } else if (track.currCollumn == 2 || track.currCollumn == 3) {
       C = 1;
    } else if (track.currCollumn == 4 || track.currCollumn == 5) {
       C = 2;
    } else if (track.currCollumn == 6 || track.currCollumn == 7) {
       C = 3;
    } else if (track.currCollumn == 8 || track.currCollumn == 9) {
       C = 4;
    } else if (track.currCollumn == 10 || track.currCollumn == 11) {
       C = 5; 
    } else {
        track.validPath = FALSE;
    }

   if (g->whoseTurn == -1) {
      isLegal= FALSE;
    } else if (a.actionCode == PASS) {
      isLegal = TRUE;
    } else if (a.actionCode == BUILD_CAMPUS) {
       //campus is not adjacent to other campus
       int validCampus = FALSE;
       
       if (track.prevCollumn == (track.currCollumn - 1) &&
           track.prevRow == (track.currRow - 1)) {
           
           if (g->boardVertices[C][R-1] == 0 &&
               g->boardVertices[C+1][R] == 0 &&
               g->boardVertices[C][R+1] == 0) {

               validCampus = TRUE;
           }

       } else if (track.prevCollumn == (track.currCollumn + 1) &&
           track.prevRow == (track.currRow)) {

           if (g->boardVertices[C][R-1] == 0 &&
               g->boardVertices[C+1][R] == 0 &&
               g->boardVertices[C][R+1] == 0) {

               validCampus = TRUE;
           }
           
       } else if (track.prevCollumn == (track.currCollumn - 1) &&
           track.prevRow == (track.currRow + 1)) {

           if (g->boardVertices[C][R-1] == 0 &&
               g->boardVertices[C+1][R] == 0 &&
               g->boardVertices[C][R+1] == 0) {

               validCampus = TRUE;
           }    

       } else if (track.prevCollumn == (track.currCollumn + 1) &&
           track.prevRow == (track.currRow - 1)) {
           
           if (g->boardVertices[C][R-1] == 0 &&
               g->boardVertices[C-1][R] == 0 &&
               g->boardVertices[C][R+1] == 0) {

               validCampus = TRUE;
           }

       } else if (track.prevCollumn == (track.currCollumn - 1) &&
           track.prevRow == (track.currRow)) {

           if (g->boardVertices[C][R-1] == 0 &&
               g->boardVertices[C-1][R] == 0 &&
               g->boardVertices[C][R+1] == 0) {

               validCampus = TRUE;
           }

       } else if (track.prevCollumn == (track.currCollumn + 1) &&
           track.prevRow == (track.currRow + 1)) {
           
           if (g->boardVertices[C][R-1] == 0 &&
               g->boardVertices[C-1][R] == 0 &&
               g->boardVertices[C][R+1] == 0) {

               validCampus = TRUE;
           }

       }

       if (g->boardVertices[C][R] != g->whoseTurn) {
          validCampus = FALSE;
       }

       //campus is on arc belonging to player
       int requiredBPS = 1;
       int requiredBQNs = 1;
       int requiredMJ = 1;
       int requiredMTV = 1;

       if (g->University[g->whoseTurn].MJs >= requiredMJ
       && g->University[g->whoseTurn].MTVs >= requiredMTV
       && g->University[g->whoseTurn].BQNs >= requiredBQNs
       && g->University[g->whoseTurn].BPSs >= requiredBPS) {
          if (validCampus == TRUE) {
            isLegal = TRUE;
          }
       }
       
       if (g->boardVertices[C][R] == 0 &&
           g->boardVertices) {

       }

   } else if (a.actionCode == BUILD_GO8) {
      int requiredMJ = 2;
      int requiredMMONEYS = 3;

      if (g->University[g->whoseTurn].MJs >= requiredMJ &&
          g->University[g->whoseTurn].MMONEYs >= requiredMMONEYS) {

         if (g->boardVertices[C][R] == g->whoseTurn &&
             g->University[g->whoseTurn].GO8s <= 8) {
            isLegal = TRUE;
         }
      }
   } else if (a.actionCode == OBTAIN_ARC) {
      //check path is valid (not occupied by another arc)
      //not connected to other campus arc
      int requiredBQN = 1;
      int requiredBPS = 1;

      if (g->University[g->whoseTurn].MJs >= requiredBQN &&
          g->University[g->whoseTurn].MMONEYs >= requiredBPS) {
         isLegal = TRUE;
      }


   } else if (a.actionCode == START_SPINOFF) {
      int requiredMTV = 1;
      int requiredMMONEYS = 1;
      int requiredMJ = 1;

      if (g->University[g->whoseTurn].MJs >= requiredMJ &&
          g->University[g->whoseTurn].MMONEYs >= requiredMMONEYS &&
          g->University[g->whoseTurn].MTVs >= requiredMTV) {
      
         isLegal = TRUE;
      }

   } else if (a.actionCode == OBTAIN_PUBLICATION) {
      isLegal = FALSE;
   } else if (a.actionCode == OBTAIN_IP_PATENT) {
      isLegal = FALSE;
   } else if (a.actionCode == RETRAIN_STUDENTS) {
      //check number of students is enough
      int studentNumber = 0;
      
      if (a.disciplineFrom == STUDENT_THD) {
         isLegal = FALSE;
         studentNumber = FALSE;
      } else if (a.disciplineFrom == STUDENT_BPS) {
         studentNumber = g->University[g->whoseTurn].BPSs;
      } else if (a.disciplineFrom == STUDENT_BQN) {
         studentNumber = g->University[g->whoseTurn].BQNs;
      } else if (a.disciplineFrom == STUDENT_MJ) {
         studentNumber = g->University[g->whoseTurn].MJs;
      }else if (a.disciplineFrom == STUDENT_MTV ) {
         studentNumber = g->University[g->whoseTurn].MTVs;
      } else if (a.disciplineFrom == STUDENT_MMONEY) {
         studentNumber = g->University[g->whoseTurn].MMONEYs;
      }
      

      if (a.disciplineFrom != STUDENT_THD && studentNumber >= 3) {
         isLegal = TRUE;
      }

   }
   return isLegal;
}

int getKPIpoints (Game g, int player){
    int university = -1;
    int i = 0;
    
    if (i<NUM_UNIS) {
        return g-> University[i] . KPIs
    }
    i++
}


int getARCs (Game g, int player){
        return g-> University[player - 1] . ARCGrants
}

int getARCs (Game g, int player);

int getGO8s (Game g, int player);

int getCampuses (Game g, int player);

int getIPs (Game g, int player);

int getPublications (Game g, int player) {

        return (g-> University[player-1] . Patents + g-> University[player-1].Papers)
}
int getStudents(Game g, int player, int studentID){
    int numStudents = FAILED;
    if (studentID == STUDENT_THD){
		numStudents = g->University[player - 1].THDs;
    }
    if (studentID == STUDENT_BPS){
		numStudents = g->University[player - 1].BPSs;
    }
    if (studentID == STUDENT_BQN){
		numStudents = g->University[player - 1].BQNs;
    }
    if (studentID == STUDENT_MJ){
		numStudents = g->University[player - 1].MJs;
    }
    if (studentID == STUDENT_MTV){
		numStudents = g->University[player - 1].MTVs;
    }
    if (studentID == STUDENT_MMONEY){
		numStudents = g->University[player - 1].MMONEYs;
    }
    assert(numStudents != FAILED);
    return numStudents;
}

int getExchangeRate (Game g, int player, 
                     int disciplineFrom, int disciplineTo);
