#ifndef WIN_CHECK_H
#define WIN_CHECK_H

#include "TwixtBoard.h"

int next(char board[SIZE][SIZE], int r, int c, char player);
int Win_check(char board[SIZE][SIZE], char player);

#endif
