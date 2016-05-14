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
   }
   return isLegal;
}
