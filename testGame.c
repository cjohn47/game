#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Game.h"

#define DEFAULT_DISCIPLINES {STUDENT_BQN, STUDENT_MMONEY, STUDENT_MJ, \
                STUDENT_MMONEY, STUDENT_MJ, STUDENT_BPS, STUDENT_MTV, \
                STUDENT_MTV, STUDENT_BPS,STUDENT_MTV, STUDENT_BQN, \
                STUDENT_MJ, STUDENT_BQN, STUDENT_THD, STUDENT_MJ, \
                STUDENT_MMONEY, STUDENT_MTV, STUDENT_BQN, STUDENT_BPS}
#define DEFAULT_DICE {9,10,8,12,6,5,3,11,3,11,4,6,4,7,9,2,8,10,5}

#define NUM_UNIS 3

void testNewGame(void);
void testDisposeGame(void);
void testMakeAction(void);
void testThrowDice(void);
void testGetDiscipline(void);
void testGetDiceValue(void);
void testGetMostARCs(void);
void testGetMostPublications(void);
void testGetTurnNumber(void);
void testGetWhoseTurn(void);
void testGetCampus(void);
void testGetARC(void);
void testIsLegalAction(void);
void testGetKPIpoints(void);
void testGetARCs(void);
void testGetGO8s(void);
void testGetCampuses(void);
void testGetIPs(void);
void testGetPublications(void);
void testGetStudents(void);
void testGetExchangeRate(void);

int main(int argc, char *argv[]){
  testNewGame();
  testDisposeGame();
  testMakeAction();
  testThrowDice();
  testGetDiscipline();
  testGetDiceValue();
  testGetMostARCs();
  testGetMostPublications();
  testGetTurnNumber();
  testGetWhoseTurn();
  testGetCampus();
  testGetARC();
  testIsLegalAction();
  testGetKPIpoints();
  testGetARCs();
  testGetGO8s();
  testGetCampuses();
  testGetIPs();
  testGetPublications();
  testGetStudents();
  testGetExchangeRate();
  
  printf("All tests passed!\n");
  return EXIT_SUCCESS;
}

void testNewGame(void){
  Game testGame;
  int disciplines[] = DEFAULT_DISCIPLINES;
  int dice[] = DEFAULT_DICE;
  
  newGame(disciplines, dice);
  
  assert(getDiceValue(testGame, 0) == dice[0]);
  assert(getWhoseTurn(testGame) == 0);  
}

void testDisposeGame(void){
  Game testGame = newGame;
  dispose(testGame);
  
  assert(testGame == NULL)
}

void testMakeAction(void){
  
}

void testThrowDice(void){
  
}

void testGetDiscipline(void){
  
}

void testGetDiceValue(void){
  
}

void testGetMostARCs(void){
  
}

void testGetMostPublications(void){
  
}

void testGetTurnNumber(void){
  
}

void testGetWhoseTurn(void){
  
}

void testGetCampus(void){
  
}

void testGetARC(void){
  
}

void testIsLegalAction() {
  Game g;
  int disciplines[] = DEFAULT_DISCIPLINES;
  int dice[] = DEFAULT_DICE;
  
  newGame(disciplines, dice);
  
   assert (isLegalAction(Game g, OBTAIN_IP_PATENT) == FALSE);
   assert (isLegalAction(Game g, PASS) == TRUE);
   assert (isLegalAction(Game g, RETRAIN_STUDENTS) == FALSE);
   assert (isLegalAction(Game g, BUILD_CAMPUS) == FALSE);
   assert (isLegalAction(Game g, OBTAIN_PUBLICATION) == FALSE);
   assert (isLegalAction(Game g, START_SPINOFF) == FALSE);
   assert (isLegalAction(Game g, OBTAIN_ARC) == FALSE);
   assert (isLegalAction(Game g, BUILD_GO8) == FALSE);
}

void testGetKPIpoints(void){
  
}

void testGetARCs(void){
  
}

void testGetGO8s(void){
  
}

void testGetCampuses(void){
  
}

void testGetIPs(void){
  
}

void testGetPublications(void){
  
}

void testGetStudents(void){
  
}

void testGetExchangeRate(void){
  
}

/* void testGets() {
  Game g;
  int disciplines[] = DEFAULT_DISCIPLINES;
  int dice[] = DEFAULT_DICE;
  
  newGame(disciplines, dice);
  
  assert (getMostARCs(Game g) == NO_ONE);

   assert (getDiceValue(Game g, 1) == 9);
   assert (getDiceValue(Game g, 2) == 10);
   assert (getDiceValue(Game g, 3) == 8);
   assert (getDiceValue(Game g, 4) == 12);
   assert (getDiceValue(Game g, 5) == 6);
   assert (getDiceValue(Game g, 6) == 5);
   assert (getDiceValue(Game g, 7) == 3);
   assert (getDiceValue(Game g, 8) == 11);
   assert (getDiceValue(Game g, 9) == 3);
   assert (getDiceValue(Game g, 10) == 11);
   assert (getDiceValue(Game g, 11) == 4);
   assert (getDiceValue(Game g, 12) == 6);
   assert (getDiceValue(Game g, 13) == 4);
   assert (getDiceValue(Game g, 14) == 7);
   assert (getDiceValue(Game g, 15) == 9);
   assert (getDiceValue(Game g, 16) == 2);
   assert (getDiceValue(Game g, 17) == 8);
   assert (getDiceValue(Game g, 18) == 10);
   assert (getDiceValue(Game g, 19) == 5);
   
   assert (getTurnNumber(Game g) == -1);

   assert (getWhoseTurn(Game g) == NO_ONE);

   assert (getCampus(Game g, "RR") == VACANT_VERTEX);
   assert (getCampus(Game g, "RRL") == VACANT_VERTEX);
   assert (getCampus(Game g, "LL") == VACANT_VERTEX);
   assert (getCampus(Game g, "LLR") == VACANT_VERTEX);
   assert (getCampus(Game g, "RRLL") == VACANT_VERTEX);
   assert (getCampus(Game g, "RLLL") == VACANT_VERTEX);
   assert (getCampus(Game g, "RB") == CAMPUS_A);

   assert(getMostPublications(Game g) == NO_ONE);
}  
*/




