#include "check4links.h"
#include "Win_check.h"
 
int next(char board[SIZE][SIZE],int r, int c, char player){
    trace[r][c]=1;
    if(player=='R' && r==SIZE-1) return 1;
    if(player=='B' && c==SIZE-1) return 1;
    for(int i=0; i<count; i++){
        if(links[i].r1 == r && links[i].c1 == c) {
            int nr = links[i].r2;
            int nc = links[i].c2;
            if(trace[nr][nc]==0 && board[nr][nc]==player){
                if(next(board,nr,nc,player)) return 1;
            }
        }
        if(links[i].r2 == r && links[i].c2 == c) {
            int nr = links[i].r1;
            int nc = links[i].c1;
            if(trace[nr][nc]==0 && board[nr][nc]==player){
                if(next(board,nr,nc,player)) return 1;
            }
        }
    }
    return 0;
}


int Win_check(char board[SIZE][SIZE],char player){
    for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE; j++){
            trace[i][j]=0;
        }
    }
    if(player=='R'){
        for(int k=1; k<SIZE-1; k++){
            if(board[0][k]=='R' && trace[0][k]==0){
                if(next(board,0,k,'R')) return 1;
            }
        }
    }
    else if(player=='B'){
        for(int k=1; k<SIZE-1; k++){
            if(board[k][0]=='B' && trace[k][0]==0){
                if(next(board,k,0,'B')) return 1;
            }
        }
    }
    return 0;
}

