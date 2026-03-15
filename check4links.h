#ifndef CHECK4LINKS_H
#define CHECK4LINKS_H

#include "TwixtBoard.h"

typedef struct {
    int r1, c1, r2, c2;
    char P;
} Link;

/* GLOBALS — DECLARATIONS ONLY */
extern Link links[10000];
extern int count;
extern int knight_moves[8][2];
extern int trace[SIZE][SIZE];

void print_links(void);
void check4links(char board[SIZE][SIZE], int r, int c, char player);

#endif
