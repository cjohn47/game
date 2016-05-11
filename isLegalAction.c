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
       || g->University[g->whoseTurn]->MTVs >= requiredMTV
       || g->University[g->whoseTurn]->BQNs >= requiredBQNs
       || g->University[g->whoseTurn]->BPSs >= requiredPBS) {
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
