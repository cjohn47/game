int isLegalAction (Game g, action a) {
   int isLegal = 0;
   int correctPlayer = player-1;

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
    track.CurrRow = 0;
    track.validPath = TRUE;

   if (a->destination[0] != 'R' && a->destination[0] != 'L') {
      point.validPath = FALSE;
   } else {
      track.prevCollumn = 5;
      track.prevRow = 0;

      if (a->destination[0] == 'R') {
         track.currCollumn = (track.prevCollumn - 1);
         track.currCollumn = (track.prevRow + 1);
      } else if (a->destination[0] == 'L') {
         track.currCollumn = (track.prevCollumn + 1);
         track.currCollumn = (track.prevRow);
      }
    }

      int i = 1;
      while (a->destination[i] != NULL) {
         if (track.currCollumn >= //outside || track.collumn //outside
         	 //||row outside ) {
            track.validPath = FALSE;
         } else if (a->destination[i] == 'R') {
            
            if (track.currCollumn == (track.prevCollumn - 1) 
	        && track.currCollumn == (track.prevRow - 1)) {
	
               track.prevCollumn = track.currCollumn;
               track.prevRow = track.currRow;
               track.currCollumn = currCollumn - 1;
               track.currRow = track.currRow + 1;

            } else if (track.currCollumn == (track.prevCollumn + 1) 
	                    && track.currCollumn == (track.prevRow)) {
	          //execute movement
               track.prevCollumn = track.currCollumn;
               track.prevRow= track.currRow;
               track.currCollumn = track.currCollumn - 1;
               track.currRow = track.currRow - 1;

            } else if (track.currCollumn == (track.prevCollumn - 1) 
	                   && track.currCollumn == (track.prevRow + 1)) {
	                   //execute movement
	           track.prevCollumn = track.currCollumn;
               track.prevRow = track.currRow;
               track.currCollumn++;


            } else if (track.currCollumn == (track.prevCollumn + 1) 
	                   && track.currCollumn == (track.prevRow - 1)) {
	          //execute movement
	          track.prevCollumn = track.currCollumn;
              track.prevRow = track.currRow;
              track.currCollumn--;


            } else if (track.currCollumn == (track.prevCollumn - 1) 
	                   && track.currCollumn == (track.prevRow)) {
	           //execute movement
	           track.prevCollumn = track.currCollumn;
               track.prevRow = track.currRow;
               track.currCollumn++;
               track.currRow++;


            } else if (track.currCollumn == (track.prevCollumn + 1) 
	                   && track.currCollumn == (track.prevRow + 1)) {
	           //execute movement
	           track.prevCollumn = track.currCollumn;
               track.prevRow = track.currRow;
               track.currCollumn++;
               track.currRow--;
            }

         } else if (a->destination[i] == 'L') {
               
            if (track.currCollumn == (track.prevCollumn - 1) 
	            && track.currCollumn == (track.prevRow - 1)) {
	
               track.prevCollumn = track.currCollumn;
               track.prevCollumn = track.currRow;
               track.currCollumn = ;
               track.currRow = ;

            } else if (track.currCollumn == (track.prevCollumn + 1) 
	                    && track.currCollumn == (track.prevRow)) {
	          //execute movement
               track.prevCollumn = track.currCollumn;
               track.prevCollumn = track.currRow;
               track.currCollumn = ;
               track.currRow = ;

            } else if (track.currCollumn == (track.prevCollumn - 1) 
	                   && track.currCollumn == (track.prevRow + 1)) {
	                   //execute movement
	           track.prevCollumn = track.currCollumn;
               track.prevCollumn = track.currRow;
               track.currCollumn = ;
               track.currRow = ;


            } else if (track.currCollumn == (track.prevCollumn + 1) 
	                   && track.currCollumn == (track.prevRow - 1)) {
	          //execute movement
	          track.prevCollumn = track.currCollumn;
              track.prevCollumn = track.currRow;
              track.currCollumn = ;
              track.currRow = ;


            } else if (track.currCollumn == (track.prevCollumn - 1) 
	                   && track.currCollumn == (track.prevRow)) {
	           //execute movement
	           track.prevCollumn = track.currCollumn;
               track.prevCollumn = track.currRow;
               track.currCollumn = ;
               track.currRow = ;


            } else if (track.currCollumn == (track.prevCollumn + 1) 
	                   && track.currCollumn == (track.prevRow + 1)) {
	           //execute movement
	           track.prevCollumn = track.currCollumn;
               track.prevCollumn = track.currRow;
               track.currCollumn = ;
               track.currRow = ;
            }
         }

         

            

       
       

      }
   }

   if (destination[i] == 'R') {
        
      	} else if (destination[i] == 'L') {
    
        } else if (destination[i] == 'B') {

      }




   if (g->currentTurn == -1) {
      isLegal= FALSE;
   }
 //needs to be elses from here on
 //action code 0
   if (a->actionCode == PASS) {
   	isLegal = TRUE;
   }
 
 //action code 1
   if (a->actionCode == BUILD_CAMPUS) {
   	   //campus is not adjacent to other campus
   	   //campus is on arc belonging to player
   	   int requiredBPS = 1;
   	   int requiredBQNSs = 1;
   	   int requiredMJ = 1;
   	   int requiredMTV = 1;

   	   if (g->University[g->whoseTurn]->MJs >= requiredMJ
       && g->University[g->whoseTurn]->MTVs >= requiredMTV
       && g->University[g->whoseTurn]->BQNs >= requiredBQNs
       && g->University[g->whoseTurn]->BPSs >= requiredPBS) {
          if (/*campus on applicable vertex*/ ) {
            isLegal = TRUE;
          }
       }

   }

//action code 2
   if (a->actionCode == BUILD_GO8) {
      int requiredMJ = 2;
      int requiredMMONEYS = 3;

      if (g->University[g->whoseTurn]->MJs >= requiredMJ
       || g->University[g->whoseTurn]->MMONEYS >= requiredMMONEYS) {

         if (/*GO8 on applicable vertex*/ ) {
            isLegal = TRUE;
         }
      }
   }
//action code 3
   if (a->actionCode == OBTAIN_ARC) {
      //check path is valid (not occupied by another arc)
      //not connected to other campus arc
   }
//action code 4
   if (a->actionCode == START_SPINOFF) {
      int requiredMTV = 1;
      int required = 1;
      int requiredMJ = 1;

   }
//action code 5
   if (a->actionCode == OBTAIN_PUBLICATION) {
      isLegal = FALSE;
   }
// action code 6
   if (a->actionCode == OBTAIN_IP_PATENT) {
      isLegal = FALSE;
   }
//action code 7
   if (a->actionCode == RETRAIN_STUDENTS) {
      //check number of students is enough
      int studentNumber;
      
      if (a->disciplineFrom == STUDENT_THD) {
         isLegal = FALSE;
         studentNumber = FALSE;
      } else if (a->disciplineFrom == STUDENT_BPS) {
         studentNumber = g->University[g->whoseTurn].BPSs;
      } else if (a->disciplineFrom == STUDENT_BQN) {
      	 studentNumber = g->University[g->whoseTurn].BQNs;
      } else if (a->disciplineFrom == STUDENT_MJ) {
      	 studentNumber = g->University[g->whoseTurn].MJs;
      }else if (a->disciplineFrom == STUDENT_MTV ) {
      	 studentNumber = g->University[g->whoseTurn].MTVs;
      } else if (a->disciplineFrom == STUDENT_MMONEY) {
      	 studentNumber = g->University[g->whoseTurn].MMONEYs;
      }
      

      if (a->disciplineFrom != STUDENT_THD && studentNumber >= 3 && ) {
         isLegal = TRUE;
      }

   }



   return isLegal;
}




