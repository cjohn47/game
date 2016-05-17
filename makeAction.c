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
   
   if(currPlayer == UNI_A) {
      uniCampus = CAMPUS_A;
	    uniG08 = G08_A;
	} 
	else if (currPlayer == UNI_B) {
	  uniCampus = CAMPUS_B;
	  uniG08 = G08_B;
	}
	else if (currPlayer == UNI_C) {
	  uniCampus = CAMPUS_C;
	  uniG08 = G08_C;
	}
	
   typedef struct _pathTrack {
      int currCollumn;
      int currRow;
      int validPath;
     
      int prevCollumn;
      int prevRow;
    } pathTrack;
    
    pathTrack track;

    

    //use boardVertex[C][R] = currPlayer; 
    //pathVertex(g, a.destination);
   
    //g->boardVertices[track.currCollumn][track.currRow] = currPlayer;
   
   if(a.actionCode == BUILD_CAMPUS) {
    //record position of vertex   
	  //update number of "resources" with counter
	  //increase number of KPI
	  
	  
	  //finding position of vertex on board
	   g->boardVertices[track.currCollumn][track.currRow] = uniCampus;
	  
	   g->University[currPlayer-1].Campuses++;
	  
	   g->University[currPlayer-1].BPSs--;
	   g->University[currPlayer-1].BQNs--;
	   g->University[currPlayer-1].MJs--;
	   g->University[currPlayer-1].MTVs--;
	  
      g->University[currPlayer-1].KPI+=10;
   
   
   } else if (a.actionCode == BUILD_G08) {
   
       g->boardVertices[track.currColumn][track.currRow] = uniG08;
       
       g->University[currPlayer-1].Campuses--;
	     g->University[currPlayer-1].G08s++;
	  
	     g->University[currPlayer-1].MJs -= 2;
       g->University[currPlayer-1].MMONEYs -=3;
       g->University[currPlayer-1].KPIs+=10;
	  
	  
	  
   } else if (a.actionCode == OBTAIN_ARC) {
       g->University[currPlayer-1].ARCGrants++;
       g->University[currPlayer-1].BPS--;
       g->University[currPlayer-1].BQNs--;
       g->University[currPlayer-1].KPIs+=10;
   
   
   
   } else if (a.actionCode == RETRAIN_STUDENTS) {
   
   
     int rate = getExchangeRate(g, currPlayer, a.disciplineFrom, a.disciplineTo);
	  
	  
   
   } else if (a.actionCode == OBTAIN_PUBLICATION) {
   
     g->University[currPlayer-1].MTVs--;
	   g->University[currPlayer-1].MJs--;
	   g->University[currPlayer-1].Papers++;
     g->University[currPlayer-1].Patents++;
     g->University[currPlayer-1].MMONEYs--;
     g->University[currPlayer-1].KPIs+=10;
   
   
   
   } else if (a.actionCode == OBTAIN_IP_PUBLICATION) {
   
      g->University[currPlayer-1].MJs--;
	    g->University[currPlayer-1].MTVs--;
	    g->University[currPlayer-1].MMONEYs--;
      g->University[currPlayer-1].IPs++;
      g->University[currPlayer-1].KPIs+=10;
   

}
