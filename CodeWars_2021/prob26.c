//
// Created by Arnav on 3/2/2023.
//

#include <stdio.h>
#include <stdlib.h>

#define COLOR 0
#define N 1
#define L 2

int dimx;
int dimy;
int doors;
int t=0;

typedef int dtype[3];

char *board;
dtype *door;
int begin;
int finish;

void dump(t)int t;{
    int i;
    printf("time: %d\n",t);
    for(i=0;i<dimx*dimy;i++) {
        putchar(board[i]);
        if(((i+1)%dimx)==0)
            putchar('\n');
    }
}

void final(c) char *c; {
    char l;
    int t;
    int i;

    for(t=0,l='x',i=0;c[i];i++) {
        if(c[i]!=l) {
            if(i) printf("%c %d\n",l,t);
            t=1;
            l=c[i];}
        else
            t++;
    }
    printf("%c %d\n",l,t);
}
void actuate(t) int t; {
    int i;
    for(i=0;i<doors;i++)
        if(t>=door[i][N]) {
            board[door[i][L]]=(door[i][COLOR]=='G')?'.':'#';
        }
        else
            board[door[i][L]]=(door[i][COLOR]=='G')?'#':'.';
}


void play(d,l,h) int d,l; char *h;{
    int x,y;
    char hist[1024];

    actuate(d);
    x=l%dimx;
    y=l/dimx;

    if(l==finish) {
        final(h);
        exit(0);
    }

    if(((x+1)<dimx)&&(board[l+1]=='.')) {
        board[l+1]='*';
        sprintf(hist,"%sE",h);
        play(d+2,l+1,hist);
        board[l+1]='.';
    }

    if(((x-1)>=0)&&(board[l-1]=='.')) {
        board[l-1]='*';
        sprintf(hist,"%sW",h);
        play(d+2,l-1,hist);
        board[l-1]='.';
    }

    if(((y+1)<dimy)&&(board[l+dimx]=='.')) {
        board[l+dimx]='*';
        sprintf(hist,"%sS",h);
        play(d+2,l+dimx,hist);
        board[l+dimx]='.';
    }

    if(((y-1)>=0)&&(board[l-dimx]=='.')) {
        board[l-dimx]='*';
        sprintf(hist,"%sN",h);
        play(d+2,l-dimx,hist);
        board[l-dimx]='.';
    }
}


int main(argc,argv) int argc; char **argv; {
    int i=0;
    int x,y,t;
    char c;
    char cc[2];


    scanf("%d %d %d",&dimx,&dimy,&doors);
    board=malloc(sizeof(char)*dimx*dimy);
    door=malloc(sizeof(int)*4*doors);


    while(i<dimx*dimy) {
        c=getchar();
        if(c=='B') { begin=i;  board[i]=c;   i++; continue; }
        if(c=='F') { finish=i; board[i]='.'; i++; continue; }
        if(c=='R') { board[i]='.'; i++; continue; }
        if(c=='G') { board[i]='#'; i++; continue; }
        if((c=='.')||(c=='#')) { board[i]=c; i++; continue; }
    }

    for(i=0;i<doors;i++) {
        scanf("%s %d %d %d",cc,&t,&x,&y);
        door[i][COLOR]=cc[0];
        door[i][N]=t;
        door[i][L]=y*dimx+x;
    }

    play(0,begin,"");
}



