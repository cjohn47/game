#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "game.h"

#define DEFAULT_DISCIPLINES {STUDENT_BQN, STUDENT_MMONEY, STUDENT_MJ, \
                STUDENT_MMONEY, STUDENT_MJ, STUDENT_BPS, STUDENT_MTV, \
                STUDENT_MTV, STUDENT_BPS,STUDENT_MTV, STUDENT_BQN, \
                STUDENT_MJ, STUDENT_BQN, STUDENT_THD, STUDENT_MJ, \
                STUDENT_MMONEY, STUDENT_MTV, STUDENT_BQN, STUDENT_BPS}
#define DEFAULT_DICE {9,10,8,12,6,5,3,11,3,11,4,6,4,7,9,2,8,10,5}

void testNewGame(void);
void testDisposeGame(void)

int main(int argc, char *argv[]){
  testNewGame();
  testDisposeGame();
  
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

void testDisposeGame(){
  Game testGame = newGame;
  dispose(testGame);
  
  assert(testGame == NULL)
}

