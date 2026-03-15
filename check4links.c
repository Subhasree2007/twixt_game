#include <stdio.h>
#include "check4links.h"

Link links[10000];
int count = 0; 

int knight_moves[8][2] = {
    {-2,-1},{-2,1},{2,-1},{2,1},
    {-1,-2},{-1,2},{1,-2},{1,2}
};

int trace[SIZE][SIZE];

void print_links(void){
    for(int i=0; i< count; i++){
        printf("%c:(%d,%d)->(%d,%d)   ",links[i].P, links[i].r1, links[i].c1, links[i].r2, links[i].c2);
    }
}

void check4links(char board[SIZE][SIZE], int r, int c, char player){
    for(int i = 0; i < 8; i++) {
        int kr = r + knight_moves[i][0];
        int kc = c + knight_moves[i][1];

        if(kr >= 0 && kr < SIZE && kc >= 0 && kc < SIZE) {
            if(board[kr][kc] == player){
                int flag=0;
                int my= c-kc;
                int mx= r-kr;
                if(i<4){
                    if(board[(r+kr)/2][c]!='.'){
                        for(int j = 0; j < count; j++) {
                            if((links[j].r1 == ((r+kr)/2) && links[j].c1 == c) || (links[j].r2 == ((r+kr)/2) && links[j].c2 == c)){
                                int x1= links[j].r1;
                                int y1= links[j].c1;
                                int x2= links[j].r2;
                                int y2= links[j].c2;
                                if((my*(x1-r)-mx*(y1-c))*(my*(x2-r)-mx*(y2-c))<0){
                                    flag=1;
                                    continue;
                                }
                            }
                        }
                    }
                    if(board[(r+kr)/2][kc]!='.'){
                        for(int j = 0; j < count; j++) {
                            if((links[j].r1 == ((r+kr)/2) && links[j].c1 == kc) || (links[j].r2 == ((r+kr)/2) && links[j].c2 == kc)){
                                int x1= links[j].r1;
                                int y1= links[j].c1;
                                int x2= links[j].r2;
                                int y2= links[j].c2;
                                if((my*(x1-r)-mx*(y1-c))*(my*(x2-r)-mx*(y2-c))<0){
                                    flag=1;
                                    continue;
                                }
                            }
                        }
                    }
                }
                else{
                    if(board[r][(c+kc)/2]!='.'){
                        for(int j = 0; j < count; j++) {
                            if((links[j].r1 == r && links[j].c1 == ((c+kc)/2)) || (links[j].r2 == r && links[j].c2 == ((c+kc)/2))){
                                int x1= links[j].r1;
                                int y1= links[j].c1;
                                int x2= links[j].r2;
                                int y2= links[j].c2;
                                if((my*(x1-r)-mx*(y1-c))*(my*(x2-r)-mx*(y2-c))<0){
                                    flag=1;
                                    continue;
                                }
                            }
                        }
                    }
                    if(board[kr][(c+kc)/2]!='.'){
                        for(int j = 0; j < count; j++) {
                            if((links[j].r1 == kr && links[j].c1 == ((c+kc)/2)) || (links[j].r2 == kr && links[j].c2 == ((c+kc)/2))){
                                int x1= links[j].r1;
                                int y1= links[j].c1;
                                int x2= links[j].r2;
                                int y2= links[j].c2;
                                if((my*(x1-r)-mx*(y1-c))*(my*(x2-r)-mx*(y2-c))<0){
                                    flag=1;
                                    continue;
                                }
                            }
                        }
                    }
                }
                if(board[kr][c]!='.'){
                    for(int j = 0; j < count; j++) {
                        if((links[j].r1 == kr && links[j].c1 == c) || (links[j].r2 == kr && links[j].c2 == c)){
                            int x1= links[j].r1;
                            int y1= links[j].c1;
                            int x2= links[j].r2;
                            int y2= links[j].c2;
                            if((my*(x1-r)-mx*(y1-c))*(my*(x2-r)-mx*(y2-c))<0){
                                flag=1;
                                continue;
                            }
                        }
                    }
                }
                if(board[r][kc]!='.'){
                    for(int j = 0; j < count; j++) {
                        if((links[j].r1 == r && links[j].c1 == kc) || (links[j].r2 == r && links[j].c2 == kc)){
                            int x1= links[j].r1;
                            int y1= links[j].c1;
                            int x2= links[j].r2;
                            int y2= links[j].c2;
                            if((my*(x1-r)-mx*(y1-c))*(my*(x2-r)-mx*(y2-c))<0){
                                flag=1;
                                continue;
                            }
                        }
                    }
                }
                if(flag==0){
                    links[count].r1 = r;
                    links[count].c1 = c;
                    links[count].r2 = kr;
                    links[count].c2 = kc;
                    links[count].P= player;
                    count++;
                    printf("Link created between (%d,%d) and (%d,%d)\n", r, c, kr, kc);
                }
            }
        }
    }
}