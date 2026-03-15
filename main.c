#include <stdio.h>
#include "TwixtBoard.h"
#include "check4links.h"
#include "Win_check.h"

int main(){

    printf("Welcome to TWIXT!!\nHAPPY GAME (^-^)\n");

    char board[SIZE][SIZE];
    for (int i=0;i<SIZE;i++)
        for (int j=0;j<SIZE;j++)
            board[i][j]='.';

    board[0][0]=board[0][SIZE-1]=board[SIZE-1][0]=board[SIZE-1][SIZE-1]=' ';

    char P1='R', P2='B', T;
    int first, n=0;

    do{
    printf("Choose who will play first:\n1-> Red(R): top to bottom\n2-> Blue(B):left to right\n");
    scanf("%d",&first);
    if(first==1) n=0;
    else if(first==2){
        T=P1;
        P1=P2;
        P2=T;
        n=0;
    }else {
        printf("Decide karlo yrr..\n");
        n=1;
    }
    }while(n==1);
    int r,c;
    while (1){
        TwixtBoard(board);
        printf("Player %c to play.\nPlease enter row and column\nOr enter -1 to resign: ",P1);
        scanf("%d",&r);
        if (r==-1){
            printf("%c Resigns\n%c Wins!!\nThank You for Playing",P1,P2);
            break;
        }
        scanf("%d", &c);

        if(r<0 || c<0 || r>=SIZE || c>=SIZE || ((r==0||r==23) && (c==0||c==23))) printf("Out of Board Coordinates!!\nEnter again\n");
        else if((P1=='B'&& r==0)||(P1=='B'&& r==SIZE-1)||(P1=='R'&& c==0)||(P1=='R'&& c==SIZE-1))
            printf("Not your territory. Try other places.\n");
        else if(board[r][c]!='.') printf("Place taken!!\nEnter something else\n");
        else{
            board[r][c] = P1;
            check4links(board, r, c, P1);
            printf("Number of links= %d\n",count);
            printf("LINKS:  ");
            print_links();
            printf("\n");
            if(Win_check(board,P1)){
                printf("Player %c WON!!\nCongrats! Thank you for playing.",P1);
                break;
            }
            T=P2;
            P2=P1;
            P1=T;
        }

    }
    return 0;
}
