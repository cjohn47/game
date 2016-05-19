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

    //converting current vertex to form used in game struct
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
   
    //converting previous vertex to form used in struct
    int CP = track.prevCollumn;
    int RP = track.prevRow;

    if (track.currCollumn == 0 || track.currCollumn == 1) {
       CP = 0;
    } else if (track.currCollumn == 2 || track.currCollumn == 3) {
       CP = 1;
    } else if (track.currCollumn == 4 || track.currCollumn == 5) {
       CP = 2;
    } else if (track.currCollumn == 6 || track.currCollumn == 7) {
       CP = 3;
    } else if (track.currCollumn == 8 || track.currCollumn == 9) {
       CP = 4;
    } else if (track.currCollumn == 10 || track.currCollumn == 11) {
       CP = 5; 
    } else {
        track.validPath = FALSE;
    }

   //START OF ACTION CHECKS
   if (g->whoseTurn == -1) {
      isLegal= FALSE;
    } else if (a.actionCode == PASS) {
      isLegal = TRUE;
    } else if (a.actionCode == BUILD_CAMPUS) {
       
       int validCampus = FALSE;
       
       //checking no other campuses adjacent
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

       //checking campus is built on arc belonging to player
       //and that nothing is in the specified point
       if (g->boardArcs[C][R] != g->whoseTurn &&
           g->boardVertices[C][R] == NO_ONE) {
          validCampus = FALSE;
       }
       
       //checking costs
       int requiredBPS = 1;
       int requiredBQNs = 1;
       int requiredMJ = 1;
       int requiredMTV = 1;

       if (g->University[g->whoseTurn-1].MJs >= requiredMJ
       && g->University[g->whoseTurn-1].MTVs >= requiredMTV
       && g->University[g->whoseTurn-1].BQNs >= requiredBQNs
       && g->University[g->whoseTurn-1].BPSs >= requiredBPS) {
          if (validCampus == TRUE) {
            isLegal = TRUE;
          }
       }

   } else if (a.actionCode == BUILD_GO8) {
      int requiredMJ = 2;
      int requiredMMONEYS = 3;

      if (g->University[g->whoseTurn-1].MJs >= requiredMJ &&
          g->University[g->whoseTurn-1].MMONEYs >= requiredMMONEYS) {

         if (g->boardVertices[C][R] == g->whoseTurn &&
             g->University[g->whoseTurn-1].GO8s <= 8) {
            isLegal = TRUE;
         }
      }
   } else if (a.actionCode == OBTAIN_ARC) {
   
      int validARC = FALSE;
      //check path is valid (not occupied by another arc)
      // and that the arc is connected to other arc
      if (boardArcs[C][P] == NO_ONE && boardArcs[CP][RP] == g->whoseTurn) {
         validARC = TRUE;
      }

      //checking costs
      int requiredBQN = 1;
      int requiredBPS = 1;

      if (g->University[g->whoseTurn-1].MJs >= requiredBQN &&
          g->University[g->whoseTurn-1].MMONEYs >= requiredBPS &&
          validARC == TRUE) {
         isLegal = TRUE;
      }


   } else if (a.actionCode == START_SPINOFF) {
      int requiredMTV = 1;
      int requiredMMONEYS = 1;
      int requiredMJ = 1;

      if (g->University[g->whoseTurn-1].MJs >= requiredMJ &&
          g->University[g->whoseTurn-1].MMONEYs >= requiredMMONEYS &&
          g->University[g->whoseTurn-1].MTVs >= requiredMTV) {
      
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
         studentNumber = g->University[g->whoseTurn-1].BPSs;
      } else if (a.disciplineFrom == STUDENT_BQN) {
         studentNumber = g->University[g->whoseTurn-1].BQNs;
      } else if (a.disciplineFrom == STUDENT_MJ) {
         studentNumber = g->University[g->whoseTurn-1].MJs;
      }else if (a.disciplineFrom == STUDENT_MTV ) {
         studentNumber = g->University[g->whoseTurn-1].MTVs;
      } else if (a.disciplineFrom == STUDENT_MMONEY) {
         studentNumber = g->University[g->whoseTurn-1].MMONEYs;
      }
      

      if (a.disciplineFrom != STUDENT_THD && studentNumber >= 3) {
         isLegal = TRUE;
      }

   }
   
   return isLegal;
}
