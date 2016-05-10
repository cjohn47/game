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
  Game testGame;
  int disciplines[] = DEFAULT_DISCIPLINES;
  int dice[] = DEFAULT_DICE;
  
  newGame(disciplines, dice);
}

void testThrowDice(void){
  Game testGame;
  int disciplines[] = DEFAULT_DISCIPLINES;
  int dice[] = DEFAULT_DICE;
  
  newGame(disciplines, dice);
}

void testGetDiscipline(void){
  Game testGame;
  int disciplines[] = DEFAULT_DISCIPLINES;
  int dice[] = DEFAULT_DICE;
  
  newGame(disciplines, dice);
}

void testGetDiceValue(void){
  Game testGame;
  int disciplines[] = DEFAULT_DISCIPLINES;
  int dice[] = DEFAULT_DICE;
  
  newGame(disciplines, dice);
  
  assert (getDiceValue(Game testGame, 1) == 9);
  assert (getDiceValue(Game testGame, 2) == 10);
  assert (getDiceValue(Game testGame, 3) == 8);
  assert (getDiceValue(Game testGame, 4) == 12);
  assert (getDiceValue(Game testGame, 5) == 6);
  assert (getDiceValue(Game testGame, 6) == 5);
  assert (getDiceValue(Game testGame, 7) == 3);
  assert (getDiceValue(Game testGame, 8) == 11);
  assert (getDiceValue(Game testGame, 9) == 3);
  assert (getDiceValue(Game testGame, 10) == 11);
  assert (getDiceValue(Game testGame, 11) == 4);
  assert (getDiceValue(Game testGame, 12) == 6);
  assert (getDiceValue(Game testGame, 13) == 4);
  assert (getDiceValue(Game testGame, 14) == 7);
  assert (getDiceValue(Game testGame, 15) == 9);
  assert (getDiceValue(Game testGame, 16) == 2);
  assert (getDiceValue(Game testGame, 17) == 8);
  assert (getDiceValue(Game testGame, 18) == 10);
  assert (getDiceValue(Game testGame, 19) == 5);
}

void testGetMostARCs(void){
  Game testGame;
  int disciplines[] = DEFAULT_DISCIPLINES;
  int dice[] = DEFAULT_DICE;
  
  newGame(disciplines, dice);
  
  assert (getMostARCs(Game testGame) == NO_ONE);
}

void testGetMostPublications(void){
  Game testGame;
  int disciplines[] = DEFAULT_DISCIPLINES;
  int dice[] = DEFAULT_DICE;
  
  newGame(disciplines, dice);
}

void testGetTurnNumber(void){
  Game testGame;
  int disciplines[] = DEFAULT_DISCIPLINES;
  int dice[] = DEFAULT_DICE;
  
  newGame(disciplines, dice);
  
  assert (getTurnNumber(Game testGame) == -1);
}

void testGetWhoseTurn(void){
  Game testGame;
  int disciplines[] = DEFAULT_DISCIPLINES;
  int dice[] = DEFAULT_DICE;
  
  newGame(disciplines, dice);
  
  assert (getWhoseTurn(Game testGame) == NO_ONE);
}

void testGetCampus(void){
  Game testGame;
  int disciplines[] = DEFAULT_DISCIPLINES;
  int dice[] = DEFAULT_DICE;
  
  newGame(disciplines, dice);
}

void testGetARC(void){
  Game testGame;
  int disciplines[] = DEFAULT_DISCIPLINES;
  int dice[] = DEFAULT_DICE;
  
  newGame(disciplines, dice);
}

void testIsLegalAction() {
  Game testGame;
  int disciplines[] = DEFAULT_DISCIPLINES;
  int dice[] = DEFAULT_DICE;
  
  newGame(disciplines, dice);
  
  assert (isLegalAction(Game testGame, OBTAIN_IP_PATENT) == FALSE);
  assert (isLegalAction(Game testGame, PASS) == TRUE);
  assert (isLegalAction(Game testGame, RETRAIN_STUDENTS) == FALSE);
  assert (isLegalAction(Game testGame, BUILD_CAMPUS) == FALSE);
  assert (isLegalAction(Game testGame, OBTAIN_PUBLICATION) == FALSE);
  assert (isLegalAction(Game testGame, START_SPINOFF) == FALSE);
  assert (isLegalAction(Game testGame, OBTAIN_ARC) == FALSE);
  assert (isLegalAction(Game testGame, BUILD_GO8) == FALSE);
}

void testGetKPIpoints(void){
  Game testGame;
  int disciplines[] = DEFAULT_DISCIPLINES;
  int dice[] = DEFAULT_DICE;
  
  newGame(disciplines, dice);
}

void testGetARCs(void){
  Game testGame;
  int disciplines[] = DEFAULT_DISCIPLINES;
  int dice[] = DEFAULT_DICE;
  
  newGame(disciplines, dice);
}

void testGetGO8s(void){
  Game testGame;
  int disciplines[] = DEFAULT_DISCIPLINES;
  int dice[] = DEFAULT_DICE;
  
  newGame(disciplines, dice);
}

void testGetCampuses(void){
  Game testGame;
  int disciplines[] = DEFAULT_DISCIPLINES;
  int dice[] = DEFAULT_DICE;
  
  newGame(disciplines, dice);
  
  assert (getCampus(Game testGame, "RR") == VACANT_VERTEX);
  assert (getCampus(Game testGame, "RRL") == VACANT_VERTEX);
  assert (getCampus(Game testGame, "LL") == VACANT_VERTEX);
  assert (getCampus(Game testGame, "LLR") == VACANT_VERTEX);
  assert (getCampus(Game testGame, "RRLL") == VACANT_VERTEX);
  assert (getCampus(Game testGame, "RLLL") == VACANT_VERTEX);
  assert (getCampus(Game testGame, "RB") == CAMPUS_A);
}

void testGetIPs(void){
  Game testGame;
  int disciplines[] = DEFAULT_DISCIPLINES;
  int dice[] = DEFAULT_DICE;
  
  newGame(disciplines, dice);
}

void testGetPublications(void){
  Game testGame;
  int disciplines[] = DEFAULT_DISCIPLINES;
  int dice[] = DEFAULT_DICE;
  
  newGame(disciplines, dice);
  
  assert(getMostPublications(Game testGame) == NO_ONE);
}

void testGetStudents(void){
  Game testGame;
  int disciplines[] = DEFAULT_DISCIPLINES;
  int dice[] = DEFAULT_DICE;
  
  newGame(disciplines, dice);
}

void testGetExchangeRate(void){
  Game testGame;
  int disciplines[] = DEFAULT_DISCIPLINES;
  int dice[] = DEFAULT_DICE;
  
  newGame(disciplines, dice);
}




