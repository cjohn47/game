// make the specified action for the current player and update the
// Game state accordingly.
// The function may assume that the action requested is legal.
// START_SPINOFF is not a legal action here

void makeAction(Game g, action a) {
   // perform the requested action `a'
   // update counters as required (e.g. uniWithMostPubs, numIPs, 
   // numKPI, studentAmounts etc)
 
   int currPlayer = getWhoseTurn(g);
   int uniCampus;
   int uniG08;
   int uniArc;
   
      if(currPlayer == UNI_A) {
         uniCampus = CAMPUS_A;
	 uniG08 = G08_A;
	 uniArc = ARC_A;
	} 
	else if (currPlayer == UNI_B) {
	  uniCampus = CAMPUS_B;
	  uniG08 = G08_B;
	  uniArc = ARC_B;
	}
	else if (currPlayer == UNI_C) {
	  uniCampus = CAMPUS_C;
	  uniG08 = G08_C;
	  uniArc = ARC_C;
	}
	
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

    

    //use boardVertex[C][R] = currPlayer; 
    //pathVertex(g, a.destination);
   
    //g->boardVertices[track.currCollumn][track.currRow] = currPlayer;

   if(a.actionCode == BUILD_CAMPUS) {
    //record position of vertex   
    //update number of "resources" with counter
    //increase number of KPI
	  
	  
      //finding position of vertex on board
      g->boardVertices[C][R] = uniCampus;
	  
      g->University[currPlayer-1].Campuses++;
      g->University[currPlayer-1].BPSs--;
      g->University[currPlayer-1].BQNs--;
      g->University[currPlayer-1].MJs--;
      g->University[currPlayer-1].MTVs--;
	  
      g->University[currPlayer-1].KPI+=10;
   
   
   } else if (a.actionCode == BUILD_G08) {
   
      g->boardVertices[C][R] = uniG08;
       
      g->University[currPlayer-1].Campuses--;
      g->University[currPlayer-1].G08s++;
	  
      g->University[currPlayer-1].MJs -= 2;
      g->University[currPlayer-1].MMONEYs -=3;
      g->University[currPlayer-1].KPIs+=10;
	  
	  
	  
   } else if (a.actionCode == OBTAIN_ARC) {
       
      g->boardArcs[C][R] = uniArc; 
       
      g->University[currPlayer-1].ARCGrants++;
      g->University[currPlayer-1].BPS--;
      g->University[currPlayer-1].BQNs--;
      g->University[currPlayer-1].KPIs+=10;
   
       
   
   } else if (a.actionCode == RETRAIN_STUDENTS) {
   
   
     int rate = getExchangeRate(g, currPlayer, 
                                a.disciplineFrom, a.disciplineTo);
	  
	  
   
   } else if (a.actionCode == OBTAIN_PUBLICATION) {
   
      g->University[currPlayer-1].MTVs--;
      g->University[currPlayer-1].MJs--;
      (g->University[currPlayer-1].Papers + g->University[currPlayer-1].Patents) ++;
      g->University[currPlayer-1].MMONEYs--;
      g->University[currPlayer-1].KPIs+=10;
     
     //update Uni with most pubs
      g->University[currPlayer-1] = getMostPublications(g);
   
   
   
   } else if (a.actionCode == OBTAIN_IP_PUBLICATION) {
   
      g->University[currPlayer-1].MJs--;
      g->University[currPlayer-1].MTVs--;
      g->University[currPlayer-1].MMONEYs--;
      g->University[currPlayer-1].IPs++;
      g->University[currPlayer-1].KPIs+=10;
   
      
}
