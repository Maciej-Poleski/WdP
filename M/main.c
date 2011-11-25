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

int *matrix;
int n,m;

char *command;

#define GET(x,y) (*(matrix+m*(x)+(y)))

inline void solution(void)
{
    int z;
    command=malloc(sizeof(char)*8);
    input("%i",&z);
    while(z--)
    {
        input("%i%i",&n,&m);
        matrix=malloc(sizeof(int)*n*m);
        int i;
        for(i=0;i<n*m;++i)
            input("%d",matrix+i);
        int k;
        input("%i",&k);
        while(k--)
        {
            int a;
            input("%s%i%i",command,&i,&a);
            if(*command=='W')
            {
                int x=0,y=0;
                int p;
                for(p=0;p<m;++p)
                {
                    if(GET(i,p)<a)
                    {
                        int t=GET(i,p);
                        GET(i,p)=GET(i,y);
                        GET(i,y++)=GET(i,x);
                        GET(i,x++)=t;
                    }
                    else if(GET(i,p)==a)
                    {
                        int t=GET(i,p);
                        GET(i,p)=GET(i,y);
                        GET(i,y++)=t;
                    }
                }
                for(p=0;p<m;++p)
                    output("%d ",GET(i,p));
                output("\n%d %d\n",x,y);
            }
            else
            {
                check(*command=='K');
                int x=0,y=0;
                int p;
                for(p=0;p<n;++p)
                {
                    if(GET(p,i)<a)
                    {
                        int t=GET(p,i);
                        GET(p,i)=GET(y,i);
                        GET(y++,i)=GET(x,i);
                        GET(x++,i)=t;
                    }
                    else if(GET(p,i)==a)
                    {
                        int t=GET(p,i);
                        GET(p,i)=GET(y,i);
                        GET(y++,i)=t;
                    }
                }
                for(p=0;p<n;++p)
                    output("%d ",GET(p,i));
                output("\n%d %d\n",x,y);
            }
        }
        free(matrix);
    }
    free(command);
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
