// Maciej Poleski
#ifndef DEBUG
#ifndef NDEBUG
#define NDEBUG
#endif
#define init(x,y)
#define end()
#define input(format,...) scanf(format,## __VA_ARGS__)
#define output(format,...) printf(format,## __VA_ARGS__)
#define inchar() getchar()
#define outchar(x) putchar((x))
#define uninchar(x) ungetc((x),stdin)
#define check(x)
#else
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
FILE *_input=NULL;
FILE *_output=NULL;
bool _initialized=false;
void init(int argc,char**argv)
{
    if(argc!=3)
    {
        fprintf(stderr,"Potrzebne są dwa argumenty <wejście> <wyjście>\n");
        exit(1);
    }
    _input=fopen(argv<:1:>,"r");
    _output=fopen(argv<:2:>,"w");
    _initialized=true;
}
void end(void)
{
    fclose(_input);
    fclose(_output);
}
#define input(format,...) fscanf(_input,format,## __VA_ARGS__)
#define output(format,...) fprintf(_output,format,## __VA_ARGS__)
#define inchar() getc(_input)
#define outchar(x) putc((x),_output)
#define check(x) assert(x)
#define uninchar(x) ungetc((x),_input)
#endif

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <time.h>

int L[40][40];
int n,m,k,x1,x2,y1,y2;

long long stepIn(int x,int y)
{
    check(x>=0);
    check(x<n);
    check(y>=0);
    check(y<m);
    if(x==y1 && y==y2)
        return 1L;
    long long result=0L;
    L[x][y]=~L[x][y];
    if(x+1<n && ((L[x+1][y]&(1<<k))==0))
    {
        result+=stepIn(x+1,y);
    }
    if(x-1>=0 && ((L[x-1][y]&(1<<k))==0))
    {
        result+=stepIn(x-1,y);
    }
    if(y+1<m && ((L[x][y+1]&(1<<k))==0))
    {
        result+=stepIn(x,y+1);
    }
    if(y-1>=0 && ((L[x][y-1]&(1<<k))==0))
    {
        result+=stepIn(x,y-1);
    }
    L[x][y]=~L[x][y];
    return result;
}

inline void solution(void)
{
    int z;
    input("%i",&z);
    while(z--)
    {
        input("%i%i%i%i%i%i",&n,&m,&x1,&x2,&y1,&y2);
        --x1; --x2; --y1; --y2;
        int i,j;
        for(i=0;i<n;++i)
            for(j=0;j<m;++j)
                input("%i",&L[i][j]);
        input("%i",&k);
        long long result=stepIn(x1,x2);
        if(result==0)
            output("NIE\n");
        else
            output("TAK %lld\n",result);
    }
}

#ifdef DEBUG

inline checkAll(void)
{

}

#endif // DEBUG

int main(int argc,char**argv)
{
#ifdef DEBUG
    init(argc,argv);
    checkAll();
#endif // DEBUG
    solution();
#ifdef DEBUG
    end();
#endif // DEBUG
    return 0;
}
