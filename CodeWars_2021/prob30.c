//
// Created by Arnav on 3/2/2023.
//

#include <stdio.h>
#define MAX 10
#define EMPTY 0
#define FULL 1
#define VECS 4
#define R 0
#define C 1

int dim;
int total=0;
int board[MAX][MAX];
int final[MAX][MAX];

int v[VECS][2]={{1,0},{-1,0},{0,1},{0,-1}};

int look(r,c,i) int r,c,i; {
    int d;
    int f=0;
    for(d=1;d<dim;d++)
        if(((r+d*v[i][R])>=0)&&((r+d*v[i][R])<dim)&&((c+d*v[i][C])>=0)&&((c+d*v[i][C])<dim)&&(board[r+d*v[i][R]][c+d*v[i][C]])) {f=d;break;}
    return f;
}

int vis(r,c) int r,c; {
    int i;
    int d;
    int seen[4]={0,0,0,0};
    int s=0;


    for(d=1;d<dim;d++)
        for(i=0;i<VECS;i++)
            if(((r+d*v[i][R])>=0)&&((r+d*v[i][R])<dim)&&((c+d*v[i][C])>=0)&&((c+d*v[i][C])<dim)) {
                seen[i]+=board[r+d*v[i][R]][c+d*v[i][C]];
//   if(board[r+d*v[i][R]][c+d*v[i][C]]) printf("%d,%d can see %d,%d\n",r,c,r+d*v[i][R],c+d*v[i][C]);
            }
    for(i=0;i<VECS;i++)
        s+=(seen[i]>0);
    return s;
}

void dump(){
    int r,c;
    for(r=0;r<dim;r++) {
        for(c=0;c<dim;c++)
            printf("%s%s",board[r][c]?"<>":"..",((c+1)<dim)?" ":"\n");
    }
}

void finaldump(){
    int r,c;
    for(r=0;r<dim;r++) {
        for(c=0;c<dim;c++)  {
            if(final[r][c])
                printf("%2d%s",final[r][c],((c+1)<dim)?" ":"\n");
            else
                printf("..%s",((c+1)<dim)?" ":"\n");
        }
    }
}

void play(r,c,d,p) int r,c,d,p; {
    int i;
    int l;

    board[r][c]=EMPTY;
    final[r][c]=d;

#ifdef DEBUG
    printf("play(%d,%d,%d,%d)\n",r,c,d,p);
finaldump();
#endif

    if(d==total) {
        finaldump();
        //exit(0);
    }
    else {
        for(i=0;i<VECS;i++)
            if(l=look(r,c,i)) {
                if((v[i][R]==(-v[p][R]))&&(v[i][C]==(-v[p][C]))) continue; //no reversing
                play(r+l*v[i][R],c+l*v[i][C],d+1,i);
            }
    }

    board[r][c]=FULL;
    final[r][c]=-FULL;

}

int main(argc,argv) int argc; char **argv; {
    int i;
    int v;
    char buf[3];

    scanf("%d",&dim);
    for(i=0;i<dim*dim;i++) {
        scanf("%s",buf);
        total+=(board[i/dim][i%dim]=(buf[0]=='<'));
        final[i/dim][i%dim]=-board[i/dim][i%dim];
    }

    for(i=0;i<dim*dim;i++)
        if(board[i/dim][i%dim]&&(vis(i/dim,i%dim)==1))
            play(i/dim,i%dim,1,VECS);
}
