#include <stdio.h> 
#include "TwixtBoard.h"

void TwixtBoard(char board[SIZE][SIZE]) {
    printf("   ");
    for (int n=0; n<SIZE; n++) printf("%2d ",n);
    printf("\n");
        printf(" 0  ");
        for (int j=0; j<SIZE; j++) {
            printf("%c  ",board[0][j]);
        }
        printf("\n");
        printf("   ");
    for(int i=0; i<SIZE; i++) printf("---");
    printf("\n");
    for (int i=1; i<SIZE-1; i++) {
        printf("%2d  ",i);
        printf("%c |",board[i][0]);
        for (int j=1; j<SIZE-1; j++) {
            printf("%c  ",board[i][j]);
        }
        printf("|%c",board[i][SIZE-1]);
        printf("\n");
    }
    printf("   ");
    for(int i=0; i<SIZE; i++) printf("---");
    printf("\n");
    printf("%d  ",SIZE-1);
    for (int j=0; j<SIZE; j++) {
        printf("%c  ",board[SIZE-1][j]);
    }
    printf("\n");
}
