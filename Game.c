#include <stdio.h>
#include <stdlib.h>

typedef struct _stats{
    int KPIs
    int Campuses
    int Group
    int ARC Grants
    int Patents
    int Papers
    int THDs
    int BPSs
    int BQNs
    int MJs
    int MTVs
    int MMONEYs
} stats;

typedef struct _game {
    int turnNumber; 
    int whoseTurn;
    int currentDice;
    stats PlayerA;
    stats PlayerB;
    stats PlayerC;
}
