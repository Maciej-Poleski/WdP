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

#ifdef DEBUG

void checkStack(void);

#else

inline void checkStack(void) {}

#endif // DEBUG

int n,m,s;
bool swapped;
bool y[40];
bool xpy[39*2+1];
bool xmy[39*2+1];

inline bool count(int row)
{
    check(row>=0);
    check(row<=n);
    if(s>n-row)
        return false;
    if(s==0)
    {
        output("TAK\n");
        return true;
    }
    int i;
    --s;
    for(i=0;i<m;++i)
    {
        if(y[i] || xpy[row+i] || xmy[row-i+m-1])
            continue;
        y[i]=xpy[row+i]=xmy[row-i+m-1]=true;
        if(count(row+1))
        {
            if(swapped)
                output("%d %d\n",i+1,row+1);
            else
                output("%d %d\n",row+1,i+1);
            return true;
        }
        y[i]=xpy[row+i]=xmy[row-i+m-1]=false;
    }
    ++s;
    return count(row+1);
}

inline void solution(void)
{
    int z;
    input("%i",&z);
    while(z--)
    {
        input("%i%i%i",&n,&m,&s);
        if(n>m)
        {
            int t=n;
            n=m;
            m=t;
            swapped=true;
        }
        else
            swapped=false;
        memset(y,0,sizeof(bool)*m);
        memset(xpy,0,sizeof(bool)*(n+m-1));
        memset(xmy,0,sizeof(bool)*(n+m-1));
        if(!count(0))
        {
            output("NIE\n");
        }
    }
}

#ifdef DEBUG

inline void checkAll(void)
{

}

void checkStack(void)
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
